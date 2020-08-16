#include QMK_KEYBOARD_H

enum custom_keycodes {
  KRZ1 = SAFE_RANGE,
  KRZ2
};

const int delay = 100;
const char *sentences[] = {
  "Polak potrafi\n",
  "Hyper intelligent\n",
  "Det 'r bra att g;ra bra saker\n",
  "En sm[lands tack!\n"
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case KRZ1: ;
        int sentences_size = sizeof(sentences) / sizeof(sentences[0]);
        int i = rand() % sentences_size;
        send_string_with_delay(sentences[i], delay);
        return false;
      case KRZ2: ;
        send_string(SS_LCMD(" ") "terminal\n");
        return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT( KRZ1, KRZ2 )
};
