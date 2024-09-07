#pragma once

#include QMK_KEYBOARD_H

typedef enum naginata_keycodes {
    NG_Q = SAFE_RANGE, // 薙刀式シフトキー
    NG_W,
    NG_E,
    NG_R,
    NG_T,
    NG_Y,
    NG_U,
    NG_I,
    NG_O,
    NG_P,

    NG_A,
    NG_S,
    NG_D,
    NG_F,
    NG_G,
    NG_H,
    NG_J,
    NG_K,
    NG_L,
    NG_SCLN,

    NG_Z,
    NG_X,
    NG_C,
    NG_V,
    NG_B,
    NG_N,
    NG_M,
    NG_COMM,
    NG_DOT,
    NG_SLSH,

    NG_LSHFT,
    NG_RSHFT,
} NGKEYS;

bool process_naginata(uint16_t, keyrecord_t *);
