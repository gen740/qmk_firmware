OLED_ENABLE = no
RGB_MATRIX_ENABLE = no

MOUSEKEY_ENABLE = no
TAP_DANCE_ENABLE = no
UNICODE_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no

SRC += naginata.c
SRC += combo.c
SRC += oled.c
SRC += naginata_keydata.c
# SRC += naginata_v13u.c

# EXTRAFLAGS += -Os
LTO_ENABLE = yes

COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
