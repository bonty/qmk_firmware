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
//   _QWERTY,
    _COLEMAK,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
    _NAV,
    _WINNAV,
    _OPTION,
};

// Mod-Tap Modifiers
#define CTLESC CTL_T(KC_ESC)
#define SFTENT SFT_T(KC_ENT)
#define GUIENT GUI_T(KC_ENT)

// Mod-Tap Layers
#define MT_SPC LT(_NAV, KC_SPC)

// Layers
#define SYMBOL OSL(_SYMBOL)
#define NUMBER OSL(_NUMBER)
#define FUNCTN MO(_FUNCTION)
#define WINNAV MO(_WINNAV)
#define OPTION OSL(_OPTION)

// OneShot Modifiers
#define OS_SFT OSM(MOD_LSFT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_MEH OSM(MOD_MEH)

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
#define DE_LINE LCTL(KC_K)
#define FW_WORD LALT(KC_RGHT)
#define BK_WORD LALT(KC_LEFT)
#define FW_LINE LGUI(KC_RGHT)
#define BK_LINE LGUI(KC_LEFT)

// Yabai Shortcuts
#define WARP_PR LSFT(KC_F13)
#define WARP_NT LSFT(KC_F14)
#define STCK_PR LSFT(KC_F15)
#define STCK_NT LSFT(KC_F16)
#define SEND_PR LSFT(KC_F17)
#define SEND_NT LSFT(KC_F18)
#define ROT_PRV LALT(LSFT(KC_F13))
#define ROT_NXT LALT(LSFT(KC_F14))
#define MIRROR LALT(LSFT(KC_F15))
#define BALANCE LALT(LSFT(KC_F16))
#define RESIZEL LALT(LSFT(KC_F17))
#define RESIZER LALT(LSFT(KC_F18))
#define Y_RESET LCTL(LALT(LGUI(KC_F19)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
        CTLESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    GUIENT, \
        OS_SFT,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_LBRC, KC_RBRC, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OS_SFT, \
                                   OS_ALT,  OS_GUI,  NUMBER,  MT_SPC,  SFTENT,  SYMBOL,  OS_CTL,  OS_MEH \
    ),

    [_SYMBOL] = LAYOUT(
        XXXXXXX, KC_DQUO, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                   KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, XXXXXXX, \
        XXXXXXX, KC_SLSH, KC_MINS, KC_LCBR, KC_RCBR, KC_ASTR,                   KC_QUES, KC_LPRN, KC_RPRN, KC_QUOT, KC_COLN, XXXXXXX, \
        XXXXXXX, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  XXXXXXX, XXXXXXX, KC_PLUS, KC_PERC, KC_BSLS, KC_AT,   XXXXXXX, XXXXXXX, \
                                   XXXXXXX, XXXXXXX, FUNCTN,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    [_NUMBER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PERC, XXXXXXX, \
        XXXXXXX, OS_CTL,  OS_ALT,  OS_GUI,  OS_SFT,  XXXXXXX,                   KC_0,    KC_4,    KC_5,    KC_6,    KC_ASTR, KC_SLSH, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_MINS, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FUNCTN,  XXXXXXX, XXXXXXX \
    ),

    [_FUNCTION] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, \
        XXXXXXX, OS_CTL,  OS_ALT,  OS_GUI,  OS_SFT,  XXXXXXX,                   XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    [_NAV] = LAYOUT(
        OPTION,  XXXXXXX, XXXXXXX, BS_WORD, DE_WORD, BS_LINE,                   FW_LINE, BK_WORD, KC_UP,   FW_WORD, KC_PGUP, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_DEL,  DE_LINE,                   BK_LINE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, \
        XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   REDO,    XXXXXXX, XXXXXXX, HISTBK,  PREVTAB, NEXTTAB, HISTFW,  XXXXXXX, XXXXXXX, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, WINNAV,  KC_LCTL, XXXXXXX \
    ),

    [_WINNAV] = LAYOUT(
        XXXXXXX, Y_RESET, XXXXXXX, ROT_PRV, ROT_NXT, XXXXXXX,                   XXXXXXX, WARP_PR, WARP_NT, STCK_PR, SEND_PR, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, MIRROR,  BALANCE, XXXXXXX,                   KC_F19,  KC_F13,  KC_F14,  STCK_NT, SEND_NT, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, RESIZEL, RESIZER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F17,  KC_F18,  XXXXXXX, XXXXXXX, XXXXXXX, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    [_OPTION] = LAYOUT(
        XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    )
};

// Combo
typedef const uint16_t comb_keys_t[];

static PROGMEM comb_keys_t
    comb_keys_Kana = {KC_M, KC_N, COMBO_END},
    comb_keys_Eisu = {KC_T, KC_G, COMBO_END},
    comb_keys_Tab  = {KC_N, KC_E, COMBO_END},
    comb_keys_STab = {KC_E, KC_I, COMBO_END},
    comb_keys_Esc  = {KC_S, KC_T, COMBO_END};

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
        case _OPTION:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            rgblight_mode_noeeprom(1);
            break;
        default:
            rgblight_reload_from_eeprom();
            break;
    }
    return state;
}
