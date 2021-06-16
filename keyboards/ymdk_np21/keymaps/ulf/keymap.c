#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

// Custom macropad built with a ymdk_np21 PCB and Cherry brown switches

enum layer_names {
    _num,
    _func
};

// RCS - Right ctrl + right shift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_num] = LAYOUT_ortho_6x4(
        SE_PERC, SE_LPRN, SE_RPRN, TG(_func),
        SE_EXLM, SE_SLSH, SE_ASTR, SE_MINS,
        KC_7   , KC_8   , KC_9   , SE_PLUS,
        KC_4   , KC_5   , KC_6   , SE_EQL ,
        KC_1   , KC_2   , KC_3   , KC_BSPC,
        KC_0   , SE_COMM, SE_DOT , KC_ENT
    ),
    [_func] = LAYOUT_ortho_6x4(
        RCS(KC_F1) , RCS(KC_F2) , RCS(KC_F3) , RCS(KC_F4) ,
        RCS(KC_F5) , RCS(KC_F6) , RCS(KC_F7) , RCS(KC_F8) ,
        RCS(KC_F9) , RCS(KC_F10), RCS(KC_F11), RCS(KC_F12),
        RCS(KC_F13), RCS(KC_F14), RCS(KC_F15), RCS(KC_F16),
        RCS(KC_F17), RCS(KC_F18), RCS(KC_F19), RCS(KC_F20),
        RCS(KC_F21), RCS(KC_F22), RCS(KC_F23), TG(_func)
    )
};
