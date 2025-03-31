#include <stdio.h>
#include <string.h>

#include "action.h"
#include "action_layer.h"
#include "dvorak.h"
#include "gen740.h"
#include "naginata_keydata.h"

static const naginata_node_t *ng_current_node = &naginata_node_root;
static bool ng_char_emit = false;

static bool ng_send_exit_event(const uint16_t keys[], const uint8_t bounds) {
  bool flag = false;
  for (int8_t i = 0; i < bounds; i++) {
    if (keys[i] == KC_LANGUAGE_2) {
      tap_code(KC_LNG2);
      layer_move(L_DVO);
      flag = true;
    } else {
      tap_code16(keys[i]);
      flag = true;
    }
  }
  return flag;
}

static bool ng_is_key_in_branch(const naginata_node_t *node, uint16_t key) {
  const naginata_node_t *n = node;
  while (n != NULL) {
    if (n->key == key) {
      return true;
    }
    n = n->parent;
  }
  return false;
}

bool process_naginata(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NG_A ... NG_RSFT3: {
      uint16_t ng_rollback_keybuf[8];
      uint8_t ng_rollback_keybuf_len = 0;

      if (record->event.pressed) {
        ng_char_emit = false;
        const naginata_node_t *next_node = ng_current_node->next_node(keycode);
        if (next_node == NULL) {
          while (ng_current_node->parent != NULL) {
            ng_rollback_keybuf[ng_rollback_keybuf_len++] = ng_current_node->key;
            ng_current_node = ng_current_node->parent;
            if (ng_current_node->next_node(keycode) != NULL) {
              ng_current_node = ng_current_node->next_node(keycode);
              break;
            }
          }
          for (int8_t i = ng_rollback_keybuf_len - 1; i >= 0; i--) {
            ng_send_exit_event(
                naginata_node_root.next_node(ng_rollback_keybuf[i])->keys,
                naginata_node_root.next_node(ng_rollback_keybuf[i])->bounds);
          }
        } else {
          ng_current_node = next_node;
        }
      } else {
        if (ng_current_node->key == keycode) {
          if (!ng_char_emit) {
            ng_char_emit = ng_send_exit_event(ng_current_node->keys,
                                              ng_current_node->bounds);
          }
          ng_current_node = ng_current_node->parent;
        } else if (ng_is_key_in_branch(ng_current_node, keycode)) {
          if (!ng_char_emit) {
            ng_char_emit = ng_send_exit_event(ng_current_node->keys,
                                              ng_current_node->bounds);
          }
          while (ng_current_node->parent != NULL) {
            if (ng_current_node->key == keycode) {
              if (!ng_char_emit) {
                ng_send_exit_event(ng_current_node->keys,
                                   ng_current_node->bounds);
              }
              ng_current_node = ng_current_node->parent;
              break;
            } else {
              ng_rollback_keybuf[ng_rollback_keybuf_len++] =
                  ng_current_node->key;
              ng_current_node = ng_current_node->parent;
            }
          }
          for (int8_t i = ng_rollback_keybuf_len - 1; i >= 0; i--) {
            const naginata_node_t *n =
                ng_current_node->next_node(ng_rollback_keybuf[i]);
            if (n == NULL) {
              break;
            }
            ng_current_node = n;
          }
        }
      }
    }
  }
  return true;
}
