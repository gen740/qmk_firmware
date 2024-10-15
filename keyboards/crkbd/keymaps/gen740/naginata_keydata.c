#include "naginata_keydata.h"

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

#define B_LSFT (1UL << (NG_LSHFT - NG_Q)) //
#define B_RSFT (1UL << (NG_RSHFT - NG_Q)) //


const PROGMEM naginata_keymap ngmap[NAGINATA_KEY_NUMBER] = {

    // 追加
};

#undef B_Q
#undef B_W
#undef B_E
#undef B_R
#undef B_T

#undef B_Y
#undef B_U
#undef B_I
#undef B_O
#undef B_P

#undef B_A
#undef B_S
#undef B_D
#undef B_F
#undef B_G

#undef B_H
#undef B_J
#undef B_K
#undef B_L
#undef B_S

#undef B_Z
#undef B_X
#undef B_C
#undef B_V
#undef B_B

#undef B_N
#undef B_M
#undef B_COMM
#undef B_DOT
#undef B_SLSH

#undef B_LSFT
#undef B_RSFT
