#include "dvorak.h"
#include "dvorak_keydata.h"

uint64_t dvorak_keycomb          = 0;
bool     dv_combo_char_activated = false;

void dv_press_key(uint64_t key) {
    dvorak_keycomb |= 1UL << (key - DV_A);
}

void dv_release_key(uint64_t key) {
    dvorak_keycomb &= ~(1UL << (key - DV_A));
}

const char* dvorak_search(uint64_t key_comb) {
    for (int i = 0; i < DVORAK_KEY_NUMBER; i++) {
        if (dvmap[i].key == 0xffffffff) { // End of dvmap
            break;
        }
        if (key_comb == dvmap[i].key) {
            return dvmap[i].val;
        }
    }
    return NULL;
}

bool process_dvorak(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            case DV_A ... DV_RSFT:
                dv_press_key(keycode);
                dv_combo_char_activated = false;
                break;
            default:
                break;
        }
    } else {
        switch (keycode) {
            case DV_A ... DV_RSFT: {
                if (dv_combo_char_activated) {
                    dv_release_key(keycode);
                    break;
                }
                const char* str = dvorak_search(dvorak_keycomb);
                if (str != NULL) {
                    dv_combo_char_activated = true;
                    if (strcmp(str, "nag") == 0) {
                        tap_code(KC_LNG1);
                        layer_move(L_NAG);
                    } else {
                        send_string(str);
                    }
                } else {
                    str = dvorak_search(1UL << (keycode - DV_A));
                    if (str != NULL) {
                        if (strcmp(str, "nag") == 0) {
                            tap_code(KC_LNG1);
                            layer_move(L_NAG);
                        } else {
                            send_string(str);
                        }
                    }
                }
                dv_release_key(keycode);
                return true;
                break;
            }
            default:
                break;
        }
    }
    return true;
}

/**/
/*const PROGMEM int dvorak_persistent_keys[2] = {*/
/*    DV_LSFT,*/
/*    DV_RSFT,*/
/*};*/
/**/
/*uint64_t dvorak_keycomb      = 0;*/
/*uint64_t prev_dvorak_keycomb = 0;*/
/**/
/*void dv_press_key(uint32_t key) {*/
/*    prev_dvorak_keycomb = dvorak_keycomb;*/
/*    dvorak_keycomb |= 1UL << (key - DV_A);*/
/*}*/
/**/
/*void dv_release_key(uint32_t key) {*/
/*    prev_dvorak_keycomb = dvorak_keycomb;*/
/*    dvorak_keycomb &= ~(1UL << (key - DV_A));*/
/*}*/
/**/
/**/
/*static uint32_t emit_event_callback(uint32_t trigger_time, void* cb_arg) {*/
/*    const char* str = dvorak_search(dvorak_keycomb);*/
/*    if (str != NULL) {*/
/*        if (strcmp(str, "nag") == 0) {*/
/*            tap_code(KC_LNG1);*/
/*            layer_move(L_NAG);*/
/*        } else {*/
/*            send_string(str);*/
/*        }*/
/*        prev_dvorak_keycomb = 0;*/
/*        dvorak_keycomb      = 0;*/
/*    } else {*/
/*        str = dvorak_search(prev_dvorak_keycomb);*/
/*        if (strcmp(str, "nag") == 0) {*/
/*            tap_code(KC_LNG1);*/
/*            layer_move(L_NAG);*/
/*        } else {*/
/*            send_string(str);*/
/*        }*/
/*        dvorak_keycomb = (dvorak_keycomb ^ prev_dvorak_keycomb) & dvorak_keycomb;*/
/*    }*/
/*    return 0;*/
/*}*/
/**/
/*deferred_token emit_event_callback_token = 0;*/
/**/
/*bool process_dvorak(uint16_t keycode, keyrecord_t* record) {*/
/*    switch (keycode) {*/
/*        case DV_A ... DV_RSFT:*/
/*            if (record->event.pressed) {*/
/*                dv_press_key(keycode);*/
/*                if (!extend_deferred_exec(emit_event_callback_token, DVORAK_COMBO_DURATION)) {*/
/*                    emit_event_callback_token = defer_exec(DVORAK_COMBO_DURATION, emit_event_callback, NULL);*/
/*                }*/
/*            } else {*/
/*                emit_event_callback(0, NULL);*/
/*                cancel_deferred_exec(emit_event_callback_token);*/
/*                dv_release_key(keycode);*/
/*            }*/
/*            break;*/
/*        default:*/
/*            break;*/
/*    }*/
/*    return true;*/
/*}*/
