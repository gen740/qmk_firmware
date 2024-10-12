#include "naginata_keydata.h"

uint32_t naginata_keycomb     = 0;
bool     combo_char_activated = false;

void nag_press_key(uint32_t key) {
    naginata_keycomb |= 1UL << (key - NG_Q);
}

void nag_release_key(uint32_t key) {
    naginata_keycomb &= ~(1UL << (key - NG_Q));
}

const char* naginata_search(uint32_t key_comb) {
    for (int i = 0; i < NAGINATA_KEY_NUMBER; i++) {
        if (key_comb == ngmap[i].key) {
            return ngmap[i].kana;
        }
    }
    return NULL;
}

bool process_naginata(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            case NG_Q ... NG_RSHFT:
                nag_press_key(keycode);
                combo_char_activated = false;
                break;
            default:
                break;
        }
    } else {
        switch (keycode) {
            case NG_Q ... NG_RSHFT: {
                if (combo_char_activated) {
                    nag_release_key(keycode);
                    break;
                }
                const char* kana = naginata_search(naginata_keycomb);
                if (kana != NULL) {
                    combo_char_activated = true;
                    send_string(kana);
                } else {
                    kana = naginata_search(1UL << (keycode - NG_Q));
                    if (kana != NULL) {
                        send_string(kana);
                    }
                }
                nag_release_key(keycode);
                return true;
                break;
            }
            default:
                break;
        }
    }
    return true;
}
