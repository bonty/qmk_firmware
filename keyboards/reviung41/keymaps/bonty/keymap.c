#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _NAV,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
    _OPTION
};

// Mod-Tap Modifiers
#define SFTENT SFT_T(KC_ENT)

// Mod-Tap Layers
#define MT_SPC LT(_NAV, KC_SPC)

// Layers
#define NUMBER OSL(_NUMBER)
#define FUNCTN MO(_FUNCTION)
#define SYMBOL OSL(_SYMBOL)
#define OPTION OSL(_OPTION)

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
#define DE_LINE LCTL(KC_K)
#define FW_WORD LALT(KC_RGHT)
#define BK_WORD LALT(KC_LEFT)
#define FW_LINE LGUI(KC_RGHT)
#define BK_LINE LGUI(KC_LEFT)

// Layout
#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    OS_CTL,   KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
    OS_SFT,   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  OS_SFT,
                                            OS_GUI,    NUMBER,   MT_SPC,   SYMBOL,   OS_ALT
  ),

  [_COLEMAK] = LAYOUT_reviung41(
    _______,  KC_Q,     KC_W,     KC_F,     KC_P,      KC_B,               KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  _______,
    _______,  KC_A,     KC_R,     KC_S,     KC_T,      KC_G,               KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     _______,
    _______,  KC_Z,     KC_X,     KC_C,     KC_D,      KC_V,               KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
                                            _______,   _______,  _______,  _______,  _______
  ),

  [_NAV] = LAYOUT_reviung41(
    OPTION,   XXXXXXX,  XXXXXXX,  BS_WORD,  DE_WORD,   BS_LINE,            FW_LINE,  BK_WORD,  KC_UP,    FW_WORD,  KC_PGUP,   XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,  KC_DEL,    DE_LINE,            BK_LINE,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,   XXXXXXX,
    XXXXXXX,  UNDO,     CUT,      COPY,     PASTE,     REDO,               HISTBK,   PREVTAB,  NEXTTAB,  HISTFW,   XXXXXXX,   XXXXXXX,
                                            XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_LSFT,  KC_LALT
  ),

  [_SYMBOL] = LAYOUT_reviung41(
    XXXXXXX,  KC_DQUO,  KC_UNDS,  KC_LBRC,  KC_RBRC,   KC_CIRC,            KC_EXLM,  KC_LT,    KC_GT,    KC_EQL,   KC_AMPR,  XXXXXXX,
    XXXXXXX,  KC_SLSH,  KC_MINS,  KC_LCBR,  KC_RCBR,   KC_ASTR,            KC_QUES,  KC_LPRN,  KC_RPRN,  KC_QUOT,  KC_COLN,  XXXXXXX,
    XXXXXXX,  KC_HASH,  KC_DLR,   KC_PIPE,  KC_TILD,   KC_GRV,             KC_PLUS,  KC_PERC,  KC_BSLS,  KC_AT,    XXXXXXX,  XXXXXXX,
                                            XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_NUMBER] = LAYOUT_reviung41(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_PERC,  XXXXXXX,
    XXXXXXX,  OS_CTL,   OS_ALT,   OS_GUI,   OS_SFT,    XXXXXXX,            KC_0,     KC_4,     KC_5,     KC_6,     KC_ASTR,  KC_SLSH,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_PLUS,  KC_MINS,
                                            XXXXXXX,   XXXXXXX,  XXXXXXX,  FUNCTN,   XXXXXXX
  ),

  [_FUNCTION] = LAYOUT_reviung41(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F12,   XXXXXXX,
    XXXXXXX,  OS_CTL,   OS_ALT,   OS_GUI,   OS_SFT,    XXXXXXX,            XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F11,   XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F10,   XXXXXXX,
                                            XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_OPTION] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  QWERTY,   COLEMAK,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
};

// Combo
typedef const uint16_t comb_keys_t[];

static PROGMEM comb_keys_t
    // QWERTY
    comb_keys_QwKana = {KC_H, KC_J, COMBO_END},
    comb_keys_QwEisu = {KC_F, KC_G, COMBO_END},
    comb_keys_QwEsc  = {KC_D, KC_F, COMBO_END},
    comb_keys_QwTab  = {KC_U, KC_I, COMBO_END},
    comb_keys_QwSTab = {KC_I, KC_O, COMBO_END},
    comb_keys_QwBksp = {KC_J, KC_K, COMBO_END},
    comb_keys_QwABsp = {KC_J, KC_K, KC_L, COMBO_END},
    comb_keys_QwDel  = {KC_K, KC_L, COMBO_END},
    // ColemakDH
    comb_keys_CmKana = {KC_M, KC_N, COMBO_END},
    comb_keys_CmEisu = {KC_T, KC_G, COMBO_END},
    comb_keys_CmEsc  = {KC_S, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(comb_keys_QwKana, KC_LANG1),
    COMBO(comb_keys_QwEisu, KC_LANG2),
    COMBO(comb_keys_QwEsc,  KC_ESC),
    COMBO(comb_keys_QwTab,  KC_TAB),
    COMBO(comb_keys_QwSTab, LSFT(KC_TAB)),
    COMBO(comb_keys_QwBksp, KC_BSPC),
    COMBO(comb_keys_QwABsp, LALT(KC_BSPC)),
    COMBO(comb_keys_QwDel,  KC_DEL),
    COMBO(comb_keys_CmKana, KC_LANG1),
    COMBO(comb_keys_CmEisu, KC_LANG2),
    COMBO(comb_keys_CmEsc,  KC_ESC),
};
