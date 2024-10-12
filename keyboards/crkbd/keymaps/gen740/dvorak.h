#pragma once

#include QMK_KEYBOARD_H
#define DVORAK_COMBO_DURATION 80
#include "gen740.h"

typedef enum dvorak_keycodes {
    DV_A = MK_SAFE_RANGE,
    DV_B,
    DV_C,
    DV_D,
    DV_E,
    DV_F,
    DV_G,
    DV_H,
    DV_I,
    DV_J,
    DV_K,
    DV_L,
    DV_M,
    DV_N,
    DV_O,
    DV_P,
    DV_Q,
    DV_R,
    DV_S,
    DV_T,
    DV_U,
    DV_V,
    DV_W,
    DV_X,
    DV_Y,
    DV_Z,
    DV_QUOT,
    DV_COMM,
    DV_DOT,
    DV_SCLN,
    DV_LSFT,
    DV_RSFT,
    DV_SAFE_RANGE,
} DVOKEYS;

bool process_dvorak(uint16_t, keyrecord_t *);
