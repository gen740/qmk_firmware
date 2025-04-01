#define BS_alt ALT_T(KC_BSPC)
#define BS_ctrl CTL_T(KC_BSPC)
#define TAB_sft SFT_T(KC_TAB)
#define RBRC_sft SFT_T(KC_RBRC)
#define ENT_mod LT(L_MOD, KC_ENT)
#define SPC_sft SFT_T(KC_SPC)
#define ENT_sft SFT_T(KC_ENT)
#define BSPC_rai LT(L_RAI, KC_BSPC)

#define MO_MOD MO(L_MOD)
#define MO_MS MO(L_MOUSE)
#define DF_GAME DF(L_GAME)
#define MO_GAME2 MO(L_GAME2)
#define DF_DVO DF(L_DVO)

#define KK_VOLU A(S(KC_VOLU))
#define KK_VOLD A(S(KC_VOLD))

#define LAYOUT_ex2(layout) [layout] = LAYOUT_split_3x6_3_ex2(

#define CS(KC) LCTL(S(KC))
#define LAGDOWN LAG(KC_DOWN)
#define LAGUP LAG(KC_UP)

#define G_PLUS G(KC_EQL)
#define G_0 G(KC_0)
#define G_MINS G(KC_MINS)
#define G_S_TAB G(S(KC_TAB))
