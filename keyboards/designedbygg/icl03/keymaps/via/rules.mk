VIA_ENABLE = yes
#MOUSEKEY_ENABLE = yes
LED_WIN_LOCK_PIN = yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
LTO_ENABLE = yes
endif
