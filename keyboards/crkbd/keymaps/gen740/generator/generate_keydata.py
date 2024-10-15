#!python3

import sys

import json
import copy
import itertools as it
from parser import parse_mapping


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


def generate_basekeys_and_keymaps(file_path: str):
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


def generate_keymap(file_path: str):
    BASE_KEYS, keymaps, data = generate_basekeys_and_keymaps(file_path)
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

    ret = {}

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
                    ret[k] = parse_value(v)
                else:
                    print(f"Duplicate key combination: {k} what is {v}")

    extra_map = False
    for i in data:
        if extra_map:
            keycomb = tuple(i.split("=")[0].strip().split(" "))
            value = i.split("=")[1].strip()
            if keycomb not in ret:
                ret[keycomb] = value
            else:
                print(f"Duplicate key combination: {keycomb}")
        if i.startswith("##***##"):
            extra_map = True
    return ret


if __name__ == "__main__":
    generate_keymap("./naginata.txt")
    pass
