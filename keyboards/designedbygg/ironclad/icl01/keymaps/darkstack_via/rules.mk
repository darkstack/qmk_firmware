# EEPROM driver
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = sn32_flash
MOUSEKEY_ENABLE = yes
VIA_ENABLE = yes


ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
LTO_ENABLE = yes
endif
