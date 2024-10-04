#pragma once

#include "naginata.h"

#define B_Q (1UL << (NG_Q - NG_Q)) //
#define B_W (1UL << (NG_W - NG_Q)) //
#define B_E (1UL << (NG_E - NG_Q)) //
#define B_R (1UL << (NG_R - NG_Q)) //
#define B_T (1UL << (NG_T - NG_Q)) //

#define B_Y (1UL << (NG_Y - NG_Q)) //
#define B_U (1UL << (NG_U - NG_Q)) //
#define B_I (1UL << (NG_I - NG_Q)) //
#define B_O (1UL << (NG_O - NG_Q)) //
#define B_P (1UL << (NG_P - NG_Q)) //

#define B_A (1UL << (NG_A - NG_Q)) //
#define B_S (1UL << (NG_S - NG_Q)) //
#define B_D (1UL << (NG_D - NG_Q)) //
#define B_F (1UL << (NG_F - NG_Q)) //
#define B_G (1UL << (NG_G - NG_Q)) //

#define B_H (1UL << (NG_H - NG_Q))       //
#define B_J (1UL << (NG_J - NG_Q))       //
#define B_K (1UL << (NG_K - NG_Q))       //
#define B_L (1UL << (NG_L - NG_Q))       //
#define B_SCLN (1UL << (NG_SCLN - NG_Q)) //

#define B_Z (1UL << (NG_Z - NG_Q)) //
#define B_X (1UL << (NG_X - NG_Q)) //
#define B_C (1UL << (NG_C - NG_Q)) //
#define B_V (1UL << (NG_V - NG_Q)) //
#define B_B (1UL << (NG_B - NG_Q)) //

#define B_N (1UL << (NG_N - NG_Q))       //
#define B_M (1UL << (NG_M - NG_Q))       //
#define B_COMM (1UL << (NG_COMM - NG_Q)) //
#define B_DOT (1UL << (NG_DOT - NG_Q))   //
#define B_SLSH (1UL << (NG_SLSH - NG_Q)) //

#define B_LSHFT (1UL << (NG_LSHFT - NG_Q)) //
#define B_RSHFT (1UL << (NG_RSHFT - NG_Q)) //

// カナ変換テーブル //
typedef struct {
    uint32_t    key;
    const char* kana;
} naginata_keymap;

enum { NAGINATA_KEY_NUMBER = 204 };

extern const PROGMEM naginata_keymap ngmap[NAGINATA_KEY_NUMBER];
