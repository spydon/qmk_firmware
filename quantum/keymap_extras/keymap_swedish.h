#ifndef KEYMAP_SWEDISH_H
#define KEYMAP_SWEDISH_H

#include "keymap_nordic.h"

// There are slight differrences in the keyboards in the nordic contries

// Swedish redifinitions from the nordic keyset
#undef NO_AE
#define NO_AE KC_QUOT  // ä
//#undef NO_BSLS
//#define NO_BSLS KC_EQL  // '\'
#undef NO_CIRC
#define NO_CIRC LSFT(KC_RBRC)  // ^
#undef NO_TILD
#define NO_TILD ALGR(KC_RBRC)
#undef NO_GRV
#define NO_GRV LSFT(KC_EQL) // `
#undef NO_OSLH
#define NO_OSLH KC_SCLN  // ö
#undef NO_CIRC
#define NO_CIRC LSFT(KC_RBRC)
#undef NO_QUOT
#define NO_QUOT KC_BSLS
#undef NO_AM
#define NO_AM KC_CIRC
//#undef NO_PIPE
//#define NO_PIPE KC_GRV  // |

// Additional swedish keys not defined in the nordic keyset
#define NO_AA	KC_LBRC  // å
#define NO_ASTR LSFT(KC_BSLS)  // *

#endif
