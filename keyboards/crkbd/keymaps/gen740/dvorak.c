#include "dvorak.h"
#include "dvorak_keydata.h"

const dvorak_node_t* dv_current_node = &dvorak_node_root;

void                 dv_send_string(const char* str) {
    if (strcmp(str, "nag") == 0) {
        tap_code(KC_LNG1);
        layer_move(L_NAG);
        return;
    }
    send_string(str);
}

bool process_dvorak(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case DV_A ... DV_RSFT3: {
            if (record->event.pressed) {
                const dvorak_node_t* next_node = dv_current_node->next_node(keycode);

                // if not found, rollback
                if (next_node == NULL) {
                    dv_send_string(dv_current_node->value);

                    uint16_t keybuf[8];
                    uint8_t  keybuf_len = 0;

                    while (dv_current_node->parent != NULL) {
                        dv_current_node        = dv_current_node->parent;
                        const dvorak_node_t* n = dv_current_node->next_node(keycode);
                        if (n != NULL) {
                            dv_current_node = n;
                            break;
                        }
                        keybuf[keybuf_len++] = dv_current_node->key;
                    }

                    for (int8_t i = keybuf_len - 1; i >= 0; i--) {
                        const dvorak_node_t* n = dv_current_node->next_node(keybuf[i]);
                        if (n == NULL) {
                            break;
                        } else {
                            dv_current_node = n;
                        }
                    }

                } else {
                    dv_current_node = next_node;
                }
            } else {
                const dvorak_node_t* n = dv_current_node->prev_node(keycode);
                if (n != NULL) {
                    dv_send_string(dv_current_node->value);
                    dv_current_node = n;
                } else {
                    while (dv_current_node->parent != NULL) {
                        dv_send_string(dv_current_node->value);
                        dv_current_node = dv_current_node->parent;
                    }
                }
            }
            return false;
        }
        default:
            break;
    }
    return true;
}
