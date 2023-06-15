# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = qmk-dfu

COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
VPATH += keyboards/gboards

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes     # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
# RGBLIGHT_ENABLE = yes # Enable keyboard RGB underglow
RGBLIGHT_ENABLE = no # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
ENCODER_ENABLE = yes

STENO_ENABLE = yes
STENO_PROTOCOL = all