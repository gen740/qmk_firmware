#include "gen740.h"
#include "naginata.h"
#include "naginata_keydata.h"

const naginata_node_t* ng_current_node = &naginata_node_root;
bool                   ng_emmitted     = false;
int8_t                 ng_dangling_key = -1;

int8_t                 ng_find_child(uint8_t key) {
    for (uint8_t i = 0; i < ng_current_node->children_num; i++) {
        if (ng_current_node->children[i]->key == key) {
            return i;
        }
    }
    return -1;
}

bool ng_forward(uint8_t key) {
    ng_dangling_key    = -1;
    int8_t child_index = ng_find_child(key);
    if (child_index != -1) {
        ng_current_node = ng_current_node->children[child_index];
        return true;
    }
    ng_dangling_key = key;
    return false;
}

void ng_back_one(void) {
    if (ng_current_node->parent != NULL) {
        ng_current_node = ng_current_node->parent;
    }
}

void ng_rollback(uint8_t key) {
    // Search parent until root
    uint8_t keys[16];
    uint8_t keys_len = 0;
    while (ng_current_node->parent != NULL) {
        if (ng_current_node->key == key) {
            ng_back_one();
            break;
        }
        keys[keys_len++] = ng_current_node->key;
        ng_back_one();
    }
    int8_t dangling_buf = ng_dangling_key;
    for (int8_t i = keys_len - 1; i >= 0; i--) {
        ng_forward(keys[i]);
    }
    if (dangling_buf != -1) {
        ng_emmitted = false;
        ng_forward(dangling_buf);
    }
}

void ng_send_string(const char* str) {
    ng_emmitted = true;
    if (strcmp(str, "dvo") == 0) {
        tap_code(KC_LNG2);
        layer_move(L_DVO);

        return;
    }
    send_string(str);
}

// Process naginata keycodes
bool process_naginata(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NG_A ... NG_RSFT3: {
            uint8_t key = keycode - NG_A;
            if (record->event.pressed) {
                // search next
                ng_emmitted = false;
                ng_forward(key);
                if (ng_current_node->children_num == 0) {
                    ng_send_string(ng_current_node->value);
                    ng_back_one();
                }
            } else {
                if (ng_dangling_key == key) {
                    ng_dangling_key = -1;
                }
                if (ng_current_node->value != NULL) {
                    if (!ng_emmitted) {
                        ng_send_string(ng_current_node->value);
                    }
                }
                ng_rollback(key);
            }
            return false;
        }
        default:
            break;
    }
    return true;
}
