#!python3

from collections.abc import Callable
from typing import Union
import generate_keydata
import sys
import tomllib
import itertools


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
    node: Node, declarelations: set[str], definitions: set[str]
):
    if node.struct_name != "dvnode_root":
        declarelations.add(f"const dv_node_t PROGMEM {node.struct_name};")

    definitions.add(f"""{
f"""const dv_node_t* {node.struct_name}_children[{len(node.children)}] = {{
{"\n".join([f"\t&{i.struct_name}," for i in node.children])}
}};""" if len(node.children) != 0 else "" }
const PROGMEM dv_node_t {node.struct_name} = {{
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


if __name__ == "__main__":
    keydata = generate_keydata.generate_keymap()

    all_keycomb = set()
    for i in list(map(lambda x: x[0], keydata)):
        if len(i) == 1:
            all_keycomb.add(tuple(i))
        else:
            for j in itertools.permutations(i[:-1], len(i[:-1])):
                all_keycomb.add(tuple(j) + (i[-1],))

    root_node = Node(struct_name="dvnode_root")

    for i in all_keycomb:
        node = root_node

        key = []

        for j in i:
            key.append(j)
            if next_node := node.search_next(j):
                pass
            else:
                next_node = Node(
                    key=j,
                    struct_name="dvnode_" + "_".join(key),
                    parent=node,
                )
                node.children.append(next_node)
            node = next_node

    for i in keydata:
        node = root_node
        for j in i[0]:
            node = node.search_next(j)
            if node is None:
                print(f"error in {i}")
                sys.exit(1)
        node.value = i[1]

    declarelations: set[str] = set()
    definitions: set[str] = set()

    visit_all(
        root_node,
        lambda node: create_declarelations_and_definitions(
            node, declarelations, definitions
        ),
    )

    print(f"The number of declarelations: {len(declarelations)}")

    with open("./generate_config.toml", "rb") as f:
        config = tomllib.load(f)

    with open("./dvorak_keydata.h", "w") as f:
        f.write(config["dvorak"]["header"])

    with open("./dvorak_keydata.c", "w") as f:
        f.write(
            config["dvorak"]["source_prefix"]
            + "\n".join(declarelations)
            + "\n\n"
            + "\n".join(definitions)
        )
