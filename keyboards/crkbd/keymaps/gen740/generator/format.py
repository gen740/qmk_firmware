#!python3

import sys
from parser import parse_mapping


def dump_mapping(keymaps: list[str]):
    def format_row(
        mergins: tuple[int, int],
        delimiter: tuple[str, str, str],
        content: tuple[list[str], list[str]],
    ):
        result = ""
        result += " " * mergins[0]

        result += delimiter[0]
        for i, v in enumerate(content[0]):
            result += v
            if i == len(content[0]) - 1:
                break
            result += delimiter[1]
        result += delimiter[2]
        result += " " * mergins[1]

        result += delimiter[0]
        for i, v in enumerate(content[1]):
            result += v
            if i == len(content[1]) - 1:
                break
            result += delimiter[1]
        result += delimiter[2]

        return result + "\n"

    result = ""
    cell_width = max(max([len(v) for v in keymaps]), 3) + 2
    # first row
    result += format_row(
        (0, 2 * cell_width - 1),
        ("┏", "┳", "┓"),
        (
            [("━" * cell_width) for _ in range(5)],
            [("━" * cell_width) for _ in range(5)],
        ),
    )

    # second row
    result += format_row(
        (0, 2 * cell_width - 1),
        ("┃", "┃", "┃"),
        (
            [v.center(cell_width, " ") for v in keymaps[:5]],
            [v.center(cell_width, " ") for v in keymaps[5:10]],
        ),
    )

    # third row
    result += format_row(
        (0, 2 * cell_width - 1),
        ("┣", "╋", "┫"),
        (
            [("━" * cell_width) for _ in range(5)],
            [("━" * cell_width) for _ in range(5)],
        ),
    )

    # fourth row
    result += format_row(
        (0, 2 * cell_width - 1),
        ("┃", "┃", "┃"),
        (
            [v.center(cell_width, " ") for v in keymaps[10:15]],
            [v.center(cell_width, " ") for v in keymaps[15:20]],
        ),
    )

    # fifth row
    result += format_row(
        (0, 2 * cell_width - 1),
        ("┣", "╋", "┫"),
        (
            [("━" * cell_width) for _ in range(5)],
            [("━" * cell_width) for _ in range(5)],
        ),
    )

    # sixth row
    result += format_row(
        (0, 2 * cell_width - 1),
        ("┃", "┃", "┃"),
        (
            [v.center(cell_width, " ") for v in keymaps[20:25]],
            [v.center(cell_width, " ") for v in keymaps[25:30]],
        ),
    )

    # seventh row
    result += (
        "┗"
        + "━" * cell_width
        + "┻"
        + "━" * cell_width
        + "┻"
        + "━" * (cell_width - 2)
        + "┳━"
        + "┻"
        + "━" * (cell_width - 2)
        + "┳━"
        + "┻"
        + "━" * (cell_width - 2)
        + "┳━"
        + "┻"
        + "━" * (cell_width - 2)
        + "┓"
        + " "
        + "┏"
        + "━" * (cell_width - 2)
        + "┻"
        + "━┳"
        + "━" * (cell_width - 2)
        + "┻"
        + "━┳"
        + "━" * (cell_width - 2)
        + "┻"
        + "━┳"
        + "━" * (cell_width - 2)
        + "┻"
        + "━" * cell_width
        + "┻"
        + "━" * cell_width
        + "┛\n"
    )

    # eighth row
    result += format_row(
        (cell_width * 3 + 1, 1),
        ("┃", "┃", "┃"),
        (
            [v.center(cell_width, " ") for v in keymaps[30:33]],
            [v.center(cell_width, " ") for v in keymaps[33:36]],
        ),
    )

    # ninth row
    result += format_row(
        (cell_width * 3 + 1, 1),
        ("┗", "┻", "┛"),
        (
            [("━" * cell_width) for _ in range(3)],
            [("━" * cell_width) for _ in range(3)],
        ),
    )
    return result


def format_files(file_path: str):
    result = ""
    with open(file_path, "r") as f:
        data = f.readlines()

    counter = 0
    while counter < len(data):
        line = data[counter]
        if line.startswith("###*###"):
            result += line
            result += dump_mapping(
                parse_mapping(("".join(data[counter + 1 : counter + 10])).strip())
            )
            counter += 10
        else:
            result += line
            counter += 1

    with open(file_path, "w") as f:
        f.write(result)


if __name__ == "__main__":
    if len(sys.argv) == 3 and sys.argv[1] == "--format":
        format_files(sys.argv[2])
        sys.exit(0)

    print("""
Usage:
    python3 format.py --format <file_path>
    """)
