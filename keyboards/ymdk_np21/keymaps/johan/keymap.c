#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "sendstring_swedish.h"

enum custom_keycodes {
  SWEAR = SAFE_RANGE,
  LOVE,
  RUSSIAN,
};

const int delay = 100;
const char *swear[] = {
  "You have so many gaps in your teeth it looks like your tongue is in jail.\n",
  "You are a gray sprinkle on a rainbow cupcake.\n",
  "You are the human version of period cramps.\n",
  "I would give you a nasty look, but you have already got one.\n",
  "You are as useless as ueue in queue.\n",
  "Mirrors can not talk. Luckily for you they can not laugh either.\n",
  "You are the reason the gene pool needs a lifeguard.\n",
  "Aha! I see the fuck-up fairy has visited us again!\n",
  "You must have been born on a highway, that is where most accidents happen.\n",
  "I love what you have done with your hair! How do you get it to come out of the nostrils like that?\n",
  "Iron spikes!\n",
  "Cocknose\n"
};

const char *love[] = {
  "You're like a piece of furniture, you don't do much, but people notice when you are not there.\n",
  "You're the perfect amount of muscle covered in fat to be a really effective heat source.\n",
  "You have the face that I make on the Sims.\n",
  "I mean this as a compliment, you look like you collect dead animals in jars.\n"
};

const char *russian[] = {
  "U tya sho zhopa sho rozha: vse prigozhe\n",
  "Chyort!\n",
  "Chush' sobach'ya\n",
  "Razvaluha\n",
  "Hooy morzhovy\n",
  "Zhopu porvu margala vikoliu\n",
  "Shob tebe deti v sup srali\n",
  "Zalupa konskaya\n",
  "Perhot' podzalupnaya\n",
  "Blyat\n",
  "Gandon shtopany\n",
  "Perdoon stary\n",
  "Pizdobol, Pizdoon\n",
  "Govnosos\n",
  "Moodozvon\n",
  "Zaebis'\n",
  "Pizdets\n",
  "Cyka blyat\n"
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case SWEAR:
        int swear_size = sizeof(swear) / sizeof(swear[0]);
        int swear_i = rand() % swear_size;
        send_string_with_delay(swear[swear_i], delay);
        return false;
      case LOVE:
        int love_size = sizeof(love) / sizeof(love[0]);
        int love_i = rand() % love_size;
        send_string_with_delay(love[love_i], delay);
        return false;
      case RUSSIAN:
        int rus_size = sizeof(russian) / sizeof(russian[0]);
        int rus_i = rand() % rus_size;
        send_string_with_delay(russian[rus_i], delay);
        return false;
    }
  }
  return true;
};

enum layer_names {
    _func,
    _num
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_func] = LAYOUT_ortho_6x4(
        SWEAR      , LOVE       , RUSSIAN    , TG(_num)      ,
        RCS(KC_F1) , RCS(KC_F2) , RCS(KC_F3) , RCS(KC_F4) ,
        RCS(KC_F5) , RCS(KC_F6) , RCS(KC_F7) , RCS(KC_F8) ,
        RCS(KC_F9) , RCS(KC_F10), RCS(KC_F11), RCS(KC_F12),
        RCS(KC_F13), RCS(KC_F14), RCS(KC_F15), RCS(KC_F16),
        RCS(KC_F17), RCS(KC_F18), RCS(KC_F19), RCS(KC_F20)
    ),

    [_num] = LAYOUT_ortho_6x4(
        _______, _______, _______, _______,
        SE_EXLM, SE_SLSH, SE_ASTR, SE_MINS,
        KC_7   , KC_8   , KC_9   , SE_PLUS,
        KC_4   , KC_5   , KC_6   , SE_EQL ,
        KC_1   , KC_2   , KC_3   , KC_BSPC,
        KC_0   , SE_COMM, SE_DOT , KC_ENT
    )
};
