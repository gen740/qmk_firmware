#include "dvorak.h"
#include "dvorak_keydata.h"

const dv_node_t* current_node   = &dvnode_root;
bool             dv_rollingback = false;

void             dv_forward(uint8_t key) {
    for (uint8_t i = 0; i < current_node->children_num; i++) {
        if (current_node->children[i]->key == key) {
            current_node = current_node->children[i];
            break;
        }
    }
    dv_rollingback = false;
}

void dv_back_one(void) {
    if (current_node->parent != NULL) {
        current_node = current_node->parent;
    }
    dv_rollingback = true;
}

void dv_rollback(uint8_t key) {
    // Search parent until root
    uint8_t keys[16];
    uint8_t keys_len = 0;
    while (current_node->parent != NULL) {
        if (current_node->key == key) {
            dv_back_one();
            break;
        }
        keys[keys_len++] = current_node->key;
        dv_back_one();
    }
    for (int8_t i = keys_len - 1; i >= 0; i--) {
        dv_forward(keys[i]);
    }
    dv_rollingback = true;
}

// Process dvorak keycodes
bool process_dvorak(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case DV_A ... DV_RSFT3: {
            uint8_t key = keycode - DV_A;
            if (record->event.pressed) {
                // search next
                dv_forward(key);
                if (current_node->children_num == 0) {
                    send_string(current_node->value);
                    dv_back_one();
                }
            } else {
                if (current_node->key == key) {
                    if (!dv_rollingback) {
                        send_string(current_node->value);
                    }
                    dv_back_one();
                }
                dv_rollback(key);
            }
            break;
        }
        default:
            break;
    }
    return true;
}
