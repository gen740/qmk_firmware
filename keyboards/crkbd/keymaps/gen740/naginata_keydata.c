#include "naginata_keydata.h"

#include "naginata.h"

const PROGMEM naginata_keymap ngmap[NAGINATA_KEYMAP_ELEMENT_NUMBER] = {
    // 清音
    {.key = B_J, .kana = "a"},               // あ
    {.key = B_K, .kana = "i"},               // い
    {.key = B_L, .kana = "u"},               // う
    {.key = B_SHFT | B_O, .kana = "e"},      // え
    {.key = B_SHFT | B_N, .kana = "o"},      // お
    {.key = B_F, .kana = "ka"},              // か
    {.key = B_W, .kana = "ki"},              // き
    {.key = B_H, .kana = "ku"},              // く
    {.key = B_S, .kana = "ke"},              // け
    {.key = B_V, .kana = "ko"},              // こ
    {.key = B_SHFT | B_U, .kana = "sa"},     // さ
    {.key = B_R, .kana = "si"},              // し
    {.key = B_O, .kana = "su"},              // す
    {.key = B_SHFT | B_A, .kana = "se"},     // せ
    {.key = B_B, .kana = "so"},              // そ
    {.key = B_N, .kana = "ta"},              // た
    {.key = B_SHFT | B_G, .kana = "ti"},     // ち
    {.key = B_SHFT | B_L, .kana = "tu"},     // つ
    {.key = B_E, .kana = "te"},              // て
    {.key = B_D, .kana = "to"},              // と
    {.key = B_M, .kana = "na"},              // な
    {.key = B_SHFT | B_D, .kana = "ni"},     // に
    {.key = B_SHFT | B_W, .kana = "nu"},     // ぬ
    {.key = B_SHFT | B_R, .kana = "ne"},     // ね
    {.key = B_SHFT | B_J, .kana = "no"},     // の
    {.key = B_C, .kana = "ha"},              // は
    {.key = B_X, .kana = "hi"},              // ひ
    {.key = B_SHFT | B_X, .kana = "hi"},     // ひ
    {.key = B_SHFT | B_SCLN, .kana = "fu"},  // ふ
    {.key = B_P, .kana = "he"},              // へ
    {.key = B_Z, .kana = "ho"},              // ほ
    {.key = B_SHFT | B_Z, .kana = "ho"},     // ほ
    {.key = B_SHFT | B_F, .kana = "ma"},     // ま
    {.key = B_SHFT | B_B, .kana = "mi"},     // み
    {.key = B_SHFT | B_COMM, .kana = "mu"},  // む
    {.key = B_SHFT | B_S, .kana = "me"},     // め
    {.key = B_SHFT | B_K, .kana = "mo"},     // も
    {.key = B_SHFT | B_H, .kana = "ya"},     // や
    {.key = B_SHFT | B_P, .kana = "yu"},     // ゆ
    {.key = B_SHFT | B_I, .kana = "yo"},     // よ
    {.key = B_DOT, .kana = "ra"},            // ら
    {.key = B_SHFT | B_E, .kana = "ri"},     // り
    {.key = B_I, .kana = "ru"},              // る
    {.key = B_SLSH, .kana = "re"},           // れ
    {.key = B_SHFT | B_SLSH, .kana = "re"},  // れ
    {.key = B_A, .kana = "ro"},              // ろ
    {.key = B_SHFT | B_DOT, .kana = "wa"},   // わ
    {.key = B_SHFT | B_C, .kana = "wo"},     // を
    {.key = B_COMM, .kana = "nn"},           // ん
    {.key = B_SCLN, .kana = "-"},            // ー

    // 濁音
    {.key = B_J | B_F, .kana = "ga"},     // が
    {.key = B_J | B_W, .kana = "gi"},     // ぎ
    {.key = B_F | B_H, .kana = "gu"},     // ぐ
    {.key = B_J | B_S, .kana = "ge"},     // げ
    {.key = B_J | B_V, .kana = "go"},     // ご
    {.key = B_F | B_U, .kana = "za"},     // ざ
    {.key = B_J | B_R, .kana = "zi"},     // じ
    {.key = B_F | B_O, .kana = "zu"},     // ず
    {.key = B_J | B_A, .kana = "ze"},     // ぜ
    {.key = B_J | B_B, .kana = "zo"},     // ぞ
    {.key = B_F | B_N, .kana = "da"},     // だ
    {.key = B_J | B_G, .kana = "di"},     // ぢ
    {.key = B_F | B_L, .kana = "du"},     // づ
    {.key = B_J | B_E, .kana = "de"},     // で
    {.key = B_J | B_D, .kana = "do"},     // ど
    {.key = B_J | B_C, .kana = "ba"},     // ば
    {.key = B_J | B_X, .kana = "bi"},     // び
    {.key = B_F | B_SCLN, .kana = "bu"},  // ぶ
    {.key = B_F | B_P, .kana = "be"},     // べ
    {.key = B_J | B_Z, .kana = "bo"},     // ぼ
    {.key = B_Q, .kana = "vu"},           // ゔ

    // 半濁音
    {.key = B_M | B_C, .kana = "pa"},     // ぱ
    {.key = B_M | B_X, .kana = "pi"},     // ぴ
    {.key = B_V | B_SCLN, .kana = "pu"},  // ぷ
    {.key = B_V | B_P, .kana = "pe"},     // ぺ
    {.key = B_M | B_Z, .kana = "po"},     // ぽ

    // 小書き
    {.key = B_Q | B_H, .kana = "xya"},  // ゃ
    // {.key = B_Q | B_SHFT | B_H,.kana = "xya"},  //ゃ
    {.key = B_Q | B_P, .kana = "xyu"},  // ゅ
    // {.key = B_Q | B_SHFT | B_P,.kana = "xyu"},  //ゅ
    {.key = B_Q | B_I, .kana = "xyo"},  // ょ
    // {.key = B_Q | B_SHFT | B_I,.kana = "xyo"},  //ょ
    {.key = B_Q | B_J, .kana = "xa"},  // ぁ
    // {.key = B_Q | B_SHFT | B_J,.kana = "xa"},   //ぁ
    {.key = B_Q | B_K, .kana = "xi"},  // ぃ
    // {.key = B_Q | B_SHFT | B_K,.kana = "xi"},   //ぃ
    {.key = B_Q | B_L, .kana = "xu"},  // ぅ
    {.key = B_Q | B_O, .kana = "xe"},  // ぇ
    // {.key = B_Q | B_SHFT | B_O,.kana = "xe"},   //ぇ
    {.key = B_Q | B_N, .kana = "xo"},  // ぉ
    // {.key = B_Q | B_SHFT | B_N,.kana = "xo"},   //ぉ
    // {.key = B_Q | B_SHFT | B_L,.kana = "xwa"},  //ゎ
    {.key = B_G, .kana = "xtu"},  // っ

    // 清音拗音 濁音拗音 半濁拗音
    {.key = B_R | B_H, .kana = "sya"},        // しゃ
    {.key = B_R | B_P, .kana = "syu"},        // しゅ
    {.key = B_R | B_I, .kana = "syo"},        // しょ
    {.key = B_J | B_R | B_H, .kana = "zya"},  // じゃ
    {.key = B_J | B_R | B_P, .kana = "zyu"},  // じゅ
    {.key = B_J | B_R | B_I, .kana = "zyo"},  // じょ
    {.key = B_W | B_H, .kana = "kya"},        // きゃ
    {.key = B_W | B_P, .kana = "kyu"},        // きゅ
    {.key = B_W | B_I, .kana = "kyo"},        // きょ
    {.key = B_J | B_W | B_H, .kana = "gya"},  // ぎゃ
    {.key = B_J | B_W | B_P, .kana = "gyu"},  // ぎゅ
    {.key = B_J | B_W | B_I, .kana = "gyo"},  // ぎょ
    {.key = B_G | B_H, .kana = "tya"},        // ちゃ
    {.key = B_G | B_P, .kana = "tyu"},        // ちゅ
    {.key = B_G | B_I, .kana = "tyo"},        // ちょ
    {.key = B_J | B_G | B_H, .kana = "dya"},  // ぢゃ
    {.key = B_J | B_G | B_P, .kana = "dyu"},  // ぢゅ
    {.key = B_J | B_G | B_I, .kana = "dyo"},  // ぢょ
    {.key = B_D | B_H, .kana = "nya"},        // にゃ
    {.key = B_D | B_P, .kana = "nyu"},        // にゅ
    {.key = B_D | B_I, .kana = "nyo"},        // にょ
    {.key = B_X | B_H, .kana = "hya"},        // ひゃ
    {.key = B_X | B_P, .kana = "hyu"},        // ひゅ
    {.key = B_X | B_I, .kana = "hyo"},        // ひょ
    {.key = B_J | B_X | B_H, .kana = "bya"},  // びゃ
    {.key = B_J | B_X | B_P, .kana = "byu"},  // びゅ
    {.key = B_J | B_X | B_I, .kana = "byo"},  // びょ
    {.key = B_M | B_X | B_H, .kana = "pya"},  // ぴゃ
    {.key = B_M | B_X | B_P, .kana = "pyu"},  // ぴゅ
    {.key = B_M | B_X | B_I, .kana = "pyo"},  // ぴょ
    {.key = B_B | B_H, .kana = "mya"},        // みゃ
    {.key = B_B | B_P, .kana = "myu"},        // みゅ
    {.key = B_B | B_I, .kana = "myo"},        // みょ
    {.key = B_E | B_H, .kana = "rya"},        // りゃ
    {.key = B_E | B_P, .kana = "ryu"},        // りゅ
    {.key = B_E | B_I, .kana = "ryo"},        // りょ

    // 清音外来音 濁音外来音
    {.key = B_M | B_E | B_K, .kana = "thi"},     // てぃ
    {.key = B_M | B_E | B_P, .kana = "thu"},     // てゅ
    {.key = B_J | B_E | B_K, .kana = "dhi"},     // でぃ
    {.key = B_J | B_E | B_P, .kana = "dhu"},     // でゅ
    {.key = B_M | B_D | B_L, .kana = "toxu"},    // とぅ
    {.key = B_J | B_D | B_L, .kana = "doxu"},    // どぅ
    {.key = B_M | B_R | B_O, .kana = "sye"},     // しぇ
    {.key = B_M | B_G | B_O, .kana = "tye"},     // ちぇ
    {.key = B_J | B_R | B_O, .kana = "zye"},     // じぇ
    {.key = B_J | B_G | B_O, .kana = "dye"},     // ぢぇ
    {.key = B_V | B_SCLN | B_J, .kana = "fa"},   // ふぁ
    {.key = B_V | B_SCLN | B_K, .kana = "fi"},   // ふぃ
    {.key = B_V | B_SCLN | B_O, .kana = "fe"},   // ふぇ
    {.key = B_V | B_SCLN | B_N, .kana = "fo"},   // ふぉ
    {.key = B_V | B_SCLN | B_P, .kana = "fyu"},  // ふゅ
    {.key = B_V | B_K | B_O, .kana = "ixe"},     // いぇ
    {.key = B_V | B_L | B_K, .kana = "wi"},      // うぃ
    {.key = B_V | B_L | B_O, .kana = "we"},      // うぇ
    {.key = B_V | B_L | B_N, .kana = "uxo"},     // うぉ
    {.key = B_F | B_L | B_J, .kana = "va"},      // ゔぁ
    {.key = B_F | B_L | B_K, .kana = "vi"},      // ゔぃ
    {.key = B_F | B_L | B_O, .kana = "ve"},      // ゔぇ
    {.key = B_F | B_L | B_N, .kana = "vo"},      // ゔぉ
    {.key = B_F | B_L | B_P, .kana = "vuxyu"},   // ゔゅ :WARN:
    {.key = B_V | B_H | B_J, .kana = "kuxa"},    // くぁ
    {.key = B_V | B_H | B_K, .kana = "kuxi"},    // くぃ
    {.key = B_V | B_H | B_O, .kana = "kuxe"},    // くぇ
    {.key = B_V | B_H | B_N, .kana = "kuxo"},    // くぉ
    {.key = B_V | B_H | B_L, .kana = "qwa"},     // くゎ
    {.key = B_F | B_H | B_J, .kana = "guxa"},    // ぐぁ
    {.key = B_F | B_H | B_K, .kana = "guxi"},    // ぐぃ
    {.key = B_F | B_H | B_O, .kana = "guxe"},    // ぐぇ
    {.key = B_F | B_H | B_N, .kana = "guxo"},    // ぐぉ
    {.key = B_F | B_H | B_L, .kana = "guxwa"},   // ぐゎ :WARN:
    {.key = B_V | B_DOT | B_J, .kana = "tsa"},   // つぁ
    {.key = B_V | B_DOT | B_K, .kana = "tsi"},   // つぃ
    {.key = B_V | B_DOT | B_O, .kana = "tse"},   // つぇ
    {.key = B_V | B_DOT | B_N, .kana = "tso"},   // つぉ

    // 追加
    {.key = B_SHFT, .kana = " "},  //
    // {.key = B_Q,         .kana = ""},                //
    {.key = B_V | B_SHFT, .kana = ","},    //
    {.key = B_M | B_SHFT, .kana = "."},    //
    {.key = B_U, .kana = SS_TAP(X_BSPC)},  //

    // enter
    {.key = B_V | B_M, .kana = SS_TAP(X_ENTER)},  //
    {.key = B_SHFT | B_V | B_M,
     .kana = SS_TAP(X_ENTER)},              // enter+シフト(連続シフト)
    {.key = B_J | B_K | B_T, .kana = "/"},  // ・

    // その他
    {.key = B_J | B_K | B_F, .kana = "["},     //
    {.key = B_J | B_K | B_V, .kana = "]"},     //
    {.key = B_M | B_COMM | B_F, .kana = "{"},  //
    {.key = B_M | B_COMM | B_V, .kana = "}"},  //
    // {.key = B_F | B_D    | B_K     ,.kana = SS_RCTL(X_O)},
    // {.key = B_F | B_D    | B_COMM  ,.kana = SS_TAP(X_DOWN)},
    {.key = B_J | B_K | B_D, .kana = "?"},  //
    {.key = B_J | B_K | B_C, .kana = "!"},  //
    {.key = B_J | B_K | B_G, .kana = "("},  //
    {.key = B_J | B_K | B_B, .kana = ")"},  //
    {.key = B_J | B_K | B_S, .kana = "/"},  //

    // 数字
    {.key = B_U | B_I | B_Q, .kana = "1"},
    {.key = B_U | B_I | B_W, .kana = "2"},
    {.key = B_U | B_I | B_E, .kana = "3"},
    {.key = B_U | B_I | B_R, .kana = "4"},
    {.key = B_U | B_I | B_T, .kana = "5"},
    {.key = B_E | B_R | B_Y, .kana = "6"},
    {.key = B_E | B_R | B_U, .kana = "7"},
    {.key = B_E | B_R | B_I, .kana = "8"},
    {.key = B_E | B_R | B_O, .kana = "9"},
    {.key = B_E | B_R | B_P, .kana = "0"},
};

const PROGMEM naginata_keymap_long
    ngmapl_mac[NAGINATA_KEYMAP_LONG_ELEMENT_NUMBER] = {
        // 編集モード Mac
        {.key = B_T, .kana = SS_TAP(X_LEFT)},                     //
        {.key = B_Y, .kana = SS_TAP(X_RIGHT)},                    //
                                                                  //
        {.key = B_C | B_COMM, .kana = SS_LSFT(SS_TAP(X_ENTER))},  //

        {.key = B_F | B_D | B_H, .kana = SS_LCTL("i")},     //
        {.key = B_F | B_D | B_N, .kana = SS_LCTL("o")},     //
        {.key = B_F | B_D | B_J, .kana = SS_LCTL("p")},     //
        {.key = B_F | B_D | B_M, .kana = SS_LCTL("n")},     //
        {.key = B_F | B_D | B_K, .kana = SS_LCTL("f")},     //
        {.key = B_F | B_D | B_COMM, .kana = SS_LCTL("b")},  //

        {.key = B_F | B_D | B_SCLN, .kana = SS_LCTL("k")},  //
        {.key = B_F | B_D | B_SLSH, .kana = SS_LCTL("j")},  //
        {.key = B_F | B_D | B_U, .kana = SS_LCTL("a")},     //
        {.key = B_F | B_D | B_I, .kana = SS_LCTL("e")},     //
        {.key = B_F | B_D | B_O, .kana = SS_LCTL("k")},     //

        // {.key = B_C | B_V | B_H,   .kana = SS_LCTL("i")},     //
        // {.key = B_C | B_V | B_N,   .kana = SS_LCTL("o")},     //
        {.key = B_C | B_V | B_J, .kana = SS_LCTL("P")},     //
        {.key = B_C | B_V | B_M, .kana = SS_LCTL("N")},     //
        {.key = B_C | B_V | B_K, .kana = SS_LCTL("F")},     //
        {.key = B_C | B_V | B_COMM, .kana = SS_LCTL("B")},  //
        {.key = B_C | B_V | B_I, .kana = SS_LCTL("R")},     //
        // {.key = B_F | B_D | B_N,   .kana = SS_LCTL("o")},     //
        // {.key = B_F | B_D | B_N,   .kana = SS_LCTL("o")},     //
};
