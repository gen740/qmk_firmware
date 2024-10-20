#!python3

from typing import Union
from itertools import combinations
import generate_keydata
import sys
import tomllib


def create_struct_name(title: str, key: tuple, reverse: bool):
    if len(key) == 0:
        return f"{title}_node_root"

    if reverse:
        return f"{title}_reversenode_" + "_".join(key)
    else:
        return f"{title}_node_" + "_".join(key)


class Node:
    def __init__(
        self,
        *,
        title: str,
        keys: tuple,
        reverse: bool,
        value: str | None = None,
        parent: Union["Node", None] = None,
    ):
        self.struct_name: str = create_struct_name(title, keys, reverse)

        self.parent: Node | None = parent
        self.value: str | None = value
        self.reverse: bool = reverse
        self.keys: tuple = keys

        # キー押下時へ遷移するノード
        self.children: dict[str, Node] = dict()

        # キー引上げ時へ遷移するノード
        self.reverse_children: dict[str, Node] = dict()

    def search_next(self, key: str, reverse: bool = False):
        if not reverse:
            for k, v in self.children:
                if k == key:
                    return v
            return None
        else:
            for k, v in self.reverse_children:
                if k == key:
                    return v
            return None

    def __str__(self):
        return f"""
struct_name     : {self.struct_name}
keys            : {self.keys}
parent          : {self.parent.struct_name if self.parent else None}
children        : {[i.struct_name for i in self.children.values()]}
value           : {self.value}
reverse         : {self.reverse}
reverse_children: {[i.struct_name for i in self.reverse_children.values()]}
        """

    def __repr__(self):
        return self.__str__()

    def __eq__(self, other):
        return self.struct_name == other.struct_name

    def __hash__(self):
        return hash(self.struct_name)


def create_declarelations_and_definitions(
    title: str, node: Node, declarelations: set[str], definitions: set[str]
):
    if node.struct_name != f"{title}_node_root":
        declarelations.add(f"const {title}_node_t {node.struct_name};")

    definitions.add(f"""
const {title}_node_t {node.struct_name} = {{
  .parent       = {f"&{node.parent.struct_name}" if node.parent else "NULL"},
  .children     = {f"{node.struct_name}_children" if len(node.children) != 0 else "NULL"},
  .children_num = {len(node.children)},
  .key          = {"-1" if len(node.keys) == 0 else (node.keys[-1] or None)},
  .value        = {node.value or "NULL"},
  .reverse      = {"true" if node.reverse else "false"},
}};
""")


def generate_sublists(arr):
    result = []
    for i in range(1, len(arr)):
        result.extend(list(comb) for comb in combinations(arr, i))
    return tuple(result)


def generate_tree(title: str, file_name: str):
    keydata = generate_keydata.generate_keymap(file_name)

    root_node = Node(title=title, keys=tuple(), reverse=False)

    all_nodes: list[Node] = [root_node]

    # Create all nodes
    for i in keydata:
        keys = []
        for j in i:
            keys.append(j)

            node = Node(title=title, keys=tuple(keys), reverse=False)
            if node not in all_nodes:
                all_nodes.append(node)

            for k in generate_sublists(keys):
                node = Node(title=title, keys=tuple(k), reverse=True)
                if node not in all_nodes:
                    all_nodes.append(node)

    # Check if all nodes are unique
    assert len(all_nodes) == len(set(all_nodes))

    for i in all_nodes:
        # Create forward edge
        for j in all_nodes:
            if (
                (len(j.keys) - len(i.keys) == 1)
                and not j.reverse
                and (j.keys[: len(i.keys)] == i.keys)
            ):
                i.children[j.keys[len(i.keys)]] = j
                j.parent = i

        # Create backword edge
        if len(i.keys) == 0:
            i.reverse_children = dict()
        elif len(i.keys) == 1:
            i.reverse_children[i.keys[0]] = root_node
        else:
            for k in range(len(i.keys)):
                keys_without_k = i.keys[:k] + i.keys[k + 1 :]

                i.reverse_children[i.keys[k]] = all_nodes[
                    all_nodes.index(
                        Node(
                            title=title,
                            keys=keys_without_k,
                            reverse=True,
                        )
                    )
                ]

    mask = [False for _ in all_nodes]

    def visit(node: Node):
        if mask[all_nodes.index(node)]:
            return
        mask[all_nodes.index(node)] = True

        for c in node.children.values():
            visit(c)
        for c in node.reverse_children.values():
            visit(c)

    visit(root_node)

    # Check if all nodes are reachable
    assert all(mask)

    # set values
    for i in keydata:
        current_node = root_node
        for j in i:
            current_node = current_node.children[j]
        current_node.value = keydata[i]

    # set value for intermediate nodes
    for i in all_nodes:
        if i.value is None and len(i.keys) > 1 and not i.reverse:
            last_key = i.keys[-1]
            for k in keydata:
                if (last_key,) == k:
                    i.value = keydata[k]

    return all_nodes


def generate_decl_def(title: str, file_name: str):
    all_node = generate_tree(title, file_name)

    declarelations: set[str] = set()
    definitions: set[str] = set()

    for node in all_node:
        declarelations.add(f"const {title}_node_t {node.struct_name};")

        definitions.add(f"""\
const {title}_node_t* {node.struct_name}_next_node(uint16_t key) {{
    switch (key) {{
        {"".join([f"case {k}: return &{v.struct_name};\n" for k, v in node.children.items()])}
        default: return NULL;
    }}
}}

const {title}_node_t* {node.struct_name}_prev_node(uint16_t key) {{
    switch (key) {{
        {"".join([f"case {k}: return &{v.struct_name};\n" for k, v in node.reverse_children.items()])}
        default: return NULL;
    }}
}}

const {title}_node_t {node.struct_name} = {{
    .parent       = {f"&{node.parent.struct_name}" if node.parent else "NULL"},
    .key          = {"-1" if len(node.keys) == 0 else (node.keys[-1] or None)},
    .value        = {node.value or "NULL"},
    .reverse      = {"true" if node.reverse else "false"},
    .next_node    = {node.struct_name}_next_node,
    .prev_node    = {node.struct_name}_prev_node,
    }};
""")

    return declarelations, definitions


def generate_code(title: str, file_name: str):
    declarelations, definitions = generate_decl_def(title, file_name)
    print(f"Generated {len(declarelations)} declarelations")

    with open("./generate_config.toml", "rb") as f:
        config = tomllib.load(f)

    header = config[title]["header"]
    source = (
        config[title]["source_prefix"]
        + "\n".join(declarelations)
        + "\n\n"
        + "\n".join(definitions)
    )

    return header, source


if __name__ == "__main__":
    if len(sys.argv) == 3 and sys.argv[1] == "--generate":
        header, source = generate_code(sys.argv[2], f"{sys.argv[2]}.txt")
        with open(f"./{sys.argv[2]}_keydata.h", "w") as f:
            f.write(header)
        with open(f"./{sys.argv[2]}_keydata.c", "w") as f:
            f.write(source)
        sys.exit(0)
    print("Usage: python3 main.py --generate <title>")
