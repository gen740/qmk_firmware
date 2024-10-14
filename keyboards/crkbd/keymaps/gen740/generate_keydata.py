#!python3

import re
import sys
import tomllib
import json


KEYMAPPING_FILE = "./dvorak.txt"


TEST_STRING = """
┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓                     ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
┃  '  ┃  ,  ┃  .  ┃  p  ┃  y  ┃                     ┃  f  ┃  g  ┃  c  ┃  r  ┃  l  ┃
┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫                     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
┃  a  ┃  o  ┃  e  ┃  u  ┃  i  ┃                     ┃  d  ┃  h  ┃  t  ┃  n  ┃  s  ┃
┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫                     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
┃  ;  ┃  q  ┃  j  ┃  k  ┃  x  ┃                     ┃  b  ┃  m  ┃  w  ┃  v  ┃  z  ┃
┗━━━━━┻━━━━━┻━━━┳━┻━━━┳━┻━━━┳━┻━━━┓             ┏━━━┻━┳━━━┻━┳━━━┻━┳━━━┻━━━━━┻━━━━━┛
                ┃     ┃ <s> ┃     ┃             ┃     ┃ <r> ┃     ┃
                ┗━━━━━┻━━━━━┻━━━━━┛             ┗━━━━━┻━━━━━┻━━━━━┛
"""


BORDER_CHARS = ["┏", "┳", "┓", "┃", "┣", "┫", "╋", "┗", "┻", "┛"]


pattern = re.compile(
    r"""┏━*┳━*┳━*┳━*┳━*┓\s*┏━*┳━*┳━*┳━*┳━*┓
┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃\s*┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃
┣━*╋━*╋━*╋━*╋━*┫\s*┣━*╋━*╋━*╋━*╋━*┫
┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃\s*┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃
┣━*╋━*╋━*╋━*╋━*┫\s*┣━*╋━*╋━*╋━*╋━*┫
┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃\s*┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃([^┃]*)┃
┗━*┻━*┻━*┳━┻━*┳━┻━*┳━┻━*┓\s*┏━*┻━┳━*┻━┳━*┻━┳━*┻━*┻━*┛
\s*┃([^┃]*)┃([^┃]*)┃([^┃]*)┃\s*┃([^┃]*)┃([^┃]*)┃([^┃]*)┃
\s*┗━*┻━*┻━*┛\s*┗━*┻━*┻━*┛""",
    re.DOTALL,
)


def parse_mapping(keymap_str: str):
    matches = re.match(pattern, keymap_str)
    if matches is None:
        raise ValueError("Invalid keymap string")
    return list(map(lambda x: x.strip(), matches.groups()))


def generate_keymap():
    with open("dvorak.txt", "r") as f:
        data = f.readlines()
    BASE_KEYS = []

    counter = 0
    while counter < len(data):
        line = data[counter]
        if line.startswith("###**###"):
            BASE_KEYS = parse_mapping(
                ("".join(data[counter + 1 : counter + 10])).strip()
            )
            counter += 10
        else:
            counter += 1

    keymaps = []

    counter = 0
    while counter < len(data):
        line = data[counter]
        if line.startswith("###*###"):
            keymaps.append(
                parse_mapping(("".join(data[counter + 1 : counter + 10])).strip())
            )
            counter += 10
        else:
            counter += 1

    ret = []
    for keymap in keymaps:
        persistent_keys = []
        for i, v in enumerate(keymap):
            if v == "●":
                persistent_keys.append(BASE_KEYS[i])

        for i, v in enumerate(keymap):
            if v == "" or v == "●":
                continue
            ret.append(
                (
                    persistent_keys + [BASE_KEYS[i]],
                    parse_value(v),
                )
            )
    extra_map = False
    for i in data:
        if extra_map:
            ret.append((i.split("=")[0].strip().split(" "), i.split("=")[1].strip()))
        if i.startswith("##***##"):
            extra_map = True
    return ret


def parse_value(value: str):
    if value == "<s>":
        return '" "'
    elif value == "<r>":
        return "SS_TAP(X_ENT)"
    if len(value) > 1 and "-" in value:
        v = value.split("-")
        ret = f'"{v[1]}"'
        if "c" in v[0]:
            ret = f"SS_LCTL({ret})"
        if "s" in v[0]:
            ret = f"SS_LSFT({ret})"
        if "a" in v[0]:
            ret = f"SS_LALT({ret})"
        if "g" in v[0]:
            ret = f"SS_LGUI({ret})"
        return ret
    return f"{json.dumps(value)}"


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

    with open("./generate_config.toml", "rb") as f:
        config = tomllib.load(f)

    generated_keymap = generate_keymap()

    declarelations = set()

    for i in list(map(lambda x: x[0], generated_keymap)):
        # if len(i) == 1:
        declarelations.add(tuple(i))
        # else:
        #     for j in itertools.permutations(i[:-1], len(i[:-1])):
        #         declarelations.add(tuple(j) + (i[-1],))
        print(i)
        # declarelations.add(i[1])
    for i in declarelations:
        print(i)
    # print(declarelations)

    # declarelations.add

    # print(list(map(lambda x: x[0], generated_keymap)))

    # # check if there is duplicate keymap
    # keymap_combos = list(map(lambda x: x[1], generated_keymap))
    # invalid = False
    # for i, v in enumerate(keymap_combos):
    #     if v in keymap_combos[i + 1 :]:
    #         print(f"Duplicate keymap found: {v}")
    #         print(f">>> {generated_keymap[i][0]}")
    #         invalid = True
    #
    # if invalid:
    #     sys.exit(1)
    #
    # with open("./dvorak_keydata_generated.h", "w") as f:
    #     f.write(config["dvorak"]["header"].replace("{-}", str(len(generated_keymap))))
    #
    # with open("./dvorak_keydata_generated.c", "w") as f:
    #     f.write(
    #         config["dvorak"]["source_prefix"]
    #         + "".join(map(lambda x: x[0], generated_keymap))
    #         + config["dvorak"]["source_suffix"]
    #     )

    # print(generate_keymap())
