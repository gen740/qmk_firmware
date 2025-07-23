# fmt: off
dvorak_keydata = {
    "Base": [
        "DV_QUOT", "DV_COMM", "DV_DOT"  , "DV_P"    , "DV_Y"    , "DV_F"    , "DV_G"    , "DV_C"    , "DV_R", "DV_L",
        "DV_A"   , "DV_O"   , "DV_E"    , "DV_U"    , "DV_I"    , "DV_D"    , "DV_H"    , "DV_T"    , "DV_N", "DV_S",
        "DV_SCLN", "DV_Q"   , "DV_J"    , "DV_K"    , "DV_X"    , "DV_B"    , "DV_M"    , "DV_W"    , "DV_V", "DV_Z",
                              "DV_LSFT1", "DV_LSFT2", "DV_LSFT3", "DV_RSFT3", "DV_RSFT2", "DV_RSFT1",
    ],
    "Keymaps": [
        [ # Normal
            "KC_QUOT", "KC_COMM", "KC_DOT" , "KC_P"  , "KC_Y", "KC_F", "KC_G"  , "KC_C"  , "KC_R", "KC_L",
            "KC_A"   , "KC_O"   , "KC_E"   , "KC_U"  , "KC_I", "KC_D", "KC_H"  , "KC_T"  , "KC_N", "KC_S",
            "KC_SCLN", "KC_Q"   , "KC_J"   , "KC_K"  , "KC_X", "KC_B", "KC_M"  , "KC_W"  , "KC_V", "KC_Z",
                                  "KC_BSPC", "KC_SPC", None  , None  , "KC_ENT", "KC_TAB",
        ],

        [ # Shift
            "S(KC_QUOT)", "S(KC_COMM)", "S(KC_DOT)" , "S(KC_P)"  , "S(KC_Y)", "S(KC_F)", "S(KC_G)"  , "S(KC_C)"  , "S(KC_R)", "S(KC_L)",
            "S(KC_QUOT)", 1           , 1           , "S(KC_U)"  , "S(KC_I)", "S(KC_D)", "S(KC_H)"  , "S(KC_T)"  , "S(KC_N)", "S(KC_S)",
            "S(KC_SCLN)", "S(KC_Q)"   , "S(KC_J)"   , "S(KC_K)"  , "S(KC_X)", "S(KC_B)", "S(KC_M)"  , "S(KC_W)"  , "S(KC_V)", "S(KC_Z)",
                                        "S(KC_BSPC)", "S(KC_SPC)", None     , None     , "S(KC_ENT)", "S(KC_TAB)",
        ],

        [ # Shift
            "S(KC_QUOT)", "S(KC_COMM)", "S(KC_DOT)" , "S(KC_P)"  , "S(KC_Y)", "S(KC_F)", "S(KC_G)"  , "S(KC_C)"  , "S(KC_R)", "S(KC_L)",
            "S(KC_A)"   , "S(KC_O)"   , "S(KC_E)"   , "S(KC_U)"  , "S(KC_I)", "S(KC_D)", "S(KC_H)"  , 1          , 1        , "S(KC_S)",
            "S(KC_SCLN)", "S(KC_Q)"   , "S(KC_J)"   , "S(KC_K)"  , "S(KC_X)", "S(KC_B)", "S(KC_M)"  , "S(KC_W)"  , "S(KC_V)", "S(KC_Z)",
                                        "S(KC_BSPC)", "S(KC_SPC)", None     , None     , "S(KC_ENT)", "S(KC_TAB)",
        ],

        [ # Left Control
            "C(KC_QUOT)", "C(KC_COMM)", "C(KC_DOT)" , "C(KC_P)"  , "C(KC_Y)", None, None, None, None, None,
            "C(KC_A)"   , "C(KC_O)"   , "C(KC_E)"   , "C(KC_U)"  , "C(KC_I)", None, 1   , 1   , None, None,
            "C(KC_SCLN)", "C(KC_Q)"   , "C(KC_J)"   , "C(KC_K)"  , "C(KC_X)", None, None, None, None, None,
                                        "C(KC_BSPC)", "C(KC_SPC)", None     , None, None, None,
        ],

        [ # Right Control
            None, None, None, None, None, "C(KC_F)", "C(KC_G)"  , "C(KC_C)"  , "C(KC_R)", "C(KC_L)",
            None, None, 1   , 1   , None, "C(KC_D)", "C(KC_H)"  , "C(KC_T)"  , "C(KC_N)", "C(KC_S)",
            None, None, None, None, None, "C(KC_B)", "C(KC_M)"  , "C(KC_W)"  , "C(KC_V)", "C(KC_Z)",
                        None, None, None, None     , "C(KC_ENT)", "C(KC_TAB)",
        ],

        [ # GUI
            "G(KC_QUOT)", "G(KC_COMM)", "G(KC_DOT)" , "G(KC_P)"  , "G(KC_Y)", "G(KC_F)", "G(KC_G)"  , "G(KC_C)", "G(KC_R)", "G(KC_L)",
            "G(KC_A)"   , "G(KC_O)"   , "G(KC_E)"   , "G(KC_U)"  , "G(KC_I)", "G(KC_D)", "G(KC_H)"  , "G(KC_T)", "G(KC_N)", "G(KC_S)",
            "G(KC_SCLN)", "G(KC_Q)"   , "G(KC_J)"   , "G(KC_K)"  , "G(KC_X)", "G(KC_B)", "G(KC_M)"  , "G(KC_W)", "G(KC_V)", "G(KC_Z)",
                                        "G(KC_BSPC)", "G(KC_SPC)", None     , None     , "G(KC_ENT)", 1        ,
        ],

        [ # Option
            "A(KC_QUOT)", "A(KC_COMM)", "A(KC_DOT)", "A(KC_P)"  , "A(KC_Y)", "A(KC_F)", "A(KC_G)"  , "A(KC_C)"  , "A(KC_R)", "A(KC_L)",
            "A(KC_A)"   , "A(KC_O)"   , "A(KC_E)"  , "A(KC_U)"  , "A(KC_I)", "A(KC_D)", "A(KC_H)"  , "A(KC_T)"  , "A(KC_N)", "A(KC_S)",
            "A(KC_SCLN)", "A(KC_Q)"   , "A(KC_J)"  , "A(KC_K)"  , "A(KC_X)", "A(KC_B)", "A(KC_M)"  , "A(KC_W)"  , "A(KC_V)", "A(KC_Z)",
                                        1          , "A(KC_SPC)", None     , None     , "A(KC_ENT)", "A(KC_TAB)",
        ],

        [ # GUI + Option
            "G(A(KC_QUOT))", "G(A(KC_COMM))", "G(A(KC_DOT))", "G(A(KC_P))"  , "G(A(KC_Y))", "G(A(KC_F))", "G(A(KC_G))"  , "G(A(KC_C))"  , "G(A(KC_R))", "G(A(KC_L))",
            "G(A(KC_A))"   , "G(A(KC_O))"   , "G(A(KC_E))"  , "G(A(KC_U))"  , "G(A(KC_I))", "G(A(KC_D))", "G(A(KC_H))"  , "G(A(KC_T))"  , "G(A(KC_N))", "G(A(KC_S))",
            "G(A(KC_SCLN))", "G(A(KC_Q))"   , "G(A(KC_J))"  , "G(A(KC_K))"  , "G(A(KC_X))", "G(A(KC_B))", "G(A(KC_M))"  , "G(A(KC_W))"  , "G(A(KC_V))", "G(A(KC_Z))",
                                              1             , "G(A(KC_SPC))", None        , None        , "G(A(KC_ENT))", 1,
        ],

        [ # GUI + LShift
            "S(G(KC_QUOT))", "S(G(KC_COMM))", "S(G(KC_DOT))" , "S(G(KC_P))"  , "S(G(KC_Y))", "S(G(KC_F))", "S(G(KC_G))"  , "S(G(KC_C))", "S(G(KC_R))", "S(G(KC_L))",
            "S(G(KC_A))"   , 1              , 1              , "S(G(KC_U))"  , "S(G(KC_I))", "S(G(KC_D))", "S(G(KC_H))"  , "S(G(KC_T))", "S(G(KC_N))", "S(G(KC_S))",
            "S(G(KC_SCLN))", "S(G(KC_Q))"   , "S(G(KC_J))"   , "S(G(KC_K))"  , "S(G(KC_X))", "S(G(KC_B))", "S(G(KC_M))"  , "S(G(KC_W))", "S(G(KC_V))", "S(G(KC_Z))",
                                              "S(G(KC_BSPC))", "S(G(KC_SPC))", None        , None        , "S(G(KC_ENT))", 1        ,
        ],

        [ # GUI + RShift
            "S(G(KC_QUOT))", "S(G(KC_COMM))", "S(G(KC_DOT))" , "S(G(KC_P))"  , "S(G(KC_Y))", "S(G(KC_F))", "S(G(KC_G))"  , "S(G(KC_C))", "S(G(KC_R))", "S(G(KC_L))",
            "S(G(KC_A))"   , "S(G(KC_O))"   , "S(G(KC_E))"   , "S(G(KC_U))"  , "S(G(KC_I))", "S(G(KC_D))", "S(G(KC_H))"  , 1           , 1           , "S(G(KC_S))",
            "S(G(KC_SCLN))", "S(G(KC_Q))"   , "S(G(KC_J))"   , "S(G(KC_K))"  , "S(G(KC_X))", "S(G(KC_B))", "S(G(KC_M))"  , "S(G(KC_W))", "S(G(KC_V))", "S(G(KC_Z))",
                                              "S(G(KC_BSPC))", "S(G(KC_SPC))", None        , None        , "S(G(KC_ENT))", 1        ,
        ],

        [ # Left Symbol
            "KC_GRV", "KC_SLSH", "KC_HASH", "KC_AMPR", None     , None, None, None, None, None,
            None    , "KC_QUES", "KC_LPRN", "KC_LBRC", "KC_LCBR", None, 1   , None, 1   , None,
            None    , "KC_BSLS", "KC_PIPE", "KC_PLUS", "KC_EQL" , None, None, None, None, None,
                                 None     , None     , None     , None, None, None,
        ],

        [ # Right Symbol
            None, None, None, None, None, None     , "KC_AT"  , "KC_TILD", "KC_PERC", "KC_DLR",
            None, 1   , None, 1,    None, "KC_RCBR", "KC_RBRC", "KC_RPRN", "KC_EXLM", None    ,
            None, None, None, None, None, "KC_UNDS", "KC_MINS", "KC_ASTR", "KC_CIRC", None    ,
                        None, None, None, None     , None     , None     ,
        ],

        [ # Left Symbol + Ctrl
            "C(KC_GRV)", "C(KC_SLSH)", "C(KC_HASH)", "C(KC_AMPR)", None        , None, None, None, None, None,
            None       , "C(KC_QUES)", "C(KC_LPRN)", "C(KC_LBRC)", "C(KC_LCBR)", None, 1   , None, 1   , None,
            None       , "C(KC_BSLS)", "C(KC_PIPE)", "C(KC_PLUS)", "C(KC_EQL)" , None, None, None, None, None,
                                       None        , None        , None        , None, 1   , None,
        ],

        [ # Right Symbol + Ctrl
            None, None, None, None, None, None        , "C(KC_AT)"  , "C(KC_TILD)", "C(KC_PERC)", "C(KC_DLR)",
            None, 1   , None, 1   , None, "C(KC_RCBR)", "C(KC_RBRC)", "C(KC_RPRN)", "C(KC_EXLM)", None       ,
            None, None, None, None, None, "C(KC_UNDS)", "C(KC_MINS)", "C(KC_ASTR)", "C(KC_CIRC)", None       ,
                        None, 1   , None, None        , None        , None        ,
        ],

        [ # Math expressions
            None  , "KC_SLSH", "KC_LPRN", "KC_LBRC"   , "KC_LCBR", "KC_RCBR", "KC_RBRC"  , "KC_RPRN", "KC_PERC", None  ,
            "KC_1", "KC_2"   , "KC_3"   , "KC_4"      , "KC_5"   , "KC_6"   , "KC_7"     , "KC_8"   , "KC_9"   , "KC_0",
            None  , None     , None     , "G(KC_MINS)", None     , "G(KC_0)", "G(KC_EQL)", None     , None     , None  ,
                               None     , None        , None     , 1        , None       , None     ,
        ],

        [ # Left Hyper
            "HYPR(KC_QUOT)", "HYPR(KC_COMM)", "HYPR(KC_DOT)", "HYPR(KC_P)", "HYPR(KC_Y)", None, None, None, None, None,
            "HYPR(KC_A)"   , "HYPR(KC_O)"   , "HYPR(KC_E)"  , "HYPR(KC_U)", "HYPR(KC_I)", None, 1   , 1   , 1   , None,
            "HYPR(KC_SCLN)", "HYPR(KC_Q)"   , "HYPR(KC_J)"  , "HYPR(KC_K)", "HYPR(KC_X)", None, None, None, None, None,
                                              None          , None        , None        , None, None, None,
        ],

        [ # Right Hyper
            None, None, None, None, None, "HYPR(KC_F)", "HYPR(KC_G)", "HYPR(KC_C)", "HYPR(KC_R)", "HYPR(KC_L)",
            None, 1   , 1   , 1   , None, "HYPR(KC_D)", "HYPR(KC_H)", "HYPR(KC_T)", "HYPR(KC_N)", "HYPR(KC_S)",
            None, None, None, None, None, "HYPR(KC_B)", "HYPR(KC_M)", "HYPR(KC_W)", "HYPR(KC_V)", "HYPR(KC_Z)",
                        None, None, None, None        , None        , None        ,
        ],

        [ # Escape
            None, 0   , "KC_ESC", None, None, None, None, None, None, None,
            None, None, None    , None, None, None, None, None, None, None,
            None, None, None    , None, None, None, None, None, None, None,
                        None    , None, None, None, None, None,
        ],

        [ # to naginata
            None, None, None, None, None, None           , None, None, None, None,
            None, None, None, None, None, "KC_LANGUAGE_1", 0   , None, None, None,
            None, None, None, None, None, None           , None, None, None, None,
                        None, None, None, None           , None, None,
        ],

        [ # Disable
            None, None, None, None, None           , None, None, None, None, None,
            None, None, None, 0   , "KC_LANGUAGE_2", None, None, None, None, None,
            None, None, None, None, None           , None, None, None, None, None,
                        None, None, None           , None, None, None,
        ],


    ]
}
