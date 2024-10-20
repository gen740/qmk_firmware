from code_generator import Node, generate_tree, visit_all, visit_reverse_all
from graphviz import Digraph


def main():
    root_node = generate_tree("naginata", "naginata.txt")

    print(root_node.reverse_children)

    dot = Digraph(comment="Example Graph")

    dot.node(root_node.struct_name or "", f"{root_node.key}")

    def create_node(node: Node):
        dot.node(node.struct_name or "", f"{node.key}\n{node.value}")
        if node.parent:
            dot.edge(
                node.parent.struct_name or "", node.struct_name or "", constraint="true"
            )

    def create_reverse_node(node: Node):
        print(node)
        dot.node(node.struct_name or "", f"{node.key}\n{node.value}", style="dashed")
        if node.parent:
            dot.edge(
                node.parent.struct_name or "",
                node.struct_name or "",
                constraint="true",
                style="dashed",
            )

    visit_all(root_node, create_node)
    visit_reverse_all(root_node, create_reverse_node)

    # グラフを出力
    dot.render("example-output", format="png")


if __name__ == "__main__":
    main()
    # root_node = generate_tree("dvorak", "dvorak.txt")
    #
    # print(root_node)
