#pragma once

#include QMK_KEYBOARD_H

enum my_keycodes {
  NAG_ESC = SAFE_RANGE + 32,
};

enum layer_number {
  L_DVORAK,
  L_NAGINATA,
  L_RAISE,
  L_ADJUST,
  L_MODIFIER,
  L_MEH,
  L_HYPER,
  L_LCAG,
  L_GAME,
  L_GAME2,
};
