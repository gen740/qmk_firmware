OLED_ENABLE = yes
RGB_MATRIX_ENABLE = yes

MOUSEKEY_ENABLE = no
TAP_DANCE_ENABLE = no
UNICODE_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no

SRC += naginata_v13u.c

# EXTRAFLAGS += -flto
LTO_ENABLE = yes

# check no when firmware is right
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
