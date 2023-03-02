#include "gen740.h"
#include "naginata.h"

typedef union {
  uint32_t pr_counter;
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) { //
  user_config.pr_counter = eeconfig_read_user();
}

// clang-format off

#define KC_C_BS CTL_T(KC_BSPC)
#define KC_M_ENT LT(L_MODIFIER, KC_ENT)

#define RAISE MO(L_RAISE)
#define LOWER OSL(L_MEH)
#define ADJUST MO(L_ADJUST)

#define KC_S_TAB SFT_T(KC_TAB)
#define KC_S_RBRC SFT_T(KC_RBRC)
#define KK_VOLU A(S(KC_VOLU))
#define KK_VOLD A(S(KC_VOLD))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_DVORAK] =
/*  1 ━━━━━━━ 2 ━━━━━━ 3 ━━━━━━ 4 ━━━━━━ 5 ━━━━━━━━━━━━ 6 ━━━━━━━┳━━━ 7 ━━━━━━━ 8 ━━━━━ 9 ━━━━━━ 10 ━━━ 11 ━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   QK_GESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,          KC_Y,   /*┃*/ KC_F,     KC_G,   KC_C,    KC_R,  KC_L,      KC_LBRC,    //┃
   KC_S_TAB, KC_A,    KC_O,    KC_E,    KC_U,          KC_I,   /*┃*/ KC_D,     KC_H,   KC_T,    KC_N,  KC_S,      KC_S_RBRC,  //┃
   KC_SLSH,  KC_SCLN, KC_Q,    KC_J,    KC_K,          KC_X,   /*┃*/ KC_B,     KC_M,   KC_W,    KC_V,  KC_Z,      KC_MINS,    //┃
                               KC_LALT, KC_C_BS,       KC_SPC, /*┃*/ KC_M_ENT, RAISE,  KC_RGUI                                //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */ ),

    [L_NAGINATA] =
/*  1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   NAG_ESC,    NG_Q,       NG_W,       NG_E,       NG_R,       NG_T,       /*┃*/   NG_Y,       NG_U,       NG_I,       NG_O,       NG_P,       _______    ,//┃
   _______,    NG_A,       NG_S,       NG_D,       NG_F,       NG_G,       /*┃*/   NG_H,       NG_J,       NG_K,       NG_L,       NG_SCLN,    _______    ,//┃
   RAISE,      NG_Z,       NG_X,       NG_C,       NG_V,       NG_B,       /*┃*/   NG_N,       NG_M,       NG_COMM,    NG_DOT,     NG_SLSH,    RAISE      ,//┃
                                       S(KC_SPC),  NG_SHFT,    _______,    /*┃*/   KC_ENT,     NG_SHFT,    KC_RGUI                                         //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */ ),

    [L_RAISE] =
/*  1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   _______,    KC_CIRC,    KC_PERC,    KC_PLUS,    KC_LPRN,    KC_HASH,    /*┃*/   KC_EQL,     KC_RPRN,    KC_ASTR,    KC_DLR,     KC_EXLM,    _______    ,//┃
   KC_BSLS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       /*┃*/   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_GRV     ,//┃
   _______,    _______,    _______,    KC_AMPR,    KC_LCBR,    _______,    /*┃*/   _______,    KC_RCBR,    KC_AT,      KC_PIPE,    _______,    _______    ,//┃
                                       _______,    _______,    ADJUST,     /*┃*/   _______,    _______,    _______                                         //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */),

    [L_ADJUST] =
/*  1 ━━━━━━━━━ 2 ━━━━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   KC_F1,      KC_F2,         KC_F3,      KC_F4,      KC_F5,      KC_F6,      /*┃*/   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F11     ,//┃
   RGB_TOG,    DF(L_BLENDER), _______,    _______,    _______,    _______,    /*┃*/   _______,    _______,    _______,    RGB_HUD,    RGB_HUD,    RGB_SAI    ,//┃
   RGB_MOD,    _______,       _______,    KC_BRID,    KC_BRIU,    SV_COUNT,   /*┃*/   RST_COUNT,  _______,    _______,    _______,    RGB_SPD,    RGB_SPI    ,//┃
                                          HF_RST,     _______,    _______,    /*┃*/   _______,    _______,    _______                                         //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */ ),

    [L_MODIFIER] =
/*  1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   _______,    _______,    KC_MPRV,    KC_MPLY,    KC_MNXT,    _______,    /*┃*/   _______,    _______,    KC_UP,      _______,    LAG(KC_UP),   G(KC_PLUS) ,//┃
   _______,    KK_VOLD,    KC_VOLD,    KC_MUTE,    KC_VOLU,    KK_VOLU,    /*┃*/   LOWER,      KC_LEFT,    KC_DOWN,    KC_RGHT,    LAG(KC_DOWN), G(KC_0)    ,//┃
   _______,    _______,    _______,    _______,    _______,    _______,    /*┃*/   _______,    _______,    _______,      _______,    _______,    G(KC_MINS) ,//┃
                                       _______,    _______,    _______,    /*┃*/   _______,    _______,    _______                                           //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */ ),

    [L_MEH] =
/*  1 ━━━━━━━━━━━ 2 ━━━━━━━━━━━ 3 ━━━━━━━━━━━ 4 ━━━━━━━━━━━ 5 ━━━━━━━━━━━ 6 ━━━━━━━━━━━━━┳━━━━━━━ 7 ━━━━━━━━━━ 8 ━━━━━━━━ 9 ━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━ 12 ━━━━━━━━━━━━┓ */ LAYOUT(
   MEH(KC_ESC),  MEH(KC_QUOT), MEH(KC_COMM), MEH(KC_DOT),  MEH(KC_P),    MEH(KC_Y),    /*┃*/     MEH(KC_F),   MEH(KC_G), MEH(KC_C), MEH(KC_R),  MEH(KC_L), MEH(KC_LBRC), //┃
   MEH(KC_TAB),  MEH(KC_A),    MEH(KC_O),    MEH(KC_E),    MEH(KC_U),    MEH(KC_I),    /*┃*/     MEH(KC_D),   MEH(KC_H), MEH(KC_T), MEH(KC_N),  MEH(KC_S), MEH(KC_RBRC), //┃
   MEH(KC_SLSH), MEH(KC_SCLN), MEH(KC_Q),    MEH(KC_J),    MEH(KC_K),    MEH(KC_X),    /*┃*/     MEH(KC_B),   MEH(KC_M), MEH(KC_W), MEH(KC_V),  MEH(KC_Z), MEH(KC_MINS), //┃
                                             _______,      MEH(KC_BSPC), MEH(KC_SPACE),/*┃*/     MEH(KC_ENT), _______,   _______                                         //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */),

    [L_HYPER] =
/*  1 ━━━━━━━━━━━━ 2 ━━━━━━━━━━━━ 3 ━━━━━━━━━━━━ 4 ━━━━━━━━━━━━ 5 ━━━━━━━━━━━━ 6 ━━━━━━━━━━━━━━┳━━━━━━━ 7 ━━━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━━━━┓ */ LAYOUT(
   HYPR(KC_ESC),  HYPR(KC_QUOT), HYPR(KC_Z),    HYPR(KC_DOT),  HYPR(KC_P),    HYPR(KC_Y),    /*┃*/     HYPR(KC_F),   HYPR(KC_G), HYPR(KC_C), HYPR(KC_R),  HYPR(KC_L), HYPR(KC_LBRC), //┃
   HYPR(KC_TAB),  HYPR(KC_A),    HYPR(KC_O),    HYPR(KC_E),    HYPR(KC_U),    HYPR(KC_I),    /*┃*/     HYPR(KC_D),   HYPR(KC_H), HYPR(KC_T), HYPR(KC_N),  HYPR(KC_S), HYPR(KC_RBRC), //┃
   HYPR(KC_SLSH), HYPR(KC_SCLN), HYPR(KC_Q),    HYPR(KC_J),    HYPR(KC_K),    HYPR(KC_X),    /*┃*/     HYPR(KC_B),   HYPR(KC_M), HYPR(KC_W), HYPR(KC_V),  HYPR(KC_Z), HYPR(KC_MINS), //┃
                                                 _______,      HYPR(KC_BSPC), HYPR(KC_SPACE),/*┃*/     HYPR(KC_ENT), _______,   _______                                              //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */),

    [L_LCAG] =
/*  1 ━━━━━━━━━━━━ 2 ━━━━━━━━━━━━ 3 ━━━━━━━━━━━━ 4 ━━━━━━━━━━━━ 5 ━━━━━━━━━━━━ 6 ━━━━━━━━━━━━━━┳━━━━━━━ 7 ━━━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━━━━┓ */ LAYOUT(
   LCAG(KC_ESC),  LCAG(KC_QUOT), LCAG(KC_COMM), LCAG(KC_DOT),  LCAG(KC_P),    LCAG(KC_Y),    /*┃*/     LCAG(KC_F),   LCAG(KC_G), LCAG(KC_C), LCAG(KC_R),  LCAG(KC_L), LCAG(KC_LBRC), //┃
   LCAG(KC_TAB),  LCAG(KC_A),    LCAG(KC_O),    LCAG(KC_E),    LCAG(KC_U),    LCAG(KC_I),    /*┃*/     LCAG(KC_D),   LCAG(KC_H), LCAG(KC_T), LCAG(KC_N),  LCAG(KC_S), LCAG(KC_RBRC), //┃
   LCAG(KC_SLSH), LCAG(KC_SCLN), LCAG(KC_Q),    LCAG(KC_J),    LCAG(KC_K),    LCAG(KC_X),    /*┃*/     LCAG(KC_B),   LCAG(KC_M), LCAG(KC_W), LCAG(KC_V),  LCAG(KC_Z), LCAG(KC_MINS), //┃
                                                 _______,      LCAG(KC_BSPC), LCAG(KC_SPACE),/*┃*/     LCAG(KC_ENT), _______,   _______                                              //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */),

    [L_BLENDER] =
/*  1 ━━━━━━━━━━━━━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   KC_ESC,                 KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       /*┃*/   _______,    _______,    KC_UP,      _______,    _______,    G(KC_PLUS) ,//┃
   KC_S_TAB,               KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       /*┃*/   _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    G(KC_0)    ,//┃
   OSL(L_BLENDER_MODIFIER), KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       /*┃*/   _______,    _______,    _______,    _______,    _______,    G(KC_MINS) ,//┃
                                                   KC_LGUI,    KC_LCTL,    KC_SPC,     /*┃*/   TG(L_GAME), _______,    _______                                         //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */ ),

    [L_BLENDER_MODIFIER] =
/*  1 ━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   KC_ESC,  KC_Q,       KC_P7,      KC_P8,      KC_P9,      DF(L_DVORAK), /*┃*/   _______,    _______,    KC_UP,      _______,    _______,    G(KC_PLUS) ,//┃
   KC_TAB,  KC_A,       KC_P4,      KC_P5,      KC_P6,      KC_LSFT,      /*┃*/   _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    G(KC_0)    ,//┃
   KC_SLSH, KC_Z,       KC_P1,      KC_P2,      KC_P3,      _______,      /*┃*/   _______,    _______,    _______,    _______,    _______,    G(KC_MINS) ,//┃
                                    KC_LGUI,    KC_LCTL,    KC_SPC,       /*┃*/   TG(L_GAME), _______,    _______                                         //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */ ),

    [L_GAME] =
/*  1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   KC_ESC,     _______,    KC_Q,       KC_W,       KC_E,       KC_R,       /*┃*/   _______,    _______,    KC_UP,      _______,    _______,    G(KC_PLUS) ,//┃
   KC_TAB,     KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       /*┃*/   _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    G(KC_0)    ,//┃
   _______,    _______,    KC_Z,       KC_X,       KC_C,       KC_V,       /*┃*/   _______,    _______,    _______,    _______,    _______,    G(KC_MINS) ,//┃
                                       KC_LGUI,    KC_LCTL,    KC_SPC,     /*┃*/   TG(L_GAME), _______,    _______                                         //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */ ),

    [L_GAME2] =
/*  1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓ */ LAYOUT(
   KC_ESC,     _______,    KC_Q,       KC_W,       KC_E,       KC_R,       /*┃*/   _______,    _______,    KC_UP,      _______,    _______,    G(KC_PLUS) ,//┃
   KC_TAB,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       /*┃*/   _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    G(KC_0)    ,//┃
   _______,    _______,    KC_Z,       KC_X,       KC_C,       KC_V,       /*┃*/   _______,    _______,    _______,    _______,    _______,    G(KC_MINS) ,//┃
                                       KC_LSFT,    _______,    KC_SPC,     /*┃*/   _______,    _______,    _______                                         //┃
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */ ),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    user_config.pr_counter++;
  }
  switch (keycode) {
  case NAG_ESC:
    if (record->event.pressed) {
      tap_code(KC_LNG2);
      set_single_persistent_default_layer(L_DVORAK);
      register_code(KC_ESC);
    }
    return false;
    break;
  case SV_COUNT:
    eeconfig_update_user(user_config.pr_counter);
    return false;
    break;
  case RST_COUNT:
    user_config.pr_counter = 0;
    return false;
    break;
  default:
    if (!process_naginata(keycode, record)) {
      return false;
    }
    return true;
  }
}

#ifdef OLED_ENABLE

#ifdef IS_RIGHT
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180; // flips the display 180 degrees if offhand
}

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, //
      0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, //
      0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, //
      0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, //
      0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, //
      0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, //
      0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, //
      0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00  //
  };

  oled_write_P(qmk_logo, false);
}
#else

// clang-format off
const char numbers[12][24] = {
  {0xfc, 0xfe, 0x07, 0x83, 0xc3, 0xe3, 0x73, 0x37, 0xfe, 0xfc, 0x00, 0x00, 0x0f, 0x1f, 0x3b, 0x33, 0x31, 0x30, 0x30, 0x38, 0x1f, 0x0f, 0x00, 0x00}, //
  {0x00, 0x00, 0x00, 0x18, 0x1c, 0x0e, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x3f, 0x3f, 0x30, 0x30, 0x00, 0x00}, //
  {0x1c, 0x1e, 0x07, 0x03, 0x03, 0x83, 0xc3, 0xe7, 0x7e, 0x3c, 0x00, 0x00, 0x30, 0x38, 0x3c, 0x3e, 0x37, 0x33, 0x31, 0x30, 0x38, 0x3c, 0x00, 0x00}, //
  {0x0c, 0x0e, 0x07, 0x03, 0xc3, 0xc3, 0xc3, 0xe7, 0xfe, 0x3c, 0x00, 0x00, 0x0c, 0x1c, 0x38, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1f, 0x0f, 0x00, 0x00}, //
  {0x80, 0xe0, 0xf0, 0x38, 0x1c, 0x0e, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x3f, 0x3f, 0x03, 0x03, 0x00, 0x00}, //
  {0xf0, 0xff, 0xdf, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x03, 0x00, 0x00, 0x0c, 0x1c, 0x38, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1f, 0x0f, 0x00, 0x00}, //
  {0xfc, 0xfe, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0x8e, 0x0c, 0x00, 0x00, 0x0f, 0x1f, 0x38, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1f, 0x0f, 0x00, 0x00}, //
  {0x06, 0x07, 0x03, 0x03, 0x03, 0x83, 0xc3, 0xe3, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3f, 0x3f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}, //
  {0x3c, 0xfe, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0xfe, 0x3c, 0x00, 0x00, 0x0f, 0x1f, 0x39, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1f, 0x0f, 0x00, 0x00}, //
  {0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0x67, 0xfe, 0xfc, 0x00, 0x00, 0x0c, 0x1c, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1f, 0x0f, 0x00, 0x00}, //
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3e, 0x1e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00}, //
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //
};
// clang-format on

void write_num(int num, int index) {
  for (int i = 0; i < 24; ++i) {
    oled_write_raw_byte(numbers[num][i], i + i / 12 * 116 + index);
  }
}
#endif

bool oled_task_user(void) {
#ifdef IS_RIGHT
  render_logo();
#else
  uint32_t buf = 0;
  uint8_t data = 0;
  char pressed_counter[9] = {11, 11, 11, 11, 11, 11, 11, 11, 0};
  int n = 0;
  buf = user_config.pr_counter;
  while (buf > 0) {
    data = buf % 10;
    if (n <= 8) {
      pressed_counter[8 - n] = data;
      if ((n == 2 || n == 6) && buf >= 10) {
        n++;
        pressed_counter[8 - n] = 10;
      }
    }
    buf = buf / 10;
    n++;
  }
  for (int i = 0; i < 9; ++i) {
    write_num(pressed_counter[i], 12 * i + 138);
  }
#endif
  return false;
}

#endif
