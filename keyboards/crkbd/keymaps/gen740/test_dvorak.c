#include <string.h>

#include "action.h"
#include "action_layer.h"
#include "dvorak.h"
#include "gen740.h"

typedef struct dvorak_node2 dvorak_node2_t;

struct dvorak_node2 {
  const dvorak_node2_t *parent;                      // 4 bytes
  const dvorak_node2_t *(*next_node)(uint16_t key);  // 4 bytes
  const dvorak_node2_t *(*prev_node)(uint16_t key);  // 4 bytes
  const uint16_t key;
  const uint8_t bounds;  //  First 4 bits: modifier, Last 4 bits: keycode
                         //  bounds & 0xF0: Enter event end of the string
                         //  bounds & 0x0F: Exit event end of the string
  const uint8_t keys[];
};

const dvorak_node2_t dvorak_node_root = {
    .parent = NULL,
    .next_node = NULL,
    .prev_node = NULL,
    .key = 0,
    .bounds = 0,
    .keys = {},
};

const dvorak_node2_t *dv_current_node = &dvorak_node_root;

void dv_send_exit_event(const uint8_t keys[], const uint8_t bounds) {
  for (int8_t i = bounds & 0xF0; i < (bounds & 0x0F); i++) {
    if (keys[i] == KC_LANGUAGE_1) {
      tap_code(KC_LNG1);
      layer_move(L_NAG);
    } else {
      tap_code(keys[i]);
    }
  }
}

void dv_press_enter_event(const uint8_t keys[], const uint8_t bounds) {
  for (int8_t i = 0; i < (bounds & 0xF0); i++) {
    register_code(keys[i]);
  }
}

void dv_release_enter_event(const uint8_t keys[], const uint8_t bounds) {
  for (int8_t i = 0; i < (bounds & 0xF0); i++) {
    unregister_code(keys[i]);
  }
}

bool process_dvorak(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DV_A ... DV_RSFT3: {
      if (record->event.pressed) {
        const dvorak_node2_t *next_node = dv_current_node->next_node(keycode);

        if (next_node == NULL) {
          // For n-key rollover
          // 1. Roll back to the point where the next key is found
          // 2. replay the keys from the rollback point

          // first, send the exit string
          dv_send_exit_event(dv_current_node->keys, dv_current_node->bounds);

          uint16_t rollback_keybuf[8];
          uint8_t rollback_keybuf_len = 0;

          /* Rollback to the point where the next key is found */
          while (dv_current_node->parent != NULL) {
            dv_current_node = dv_current_node->parent;
            dv_release_enter_event(dv_current_node->keys,
                                   dv_current_node->bounds);

            const dvorak_node2_t *n = dv_current_node->next_node(keycode);
            if (n != NULL) {
              dv_current_node = n;
              dv_press_enter_event(dv_current_node->keys,
                                   dv_current_node->bounds);
              break;
            }
          }
          /* Replay the keys from the rollback point */
          for (int8_t i = rollback_keybuf_len - 1; i >= 0; i--) {
            const dvorak_node2_t *n =
                dv_current_node->next_node(rollback_keybuf[i]);
            if (n == NULL) {
              break;
            } else {
              dv_current_node = n;
              dv_press_enter_event(dv_current_node->keys,
                                   dv_current_node->bounds);
            }
          }
        } else {
          dv_current_node = next_node;
          dv_press_enter_event(dv_current_node->keys, dv_current_node->bounds);
        }
      } else {
        const dvorak_node2_t *prev_node = dv_current_node->prev_node(keycode);
        if (prev_node != NULL) {
          dv_send_exit_event(dv_current_node->keys, dv_current_node->bounds);
          dv_current_node = prev_node;
        }
      }
    }
  }
  return true;
}
