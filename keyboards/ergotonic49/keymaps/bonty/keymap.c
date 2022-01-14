/* Copyright 2021 hanachi-ap
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

enum layer_names {
    _QWERTY,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
    _NAV
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

// Shortcuts
#define REDO LSG(KC_Z)
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define NEXTTAB LCTL(KC_TAB)
#define PREVTAB LCTL(LSFT(KC_TAB))
#define HISTBK LGUI(KC_LBRC)
#define HISTFW LGUI(KC_RBRC)
#define ZOOMUP LGUI(KC_EQL)
#define ZOOMDN LGUI(KC_MINS)
#define ZOOMRE LGUI(KC_0)

// Edit Shortcuts
#define BS_WORD LALT(KC_BSPC)
#define DE_WORD LALT(KC_DEL)
#define BS_LINE LGUI(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY]=LAYOUT(   // QWERTY
			ALTTAB	,	KC_Q	,	KC_W	,	KC_E	,	KC_R	,	KC_T	,							KC_Y	,	KC_U	,	KC_I	,	KC_O	,	KC_P	,	KC_BSPC	,	KC_PGUP	,
			CTLBSP	,	KC_A	,	KC_S	,	KC_D	,	KC_F	,	KC_G	,							KC_H	,	KC_J	,	KC_K	,	KC_L	,	KC_SCLN	,	KC_ENT	,	KC_PGDN	,
			OS_SFT	,	KC_Z	,	KC_X	,	KC_C	,	KC_V	,	KC_B	,	ZOOMRE	,	KC_LGUI	,	KC_N	,	KC_M	,	KC_COMM	,	KC_DOT	,	KC_SLSH	,	OS_SFT	,
	KC_MUTE	,						KC_LALT	,	NUMBER	,	MT_SPC	,	OS_GUI	,		KC_SPC	,			OS_CTL	,	SFTENT	,	SYMBOL	,	KC_RALT	,
			KC_VOLD	,	KC_VOLU	,							ZOOMDN	,	ZOOMUP	,			KC_PGDN	,	KC_PGUP
),

[_SYMBOL]=LAYOUT(   // Symbol
			_______	,	KC_DQUO	,	KC_UNDS	,	KC_LBRC	,	KC_RBRC	,	KC_CIRC	,							KC_EXLM	,	KC_LT	,	KC_GT	,	KC_EQL	,	KC_AMPR	,	_______	,	_______	,
			_______	,	KC_SLSH	,	KC_MINS	,	KC_LCBR	,	KC_RCBR	,	KC_ASTR	,							KC_QUES	,	KC_LPRN	,	KC_RPRN	,	KC_QUOT	,	KC_COLN	,	_______	,	_______	,
			_______	,	KC_HASH	,	KC_DLR	,	KC_PIPE	,	KC_TILD	,	KC_GRV	,	XXXXXXX	,	XXXXXXX	,	KC_PLUS	,	KC_PERC	,	KC_BSLS	,	KC_AT	,	XXXXXXX	,	_______	,
	XXXXXXX	,						XXXXXXX	,	FUNCTN	,	XXXXXXX	,	XXXXXXX	,		XXXXXXX	,			XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,
			XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	XXXXXXX
),

[_NUMBER]=LAYOUT(   // Number
			XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	KC_7	,	KC_8	,	KC_9	,	KC_PERC	,	XXXXXXX	,	XXXXXXX	,
			XXXXXXX	,	OS_CTL	,	OS_ALT	,	OS_GUI	,	OS_SFT	,	XXXXXXX	,							KC_0	,	KC_4	,	KC_5	,	KC_6	,	KC_ASTR	,	KC_SLSH	,	XXXXXXX	,
			XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	KC_EQL	,	KC_1	,	KC_2	,	KC_3	,	KC_PLUS	,	KC_MINS	,
	XXXXXXX	,						XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,		XXXXXXX	,			XXXXXXX	,	XXXXXXX	,	FUNCTN	,	XXXXXXX	,
			XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	XXXXXXX
),

[_FUNCTION]=LAYOUT(   // Function
			XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	KC_F7	,	KC_F8	,	KC_F9	,	KC_F12	,	XXXXXXX	,	XXXXXXX	,
			XXXXXXX	,	RGB_VAI	,	RGB_SAI	,	RGB_HUI	,	RGB_MOD	,	RGB_TOG,							XXXXXXX,	KC_F4	,	KC_F5	,	KC_F6	,	KC_F11	,	XXXXXXX	,	XXXXXXX	,
			XXXXXXX	,	RGB_VAD	,	RGB_SAD	,	RGB_HUD	,	RGB_RMOD,	RESET	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	KC_F1	,	KC_F2	,	KC_F3	,	KC_F10	,	XXXXXXX	,
	XXXXXXX	,						XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,		XXXXXXX	,			XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,
			XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	XXXXXXX
),

[_NAV]=LAYOUT(   // Navigation
			XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	BS_WORD	,	DE_WORD	,	BS_LINE	,							KC_HOME	,	KC_PGDN	,	KC_PGUP	,	KC_END	,	HISTFW	,	XXXXXXX	,	XXXXXXX	,
			KC_LCTL	,	KC_LALT	,	KC_LGUI	,	KC_BSPC	,	KC_DEL	,	KC_LSFT	,							KC_LEFT	,	KC_DOWN	,	KC_UP	,	KC_RGHT	,	HISTBK	,	XXXXXXX	,	XXXXXXX	,
			XXXXXXX	,	UNDO	,	CUT		,	COPY	,	PASTE	,	REDO	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	PREVTAB	,	NEXTTAB	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,
	XXXXXXX	,						XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,		XXXXXXX	,			XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,
			XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	XXXXXXX	,							XXXXXXX	,	XXXXXXX
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

const uint8_t rt_matrix[][3][2] = {
    {{3,1},{3,2}},
    {{0,6},{1,6}},
    {{0,7},{3,11}},
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;
    int      cw = 0;
    if (clockwise) cw = 1;
    key.row          = rt_matrix[index][cw][0];
    key.col          = rt_matrix[index][cw][1];
    uint8_t  layer   = layer_switch_get_layer(key);
    uint16_t keycode = keymap_key_to_keycode(layer, key);
    tap_code16(keycode);
    return false;
}

const rgblight_segment_t PROGMEM rgb_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM rgb_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM rgb_scllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_caps_layer,
    rgb_numlock_layer,
    rgb_scllock_layer
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, IS_HOST_LED_ON(USB_LED_NUM_LOCK));
    rgblight_set_layer_state(1, IS_HOST_LED_ON(USB_LED_CAPS_LOCK));
    rgblight_set_layer_state(2, IS_HOST_LED_ON(USB_LED_SCROLL_LOCK));

    return true;
}

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
#endif
}
