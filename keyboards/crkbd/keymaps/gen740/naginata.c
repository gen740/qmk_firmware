#include "gen740.h"
#include "naginata.h"
#include "naginata_keydata.h"

const naginata_node_t* ng_current_node = &naginata_node_root;

void                   ng_send_string(const char* str) {
    if (strcmp(str, "dvo") == 0) {
        tap_code(KC_LNG2);
        layer_move(L_DVO);

        return;
    }
    send_string(str);
}

bool process_naginata(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NG_A ... NG_RSFT3: {
            if (record->event.pressed) {
                const naginata_node_t* next_node = ng_current_node->next_node(keycode);

                // if not found, rollback
                if (next_node == NULL) {
                    ng_send_string(ng_current_node->value);

                    uint16_t keybuf[8];
                    uint8_t  keybuf_len = 0;

                    while (ng_current_node->parent != NULL) {
                        ng_current_node          = ng_current_node->parent;
                        const naginata_node_t* n = ng_current_node->next_node(keycode);
                        if (n != NULL) {
                            ng_current_node = n;
                            break;
                        }
                        keybuf[keybuf_len++] = ng_current_node->key;
                    }

                    for (int8_t i = keybuf_len - 1; i >= 0; i--) {
                        const naginata_node_t* n = ng_current_node->next_node(keybuf[i]);
                        if (n == NULL) {
                            break;
                        } else {
                            ng_current_node = n;
                        }
                    }

                } else {
                    ng_current_node = next_node;
                }
            } else {
                ng_send_string(ng_current_node->value);
                const naginata_node_t* n = ng_current_node->prev_node(keycode);
                if (n != NULL) {
                    ng_current_node = n;
                }
            }
            return false;
        }
        default:
            break;
    }
    return true;
}
