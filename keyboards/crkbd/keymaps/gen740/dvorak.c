#include "dvorak.h"
#include "dvorak_keydata.h"

const dv_node_t* current_node    = &dvnode_root;
bool             dv_emmitted     = false;
int8_t           dv_dangling_key = -1;

int8_t           dv_find_child(uint8_t key) {
    for (uint8_t i = 0; i < current_node->children_num; i++) {
        if (current_node->children[i]->key == key) {
            return i;
        }
    }
    return -1;
}

bool dv_forward(uint8_t key) {
    dv_dangling_key    = -1;
    int8_t child_index = dv_find_child(key);
    if (child_index != -1) {
        current_node = current_node->children[child_index];
        return true;
    }
    dv_dangling_key = key;
    return false;
}

void dv_back_one(void) {
    if (current_node->parent != NULL) {
        current_node = current_node->parent;
    }
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
    int8_t dangling_buf = dv_dangling_key;
    for (int8_t i = keys_len - 1; i >= 0; i--) {
        dv_forward(keys[i]);
    }
    if (dangling_buf != -1) {
        dv_emmitted = false;
        dv_forward(dangling_buf);
    }
}

void dv_send_string(const char* str) {
    dv_emmitted = true;
    if (strcmp(str, "nag") == 0) {
        tap_code(KC_LNG1);
        layer_move(L_NAG);
        return;
    }
    send_string(str);
}

// Process dvorak keycodes
bool process_dvorak(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case DV_A ... DV_RSFT3: {
            uint8_t key = keycode - DV_A;
            if (record->event.pressed) {
                // search next
                dv_emmitted = false;
                dv_forward(key);
                if (current_node->children_num == 0) {
                    dv_send_string(current_node->value);
                    dv_back_one();
                }
            } else {
                if (dv_dangling_key == key) {
                    dv_dangling_key = -1;
                }
                if (current_node->value != NULL) {
                    if (!dv_emmitted) {
                        dv_send_string(current_node->value);
                    }
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
