#!python3

from typing import Self
import generate_keydata
import toml
import sys
import os


class Struct:
    def __init__(
        self,
        id: str,
        struct_name: str,
        key: str | None,
        bounds: int,
        keys: tuple[str, ...],
        value_leave: list[str] | None = None,
    ):
        self.id = id
        self.struct_name = struct_name
        self.key = key
        self.bounds = bounds
        self.keys = keys
        self.value_leave = value_leave

    def __eq__(self, other):
        return (
            isinstance(other, Struct)
            and self.key == other.key
            and self.bounds == other.bounds
            and self.keys == other.keys
        )

    def get_decl_str(self):
        return f"const {self.id}_node_t {self.id}_{self.struct_name};"

    def get_def_str(
        self,
        database_func: dict[tuple[str, ...], "Func"],
        database_struct: dict[tuple[str, ...], Self],
    ):
        return f"""\
const {self.id}_node_t {self.id}_{self.struct_name} = {{
    .parent       = {f"&{self.id}_{database_struct[self.keys[:-1]].struct_name}" if len(self.keys) != 0 else "NULL"},
    .next_node    = &{self.id}_{database_func[self.keys].func_name}_next_node,
    .key          = {self.key if self.key is not None else "0"},
    .bounds       = {self.bounds},
    .keys         = {f"{{ {', '.join(self.value_leave)} }}" if self.value_leave else "{}"},
}};
"""


class Func:
    def __init__(self, id: str, func_name: str, children: dict[str, tuple[str, ...]]):
        self.id = id
        self.func_name = func_name
        self.children = children

    def __eq__(self, other):
        return isinstance(other, Func) and self.children == other.children

    def generate(self, database: dict[tuple[str, ...], Struct]):
        return f"""\
const {self.id}_node_t* {self.id}_{self.func_name}_next_node(uint16_t key) {{
    switch (key) {{
        {(os.linesep + "        ").join([f"case {k}: return &{self.id}_{database[v].struct_name};" for k, v in self.children.items()] + ["default: return NULL;"])}
    }}
}}
"""


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

    def __eq__(self, other):
        return (
            isinstance(other, Node)
            and self.keys == other.keys
            and self.parent == other.parent
            and self.children == other.children
            and self._value_leave == other._value_leave
        )


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

    functions: dict[tuple[str, ...], Func] = {}
    structs: dict[tuple[str, ...], Struct] = {}

    counter = 0

    def _visit_and_generate_inital_dict(node: Node):
        global counter
        counter += 1
        functions[node.keys] = Func(
            id=f"{sys.argv[1]}",
            func_name=str(counter),
            children={k: v.keys for k, v in node.children.items()},
        )
        structs[node.keys] = Struct(
            id=f"{sys.argv[1]}",
            struct_name=str(counter),
            key=node.keys[-1] if len(node.keys) > 0 else None,
            bounds=len(node.get_value_leave())
            if node.get_value_leave() is not None
            else 0,
            keys=node.keys,
            value_leave=node.get_value_leave(),
        )
        for child in node.children.values():
            _visit_and_generate_inital_dict(child)

    _visit_and_generate_inital_dict(root)

    functions_keys = list(functions.keys())
    functions_values = list(functions.values())

    for i in range(len(functions_keys)):
        for j in range(i + 1, len(functions_keys)):
            if functions_values[i] == functions_values[j]:
                functions[functions_keys[j]] = functions[functions_keys[i]]

    function_declarations = []
    function_visited = []
    for i in functions.values():
        if i in function_visited:
            continue
        function_visited.append(i)
        function_declarations.append(i.generate(structs))

    struct_declarations = []
    struct_implementations = []

    for i in structs.values():
        struct_declarations.append(i.get_decl_str())
        struct_implementations.append(i.get_def_str(functions, structs))

    print(
        f"Generated {len(struct_implementations)} structs and {len(function_declarations)} functions"
    )

    with open(f"{sys.argv[1]}_keydata.c", "w") as f:
        f.write(config_value["source_prefix"])
        f.write(os.linesep.join(struct_declarations))
        f.write(os.linesep)
        f.write(os.linesep)
        f.write(os.linesep.join(function_declarations))
        f.write(os.linesep)
        f.write(os.linesep.join(struct_implementations))
