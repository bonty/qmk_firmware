#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _NAV,
    _SYMBOL,
    _NUMBER,
    _OPTION
};

// Mod-Tap Modifiers
#define ALTTAB ALT_T(KC_TAB)
#define GUITAB GUI_T(KC_TAB)
#define CTLESC CTL_T(KC_ESC)
#define SFTENT SFT_T(KC_ENT)

// Mod-Tap Layers
#define MT_SPC LT(_NAV, KC_SPC)

// OneShot Modifiers
#define OS_SFT OSM(MOD_LSFT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)

// Layers
#define NUMBER OSL(_NUMBER)
#define SYMBOL OSL(_SYMBOL)
#define OPTION OSL(_OPTION)

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

// Apps
#define ONEPASS LCTL(KC_ENT)
#define ALFRED LALT(KC_SPC)

// Layout
#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_reviung41(
    ALTTAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    CTLESC,   KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_MINS,
    KC_HYPR,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  ONEPASS,
                                            NUMBER,    MT_SPC,   ALFRED,   SFTENT,   SYMBOL
  ),

  [_COLEMAK] = LAYOUT_reviung41(
    _______,  KC_Q,     KC_W,     KC_F,     KC_P,      KC_B,               KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  _______,
    _______,  KC_A,     KC_R,     KC_S,     KC_T,      KC_G,               KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     _______,
    _______,  KC_Z,     KC_X,     KC_C,     KC_D,      KC_V,               KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
                                            _______,   _______,  _______,  _______,  _______
  ),

  [_NAV] = LAYOUT_reviung41(
    OPTION,   XXXXXXX,  XXXXXXX,  ONEPASS,  ALFRED,    XXXXXXX,            KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   XXXXXXX,  XXXXXXX,
    XXXXXXX,  OS_CTL,   OS_ALT,   OS_GUI,   OS_SFT,    XXXXXXX,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  HISTBK,   XXXXXXX,
    REDO,     UNDO,     CUT,      COPY,     PASTE,     XXXXXXX,            XXXXXXX,  PREVTAB,  NEXTTAB,  XXXXXXX,  HISTFW,   XXXXXXX,
                                            XXXXXXX,   XXXXXXX,  KC_TAB,   KC_BSPC,  KC_DEL
  ),

  [_SYMBOL] = LAYOUT_reviung41(
    XXXXXXX,  KC_DQUO,  KC_UNDS,  KC_LBRC,  KC_RBRC,   KC_CIRC,            KC_EXLM,  KC_LT,    KC_GT,    KC_EQL,   KC_AMPR,  XXXXXXX,
    XXXXXXX,  KC_SLSH,  KC_MINS,  KC_LCBR,  KC_RCBR,   KC_ASTR,            KC_QUES,  KC_LPRN,  KC_RPRN,  KC_QUOT,  KC_COLN,  XXXXXXX,
    XXXXXXX,  KC_HASH,  KC_DLR,   KC_PIPE,  KC_TILD,   KC_GRV,             KC_PLUS,  KC_PERC,  KC_BSLS,  KC_AT,    XXXXXXX,  XXXXXXX,
                                            XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_NUMBER] = LAYOUT_reviung41(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,      KC_LANG2,           KC_LANG1, KC_7,     KC_8,     KC_9,     KC_0,     KC_F12,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_5,      XXXXXXX,            XXXXXXX,  KC_6,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_OPTION] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  QWERTY,   COLEMAK,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

// Combo
typedef const uint16_t comb_keys_t[];

static PROGMEM comb_keys_t
    // QWERTY
    comb_keys_QwKana = {KC_H, KC_J, COMBO_END},
    comb_keys_QwEisu = {KC_F, KC_G, COMBO_END},
    comb_keys_QwEsc  = {KC_D, KC_F, COMBO_END},
    // ColemakDH
    comb_keys_CmKana = {KC_M, KC_N, COMBO_END},
    comb_keys_CmEisu = {KC_T, KC_G, COMBO_END},
    comb_keys_CmEsc  = {KC_S, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(comb_keys_QwKana, KC_LANG1),
    COMBO(comb_keys_QwEisu, KC_LANG2),
    COMBO(comb_keys_QwEsc,  KC_ESC),
    COMBO(comb_keys_CmKana, KC_LANG1),
    COMBO(comb_keys_CmEisu, KC_LANG2),
    COMBO(comb_keys_CmEsc,  KC_ESC),
};
