#include "planck.h"
#include "keymap_swedish.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

// This simple keymap is optimized for xmonad users using super as their modifier key.
// M(1) makes it possible to change virtual screens and swap windows between them.

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define _QW 0
#define _LW 1
#define _RS 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = { /* Qwerty */
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
    {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_SCLN, NO_QUOT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_SLSH, KC_RSFT},
    {KC_LCTL, KC_LALT, KC_LGUI, M(1),    MO(_LW), KC_SPC,  KC_ENT,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },
  [_RS] = { /* RAISE */
    {NO_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELT},
    {NO_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_MINS, NO_EQL,  NO_OSLH, NO_AE,   NO_BSLS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_AA,   KC_TRNS, NO_QUOT},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },
  [_LW] = { /* LOWER */
    {NO_TILD, KC_EXLM, NO_AT,   KC_HASH, NO_DLR,  KC_PERC, NO_CIRC, NO_AM,   NO_ASTR, NO_LPRN, NO_RPRN, KC_BSPC},
    {NO_ACUT, M(2),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_UNDS, NO_PLUS, NO_LCBR, NO_RCBR, NO_PIPE},
    {KC_TRNS, M(3),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_LBRC, NO_RBRC, NO_QUO2},
    {KC_TRNS, M(4),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, NO_LESS, NO_GRTR, KC_END }
  }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      break;
    case 1:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        layer_on(_RS);
      } else {
        unregister_code(KC_LGUI);
        layer_off(_RS);
      }
      break;
    case 2:
      if (record->event.pressed) {
        return MACRO( T(S), T(P), T(Y), T(D), T(O), T(N), END );
      }
      break;
    case 3:
      if (record->event.pressed) {
        return MACRO( T(K), T(L), T(A), T(R), T(N), T(A), END );
      }
      break;
    case 4:
      if (record->event.pressed) {
        return MACRO( D(LSFT), T(DOT), U(LSFT), T(MINS), T(1), D(LSFT), T(DOT), U(LSFT), T(ENTER), END );
      }
      break;
  }
  return MACRO_NONE;
};
