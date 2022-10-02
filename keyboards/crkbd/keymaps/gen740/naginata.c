#include QMK_KEYBOARD_H
#include "naginata.h"
#include "naginata_keydata.h"


uint32_t bit_buffer1     = 0;
bool     char_emitted    = false;
uint8_t  prev_key        = 0;
bool     prev_is_unknown = false;

void press_key(enum naginata_keycodes key) {
    bit_buffer1 = bit_buffer1 | 1UL << (key - NG_Q);
}

void release_key(enum naginata_keycodes key) {
    bit_buffer1 = bit_buffer1 & ~(1UL << (key - NG_Q));
}

bool process_naginata(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            case NG_Q ... NG_SHFT:
                prev_is_unknown = false;
                char_emitted    = false;
                press_key(keycode);
                prev_key = keycode;
                return false;
                break;
        }
    } else {                          // key release
        naginata_keymap      bngmap;  // PROGMEM buffer
        naginata_keymap_long bngmapl; // PROGMEM buffer
        uint32_t             bit_buffer2 = bit_buffer1;
        switch (keycode) {
            case NG_Q ... NG_SHFT:
            LookUp:
                for (int i = 0; i < (int)(sizeof ngmap / sizeof bngmap); i++) {
                    memcpy_P(&bngmap, &ngmap[i], sizeof(bngmap));
                    if (bit_buffer2 == bngmap.key && ((1UL << (keycode - NG_Q)) & bngmap.key) != 0) {
                        if (!char_emitted) {
                            if (bit_buffer1 == bit_buffer2) {
                                char_emitted = true;
                            }
                            send_string(bngmap.kana);
                        }
                        goto Found;
                    }
                }
                for (int i = 0; i < (int)(sizeof ngmapl_mac / sizeof bngmapl); i++) {
                    memcpy_P(&bngmapl, &ngmapl_mac[i], sizeof(bngmapl));
                    if (bit_buffer2 == bngmapl.key && ((1UL << (keycode - NG_Q)) & bngmapl.key) > 0) {
                        if (!char_emitted) {
                            if (bit_buffer1 == bit_buffer2) {
                                char_emitted = true;
                            }
                            send_string(bngmapl.kana);
                        }
                        goto Found;
                    }
                }
                if (bit_buffer1 == bit_buffer2) {
                    bit_buffer2 = bit_buffer2 & ~(1UL << (prev_key - NG_Q));
                    if (bit_buffer1 == bit_buffer2) {
                        goto Found;
                    }
                    if (!prev_is_unknown) {
                        prev_is_unknown = true;
                        goto LookUp;
                    }
                }
            Found:
                release_key(keycode);
                return true;
        }
    }
    return true;
}

// vim:set sw=4 ts=4 sts=4:
