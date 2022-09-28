#pragma once

#include QMK_KEYBOARD_H
#include "config.h"

#define NON_NAGINATA_COUCHI false

enum layer_number {
    L_NAGINATA,
    L_QWERTY,
    L_DVORAK,
    L_RAISE,
    L_LOWER,
    L_MODIFIER,
    L_ADJUST,
    L_GAME,
    L_GAME2,
};

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

    NG_SHFT,
    NG_SHFT2,

    NG_CLR,
} NGKEYS;

// EEPROMに保存する設定

#define NG_SAFE_RANGE SAFE_RANGE + 42

#define NG_WIN 1
#define NG_MAC 2
#define NG_LINUX 3

void naginata_type(void);
void naginata_clear(void);
void compress_buffer(int nt);
bool naginata_lookup(int nt, bool shifted);
bool process_modifier(uint16_t, keyrecord_t *);
bool process_naginata(uint16_t, keyrecord_t *);

// vim:set sw=4 ts=4 sts=4:
