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

#define B_LSHFT (1UL << (NG_LSHFT - NG_Q)) //
#define B_RSHFT (1UL << (NG_RSHFT - NG_Q)) //


const PROGMEM naginata_keymap ngmap[NAGINATA_KEY_NUMBER] = {
    // 清音
    {.key = B_J, .kana = "a"},               // あ
    {.key = B_K, .kana = "i"},               // い
    {.key = B_L, .kana = "u"},               // う
    {.key = B_LSHFT | B_O, .kana = "e"},     // え
    {.key = B_LSHFT | B_N, .kana = "o"},     // お
    {.key = B_F, .kana = "ka"},              // か
    {.key = B_W, .kana = "ki"},              // き
    {.key = B_H, .kana = "ku"},              // く
    {.key = B_S, .kana = "ke"},              // け
    {.key = B_V, .kana = "ko"},              // こ
    {.key = B_U, .kana = "sa"},              // さ
    {.key = B_LSHFT | B_U, .kana = "sa"},    // さ
    {.key = B_R, .kana = "si"},              // し
    {.key = B_O, .kana = "su"},              // す
    {.key = B_RSHFT | B_A, .kana = "se"},    // せ
    {.key = B_B, .kana = "so"},              // そ
    {.key = B_N, .kana = "ta"},              // た
    {.key = B_RSHFT | B_G, .kana = "ti"},    // ち
    {.key = B_LSHFT | B_L, .kana = "tu"},    // つ
    {.key = B_E, .kana = "te"},              // て
    {.key = B_D, .kana = "to"},              // と
    {.key = B_M, .kana = "na"},              // な
    {.key = B_RSHFT | B_D, .kana = "ni"},    // に
    {.key = B_RSHFT | B_W, .kana = "nu"},    // ぬ
    {.key = B_RSHFT | B_R, .kana = "ne"},    // ね
    {.key = B_LSHFT | B_J, .kana = "no"},    // の
    {.key = B_C, .kana = "ha"},              // は
    {.key = B_X, .kana = "hi"},              // ひ
    {.key = B_RSHFT | B_X, .kana = "hi"},    // ひ
    {.key = B_LSHFT | B_SCLN, .kana = "fu"}, // ふ
    {.key = B_P, .kana = "he"},              // へ
    {.key = B_Z, .kana = "ho"},              // ほ
    {.key = B_RSHFT | B_Z, .kana = "ho"},    // ほ
    {.key = B_RSHFT | B_F, .kana = "ma"},    // ま
    {.key = B_RSHFT | B_B, .kana = "mi"},    // み
    {.key = B_LSHFT | B_COMM, .kana = "mu"}, // む
    {.key = B_RSHFT | B_S, .kana = "me"},    // め
    {.key = B_LSHFT | B_K, .kana = "mo"},    // も
    {.key = B_LSHFT | B_H, .kana = "ya"},    // や
    {.key = B_LSHFT | B_P, .kana = "yu"},    // ゆ
    {.key = B_LSHFT | B_I, .kana = "yo"},    // よ
    {.key = B_DOT, .kana = "ra"},            // ら
    {.key = B_RSHFT | B_E, .kana = "ri"},    // り
    {.key = B_I, .kana = "ru"},              // る
    {.key = B_SLSH, .kana = "re"},           // れ
    {.key = B_LSHFT | B_SLSH, .kana = "re"}, // れ
    {.key = B_A, .kana = "ro"},              // ろ
    {.key = B_LSHFT | B_DOT, .kana = "wa"},  // わ
    {.key = B_RSHFT | B_C, .kana = "wo"},    // を
    {.key = B_COMM, .kana = "nn"},           // ん
    {.key = B_SCLN, .kana = "-"},            // ー

    // 濁音
    {.key = B_J | B_F, .kana = "ga"},    // が
    {.key = B_J | B_W, .kana = "gi"},    // ぎ
    {.key = B_F | B_H, .kana = "gu"},    // ぐ
    {.key = B_J | B_S, .kana = "ge"},    // げ
    {.key = B_J | B_V, .kana = "go"},    // ご
    {.key = B_F | B_U, .kana = "za"},    // ざ
    {.key = B_J | B_R, .kana = "zi"},    // じ
    {.key = B_F | B_O, .kana = "zu"},    // ず
    {.key = B_J | B_A, .kana = "ze"},    // ぜ
    {.key = B_J | B_B, .kana = "zo"},    // ぞ
    {.key = B_F | B_N, .kana = "da"},    // だ
    {.key = B_J | B_G, .kana = "di"},    // ぢ
    {.key = B_F | B_L, .kana = "du"},    // づ
    {.key = B_J | B_E, .kana = "de"},    // で
    {.key = B_J | B_D, .kana = "do"},    // ど
    {.key = B_J | B_C, .kana = "ba"},    // ば
    {.key = B_J | B_X, .kana = "bi"},    // び
    {.key = B_F | B_SCLN, .kana = "bu"}, // ぶ
    {.key = B_F | B_P, .kana = "be"},    // べ
    {.key = B_J | B_Z, .kana = "bo"},    // ぼ
    {.key = B_Q, .kana = "vu"},          // ゔ

    // 半濁音
    {.key = B_M | B_C, .kana = "pa"},    // ぱ
    {.key = B_M | B_X, .kana = "pi"},    // ぴ
    {.key = B_V | B_SCLN, .kana = "pu"}, // ぷ
    {.key = B_V | B_P, .kana = "pe"},    // ぺ
    {.key = B_M | B_Z, .kana = "po"},    // ぽ

    // 小書き
    {.key = B_Q | B_H, .kana = "xya"}, // ゃ
    {.key = B_Q | B_P, .kana = "xyu"}, // ゅ
    {.key = B_Q | B_I, .kana = "xyo"}, // ょ
    {.key = B_Q | B_J, .kana = "xa"},  // ぁ
    {.key = B_Q | B_K, .kana = "xi"},  // ぃ
    {.key = B_Q | B_L, .kana = "xu"},  // ぅ
    {.key = B_Q | B_O, .kana = "xe"},  // ぇ
    {.key = B_Q | B_N, .kana = "xo"},  // ぉ
    {.key = B_G, .kana = "ltu"},       // っ

    // 清音拗音 濁音拗音 半濁拗音
    {.key = B_R | B_H, .kana = "sya"},       // しゃ
    {.key = B_R | B_P, .kana = "syu"},       // しゅ
    {.key = B_R | B_I, .kana = "syo"},       // しょ
    {.key = B_J | B_R | B_H, .kana = "zya"}, // じゃ
    {.key = B_J | B_R | B_P, .kana = "zyu"}, // じゅ
    {.key = B_J | B_R | B_I, .kana = "zyo"}, // じょ
    {.key = B_W | B_H, .kana = "kya"},       // きゃ
    {.key = B_W | B_P, .kana = "kyu"},       // きゅ
    {.key = B_W | B_I, .kana = "kyo"},       // きょ
    {.key = B_J | B_W | B_H, .kana = "gya"}, // ぎゃ
    {.key = B_J | B_W | B_P, .kana = "gyu"}, // ぎゅ
    {.key = B_J | B_W | B_I, .kana = "gyo"}, // ぎょ
    {.key = B_G | B_H, .kana = "tya"},       // ちゃ
    {.key = B_G | B_P, .kana = "tyu"},       // ちゅ
    {.key = B_G | B_I, .kana = "tyo"},       // ちょ
    {.key = B_J | B_G | B_H, .kana = "dya"}, // ぢゃ
    {.key = B_J | B_G | B_P, .kana = "dyu"}, // ぢゅ
    {.key = B_J | B_G | B_I, .kana = "dyo"}, // ぢょ
    {.key = B_D | B_H, .kana = "nya"},       // にゃ
    {.key = B_D | B_P, .kana = "nyu"},       // にゅ
    {.key = B_D | B_I, .kana = "nyo"},       // にょ
    {.key = B_X | B_H, .kana = "hya"},       // ひゃ
    {.key = B_X | B_P, .kana = "hyu"},       // ひゅ
    {.key = B_X | B_I, .kana = "hyo"},       // ひょ
    {.key = B_J | B_X | B_H, .kana = "bya"}, // びゃ
    {.key = B_J | B_X | B_P, .kana = "byu"}, // びゅ
    {.key = B_J | B_X | B_I, .kana = "byo"}, // びょ
    {.key = B_M | B_X | B_H, .kana = "pya"}, // ぴゃ
    {.key = B_M | B_X | B_P, .kana = "pyu"}, // ぴゅ
    {.key = B_M | B_X | B_I, .kana = "pyo"}, // ぴょ
    {.key = B_B | B_H, .kana = "mya"},       // みゃ
    {.key = B_B | B_P, .kana = "myu"},       // みゅ
    {.key = B_B | B_I, .kana = "myo"},       // みょ
    {.key = B_E | B_H, .kana = "rya"},       // りゃ
    {.key = B_E | B_P, .kana = "ryu"},       // りゅ
    {.key = B_E | B_I, .kana = "ryo"},       // りょ

    // 清音外来音 濁音外来音
    {.key = B_M | B_E | B_K, .kana = "thi"},    // てぃ
    {.key = B_M | B_E | B_P, .kana = "thu"},    // てゅ
    {.key = B_J | B_E | B_K, .kana = "dhi"},    // でぃ
    {.key = B_J | B_E | B_P, .kana = "dhu"},    // でゅ
    {.key = B_M | B_D | B_L, .kana = "toxu"},   // とぅ
    {.key = B_J | B_D | B_L, .kana = "doxu"},   // どぅ
    {.key = B_M | B_R | B_O, .kana = "sye"},    // しぇ
    {.key = B_M | B_G | B_O, .kana = "tye"},    // ちぇ
    {.key = B_J | B_R | B_O, .kana = "zye"},    // じぇ
    {.key = B_J | B_G | B_O, .kana = "dye"},    // ぢぇ
    {.key = B_V | B_SCLN | B_J, .kana = "fa"},  // ふぁ
    {.key = B_V | B_SCLN | B_K, .kana = "fi"},  // ふぃ
    {.key = B_V | B_SCLN | B_O, .kana = "fe"},  // ふぇ
    {.key = B_V | B_SCLN | B_N, .kana = "fo"},  // ふぉ
    {.key = B_V | B_SCLN | B_P, .kana = "fyu"}, // ふゅ
    {.key = B_V | B_K | B_O, .kana = "ixe"},    // いぇ
    {.key = B_V | B_L | B_K, .kana = "wi"},     // うぃ
    {.key = B_V | B_L | B_O, .kana = "we"},     // うぇ
    {.key = B_V | B_L | B_N, .kana = "uxo"},    // うぉ
    {.key = B_F | B_L | B_J, .kana = "va"},     // ゔぁ
    {.key = B_F | B_L | B_K, .kana = "vi"},     // ゔぃ
    {.key = B_F | B_L | B_O, .kana = "ve"},     // ゔぇ
    {.key = B_F | B_L | B_N, .kana = "vo"},     // ゔぉ
    {.key = B_F | B_L | B_P, .kana = "vuxyu"},  // ゔゅ :WARN:
    {.key = B_V | B_H | B_J, .kana = "kuxa"},   // くぁ
    {.key = B_V | B_H | B_K, .kana = "kuxi"},   // くぃ
    {.key = B_V | B_H | B_O, .kana = "kuxe"},   // くぇ
    {.key = B_V | B_H | B_N, .kana = "kuxo"},   // くぉ
    {.key = B_V | B_H | B_L, .kana = "qwa"},    // くゎ
    {.key = B_F | B_H | B_J, .kana = "guxa"},   // ぐぁ
    {.key = B_F | B_H | B_K, .kana = "guxi"},   // ぐぃ
    {.key = B_F | B_H | B_O, .kana = "guxe"},   // ぐぇ
    {.key = B_F | B_H | B_N, .kana = "guxo"},   // ぐぉ
    {.key = B_F | B_H | B_L, .kana = "guxwa"},  // ぐゎ :WARN:
    {.key = B_V | B_L | B_J, .kana = "tsa"},    // つぁ
    {.key = B_V | B_L | B_K, .kana = "tsi"},    // つぃ
    {.key = B_V | B_L | B_O, .kana = "tse"},    // つぇ
    {.key = B_V | B_L | B_N, .kana = "tso"},    // つぉ

    // 追加
    {.key = B_T, .kana = SS_TAP(X_LEFT)},  //
    {.key = B_Y, .kana = SS_TAP(X_RIGHT)}, //
    /*{.key = B_S | B_D, .kana = ";"},  //*/
    /*{.key = B_K | B_L, .kana = ";"}, //*/

    // {.key = B_Q,         .kana = ""},                //
    {.key = B_LSHFT, .kana = SS_LSFT(SS_TAP(X_SPACE))}, //
                                                        //
    {.key = B_RSHFT, .kana = SS_TAP(X_SPACE)},          //
    {.key = B_V | B_RSHFT, .kana = ","},                //
    {.key = B_M | B_LSHFT, .kana = "."},                //

    // enter
    {.key = B_J | B_K | B_T, .kana = "/"}, // ・

    // その他
    {.key = B_J | B_K | B_F, .kana = "["},    //
    {.key = B_J | B_K | B_V, .kana = "]"},    //
    {.key = B_M | B_COMM | B_F, .kana = "{"}, //
    {.key = B_M | B_COMM | B_V, .kana = "}"}, //
    {.key = B_J | B_K | B_D, .kana = "?"},    //
    {.key = B_J | B_K | B_C, .kana = "!"},    //
    {.key = B_J | B_K | B_G, .kana = "("},    //
    {.key = B_J | B_K | B_B, .kana = ")"},    //
    {.key = B_J | B_K | B_S, .kana = "/"},    //

    // 数字
    {.key = B_COMM | B_DOT | B_A, .kana = "1"},
    {.key = B_COMM | B_DOT | B_S, .kana = "2"},
    {.key = B_COMM | B_DOT | B_D, .kana = "3"},
    {.key = B_COMM | B_DOT | B_F, .kana = "4"},
    {.key = B_COMM | B_DOT | B_G, .kana = "5"},
    {.key = B_X | B_C | B_H, .kana = "6"},
    {.key = B_X | B_C | B_J, .kana = "7"},
    {.key = B_X | B_C | B_K, .kana = "8"},
    {.key = B_X | B_C | B_L, .kana = "9"},
    {.key = B_X | B_C | B_SCLN, .kana = "0"},

    {.key = B_V | B_M, .kana = SS_LSFT(SS_TAP(X_ENTER))}, //

    {.key = B_F | B_D | B_H, .kana = SS_LCTL("i")},    //
    {.key = B_F | B_D | B_N, .kana = SS_LCTL("o")},    //
    {.key = B_F | B_D | B_J, .kana = SS_LCTL("p")},    //
    {.key = B_F | B_D | B_M, .kana = SS_LCTL("n")},    //
    {.key = B_F | B_D | B_K, .kana = SS_LCTL("f")},    //
    {.key = B_F | B_D | B_COMM, .kana = SS_LCTL("b")}, //

    {.key = B_F | B_D | B_SCLN, .kana = SS_LCTL("k")}, //
    {.key = B_F | B_D | B_SLSH, .kana = SS_LCTL("j")}, //
    {.key = B_F | B_D | B_U, .kana = SS_LCTL("a")},    //
    {.key = B_F | B_D | B_I, .kana = SS_LCTL("e")},    //
    {.key = B_F | B_D | B_O, .kana = SS_LCTL("k")},    //

    {.key = B_C | B_V | B_J, .kana = SS_LCTL("P")},    //
    {.key = B_C | B_V | B_M, .kana = SS_LCTL("N")},    //
    {.key = B_C | B_V | B_K, .kana = SS_LCTL("F")},    //
    {.key = B_C | B_V | B_COMM, .kana = SS_LCTL("B")}, //
    {.key = B_C | B_V | B_I, .kana = SS_LCTL("R")},    //
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

#undef B_LSHFT
#undef B_RSHFT
