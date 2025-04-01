#!python3

from typing import Self
import generate_keydata
import toml
import sys
import os


class Node:
    keys: tuple
    parent: Self | None
    children: dict[str, Self]

    _value_leave: list[str] | None = None

    def __init__(
        self,
        *,
        id: str,
        keys: tuple[str, ...],
        parent: Self | None = None,
        children: dict[str, Self] | None = None,
    ):
        self.id = id
        self.keys = keys
        self.parent = parent
        self.children = children or dict()

    def add_parent(self, parent: Self):
        self.parent = parent

    def add_child(self, key: str, child: Self):
        self.children[key] = child

    def set_value_leave(self, value: list[str]):
        self._value_leave = value

    def get_value_leave(self) -> list[str] | None:
        return self._value_leave

    def __repr__(self):
        return f"""
---------------------------------------------------------------------
keys: {self.keys}
parent: {self.parent.keys if self.parent else None}
children: {self.children.keys()}
value_leave: {self._value_leave}
---------------------------------------------------------------------
"""

    def get_struct_name(self):
        if len(self.keys) == 0:
            return f"{self.id}_node_root"
        return f"{self.id}_node_" + "_".join(self.keys)

    def get_decl_str(self):
        return f"const {self.id}_node_t {self.get_struct_name()};"

    def get_next_node_func_str(self):
        return f"""\
const {self.id}_node_t* {self.get_struct_name()}_next_node(uint16_t key) {{
  switch (key) {{
    {(os.linesep + "    ").join([f"case {k}: return &{v.get_struct_name()};" for k, v in self.children.items()] + ["default: return NULL;"])}
  }}
}}
"""

    def get_def_str(self):
        values =  (self._value_leave or [])
        return f"""\
const {self.id}_node_t {self.get_struct_name()} = {{
  .parent       = {f"&{self.parent.get_struct_name()}" if self.parent else "NULL"},
  .next_node    = &{self.get_struct_name()}_next_node,
  .key          = {"0" if len(self.keys) == 0 else (self.keys[-1] or None)},
  .bounds       = {len(values)},
  .keys         = {f"{{ {', '.join(values)} }}" if len(values) > 0 else "{}"},
}};
"""


def generate_tree(id: str):
    all_nodes: dict[tuple[str, ...], Node] = {tuple(): Node(id=id, keys=tuple())}

    for keys, value in generate_keydata.generate(id).items():
        ### Create all nodes
        for i in range(1, len(keys) + 1):
            if tuple(keys[:i]) not in all_nodes:
                all_nodes[tuple(keys[:i])] = Node(
                    id=id,
                    keys=keys[:i],
                    parent=all_nodes[tuple(keys[: i - 1])],
                )

        ### Set values

        #### Set leave values
        if all_nodes[tuple(keys)].get_value_leave() is None:
            all_nodes[tuple(keys)].set_value_leave(value)
        else:
            if all_nodes[tuple(keys)].get_value_leave() != value[1]:
                raise ValueError(
                    f"Duplicate value for key {keys} (set value: {all_nodes[tuple(keys)].get_value_leave()}value: {value})"
                )


    # Set parent and children
    for keycomb, node in all_nodes.items():
        if len(keycomb) > 0:
            node.add_parent(all_nodes[keycomb[:-1]])
            all_nodes[keycomb[:-1]].add_child(keycomb[-1], node)

    ## Clean up nodes
    clean_nodes = []

    def _visit_and_check(node: Node):
        if node in clean_nodes:
            return
        clean_nodes.append(node)
        for child in node.children.values():
            _visit_and_check(child)

    _visit_and_check(all_nodes[tuple()])

    return all_nodes[tuple()]


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <value>")
        sys.exit(1)

    config_value = toml.load("./generator/config.toml")

    if sys.argv[1] not in config_value:
        print(f"Value {sys.argv[1]} not found in config")
        sys.exit(1)
    else:
        config_value = config_value[sys.argv[1]]

    root = generate_tree(sys.argv[1])

    with open(f"{sys.argv[1]}_keydata.h", "w") as f:
        f.write(config_value["header"])

    defenitions = []
    inplementations = []

    def _visit_and_generate(node: Node):
        defenitions.append(node.get_decl_str())
        inplementations.append(node.get_next_node_func_str())
        inplementations.append(node.get_def_str())
        for child in node.children.values():
            _visit_and_generate(child)

    with open(f"{sys.argv[1]}_keydata.c", "w") as f:
        f.write(config_value["source_prefix"])
        _visit_and_generate(root)
        f.write(os.linesep.join(defenitions))
        f.write(os.linesep)
        f.write(os.linesep.join(inplementations))
