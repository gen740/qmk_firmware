OLED_ENABLE = yes

MOUSEKEY_ENABLE = no

TAP_DANCE_ENABLE = no
UNICODE_ENABLE = no


RGB_MATRIX_ENABLE = yes

SRC += naginata_v13u.c

EXTRAFLAGS += -flto
LTO_ENABLE = yes

# check no when firmware is right
COMBO_ENABLE = no
EXTRAKEY_ENABLE = no
