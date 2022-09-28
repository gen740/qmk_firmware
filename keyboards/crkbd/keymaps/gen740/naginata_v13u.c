#include QMK_KEYBOARD_H
#include "naginata.h"

#define NGBUFFER 10  // キー入力バッファのサイズ

// #define NGUP X_F21
// #define NGDN X_F22
// #define NGLT X_F23
// #define NGRT X_F24

static uint8_t  ng_chrcount    = 0;      // 文字キー入力のカウンタ
static bool     is_naginata    = false;  // 薙刀式がオンかオフか
static uint8_t  naginata_layer = 0;      // NG_*を配置しているレイヤー番号
static uint32_t keycomb        = 0UL;    // 同時押しの状態を示す。32bitの各ビットがキーに対応する。

#define B_Q (1UL << 0)  //
#define B_W (1UL << 1)  //
#define B_E (1UL << 2)  //
#define B_R (1UL << 3)  //
#define B_T (1UL << 4)  //

#define B_Y (1UL << 5)  //
#define B_U (1UL << 6)  //
#define B_I (1UL << 7)  //
#define B_O (1UL << 8)  //
#define B_P (1UL << 9)  //

#define B_A (1UL << 10)  //
#define B_S (1UL << 11)  //
#define B_D (1UL << 12)  //
#define B_F (1UL << 13)  //
#define B_G (1UL << 14)  //

#define B_H (1UL << 15)     //
#define B_J (1UL << 16)     //
#define B_K (1UL << 17)     //
#define B_L (1UL << 18)     //
#define B_SCLN (1UL << 19)  //

#define B_Z (1UL << 20)  //
#define B_X (1UL << 21)  //
#define B_C (1UL << 22)  //
#define B_V (1UL << 23)  //
#define B_B (1UL << 24)  //

#define B_N (1UL << 25)     //
#define B_M (1UL << 26)     //
#define B_COMM (1UL << 27)  //
#define B_DOT (1UL << 28)   //
#define B_SLSH (1UL << 29)  //

#define B_SHFT (1UL << 30)  //

// 文字入力バッファ
static uint16_t ninputs[NGBUFFER];  //

// キーコードとキービットの対応
// メモリ削減のため配列はNG_Qを0にしている
// clang-format off
const uint32_t ng_key[] = {
    [NG_Q - NG_Q]     = B_Q,
    [NG_W - NG_Q]     = B_W,
    [NG_E - NG_Q]     = B_E,
    [NG_R - NG_Q]     = B_R,
    [NG_T - NG_Q]     = B_T,
    [NG_Y - NG_Q]     = B_Y,
    [NG_U - NG_Q]     = B_U,
    [NG_I - NG_Q]     = B_I,
    [NG_O - NG_Q]     = B_O,
    [NG_P - NG_Q]     = B_P,
    [NG_A - NG_Q]     = B_A,
    [NG_S - NG_Q]     = B_S,
    [NG_D - NG_Q]     = B_D,
    [NG_F - NG_Q]     = B_F,
    [NG_G - NG_Q]     = B_G,
    [NG_H - NG_Q]     = B_H,
    [NG_J - NG_Q]     = B_J,
    [NG_K - NG_Q]     = B_K,
    [NG_L - NG_Q]     = B_L,
    [NG_SCLN - NG_Q]  = B_SCLN,
    [NG_Z - NG_Q]     = B_Z,
    [NG_X - NG_Q]     = B_X,
    [NG_C - NG_Q]     = B_C,
    [NG_V - NG_Q]     = B_V,
    [NG_B - NG_Q]     = B_B,
    [NG_N - NG_Q]     = B_N,
    [NG_M - NG_Q]     = B_M,
    [NG_COMM - NG_Q]  = B_COMM,
    [NG_DOT - NG_Q]   = B_DOT,
    [NG_SLSH - NG_Q]  = B_SLSH,
    [NG_SHFT - NG_Q]  = B_SHFT,
    [NG_SHFT2 - NG_Q] = B_SHFT,
};
// clang-format on

// カナ変換テーブル //
typedef struct {
    uint32_t key;
    char     kana[5];
} naginata_keymap;

// ロング
typedef struct {
    uint32_t key;
    char     kana[13];
} naginata_keymap_long;

// clang-format off
const PROGMEM naginata_keymap ngmap[] = {
    // 清音
    {.key = B_J,            .kana = "a"},   //あ
    {.key = B_K,            .kana = "i"},   //い
    {.key = B_L,            .kana = "u"},   //う
    {.key = B_SHFT | B_O,   .kana = "e"},   //え
    {.key = B_SHFT | B_N,   .kana = "o"},   //お
    {.key = B_F,            .kana = "ka"},  //か
    {.key = B_W,            .kana = "ki"},  //き
    {.key = B_H,            .kana = "ku"},  //く
    {.key = B_S,            .kana = "ke"},  //け
    {.key = B_V,            .kana = "ko"},  //こ
    {.key = B_SHFT | B_U,   .kana = "sa"},  //さ
    {.key = B_R,            .kana = "si"},  //し
    {.key = B_O,            .kana = "su"},  //す
    {.key = B_SHFT | B_A,   .kana = "se"},  //せ
    {.key = B_B,            .kana = "so"},  //そ
    {.key = B_N,            .kana = "ta"},  //た
    {.key = B_SHFT | B_G,   .kana = "ti"},  //ち
    {.key = B_SHFT | B_SCLN,.kana = "tu"},  //つ
    {.key = B_E,            .kana = "te"},  //て
    {.key = B_D,            .kana = "to"},  //と
    {.key = B_M,            .kana = "na"},  //な
    {.key = B_SHFT | B_D,   .kana = "ni"},  //に
    {.key = B_SHFT | B_R,   .kana = "nu"},  //ぬ
    {.key = B_SHFT | B_COMM,.kana = "ne"},  //ね
    {.key = B_SHFT | B_J,   .kana = "no"},  //の
    {.key = B_C,            .kana = "ha"},  //は
    {.key = B_X,            .kana = "hi"},  //ひ
    {.key = B_SHFT | B_X,   .kana = "hi"},  //ひ
    {.key = B_SHFT | B_DOT, .kana = "hu"},  //ふ
    {.key = B_P,            .kana = "he"},  //へ
    {.key = B_Z,            .kana = "ho"},  //ほ
    {.key = B_SHFT | B_Z,   .kana = "ho"},  //ほ
    {.key = B_SHFT | B_F,   .kana = "ma"},  //ま
    {.key = B_SHFT | B_B,   .kana = "mi"},  //み
    {.key = B_SHFT | B_W,   .kana = "mu"},  //む
    {.key = B_SHFT | B_S,   .kana = "me"},  //め
    {.key = B_SHFT | B_K,   .kana = "mo"},  //も
    {.key = B_SHFT | B_H,   .kana = "ya"},  //や
    {.key = B_SHFT | B_P,   .kana = "yu"},  //ゆ
    {.key = B_SHFT | B_I,   .kana = "yo"},  //よ
    {.key = B_DOT,          .kana = "ra"},  //ら
    {.key = B_SHFT | B_E,   .kana = "ri"},  //り
    {.key = B_I,            .kana = "ru"},  //る
    {.key = B_SLSH,         .kana = "re"},  //れ
    {.key = B_SHFT | B_SLSH,.kana = "re"},  //れ
    {.key = B_A,            .kana = "ro"},  //ろ
    {.key = B_SHFT | B_L,   .kana = "wa"},  //わ
    {.key = B_SHFT | B_C,   .kana = "wo"},  //を
    {.key = B_COMM,         .kana = "nn"},  //ん
    {.key = B_SCLN,         .kana = "-"},   //ー

    //濁音
    {.key = B_J | B_F,   .kana = "ga"},  //が
    {.key = B_J | B_W,   .kana = "gi"},  //ぎ
    {.key = B_F | B_H,   .kana = "gu"},  //ぐ
    {.key = B_J | B_S,   .kana = "ge"},  //げ
    {.key = B_J | B_V,   .kana = "go"},  //ご
    {.key = B_F | B_U,   .kana = "za"},  //ざ
    {.key = B_J | B_R,   .kana = "zi"},  //じ
    {.key = B_F | B_O,   .kana = "zu"},  //ず
    {.key = B_J | B_A,   .kana = "ze"},  //ぜ
    {.key = B_J | B_B,   .kana = "zo"},  //ぞ
    {.key = B_F | B_N,   .kana = "da"},  //だ
    {.key = B_J | B_G,   .kana = "di"},  //ぢ
    {.key = B_F | B_SCLN,.kana = "du"},  //づ
    {.key = B_J | B_E,   .kana = "de"},  //で
    {.key = B_J | B_D,   .kana = "do"},  //ど
    {.key = B_J | B_C,   .kana = "ba"},  //ば
    {.key = B_J | B_X,   .kana = "bi"},  //び
    {.key = B_F | B_DOT, .kana = "bu"},  //ぶ
    {.key = B_F | B_P,   .kana = "be"},  //べ
    {.key = B_J | B_Z,   .kana = "bo"},  //ぼ
    {.key = B_F | B_L,   .kana = "vu"},  //ゔ

    //半濁音
    {.key = B_M | B_C,  .kana = "pa"},  //ぱ
    {.key = B_M | B_X,  .kana = "pi"},  //ぴ
    {.key = B_V | B_DOT,.kana = "pu"},  //ぷ
    {.key = B_V | B_P,  .kana = "pe"},  //ぺ
    {.key = B_M | B_Z,  .kana = "po"},  //ぽ

    //小書き
    {.key = B_Q | B_H,         .kana = "xya"},  //ゃ
    // {.key = B_Q | B_SHFT | B_H,.kana = "xya"},  //ゃ
    {.key = B_Q | B_P,         .kana = "xyu"},  //ゅ
    // {.key = B_Q | B_SHFT | B_P,.kana = "xyu"},  //ゅ
    {.key = B_Q | B_I,         .kana = "xyo"},  //ょ
    // {.key = B_Q | B_SHFT | B_I,.kana = "xyo"},  //ょ
    {.key = B_Q | B_J,         .kana = "xa"},   //ぁ
    // {.key = B_Q | B_SHFT | B_J,.kana = "xa"},   //ぁ
    {.key = B_Q | B_K,         .kana = "xi"},   //ぃ
    // {.key = B_Q | B_SHFT | B_K,.kana = "xi"},   //ぃ
    {.key = B_Q | B_L,         .kana = "xu"},   //ぅ
    {.key = B_Q | B_O,         .kana = "xe"},   //ぇ
    // {.key = B_Q | B_SHFT | B_O,.kana = "xe"},   //ぇ
    {.key = B_Q | B_N,         .kana = "xo"},   //ぉ
    // {.key = B_Q | B_SHFT | B_N,.kana = "xo"},   //ぉ
    // {.key = B_Q | B_SHFT | B_L,.kana = "xwa"},  //ゎ
    {.key = B_G,               .kana = "xtu"},  //っ

    //清音拗音 濁音拗音 半濁拗音
    {.key = B_R | B_H,      .kana = "sya"},  //しゃ
    {.key = B_R | B_P,      .kana = "syu"},  //しゅ
    {.key = B_R | B_I,      .kana = "syo"},  //しょ
    {.key = B_J | B_R | B_H,.kana = "zya"},  //じゃ
    {.key = B_J | B_R | B_P,.kana = "zyu"},  //じゅ
    {.key = B_J | B_R | B_I,.kana = "zyo"},  //じょ
    {.key = B_W | B_H,      .kana = "kya"},  //きゃ
    {.key = B_W | B_P,      .kana = "kyu"},  //きゅ
    {.key = B_W | B_I,      .kana = "kyo"},  //きょ
    {.key = B_J | B_W | B_H,.kana = "gya"},  //ぎゃ
    {.key = B_J | B_W | B_P,.kana = "gyu"},  //ぎゅ
    {.key = B_J | B_W | B_I,.kana = "gyo"},  //ぎょ
    {.key = B_G | B_H,      .kana = "tya"},  //ちゃ
    {.key = B_G | B_P,      .kana = "tyu"},  //ちゅ
    {.key = B_G | B_I,      .kana = "tyo"},  //ちょ
    {.key = B_J | B_G | B_H,.kana = "dya"},  //ぢゃ
    {.key = B_J | B_G | B_P,.kana = "dyu"},  //ぢゅ
    {.key = B_J | B_G | B_I,.kana = "dyo"},  //ぢょ
    {.key = B_D | B_H,      .kana = "nya"},  //にゃ
    {.key = B_D | B_P,      .kana = "nyu"},  //にゅ
    {.key = B_D | B_I,      .kana = "nyo"},  //にょ
    {.key = B_X | B_H,      .kana = "hya"},  //ひゃ
    {.key = B_X | B_P,      .kana = "hyu"},  //ひゅ
    {.key = B_X | B_I,      .kana = "hyo"},  //ひょ
    {.key = B_J | B_X | B_H,.kana = "bya"},  //びゃ
    {.key = B_J | B_X | B_P,.kana = "byu"},  //びゅ
    {.key = B_J | B_X | B_I,.kana = "byo"},  //びょ
    {.key = B_M | B_X | B_H,.kana = "pya"},  //ぴゃ
    {.key = B_M | B_X | B_P,.kana = "pyu"},  //ぴゅ
    {.key = B_M | B_X | B_I,.kana = "pyo"},  //ぴょ
    {.key = B_B | B_H,      .kana = "mya"},  //みゃ
    {.key = B_B | B_P,      .kana = "myu"},  //みゅ
    {.key = B_B | B_I,      .kana = "myo"},  //みょ
    {.key = B_E | B_H,      .kana = "rya"},  //りゃ
    {.key = B_E | B_P,      .kana = "ryu"},  //りゅ
    {.key = B_E | B_I,      .kana = "ryo"},  //りょ

    //清音外来音 濁音外来音
    {.key = B_M | B_E    | B_K,.kana = "thi"},    //てぃ
    {.key = B_M | B_E    | B_P,.kana = "thu"},    //てゅ
    {.key = B_J | B_E    | B_K,.kana = "dhi"},    //でぃ
    {.key = B_J | B_E    | B_P,.kana = "dhu"},    //でゅ
    {.key = B_M | B_D    | B_L,.kana = "toxu"},   //とぅ
    {.key = B_J | B_D    | B_L,.kana = "doxu"},   //どぅ
    {.key = B_M | B_R    | B_O,.kana = "sye"},    //しぇ
    {.key = B_M | B_G    | B_O,.kana = "tye"},    //ちぇ
    {.key = B_J | B_R    | B_O,.kana = "zye"},    //じぇ
    {.key = B_J | B_G    | B_O,.kana = "dye"},    //ぢぇ
    {.key = B_V | B_DOT  | B_J,.kana = "fa"},     //ふぁ
    {.key = B_V | B_DOT  | B_K,.kana = "fi"},     //ふぃ
    {.key = B_V | B_DOT  | B_O,.kana = "fe"},     //ふぇ
    {.key = B_V | B_DOT  | B_N,.kana = "fo"},     //ふぉ
    {.key = B_V | B_DOT  | B_P,.kana = "fyu"},    //ふゅ
    {.key = B_V | B_K    | B_O,.kana = "ixe"},    //いぇ
    {.key = B_V | B_L    | B_K,.kana = "wi"},     //うぃ
    {.key = B_V | B_L    | B_O,.kana = "we"},     //うぇ
    {.key = B_V | B_L    | B_N,.kana = "uxo"},    //うぉ
    {.key = B_F | B_L    | B_J,.kana = "va"},     //ゔぁ
    {.key = B_F | B_L    | B_K,.kana = "vi"},     //ゔぃ
    {.key = B_F | B_L    | B_O,.kana = "ve"},     //ゔぇ
    {.key = B_F | B_L    | B_N,.kana = "vo"},     //ゔぉ
    {.key = B_F | B_L    | B_P,.kana = "vuxyu"},  //ゔゅ :WARN:
    {.key = B_V | B_H    | B_J,.kana = "kuxa"},   //くぁ
    {.key = B_V | B_H    | B_K,.kana = "kuxi"},   //くぃ
    {.key = B_V | B_H    | B_O,.kana = "kuxe"},   //くぇ
    {.key = B_V | B_H    | B_N,.kana = "kuxo"},   //くぉ
    {.key = B_V | B_H    | B_L,.kana = "qwa"},    //くゎ
    {.key = B_F | B_H    | B_J,.kana = "guxa"},   //ぐぁ
    {.key = B_F | B_H    | B_K,.kana = "guxi"},   //ぐぃ
    {.key = B_F | B_H    | B_O,.kana = "guxe"},   //ぐぇ
    {.key = B_F | B_H    | B_N,.kana = "guxo"},   //ぐぉ
    {.key = B_F | B_H    | B_L,.kana = "guxwa"},  //ぐゎ :WARN:
    {.key = B_V | B_SCLN | B_J,.kana = "tsa"},    //つぁ
    {.key = B_V | B_SCLN | B_K,.kana = "tsi"},    //つぃ
    {.key = B_V | B_SCLN | B_O,.kana = "tse"},    //つぇ
    {.key = B_V | B_SCLN | B_N,.kana = "tso"},    //つぉ

    //追加
    {.key = B_SHFT,      .kana = " "},               //
    // {.key = B_Q,         .kana = ""},                //
    {.key = B_V | B_SHFT,.kana = ","},               //
    {.key = B_M | B_SHFT,.kana = "."},               //
    {.key = B_U,         .kana = SS_TAP(X_BSPACE)},  //

    //enter
    {.key = B_V    | B_M,      .kana = SS_TAP(X_ENTER)},  //
    {.key = B_SHFT | B_V | B_M,.kana = SS_TAP(X_ENTER)},  // enter+シフト(連続シフト)
    {.key = B_J    | B_K | B_T,.kana = "/"},              //・

    //その他
    {.key = B_J | B_K    | B_F,     .kana = "["},              //
    {.key = B_J | B_K    | B_V,     .kana = "]"},              //
    {.key = B_M | B_COMM | B_F,     .kana = "{"},              //
    {.key = B_M | B_COMM | B_V,     .kana = "}"},              //
    // {.key = B_F | B_D    | B_K     ,.kana = SS_RCTL(X_O)},
    // {.key = B_F | B_D    | B_COMM  ,.kana = SS_TAP(X_DOWN)},
    {.key = B_J | B_K    | B_D,     .kana = "?"},              //
    {.key = B_J | B_K    | B_C,     .kana = "!"},              //
    {.key = B_J | B_K    | B_G,     .kana = "("},              //
    {.key = B_J | B_K    | B_B,     .kana = ")"},              //
    {.key = B_J | B_K    | B_S,     .kana = "/"},              //

    // かな
};


const PROGMEM naginata_keymap_long ngmapl_mac[] = {
    // 編集モード Mac
    {.key = B_T,                    .kana = SS_LCTL("b")},   //
    {.key = B_Y,                    .kana = SS_LCTL("f")},  //

    {.key = B_F | B_D | B_H,   .kana = SS_LCTL("i")},     //
    {.key = B_F | B_D | B_N,   .kana = SS_LCTL("o")},     //
    {.key = B_F | B_D | B_J,   .kana = SS_LCTL("p")},   //
    {.key = B_F | B_D | B_M,   .kana = SS_LCTL("n")},  //
    {.key = B_F | B_D | B_K,   .kana = SS_LCTL("f")},     //
    {.key = B_F | B_D | B_COMM,.kana = SS_LCTL("b")},   //
    {.key = B_F | B_D | B_L,   .kana = SS_LCTL(SS_LALT("f"))},   //
    {.key = B_F | B_D | B_DOT, .kana = SS_LCTL(SS_LALT("b"))},  //
    {.key = B_F | B_D | B_SCLN,.kana = SS_LCTL("k")},     //
    {.key = B_F | B_D | B_SLSH,.kana = SS_LCTL("j")},     //
    {.key = B_F | B_D | B_U,   .kana = SS_LCTL("a")},     //
    {.key = B_F | B_D | B_I,   .kana = SS_LCTL("e")},     //
    {.key = B_F | B_D | B_O,   .kana = SS_LCTL("k")},     //

    {.key = B_U | B_I | B_Q,.kana = "1"},    //つぉ
    {.key = B_U | B_I | B_W,.kana = "2"},    //つぉ
    {.key = B_U | B_I | B_E,.kana = "3"},    //つぉ
    {.key = B_U | B_I | B_R,.kana = "4"},    //つぉ
    {.key = B_U | B_I | B_T,.kana = "5"},    //つぉ
    {.key = B_E | B_R | B_Y,.kana = "6"},    //つぉ
    {.key = B_E | B_R | B_U,.kana = "7"},    //つぉ
    {.key = B_E | B_R | B_I,.kana = "8"},    //つぉ
    {.key = B_E | B_R | B_O,.kana = "9"},    //つぉ
    {.key = B_E | B_R | B_P,.kana = "0"},    //つぉ

    // {.key = B_C | B_V | B_H,   .kana = SS_LCTL("i")},     //
    // {.key = B_C | B_V | B_N,   .kana = SS_LCTL("o")},     //
    {.key = B_C | B_V | B_J,   .kana = SS_LCTL("P")},   //
    {.key = B_C | B_V | B_M,   .kana = SS_LCTL("N")},  //
    {.key = B_C | B_V | B_K,   .kana = SS_LCTL("F")},     //
    {.key = B_C | B_V | B_COMM,.kana = SS_LCTL("B")},   //
    {.key = B_C | B_V | B_I,   .kana = SS_LCTL("R")},     //
    // {.key = B_F | B_D | B_N,   .kana = SS_LCTL("o")},     //
    // {.key = B_F | B_D | B_N,   .kana = SS_LCTL("o")},     //

};

// clang-format on
// バッファから先頭n文字を削除する
void compress_buffer(int n) {
    if (ng_chrcount == 0) return;
    for (int j = 0; j < NGBUFFER; j++) {
        if (j + n < NGBUFFER) {
            ninputs[j] = ninputs[j + n];
        } else {
            ninputs[j] = 0;
        }
    }
    ng_chrcount -= n;
}

// modifierが押されたら薙刀式レイヤーをオフしてベースレイヤーに戻す
// get_mods()がうまく動かない
static int n_modifier = 0;

// バッファをクリアする
void naginata_clear(void) {
    for (int i = 0; i < NGBUFFER; i++) {
        ninputs[i] = 0;
    }
    ng_chrcount = 0;
    n_modifier  = 0;
}

// 薙刀式の入力処理
bool process_naginata(uint16_t keycode, keyrecord_t *record) {
    // まれに薙刀モードオンのまま、レイヤーがオフになることがあるので、対策
    if (n_modifier == 0 && is_naginata && !layer_state_is(naginata_layer)) layer_on(naginata_layer);
    if (n_modifier == 0 && !is_naginata && layer_state_is(naginata_layer)) layer_off(naginata_layer);
    if (n_modifier > 0 && layer_state_is(naginata_layer)) layer_off(naginata_layer);

    if (record->event.pressed) {
        switch (keycode) {
            case NG_SHFT ... NG_SHFT2:
#if NON_NAGINATA_COUCHI
                if (ng_chrcount >= 1) {
                    naginata_type();
                    keycomb = 0UL;
                }
                ninputs[ng_chrcount] = keycode;  // キー入力をバッファに貯める
                ng_chrcount++;
                keycomb |= ng_key[keycode - NG_Q];  // キーの重ね合わせ
                return false;
                break;
#endif
            case NG_Q ... NG_SLSH:
                ninputs[ng_chrcount] = keycode;  // キー入力をバッファに貯める
                ng_chrcount++;
                keycomb |= ng_key[keycode - NG_Q];  // キーの重ね合わせ
                // バッファが一杯になったら処理を開始
                if (ng_chrcount >= NGBUFFER) {
                    naginata_type();
                }
                return false;
                break;
        }
    } else {  // key release
        switch (keycode) {
            case NG_Q ... NG_SHFT2:
                // どれかキーを離したら処理を開始する
                keycomb &= ~ng_key[keycode - NG_Q];  // キーの重ね合わせ
                if (ng_chrcount > 0) {
                    naginata_type();
                }
                return false;
                break;
        }
    }
    return true;
}

// キー入力を文字に変換して出力する
void naginata_type(void) {
    // バッファの最初からnt文字目までを検索キーにする。
    // 一致する組み合わせがなければntを減らして=最後の1文字を除いて再度検索する。
    int nt = ng_chrcount;

    while (nt > 0) {
        if (naginata_lookup(nt, true)) return;   // 連続シフト有効で探す
        if (naginata_lookup(nt, false)) return;  // 連続シフト無効で探す
        nt--;                                    // 最後の1キーを除いて、もう一度仮名テーブルを検索する
    }
    compress_buffer(1);
}

// バッファの頭からnt文字の範囲を検索キーにしてテーブル検索し、文字に変換して出力する
// 検索に成功したらtrue、失敗したらfalseを返す
bool naginata_lookup(int nt, bool shifted) {
    naginata_keymap      bngmap;  // PROGMEM buffer
    naginata_keymap_long bngmapl;

    // keycomb_bufはバッファ内のキーの組み合わせ、keycombはリリースしたキーを含んでいない
    uint32_t keycomb_buf = 0UL;

    // バッファ内のキーを組み合わせる
    for (int i = 0; i < nt; i++) {
        keycomb_buf |= ng_key[ninputs[i] - NG_Q];
    }

    // NG_SHFT2はスペースの代わりにエンターを入力する
    if (keycomb_buf == B_SHFT && ninputs[0] == NG_SHFT2) {
        tap_code(KC_ENT);
        compress_buffer(nt);
        return true;
    }

    if (shifted) {
        // 連続シフトを有効にする
        if ((keycomb & B_SHFT) == B_SHFT) keycomb_buf |= B_SHFT;

        /* // 編集モードを連続する */
        if ((keycomb & (B_D | B_F)) == (B_D | B_F)) keycomb_buf |= (B_D | B_F);
        if ((keycomb & (B_C | B_V)) == (B_C | B_V)) keycomb_buf |= (B_C | B_V);
        if ((keycomb & (B_J | B_K)) == (B_J | B_K)) keycomb_buf |= (B_J | B_K);
        if ((keycomb & (B_M | B_COMM)) == (B_M | B_COMM)) keycomb_buf |= (B_M | B_COMM);
        if ((keycomb & (B_E | B_R)) == (B_E | B_R)) keycomb_buf |= (B_E | B_R);
        if ((keycomb & (B_U | B_I)) == (B_U | B_I)) keycomb_buf |= (B_U | B_I);

        // 濁音、半濁音を連続する
        if ((keycomb & B_F) == B_F) keycomb_buf |= B_F;
        if ((keycomb & B_J) == B_J) keycomb_buf |= B_J;
        if ((keycomb & B_V) == B_V) keycomb_buf |= B_V;
        if ((keycomb & B_M) == B_M) keycomb_buf |= B_M;
    }

    switch (keycomb_buf) {
        case B_H | B_J:
            naginata_clear();
            return true;
            break;
        default:
            for (int i = 0; i < sizeof ngmap / sizeof bngmap; i++) {
                memcpy_P(&bngmap, &ngmap[i], sizeof(bngmap));
                if (keycomb_buf == bngmap.key) {
                    send_string(bngmap.kana);
                    compress_buffer(nt);
                    return true;
                }
            }
            for (int i = 0; i < sizeof ngmapl_mac / sizeof bngmapl; i++) {
                memcpy_P(&bngmapl, &ngmapl_mac[i], sizeof(bngmapl));
                if (keycomb_buf == bngmapl.key) {
                    send_string(bngmapl.kana);
                    compress_buffer(nt);
                    return true;
                }
            }
    }
    return false;
}

// vim:set sw=4 ts=4 sts=4:
