#include "dvorak_keydata.h"

#define B_A (1UL << (DV_A - DV_A))
#define B_B (1UL << (DV_B - DV_A))
#define B_C (1UL << (DV_C - DV_A))
#define B_D (1UL << (DV_D - DV_A))
#define B_E (1UL << (DV_E - DV_A))
#define B_F (1UL << (DV_F - DV_A))
#define B_G (1UL << (DV_G - DV_A))
#define B_H (1UL << (DV_H - DV_A))
#define B_I (1UL << (DV_I - DV_A))
#define B_J (1UL << (DV_J - DV_A))
#define B_K (1UL << (DV_K - DV_A))
#define B_L (1UL << (DV_L - DV_A))
#define B_M (1UL << (DV_M - DV_A))
#define B_N (1UL << (DV_N - DV_A))
#define B_O (1UL << (DV_O - DV_A))
#define B_P (1UL << (DV_P - DV_A))
#define B_Q (1UL << (DV_Q - DV_A))
#define B_R (1UL << (DV_R - DV_A))
#define B_S (1UL << (DV_S - DV_A))
#define B_T (1UL << (DV_T - DV_A))
#define B_U (1UL << (DV_U - DV_A))
#define B_V (1UL << (DV_V - DV_A))
#define B_W (1UL << (DV_W - DV_A))
#define B_X (1UL << (DV_X - DV_A))
#define B_Y (1UL << (DV_Y - DV_A))
#define B_Z (1UL << (DV_Z - DV_A))

#define B_QUOT (1UL << (DV_QUOT - DV_A))
#define B_COMM (1UL << (DV_COMM - DV_A))
#define B_DOT (1UL << (DV_DOT - DV_A))
#define B_SCLN (1UL << (DV_SCLN - DV_A))
#define B_LSFT (1UL << (DV_LSFT - DV_A))
#define B_RSFT (1UL << (DV_RSFT - DV_A))

const PROGMEM dvorak_keymap dvmap[DVORAK_KEY_NUMBER] = {
    // Normal keys
    {.key = B_QUOT, .val = "'"},
    {.key = B_COMM, .val = ","},
    {.key = B_DOT, .val = "."},
    {.key = B_P, .val = "p"},
    {.key = B_Y, .val = "y"},

    {.key = B_F, .val = "f"},
    {.key = B_G, .val = "g"},
    {.key = B_C, .val = "c"},
    {.key = B_R, .val = "r"},
    {.key = B_L, .val = "l"},

    {.key = B_A, .val = "a"},
    {.key = B_O, .val = "o"},
    {.key = B_E, .val = "e"},
    {.key = B_U, .val = "u"},
    {.key = B_I, .val = "i"},

    {.key = B_D, .val = "d"},
    {.key = B_H, .val = "h"},
    {.key = B_T, .val = "t"},
    {.key = B_N, .val = "n"},
    {.key = B_S, .val = "s"},

    {.key = B_SCLN, .val = ";"},
    {.key = B_Q, .val = "q"},
    {.key = B_J, .val = "j"},
    {.key = B_K, .val = "k"},
    {.key = B_X, .val = "x"},

    {.key = B_B, .val = "b"},
    {.key = B_M, .val = "m"},
    {.key = B_W, .val = "w"},
    {.key = B_V, .val = "v"},
    {.key = B_Z, .val = "z"},

    {.key = B_LSFT, .val = " "},
    {.key = B_RSFT, .val = " "},

    // Shift keys
    {.key = B_RSFT | B_QUOT, .val = "\""},
    {.key = B_RSFT | B_COMM, .val = "<"},
    {.key = B_RSFT | B_DOT, .val = ">"},
    {.key = B_RSFT | B_P, .val = "P"},
    {.key = B_RSFT | B_Y, .val = "Y"},

    {.key = B_RSFT | B_F, .val = "F"},
    {.key = B_RSFT | B_G, .val = "G"},
    {.key = B_RSFT | B_C, .val = "C"},
    {.key = B_RSFT | B_R, .val = "R"},
    {.key = B_RSFT | B_L, .val = "L"},

    {.key = B_RSFT | B_A, .val = "A"},
    {.key = B_RSFT | B_O, .val = "O"},
    {.key = B_RSFT | B_E, .val = "E"},
    {.key = B_RSFT | B_U, .val = "U"},
    {.key = B_RSFT | B_I, .val = "I"},


    {.key = B_RSFT | B_D, .val = "D"},
    {.key = B_RSFT | B_H, .val = "H"},
    {.key = B_RSFT | B_T, .val = "T"},
    {.key = B_RSFT | B_N, .val = "N"},
    {.key = B_RSFT | B_S, .val = "S"},

    {.key = B_RSFT | B_SCLN, .val = ":"},
    {.key = B_RSFT | B_Q, .val = "Q"},
    {.key = B_RSFT | B_J, .val = "J"},
    {.key = B_RSFT | B_K, .val = "K"},
    {.key = B_RSFT | B_X, .val = "X"},

    {.key = B_RSFT | B_B, .val = "B"},
    {.key = B_RSFT | B_M, .val = "M"},
    {.key = B_RSFT | B_W, .val = "W"},
    {.key = B_RSFT | B_V, .val = "V"},
    {.key = B_RSFT | B_Z, .val = "Z"},

    // Ctrl keys
    {.key = B_LSFT | B_QUOT, .val = SS_LCTL("'")},
    {.key = B_LSFT | B_COMM, .val = SS_LCTL(",")},
    {.key = B_LSFT | B_DOT, .val  = SS_LCTL(".")},
    {.key = B_LSFT | B_P, .val    = SS_LCTL("p")},
    {.key = B_LSFT | B_Y, .val    = SS_LCTL("y")},

    {.key = B_LSFT | B_F, .val    = SS_LCTL("f")},
    {.key = B_LSFT | B_G, .val    = SS_LCTL("g")},
    {.key = B_LSFT | B_C, .val    = SS_LCTL("c")},
    {.key = B_LSFT | B_R, .val    = SS_LCTL("r")},
    {.key = B_LSFT | B_L, .val    = SS_LCTL("l")},

    {.key = B_LSFT | B_A, .val    = SS_LCTL("a")},
    {.key = B_LSFT | B_O, .val    = SS_LCTL("o")},
    {.key = B_LSFT | B_E, .val    = SS_LCTL("e")},
    {.key = B_LSFT | B_U, .val    = SS_LCTL("u")},
    {.key = B_LSFT | B_I, .val    = SS_LCTL("i")},

    {.key = B_LSFT | B_D, .val    = SS_LCTL("d")},
    {.key = B_LSFT | B_H, .val    = SS_LCTL("h")},
    {.key = B_LSFT | B_T, .val    = SS_LCTL("t")},
    {.key = B_LSFT | B_N, .val    = SS_LCTL("n")},
    {.key = B_LSFT | B_S, .val    = SS_LCTL("s")},

    {.key = B_LSFT | B_SCLN, .val = SS_LCTL(";")},
    {.key = B_LSFT | B_Q, .val    = SS_LCTL("q")},
    {.key = B_LSFT | B_J, .val    = SS_LCTL("j")},
    {.key = B_LSFT | B_K, .val    = SS_LCTL("k")},
    {.key = B_LSFT | B_X, .val    = SS_LCTL("x")},

    {.key = B_LSFT | B_B, .val    = SS_LCTL("b")},
    {.key = B_LSFT | B_M, .val    = SS_LCTL("m")},
    {.key = B_LSFT | B_W, .val    = SS_LCTL("w")},
    {.key = B_LSFT | B_V, .val    = SS_LCTL("v")},
    {.key = B_LSFT | B_Z, .val    = SS_LCTL("z")},

    // Ctrl + Shift keys
    {.key = B_LSFT | B_RSFT | B_QUOT, .val = SS_LCTL(SS_LSFT("'"))},
    {.key = B_LSFT | B_RSFT | B_COMM, .val = SS_LCTL(SS_LSFT(","))},
    {.key = B_LSFT | B_RSFT | B_DOT, .val  = SS_LCTL(SS_LSFT("."))},
    {.key = B_LSFT | B_RSFT | B_P, .val    = SS_LCTL(SS_LSFT("p"))},
    {.key = B_LSFT | B_RSFT | B_Y, .val    = SS_LCTL(SS_LSFT("y"))},

    {.key = B_LSFT | B_RSFT | B_F, .val    = SS_LCTL(SS_LSFT("f"))},
    {.key = B_LSFT | B_RSFT | B_G, .val    = SS_LCTL(SS_LSFT("g"))},
    {.key = B_LSFT | B_RSFT | B_C, .val    = SS_LCTL(SS_LSFT("c"))},
    {.key = B_LSFT | B_RSFT | B_R, .val    = SS_LCTL(SS_LSFT("r"))},
    {.key = B_LSFT | B_RSFT | B_L, .val    = SS_LCTL(SS_LSFT("l"))},

    {.key = B_LSFT | B_RSFT | B_A, .val    = SS_LCTL(SS_LSFT("a"))},
    {.key = B_LSFT | B_RSFT | B_O, .val    = SS_LCTL(SS_LSFT("o"))},
    {.key = B_LSFT | B_RSFT | B_E, .val    = SS_LCTL(SS_LSFT("e"))},
    {.key = B_LSFT | B_RSFT | B_U, .val    = SS_LCTL(SS_LSFT("u"))},
    {.key = B_LSFT | B_RSFT | B_I, .val    = SS_LCTL(SS_LSFT("i"))},

    {.key = B_LSFT | B_RSFT | B_D, .val    = SS_LCTL(SS_LSFT("d"))},
    {.key = B_LSFT | B_RSFT | B_H, .val    = SS_LCTL(SS_LSFT("h"))},
    {.key = B_LSFT | B_RSFT | B_T, .val    = SS_LCTL(SS_LSFT("t"))},
    {.key = B_LSFT | B_RSFT | B_N, .val    = SS_LCTL(SS_LSFT("n"))},
    {.key = B_LSFT | B_RSFT | B_S, .val    = SS_LCTL(SS_LSFT("s"))},

    {.key = B_LSFT | B_RSFT | B_SCLN, .val = SS_LCTL(SS_LSFT(";"))},
    {.key = B_LSFT | B_RSFT | B_Q, .val    = SS_LCTL(SS_LSFT("q"))},
    {.key = B_LSFT | B_RSFT | B_J, .val    = SS_LCTL(SS_LSFT("j"))},
    {.key = B_LSFT | B_RSFT | B_K, .val    = SS_LCTL(SS_LSFT("k"))},
    {.key = B_LSFT | B_RSFT | B_X, .val    = SS_LCTL(SS_LSFT("x"))},

    {.key = B_LSFT | B_RSFT | B_B, .val    = SS_LCTL(SS_LSFT("b"))},
    {.key = B_LSFT | B_RSFT | B_M, .val    = SS_LCTL(SS_LSFT("m"))},
    {.key = B_LSFT | B_RSFT | B_W, .val    = SS_LCTL(SS_LSFT("w"))},
    {.key = B_LSFT | B_RSFT | B_V, .val    = SS_LCTL(SS_LSFT("v"))},
    {.key = B_LSFT | B_RSFT | B_Z, .val    = SS_LCTL(SS_LSFT("z"))},

    // Symbol keys
    {.key = B_T | B_QUOT, .val = "`"},
    {.key = B_T | B_COMM, .val = "%"},
    {.key = B_T | B_DOT, .val = "{"},
    {.key = B_T | B_P, .val = "("},
    {.key = B_T | B_Y, .val = "["},

    {.key = B_E | B_F, .val = "]"},
    {.key = B_E | B_G, .val = ")"},
    {.key = B_E | B_C, .val = "}"},
    {.key = B_E | B_R, .val = "$"},
    {.key = B_E | B_L, .val = "!"},

    {.key = B_T | B_A, .val = "#"},
    {.key = B_T | B_O, .val = "/"},
    /*{.key = B_T | B_E, .val = "" },*/
    {.key = B_T | B_U, .val = "+"},
    {.key = B_T | B_I, .val = "|"},

    {.key = B_E | B_D, .val = "_"},
    {.key = B_E | B_H, .val = "-"},
    /*{.key = B_T | B_E, .val = "" },*/
    {.key = B_E | B_N, .val = "^"},
    {.key = B_E | B_S, .val = "~"},

    /*{.key = B_T | B_SCLN, .val = "" },*/
    {.key = B_T | B_Q, .val = "\\"},
    /*{.key = B_T | B_J, .val = "="},*/
    {.key = B_T | B_K, .val = "&"},
    {.key = B_T | B_X, .val = "=" },

    {.key = B_E | B_B, .val = "*" },
    {.key = B_E | B_M, .val = "@"},
    /*{.key = B_T | B_W, .val = ""},*/
    /*{.key = B_E | B_V, .val = "" },*/
    /*{.key = B_E | B_Z, .val = "" },*/

    {.key = B_W | B_A, .val = "1"},
    {.key = B_W | B_O, .val = "2"},
    {.key = B_W | B_E, .val = "3"},
    {.key = B_W | B_U, .val = "4"},
    {.key = B_W | B_I, .val = "5"},

    {.key = B_J | B_D, .val = "6"},
    {.key = B_J | B_H, .val = "7"},
    {.key = B_J | B_T, .val = "8"},
    {.key = B_J | B_N, .val = "9"},
    {.key = B_J | B_S, .val = "0"},


    // special keys
    {.key = B_U | B_I, .val = SS_TAP(X_ESC)}, // escape
    {.key = B_J | B_W, .val = SS_TAP(X_TAB)}, // escape
    {.key = B_D | B_H, .val = "nag"},

    /*{.key = B_H | B_N, .val = "hypr"},*/
    /*{.key = B_U | B_O, .val = "hypr"},*/


    /*{.key = B_H | B_A ,.val = "A"},*/
    /*{.key = B_H | B_B ,.val = "B"},*/
    /*{.key = B_H | B_C ,.val = "C"},*/
    /*{.key = B_H | B_D ,.val = "D"},*/
    /*{.key = B_H | B_E ,.val = "E"},*/

    {.key = 0xffffffff, .val = NULL},
};
