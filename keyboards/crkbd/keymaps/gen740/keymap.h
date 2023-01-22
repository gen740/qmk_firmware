#pragma once

#include "naginata.h"

#define NG_SAFE_RANGE (SAFE_RANGE + 32)

enum my_keycodes {
    NAG_ESC = NG_SAFE_RANGE,
    SV_COUNT,
    RST_COUNT,
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
