/* Copyright 2021 daraku-neko
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
    _NAV,
};

// Mod-Tap Modifiers
#define ALTTAB ALT_T(KC_TAB)
#define CTLBSP CTL_T(KC_BSPC)
#define SFTENT SFT_T(KC_ENT)

// Mod-Tap Layers
#define MT_SPC LT(_NAV, KC_SPC)

// Layers
#define SYMBOL OSL(_SYMBOL)
#define NUMBER OSL(_NUMBER)
#define FUNCTN MO(_FUNCTION)

// OneShot Modifiers
#define OS_SFT OSM(MOD_LSFT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)

// OS Shortcuts
#define REDO LSG(KC_Z)
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define NEXTTAB LCTL(KC_TAB)
#define PREVTAB LCTL(LSFT(KC_TAB))
#define HISTBK LGUI(KC_LBRC)
#define HISTFW LGUI(KC_RBRC)

// Edit Shortcuts
#define BS_WORD LALT(KC_BSPC)
#define DE_WORD LALT(KC_DEL)
#define BS_LINE LGUI(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        ALTTAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        CTLBSP,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
        OS_SFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_SFT, \
                                   OS_ALT,  NUMBER,  MT_SPC,  OS_GUI,  OS_CTL,  SFTENT,  SYMBOL,  OS_ALT \
    ),

    [_SYMBOL] = LAYOUT(
        _______, KC_DQUO, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                   KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, _______, \
        _______, KC_SLSH, KC_MINS, KC_LCBR, KC_RCBR, KC_ASTR,                   KC_QUES, KC_LPRN, KC_RPRN, KC_QUOT, KC_COLN, _______, \
        _______, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  XXXXXXX, XXXXXXX, KC_PLUS, KC_PERC, KC_BSLS, KC_AT,   XXXXXXX, _______, \
                                   XXXXXXX, FUNCTN,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    [_NUMBER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PERC, XXXXXXX, \
        XXXXXXX, OS_CTL,  OS_ALT,  OS_GUI,  OS_SFT,  XXXXXXX,                   KC_0,    KC_4,    KC_5,    KC_6,    KC_ASTR, KC_SLSH, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_MINS, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FUNCTN,  XXXXXXX \
    ),

    [_FUNCTION] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, \
        XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,                   XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, \
        XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, BS_WORD, DE_WORD, BS_LINE,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  HISTFW,  XXXXXXX, \
        KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, KC_DEL,  KC_LSFT,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, HISTBK,  XXXXXXX, \
        XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   REDO,    XXXXXXX, XXXXXXX, XXXXXXX, PREVTAB, NEXTTAB, XXXXXXX, XXXXXXX, XXXXXXX, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX \
    )
};

// Combo
typedef const uint16_t comb_keys_t[];

static PROGMEM comb_keys_t
    comb_keys_Kana = {KC_H, KC_J, COMBO_END},
    comb_keys_Eisu = {KC_F, KC_G, COMBO_END},
    comb_keys_Tab  = {KC_J, KC_K, COMBO_END},
    comb_keys_STab = {KC_K, KC_L, COMBO_END},
    comb_keys_Esc  = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(comb_keys_Kana, KC_LANG1),
    COMBO(comb_keys_Eisu, KC_LANG2),
    COMBO(comb_keys_Tab,  KC_TAB),
    COMBO(comb_keys_STab, LSFT(KC_TAB)),
    COMBO(comb_keys_Esc,  KC_ESC),
};

// RGB Lights
void eeconfig_init_user(void) {
    rgblight_enable();
    rgblight_sethsv_white();
    rgblight_mode(1);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAV:
            rgblight_sethsv_noeeprom(HSV_TEAL);
            rgblight_mode_noeeprom(1);
            break;
        case _SYMBOL:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            rgblight_mode_noeeprom(1);
            break;
        case _NUMBER:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            rgblight_mode_noeeprom(1);
            break;
        case _FUNCTION:
            rgblight_sethsv_noeeprom(HSV_RED);
            rgblight_mode_noeeprom(1);
            break;
        default:
            rgblight_reload_from_eeprom();
            break;
    }
    return state;
}
