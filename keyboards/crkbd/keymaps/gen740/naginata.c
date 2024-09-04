#include "naginata.h"

#include "naginata_keydata.h"

uint32_t bit_buffer1 = 0;
bool char_emitted = false;
uint8_t prev_key = 0;

void press_key(enum naginata_keycodes key) {
  bit_buffer1 = bit_buffer1 | 1UL << (key - NG_Q);
}

void release_key(enum naginata_keycodes key) {
  bit_buffer1 = bit_buffer1 & ~(1UL << (key - NG_Q));
}

bool lookup(uint16_t keycode, uint32_t bit_buffer2) {
  naginata_keymap bngmap;        // PROGMEM buffer
  naginata_keymap_long bngmapl;  // PROGMEM buffer
  for (int i = 0; i < (int)(sizeof ngmap / sizeof bngmap); i++) {
    memcpy_P(&bngmap, &ngmap[i], sizeof(bngmap));
    if (bit_buffer2 == bngmap.key &&
        ((1UL << (keycode - NG_Q)) & bngmap.key) != 0) {
      if (!char_emitted) {
        if (bit_buffer1 == bit_buffer2) {
          char_emitted = true;
        }
        send_string(bngmap.kana);
      }
      return true;
    }
  }
  for (int i = 0; i < (int)(sizeof ngmapl_mac / sizeof bngmapl); i++) {
    memcpy_P(&bngmapl, &ngmapl_mac[i], sizeof(bngmapl));
    if (bit_buffer2 == bngmapl.key &&
        ((1UL << (keycode - NG_Q)) & bngmapl.key) > 0) {
      if (!char_emitted) {
        if (bit_buffer1 == bit_buffer2) {
          char_emitted = true;
        }
        send_string(bngmapl.kana);
      }
      return true;
    }
  }
  return false;
}

bool process_naginata(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case NG_Q ... NG_SHFT:
        char_emitted = false;
        press_key(keycode);
        prev_key = keycode;
        return false;
        break;
      default:
        break;
    }
  } else {  // key release
    uint32_t bit_buffer2 = bit_buffer1;
    switch (keycode) {
      case NG_Q ... NG_SHFT:
        while (true) {
          if (lookup(keycode, bit_buffer2)) {
            break;
          }
          if (bit_buffer1 == bit_buffer2) {
            bit_buffer2 = bit_buffer2 & ~(1UL << (prev_key - NG_Q));
            if (bit_buffer1 == bit_buffer2) {
              break;
            }
            continue;
          }
          break;
        }
        release_key(keycode);
        return true;
      default:
        break;
    }
  }
  return true;
}
