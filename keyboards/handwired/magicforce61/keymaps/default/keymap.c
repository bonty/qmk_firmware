#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FN1 1
#define _FN2 2

#define KC_X0 LT(_FN2, KC_GRV)
#define KC_X1 MO(_FN1)
#define NAV_ESC LT(_FN1, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
 /*,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------. */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
 /*|esc-----`-1------`-2------`-3------`-4------`-5------`-6------`-7------`-8------`-9------`-0------`mnus----`plus----`--bksp--| */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
 /*|tab-----`-q------`-w------`-e------`-r------`-t------`-y------`-u------`-i------`-o------`-p------`-{------`-}------`--|-----| */
    NAV_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
 /*|caps----`-a------`-s------`-d------`-f------`-g------`-h------`-j------`-k------`-l------`-;------`-'------`-----------enter-| */
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSPC,
 /*|shift---`-z------`-x------`-c------`-v------`-b------`-n------`-m------`-,------`-.------`-/------`--------------------shift-| */
    KC_LCTL, KC_RGUI, KC_LALT,                            KC_SPC,                             KC_X1,   KC_RALT, KC_RCTL, KC_X1
 /*`ctrl----`-gui----`-alt----`------------------space---------------------------------------`-fn-----`-alt----`ctrl----' ANY      */
  ),

  [_FN1] = LAYOUT(
 /*,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------. */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
 /*|esc-----`-1------`-2------`-3------`-4------`-5------`-6------`-7------`-8------`-9------`-0------`mnus----`plus----`--bksp--| */
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, KC_INS,  KC_PSCR, _______, _______, _______, _______,
 /*|tab-----`-q------`-w------`-e------`-r------`-t------`-y------`-u------`-i------`-o------`-p------`-{------`-}------`--|-----| */
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,          _______,
 /*|caps----`-a------`-s------`-d------`-f------`-g------`-h------`-j------`-k------`-l------`-;------`-'------`-----------enter-| */
    _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,                   _______,
 /*|shift---`-z------`-x------`-c------`-v------`-b------`-n------`-m------`-,------`-.------`-/------`--------------------shift-| */
    _______, _______, _______,                            _______,                            _______, _______, _______, KC_MPLY
 /*`ctrl----`-gui----`-alt----`------------------space---------------------------------------`-fn-----`-alt----`ctrl----' ANY      */
  ),

  [_FN2] = LAYOUT(
 /*,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------. */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
 /*|esc-----`-1------`-2------`-3------`-4------`-5------`-6------`-7------`-8------`-9------`-0------`mnus----`plus----`--bksp--| */
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,
 /*|tab-----`-q------`-w------`-e------`-r------`-t------`-y------`-u------`-i------`-o------`-p------`-{------`-}------`--|-----| */
    _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,          _______,
 /*|caps----`-a------`-s------`-d------`-f------`-g------`-h------`-j------`-k------`-l------`-;------`-'------`-----------enter-| */
    _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______,                   _______,
 /*|shift---`-z------`-x------`-c------`-v------`-b------`-n------`-m------`-,------`-.------`-/------`--------------------shift-| */
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
 /*`ctrl----`-gui----`-alt----`------------------space---------------------------------------`-fn-----`-alt----`ctrl----' ANY      */
  )
};
