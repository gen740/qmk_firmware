#!python3

import copy
import itertools as it
from parser import parse_mapping


def _parse_string(value: str) -> list[str]:
    if len(value) == 0:
        return []
    if value.startswith('" "'):
        return ["KC_SPC"] + _parse_string(value[3:])
    elif value.startswith("<n>"):
        return ["KC_NO"] + _parse_string(value[3:])
    elif value.startswith("<s>"):
        return ["KC_SPC"] + _parse_string(value[3:])
    elif value.startswith("<e>"):
        return ["KC_ESC"] + _parse_string(value[3:])
    elif value.startswith("<r>"):
        return ["KC_ENT"] + _parse_string(value[3:])
    elif value.startswith("<b>"):
        return ["KC_BSPC"] + _parse_string(value[3:])
    elif value.startswith("<t>"):
        return ["KC_TAB"] + _parse_string(value[3:])
    elif value.startswith("<l1>"):
        return ["KC_LANGUAGE_1"] + _parse_string(value[4:])
    elif value.startswith("<l2>"):
        return ["KC_LANGUAGE_2"] + _parse_string(value[4:])
    elif value.startswith("←"):
        return ["KC_LEFT"] + _parse_string(value[1:])
    elif value.startswith("→"):
        return ["KC_RIGHT"] + _parse_string(value[1:])
    elif value.startswith("↑"):
        return ["KC_UP"] + _parse_string(value[1:])
    elif value.startswith("↓"):
        return ["KC_DOWN"] + _parse_string(value[1:])
    elif "a" <= value[0] <= "z":
        return [f"KC_{value[0].upper()}"] + _parse_string(value[1:])
    elif "0" <= value[0] <= "9":
        return [f"KC_{value[0]}"] + _parse_string(value[1:])
    elif value.startswith("'"):
        return ["KC_QUOT"] + _parse_string(value[1:])
    elif value.startswith(","):
        return ["KC_COMM"] + _parse_string(value[1:])
    elif value.startswith("."):
        return ["KC_DOT"] + _parse_string(value[1:])
    elif value.startswith(";"):
        return ["KC_SCLN"] + _parse_string(value[1:])
    elif value.startswith("-"):
        return ["KC_MINS"] + _parse_string(value[1:])
    elif value.startswith("="):
        return ["KC_EQL"] + _parse_string(value[1:])
    elif value.startswith("["):
        return ["KC_LBRC"] + _parse_string(value[1:])
    elif value.startswith("]"):
        return ["KC_RBRC"] + _parse_string(value[1:])
    elif value.startswith("\\"):
        return ["KC_BSLS"] + _parse_string(value[1:])
    elif value.startswith("`"):
        return ["KC_GRV"] + _parse_string(value[1:])
    elif value.startswith("/"):
        return ["KC_SLSH"] + _parse_string(value[1:])
    elif value.startswith("@"):
        return ["KC_AT"] + _parse_string(value[1:])
    elif value.startswith("#"):
        return ["KC_HASH"] + _parse_string(value[1:])
    elif value.startswith("$"):
        return ["KC_DLR"] + _parse_string(value[1:])
    elif value.startswith("%"):
        return ["KC_PERC"] + _parse_string(value[1:])
    elif value.startswith("^"):
        return ["KC_CIRC"] + _parse_string(value[1:])
    elif value.startswith("&"):
        return ["KC_AMPR"] + _parse_string(value[1:])
    elif value.startswith("*"):
        return ["KC_ASTR"] + _parse_string(value[1:])
    elif value.startswith("("):
        return ["KC_LPRN"] + _parse_string(value[1:])
    elif value.startswith(")"):
        return ["KC_RPRN"] + _parse_string(value[1:])
    elif value.startswith("{"):
        return ["KC_LCBR"] + _parse_string(value[1:])
    elif value.startswith("}"):
        return ["KC_RCBR"] + _parse_string(value[1:])
    elif value.startswith("|"):
        return ["KC_PIPE"] + _parse_string(value[1:])
    elif value.startswith("~"):
        return ["KC_TILD"] + _parse_string(value[1:])
    elif value.startswith("!"):
        return ["KC_EXLM"] + _parse_string(value[1:])
    elif value.startswith("?"):
        return ["KC_QUES"] + _parse_string(value[1:])
    elif value.startswith(":"):
        return ["KC_COLN"] + _parse_string(value[1:])
    elif value.startswith("+"):
        return ["KC_PLUS"] + _parse_string(value[1:])
    elif value.startswith("<"):
        return ["KC_LT"] + _parse_string(value[1:])
    elif value.startswith(">"):
        return ["KC_GT"] + _parse_string(value[1:])
    elif value.startswith("_"):
        return ["KC_UNDS"] + _parse_string(value[1:])
    raise ValueError(f"Unknown character: {value}")


def _parse_value(value: str) -> list[str]:
    modifiers: list[str] = []
    if len(value) > 1 and "-" in value:
        v = value.split("-", 1)
        if "c" in v[0]:
            modifiers.append("KC_LCTL")
        if "s" in v[0]:
            modifiers.append("KC_LSFT")
        if "a" in v[0]:
            modifiers.append("KC_LALT")
        if "g" in v[0]:
            modifiers.append("KC_LGUI")
        return modifiers + _parse_string(v[1])
    return modifiers + _parse_string(value)


def _generate_basekeys_and_keydata(file_path: str):
    with open(file_path, "r") as f:
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
    return BASE_KEYS, keymaps, data


def generate_keymaps(file_path: str) -> dict[tuple[str], list[str]]:
    BASE_KEYS, keymaps, data = _generate_basekeys_and_keydata(file_path)
    special_mappings = {
        "(1)": 0,
        "(2)": 1,
        "(3)": 2,
        "(4)": 3,
        "(5)": 4,
        "(6)": 5,
        "(7)": 6,
        "(8)": 7,
        "(9)": 8,
        "(-)": 9,
    }

    ret: dict[tuple[str], list[str]] = {}

    for keymap in keymaps:
        persistent_keycomb = [set() for _ in range(len(special_mappings))]

        for i, v in enumerate(keymap):
            if v in special_mappings:
                persistent_keycomb[special_mappings[v]].add(BASE_KEYS[i])

        for i, v in enumerate(keymap):
            if v == "" or v in special_mappings:
                continue

            keys = copy.deepcopy(persistent_keycomb)
            keys[-1].add(BASE_KEYS[i])

            keycomb = [
                tuple(x for sublst in lst for x in sublst)
                for lst in it.product(
                    *[list(it.permutations(v)) for v in keys if len(v) > 0]
                )
            ]

            for k in keycomb:
                if k not in ret:
                    ret[k] = _parse_value(v)
                else:
                    print(f"Duplicate key combination: {k} what is {v}")

    # extra_map = False
    # for i in data:
    #     if extra_map:
    #         keycomb = tuple(i.split("=")[0].strip().split(" "))
    #         value = i.split("=")[1].strip()
    #         if keycomb not in ret:
    #             ret[keycomb] = value
    #         else:
    #             print(f"Duplicate key combination: {keycomb}")
    #     if i.startswith("##***##"):
    #         extra_map = True
    return ret


if __name__ == "__main__":
    # print(generate_keymap("./naginata.txt"))
    print(generate_keymaps("./dvorak.txt"))
