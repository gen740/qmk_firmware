ENCODER_MAP_ENABLE = no

RGB_MATRIX_ENABLE = yes

MOUSEKEY_ENABLE = no
TAP_DANCE_ENABLE = no
UNICODE_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no

SRC += naginata.c
SRC += naginata_keydata.c
SRC += dvorak.c
SRC += dvorak_keydata.c
SRC += dvorak_keydata_generated.c
INTROSPECTION_KEYMAP_C += combo.c

EXTRAFLAGS += -flto=auto

COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
