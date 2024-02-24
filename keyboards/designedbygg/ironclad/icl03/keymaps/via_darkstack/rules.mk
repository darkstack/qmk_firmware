SRC += keyboards/designedbygg/common/common_via.c

VIA_ENABLE = yes
MOUSEKEY_ENABLE = yes
LED_WIN_LOCK_PIN = yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
USE_PROCESS_STACKSIZE = 0x500
USE_EXCEPTIONS_STACKSIZE = 0x250
endif

