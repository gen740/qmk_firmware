#!python3

from collections.abc import Callable
from typing import Union
import generate_keydata
import sys
import tomllib


class Node:
    def __init__(
        self,
        key: str | None = None,
        value: str | None = None,
        struct_name: str | None = None,
        parent: Union["Node", None] = None,
    ):
        self.children: list[Node] = []
        self.parent: Node | None = parent
        self.value: str | None = value
        self.key: str | None = key
        self.struct_name: str | None = struct_name

    def search_next(self, key: str):
        for i in self.children:
            if i.key == key:
                return i
        return None

    def __str__(self):
        return f"""
struct_name: {self.struct_name}
key        : {self.key}
parent     : {self.parent.struct_name if self.parent else None}
children   : {[i.struct_name for i in self.children]}
value      : {self.value}
        """


def create_declarelations_and_definitions(
    title: str, node: Node, declarelations: set[str], definitions: set[str]
):
    if node.struct_name != f"{title}_node_root":
        declarelations.add(f"const {title}_node_t {node.struct_name};")

    definitions.add(f"""{
f"""const {title}_node_t* {node.struct_name}_children[{len(node.children)}] = {{
{"\n".join([f"  &{i.struct_name}," for i in node.children])}
}};""" if len(node.children) != 0 else "" }
const {title}_node_t {node.struct_name} = {{
  .parent       = {f"&{node.parent.struct_name}" if node.parent else "NULL"},
  .children     = {f"{node.struct_name}_children" if len(node.children) != 0 else "NULL"},
  .children_num = {len(node.children)},
  .key          = {node.key or "-1"},
  .value        = {node.value or "NULL"},
}};
""")


def visit_all(node: Node, fun: Callable[[Node], None]):
    fun(node)
    for i in node.children:
        visit_all(i, fun)


def generate_tree(title: str, file_name: str):
    keydata = generate_keydata.generate_keymap(file_name)

    root_node = Node(struct_name=f"{title}_node_root")

    for i in keydata:
        current_node = root_node
        key = []

        for j in i:
            key.append(j)
            if next_node := current_node.search_next(j):
                pass
            else:
                next_node = Node(
                    key=j,
                    struct_name=f"{title}_node_" + "_".join(key),
                    parent=current_node,
                )
                current_node.children.append(next_node)
            current_node = next_node

    for i in keydata:
        current_node = root_node
        for j in i:
            current_node = current_node.search_next(j)
            if current_node is None:
                print("Error: Node not found")
                sys.exit(1)
        current_node.value = keydata[i]

    declarelations: set[str] = set()
    definitions: set[str] = set()

    visit_all(
        root_node,
        lambda node: create_declarelations_and_definitions(
            title, node, declarelations, definitions
        ),
    )

    return declarelations, definitions


def generate_code(title: str, file_name: str):
    declarelations, definitions = generate_tree(title, file_name)
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
