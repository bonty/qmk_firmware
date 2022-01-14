#include QMK_KEYBOARD_H
#include "uzu42.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY = 0,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
    _NAV
};

// Mod-Tap Modifiers
#define SFTENT SFT_T(KC_ENT)

// Mod-Tap Layers
#define MT_SPC LT(_NAV, KC_SPC)

// Layers
#define NUMBER OSL(_NUMBER)
#define FUNCTN MO(_FUNCTION)
#define SYMBOL OSL(_SYMBOL)

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

// Edit Shortcuts
#define BS_WORD LALT(KC_BSPC)
#define DE_WORD LALT(KC_DEL)
#define BS_LINE LGUI(KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,---------------------------------------.                  ,---------------------------------------.
        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                      KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                      KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,\
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
      OS_SFT, OS_ALT, OS_CTL, NUMBER, MT_SPC, OS_GUI,    OS_CTL, SFTENT, SYMBOL, OS_GUI, OS_ALT, OS_SFT\
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_SYMBOL] = LAYOUT( \
  //,---------------------------------------.                  ,---------------------------------------.
     KC_DQUO,KC_UNDS,KC_LBRC,KC_RBRC,KC_CIRC,                   KC_EXLM,  KC_LT,  KC_GT, KC_EQL,KC_AMPR,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     KC_SLSH,KC_MINS,KC_LCBR,KC_RCBR,KC_ASTR,                   KC_QUES,KC_LPRN,KC_RPRN,KC_QUOT,KC_COLN,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     KC_HASH, KC_DLR,KC_PIPE,KC_TILD, KC_GRV,                   KC_PLUS,KC_PERC,KC_BSLS,  KC_AT,XXXXXXX,\
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX, FUNCTN,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX \
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_NUMBER] = LAYOUT( \
  //,---------------------------------------.                  ,---------------------------------------.
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   KC_SLSH,   KC_7,   KC_8,   KC_9,KC_PERC,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
      OS_CTL, OS_ALT, OS_GUI, OS_SFT,XXXXXXX,                      KC_0,   KC_4,   KC_5,   KC_6,KC_ASTR,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   KC_MINS,   KC_1,   KC_2,   KC_3,KC_PLUS,\
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX, FUNCTN,XXXXXXX,XXXXXXX,XXXXXXX \
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_FUNCTION] = LAYOUT( \
  //,---------------------------------------.                  ,---------------------------------------.
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX,  KC_F7,  KC_F8,  KC_F9, KC_F12,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
      OS_CTL, OS_ALT, OS_GUI, OS_SFT,XXXXXXX,                   XXXXXXX,  KC_F4,  KC_F5,  KC_F6, KC_F11,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,RESET,                     XXXXXXX,  KC_F1,  KC_F2,  KC_F3, KC_F10,\
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX \
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_NAV] = LAYOUT( \
  //,---------------------------------------.                  ,---------------------------------------.
     XXXXXXX,XXXXXXX,BS_WORD,DE_WORD,BS_LINE,                   KC_HOME,KC_PGDN,KC_PGUP, KC_END, HISTFW,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     KC_LALT,KC_LGUI,KC_BSPC, KC_DEL,KC_LSFT,                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT, HISTBK,\
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
        UNDO,    CUT,   COPY,  PASTE,   REDO,                   XXXXXXX,PREVTAB,NEXTTAB,XXXXXXX,XXXXXXX,\
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,KC_LALT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX \
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
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
