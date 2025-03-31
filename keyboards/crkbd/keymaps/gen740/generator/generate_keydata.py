from dvorak_keydata import dvorak_keydata
from naginata_keydata import naginata_keydata
import copy
import itertools as it


def generate(type: str) -> dict[tuple[str], list[str]]:
    if type == "dvorak":
        keydata = dvorak_keydata
    elif type == "naginata":
        keydata = naginata_keydata
    else:
        raise ValueError("Invalid type")

    ret: dict[tuple[str], list[str]] = {}
    basekeys = keydata["Base"]
    keymaps = keydata["Keymaps"]

    for keymap in keymaps:
        map_priority = []

        for i in range(10):
            map_priority.append([k for k, m in zip(basekeys, keymap) if m == i])

        for basekey, key in zip(basekeys, keymap):
            map_priority_copied = copy.deepcopy(map_priority)
            if key is None or isinstance(key, int):
                continue
            map_priority_copied[0].append(basekey)

            for i in it.product(
                *list(list(it.permutations(i)) for i in map_priority_copied)
            ):
                keycomb = []
                for j in reversed(i):
                    keycomb.extend(map(str, j))

                if isinstance(key, str):
                    key = [key]
                ret[tuple(keycomb)] = key

    return ret


if __name__ == "__main__":
    print(generate("dvorak"))
