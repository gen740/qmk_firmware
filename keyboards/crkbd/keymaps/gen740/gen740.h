#pragma once

#include QMK_KEYBOARD_H

#include "naginata.h"

typedef enum my_keycodes {
    NEXT_APP = NG_SAFE_RANGE, // 薙刀式シフトキー
    PREV_APP,
    MK_SAFE_RANGE,
} MYKEYS;

enum layer_number {
  L_DVO,
  L_NAG,
};
