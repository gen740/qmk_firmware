#include "dvorak_keydata.h"

#define B_A    "\01"
#define B_B    "\02"
#define B_C    "\03"
#define B_D    "\04"
#define B_E    "\05"
#define B_F    "\06"
#define B_G    "\07"
#define B_H    "\010"
#define B_I    "\011"
#define B_J    "\012"
#define B_K    "\013"
#define B_L    "\014"
#define B_M    "\015"
#define B_N    "\016"
#define B_O    "\017"
#define B_P    "\020"
#define B_Q    "\021"
#define B_R    "\022"
#define B_S    "\023"
#define B_T    "\024"
#define B_U    "\025"
#define B_V    "\026"
#define B_W    "\027"
#define B_X    "\030"
#define B_Y    "\031"
#define B_Z    "\032"
#define B_QUOT "\033"
#define B_COMM "\034"
#define B_DOT  "\035"
#define B_SCLN "\036"
#define B_LS1  "\037"
#define B_RS1  "\040"
#define B_LS2  "\041"
#define B_RS2  "\042"
#define B_LS3  "\043"
#define B_RS3  "\044"

const PROGMEM dvorak_keymap dvmap[DVORAK_KEY_NUMBER] = {

    // special keys
    {.key = B_U B_I, .val = SS_TAP(X_ESC)}, // escape
    {.key = B_J B_W, .val = SS_TAP(X_TAB)}, // escape
    {.key = B_D B_H, .val = "nag"},
    {.key = B_LS2  B_E  B_N, .val = SS_LCTL("^")},
    {.key = B_LS2  B_J  B_W, .val = SS_LCTL(SS_TAP(X_TAB))},

    /*{.key = 0xffffffff, .val = NULL},*/
};
