#include QMK_KEYBOARD_H
#include "version.h"

#define RAZ 0 // default layer
#define DVA 1 // second layer

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[RAZ] = LAYOUT_ergodox(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_NO,
  KC_GRV,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_EQL,
  KC_TAB,          KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_SCRL,
  KC_LSFT,         KC_LCTL,     KC_LGUI,       KC_LALT, MO(DVA),
                                                                 KC_CAPS, KC_NO,
                                                                          KC_HOME,
                                                        KC_BSPC, KC_DEL,  KC_END,
  // right hand
  KC_NO,        KC_6,    KC_7,    KC_8,    KC_9,        KC_0,           KC_RBRC,
  KC_MINS,      KC_Y,    KC_U,    KC_I,    KC_O,        KC_P,           KC_LBRC,
                KC_H,    KC_J,    KC_K,    KC_L,        KC_SCLN,        KC_QUOT,
  KC_BSLS,      KC_N,    KC_M,    KC_COMM, KC_DOT,      KC_SLSH,        KC_RSFT,
                         MO(DVA), KC_RALT, KC_RGUI,     KC_RCTL,        KC_RSFT,
  KC_APP,       KC_INS,
  KC_PGUP,
  KC_PGDN,      KC_ENT,  KC_SPC
),
[DVA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
  KC_TRNS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_HOME, KC_PGDN, KC_END,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_MPRV, KC_MNXT,
  KC_VOLU,
  KC_VOLD, KC_MUTE, KC_MPLY
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    }
  }
  return true;
}
