#include "dvorak.h"

#include <stdio.h>

#include "dvorak_keydata.h"
#include "gen740.h"

static const dvorak_node_t *dv_current_node = &dvorak_node_root;
static bool dv_char_emit = false;

static bool dv_send_event(const uint16_t keys[], const uint8_t bounds) {
  bool flag = false;
  for (int8_t i = 0; i < bounds; i++) {
    if (keys[i] == KC_LANGUAGE_1) {
      tap_code(KC_LNG1);
      layer_move(L_NAG);
      flag = true;
    } else {
      tap_code16(keys[i]);
      flag = true;
    }
  }
  return flag;
}

static bool dv_is_key_in_branch(const dvorak_node_t *node, uint16_t key) {
  const dvorak_node_t *n = node;
  while (n != NULL) {
    if (n->key == key) {
      return true;
    }
    n = n->parent;
  }
  return false;
}

bool process_dvorak(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DV_A ... DV_RSFT3: {
      uint16_t dv_rollback_keybuf[8];
      uint8_t dv_rollback_keybuf_len = 0;

      if (record->event.pressed) {
        dv_char_emit = false;
        const dvorak_node_t *next_node = dv_current_node->next_node(keycode);
        const dvorak_node_t *dv_rollback_root = dv_current_node;
        if (next_node == NULL) {
          while (dv_current_node->parent != NULL) {
            dv_rollback_keybuf[dv_rollback_keybuf_len++] = dv_current_node->key;
            dv_current_node = dv_current_node->parent;
            if (dv_current_node->next_node(keycode) != NULL) {
              dv_rollback_root = dv_current_node;
              const dvorak_node_t *n = dv_current_node->next_node(keycode);
              if (n != NULL) {
                dv_current_node = dv_current_node->next_node(keycode);
              }
              break;
            }
          }
          for (int8_t i = dv_rollback_keybuf_len - 1; i >= 0; i--) {
            dv_send_event(
                dv_rollback_root->next_node(dv_rollback_keybuf[i])->keys,
                dv_rollback_root->next_node(dv_rollback_keybuf[i])->bounds);
          }
        } else {
          dv_current_node = next_node;
        }
      } else {
        if (dv_current_node->key == keycode) {
          if (!dv_char_emit) {
            dv_char_emit =
                dv_send_event(dv_current_node->keys, dv_current_node->bounds);
          }
          dv_current_node = dv_current_node->parent;
        } else if (dv_is_key_in_branch(dv_current_node, keycode)) {
          if (!dv_char_emit) {
            dv_char_emit =
                dv_send_event(dv_current_node->keys, dv_current_node->bounds);
          }
          while (dv_current_node->parent != NULL) {
            if (dv_current_node->key == keycode) {
              if (!dv_char_emit) {
                dv_send_event(dv_current_node->keys, dv_current_node->bounds);
              }
              dv_current_node = dv_current_node->parent;
              break;
            } else {
              dv_rollback_keybuf[dv_rollback_keybuf_len++] =
                  dv_current_node->key;
              dv_current_node = dv_current_node->parent;
            }
          }
          for (int8_t i = dv_rollback_keybuf_len - 1; i >= 0; i--) {
            const dvorak_node_t *n =
                dv_current_node->next_node(dv_rollback_keybuf[i]);
            if (n == NULL) {
              break;
            }
            dv_current_node = n;
          }
        }
      }
    }
  }
  return true;
}
