/* An ergonomic thumb-centered layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

enum dactyl_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

#define RAISE  MO(_RAISE)
#define LOWER  MO(_LOWER)
#define ALTTAB LGUI(KC_TAB)

enum custom_keycodes {
    CODECMT = SAFE_RANGE,
    CODE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CODECMT:
            if (record->event.pressed) {
                // ```
                SEND_STRING("``````");
            } 
            break;
        case CODE:
            if (record->event.pressed) {
                // `
                SEND_STRING("``");
            } 
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_APOS,
     KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
     CODE   , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
     CODECMT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLASH,
                       KC_EXLM, KC_QSM ,                                                            KC_PLUS, KC_EQL ,
                                                  RAISE  , KC_SPC ,      KC_ENT , LOWER  ,
                                                  KC_LSFT, KC_LGUI,      KC_BSPC, KC_DEL ,
                                                  KC_LCTL, ALTTAB ,      KC_LSFT, KC_LALT
  ),

  [_LOWER] = LAYOUT_5x6(
     KC_TILD, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_SLSH, KC_LPRN, KC_RPRN,
     KC_ACUT, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, KC_LCBR, KC_RCBR,
     _______, _______, _______, _______, _______, _______,                        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_LBRC, KC_RBRC,
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, KC_LESS, KC_GRTR,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______

  ),

  [_RAISE] = LAYOUT_5x6(
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     KC_GRV , _______, _______, _______, _______, _______,                        RESET  , _______, _______, _______, KC_MUTE, KC_PIPE,
     _______, _______, _______, _______, _______, _______,                        KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_VOLU, KC_BSLS,
     _______, _______, _______, _______, _______, _______,                        _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, _______,
                       _______, _______,                                                            _______, _______, 
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______
  ),
};
