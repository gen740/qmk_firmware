DEFERRED_EXEC_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

SRC += naginata.c
SRC += naginata_keydata.c
SRC += dvorak.c
SRC += dvorak_keydata.c

EXTRAFLAGS += -flto=auto

DEBOUNCE_TYPE = asym_eager_defer_pk
