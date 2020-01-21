// vim: set expandtab ts=5 sts=5 sw=5:
#include QMK_KEYBOARD_H

#define LCTL_ESC    LCTL_T(KC_ESC)
#define RALT_EQL    RALT_T(KC_EQL)

// Tap Dance Declarations
enum td_keycodes {
   LALT_UNDS, // left-alt when held, underscore when tapped
};

typedef enum {
   SINGLE_TAP,
   SINGLE_HOLD,
   DOUBLE_SINGLE_TAP,
} td_state_t;

// a global instance of the tapdance state type
static td_state_t td_state;

// function to determine the current tapdance state
int cur_dance(qk_tap_dance_state_t * state);

// `finished` and `reset` functions for each tapdance keycode
void lalt_unds_finished(qk_tap_dance_state_t * state, void * user_data);
void lalt_unds_reset(qk_tap_dance_state_t * state, void * user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   7  |   5  |   3  |   1  |   9  | Hyp  |           | Meh  |   0  |   2  |   4  |   6  |   8  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   G  |  -   |           |  +   |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  | Gui/'  |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   | TT(2)|LAlt/_|      |                                                                   |      |RAlt/=| TT(3) |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,--------------.     ,----------------.
 *                                        |      |       |     |       |        |
 *                                        | Space|Gui/Bsp|     |Ctrl/Tb| Return |
 *                                        |      |       |     |       |        |
 *                                        `--------------'     `----------------'
 */
     [0] = LAYOUT(
KC_GRV,   KC_7,     KC_5,     KC_3,     KC_1,     KC_9,     HYPR(KC_NO),   MEH(KC_NO),KC_0,    KC_2,     KC_4,     KC_6,     KC_8,     KC_DEL,
KC_NO,    KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_MINS,       KC_PLUS,  KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
LCTL_ESC, KC_A,     KC_R,     KC_S,     KC_T,     KC_D,                              KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     RGUI_T(KC_QUOT),
KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_LBRC,       KC_RBRC,  KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
TT(2),TD(LALT_UNDS),KC_NO,                                                                                         KC_NO,    RALT_EQL, TT(3),
                                             KC_SPC,   LGUI_T(KC_BSPC),         RCTL_T(KC_TAB),KC_ENT,
                                             KC_NO,    KC_NO,                   KC_NO,    KC_NO
     ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |      |      |      |        |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   |      |      |      |                                                                   |      |      |       |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,--------------.     ,----------------.
 *                                        |      |       |     |       |        |
 *                                        |      |       |     |       |        |
 *                                        |      |       |     |       |        |
 *                                        `--------------'     `----------------'
 */
     [1] = LAYOUT(
_______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     _______,       _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
_______,  _______,  KC_W,     KC_E,     KC_R,     KC_T,     _______,       _______,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,
_______,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                              KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  _______,
_______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     _______,       _______,  KC_N,     KC_M,     _______,  _______,  _______,  _______,
_______,  _______,  _______,                                                                                       _______,  _______,  _______,
                                             _______,  _______,                 _______,  _______,
                                             _______,  _______,                 _______,  _______
     ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  F11   |  F7  |  F5  |  F3  |  F1  |  F9  |      |           |      |  F10 |  F2  |  F4  |  F6  | F8   |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  F13   | TO(1)|      |      |      |      |      |           |      | NLock|  P7  |  P8  |  P9  |   -  |  F14   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   *  |  P4  |  P5  |  P6  |   +  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Pause|      | TO(0)|      |      |      |           |      |   ,  |  P1  |  P2  |  P3  |   /  |        |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   | TO(0)|Insert|PrScrn|                                                                   |   .  |RAlt/=| TO(3) |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,--------------.     ,----------------.
 *                                        |      |       |     |       |        |
 *                                        |      |       |     |  P0   | Enter  |
 *                                        |      |       |     |       |        |
 *                                        `--------------'     `----------------'
 */
     [2] = LAYOUT(
KC_F11,   KC_F7,    KC_F5,    KC_F3,    KC_F1,    KC_F9,    _______,       _______,  KC_F10,   KC_F2,    KC_F4,    KC_F6,    KC_F8,    KC_F12,
KC_F13,   TO(1),    _______,  _______,  _______,  _______,  _______,       _______,  KC_NLCK,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  KC_F14,
_______,  _______,  _______,  _______,  _______,  _______,                           KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_QUOT,
_______,  KC_PAUS,  _______,  TO(0),    _______,  _______,  _______,       _______,  KC_PCMM,  KC_P1,    KC_P2,    KC_P3,    KC_PSLS,  _______,
TO(0),    KC_INS,   KC_PSCR,                                                                                       KC_PDOT,RALT(KC_PEQL),TT(3),
                                             _______,  _______,                 KC_P0,    KC_PENT,
                                             _______,  _______,                 _______,  _______
     ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  F21   |  F17 |  F15 |  F13 |  F11 |  F19 |      |           |      |  F20 |  F12 |  F14 |  F16 | F18  |  F22   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  F23   |      |      |  Up  |      |   Up |      |           |      |      |      |      |      |      |  F24   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Right| Down | Left | End  |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |   Dn |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   | TO(2)|      | Reset|                                                                   |Debug |      | TO(0) |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,--------------.     ,----------------.
 *                                        |      |       |     |       |        |
 *                                        |      |       |     |  P0   | Enter  |
 *                                        |      |       |     |       |        |
 *                                        `--------------'     `----------------'
 */
	[3] = LAYOUT(
KC_F21,   KC_F17,   KC_F15,   KC_F13,   KC_F11,   KC_F19, _______,         _______,  KC_F20,   KC_F12,   KC_F14,   KC_F16,   KC_F18,   KC_F22,
KC_F23,   _______,  _______,  KC_UP,    _______,  KC_PGUP,_______,         _______,  _______,  _______,  _______,  _______,  _______,  KC_F24,
_______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,                            _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  KC_PGDN,_______,         _______,  _______,  _______,  _______,  _______,  _______,  _______,
TO(2),    _______,  RESET,                                                                                         DEBUG,    _______,  TO(0),
                                             _______,  _______,                 _______,  _______,
                                             _______,  _______,                 _______,  _______
     )
};


int cur_dance(qk_tap_dance_state_t * state) {
   if (state->count == 1) {
      if (state->interrupted || !state->pressed) {
         return SINGLE_TAP;
      } else {
         return SINGLE_HOLD;
      }
   }
   if (state->count == 2) {
      return DOUBLE_SINGLE_TAP;
   } else {
      return 3;
   }
}

// handle the possible states for each tapdance keycode you define:

void lalt_unds_finished(qk_tap_dance_state_t * state, void * user_data) {
   td_state = cur_dance(state);
   switch (td_state) {
   case SINGLE_TAP:
      register_code16(KC_UNDS);
      break;
   case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LALT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
   case DOUBLE_SINGLE_TAP: // allow pressing of two underscores `__` within tapping term
      tap_code16(KC_UNDS);
      register_code16(KC_UNDS);
   }
}

void lalt_unds_reset(qk_tap_dance_state_t * state, void * user_data) {
   switch (td_state) {
   case SINGLE_TAP:
      unregister_code16(KC_UNDS);
      break;
   case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LALT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
   case DOUBLE_SINGLE_TAP:
      unregister_code16(KC_UNDS);
   }
}

// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and
// `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
   [LALT_UNDS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lalt_unds_finished, lalt_unds_reset)
};
