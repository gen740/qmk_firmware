#include "dvorak.h"

#include <string.h>

#include "action.h"
#include "action_layer.h"
#include "dvorak_keydata.h"
#include "gen740.h"

int8_t levels[2] = {0, 0};
const dvorak_node_t *dv_current_node = &dvorak_node_root;

void dv_send_exit_event(const uint8_t keys[], const uint8_t bounds) {
  for (int8_t i = (bounds & 0xF0) >> 4; i < (bounds & 0x0F); i++) {
    if (keys[i] == KC_LANGUAGE_1) {
      tap_code(KC_LNG1);
      layer_move(L_NAG);
    } else {
      tap_code(keys[i]);
    }
  }
}

void dv_press_enter_event(const uint8_t keys[], const uint8_t bounds) {
  for (int8_t i = 0; i < (bounds & 0xF0) >> 4; i++) {
    register_code(keys[i]);
  }
}

void dv_release_enter_event(const uint8_t keys[], const uint8_t bounds) {
  for (int8_t i = 0; i < (bounds & 0xF0) >> 4; i++) {
    unregister_code(keys[i]);
  }
}

bool process_dvorak(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DV_A ... DV_RSFT3: {
      if (record->event.pressed) {
        const dvorak_node_t *next_node = dv_current_node->next_node(keycode);

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
            dv_release_enter_event(dv_current_node->keys,
                                   dv_current_node->bounds);
            dv_current_node = dv_current_node->parent;
            const dvorak_node_t *n = dv_current_node->next_node(keycode);
            if (n != NULL) {
              dv_current_node = n;
              dv_press_enter_event(dv_current_node->keys,
                                   dv_current_node->bounds);
              break;
            }
          }
          /* Replay the keys from the rollback point */
          for (int8_t i = rollback_keybuf_len - 1; i >= 0; i--) {
            const dvorak_node_t *n =
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
        levels[1] = levels[0];
        levels[0]++;
      } else {
        // Release the key
        if (dv_current_node->key == keycode) {
          dv_release_enter_event(dv_current_node->keys,
                                 dv_current_node->bounds);
          if (levels[0] > levels[1]) {
            dv_send_exit_event(dv_current_node->keys, dv_current_node->bounds);
          }
          dv_current_node = dv_current_node->parent;
        } else {
          if (levels[0] > levels[1]) {
            dv_send_exit_event(dv_current_node->keys, dv_current_node->bounds);
          }

          uint16_t rollback_keybuf[8];
          uint8_t rollback_keybuf_len = 0;

          // Rollback to the point where the next key is found
          while (dv_current_node->parent != NULL) {
            dv_release_enter_event(dv_current_node->keys,
                                   dv_current_node->bounds);
            if (dv_current_node->key == keycode) {
              dv_current_node = dv_current_node->parent;
              break;
            } else {
              rollback_keybuf[rollback_keybuf_len++] = dv_current_node->key;
              dv_current_node = dv_current_node->parent;
            }
          }

          for (int8_t i = rollback_keybuf_len - 1; i >= 0; i--) {
            const dvorak_node_t *n =
                dv_current_node->next_node(rollback_keybuf[i]);
            if (n == NULL) {
              break;
            } else {
              dv_current_node = n;
              dv_press_enter_event(dv_current_node->keys,
                                   dv_current_node->bounds);
            }
          }
        }
        levels[1] = levels[0];
        levels[0]--;
      }
    }
  }
  return true;
}
