// vim: set expandtab ts=5 sts=5 sw=5:
#include QMK_KEYBOARD_H
#include <print.h>

#define LCTL_ESC    LCTL_T(KC_ESC)

enum custom_keycodes {
     LOWER = SAFE_RANGE,
     RAISE
};

#define _COLEMAK 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define XLOWER 4
#define XRAISE 5
#define _SETTINGS 4

#define SETTINGS OSL(_SETTINGS)
#define TO_QWE DF(_QWERTY)
#define TO_COL DF(_COLEMAK)


const uint16_t PROGMEM colemak_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_5x6(
/*
 *                      ┌──────┬──────┬──────┐                        ┌──────┬──────┬──────┐
 *               ┌──────┤  3   │  1   │  9   │                        │  0   │  2   │  4   ├──────┐
 * ┌──────┬──────┤  5   ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  6   ├──────┬──────┐
 * │  ~   │  7   ├──────┤  F   │  P   │  G   │                        │  J   │  L   │  U   ├──────┤  8   │Delete│
 * ├──────┼──────┤  W   ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  Y   ├──────┼──────┤
 * │      │  Q   ├──────┤  S   │  T   │  D   │                        │  H   │  N   │  E   ├──────┤  ;   │  \   │
 * ├──────┼──────┤  R   ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  I   ├──────┼──────┤
 * │⌃/Esc │  A   ├──────┤  C   │  V   │  B   │                        │  K   │  M   │  ,   ├──────┤  O   │ '/⌘  │
 * ├──────┼──────┤  X   ├──────┼──────┴──────┘                        └──────┴──────┼──────┤  .   ├──────┼──────┤
 * │LShift│  Z   ├──────┤      │       ┌──────┐                      ┌──────┐       │      ├──────┤  /   │RShift│
 * └──────┴──────┤  -   ├──────┘┌──────┤Space │                      │Return├──────┐└──────┤  =   ├──────┴──────┘
 *               └──────┘       │Lower │      │                      │      │Raise │       └──────┘
 *                              │      ├──────┘ ┌──────┐    ┌──────┐ └──────┤      │
 *                              └──────┘┌──────┐│ LAlt │    │ RAlt │┌──────┐└──────┘
 *                                      │Bksp/⌘├┴─────┬┘    └┬─────┴┤Tab/⌃ │
 *                                      ├──────┤      │      │      ├──────┤
 *                                      │      ├──────┘      └──────┤      │
 *                                      └──────┘                    └──────┘
 */
KC_GRV,   KC_7,     KC_5,     KC_3,     KC_1,     KC_9,          KC_0,     KC_2,     KC_4,     KC_6,     KC_8,     KC_DEL,
KC_NO,    KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,          KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
LCTL_ESC, KC_A,     KC_R,     KC_S,     KC_T,     KC_D,          KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     RGUI_T(KC_QUOT),
KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,          KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                    KC_MINS,  KC_NO,                                                 KC_NO,    KC_EQL,
                                   LOWER,    KC_SPC,                  KC_ENT,   RAISE,
                                   KC_LALT,  KC_NO,                   KC_NO,    KC_RALT,
                                   LGUI_T(KC_BSPC),KC_NO,             KC_NO,    RCTL_T(KC_TAB)
)

const uint16_t PROGMEM qwerty_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_5x6(
/*
 *                      ┌──────┬──────┬──────┐                        ┌──────┬──────┬──────┐
 *               ┌──────┤  3   │  4   │  5   │                        │  6   │  7   │  8   ├──────┐
 * ┌──────┬──────┤  2   ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  9   ├──────┬──────┐
 * │      │  1   ├──────┤  E   │  R   │  T   │                        │  Y   │  U   │  I   ├──────┤  0   │      │
 * ├──────┼──────┤  W   ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  O   ├──────┼──────┤
 * │      │  Q   ├──────┤  D   │  F   │  G   │                        │  H   │  J   │  K   ├──────┤  P   │      │
 * ├──────┼──────┤  S   ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  L   ├──────┼──────┤
 * │      │  A   ├──────┤  C   │  V   │  B   │                        │  N   │  M   │      ├──────┤  ;   │      │
 * ├──────┼──────┤  X   ├──────┼──────┴──────┘                        └──────┴──────┼──────┤      ├──────┼──────┤
 * │      │  Z   ├──────┤      │       ┌──────┐                      ┌──────┐       │      ├──────┤      │      │
 * └──────┴──────┤      ├──────┘┌──────┤      │                      │      ├──────┐└──────┤      ├──────┴──────┘
 *               └──────┘       │      │      │                      │      │      │       └──────┘
 *                              │      ├──────┘ ┌──────┐    ┌──────┐ └──────┤      │
 *                              └──────┘┌──────┐│      │    │      │┌──────┐└──────┘
 *                                      │      ├┴─────┬┘    └┬─────┴┤      │
 *                                      ├──────┤      │      │      ├──────┤
 *                                      │      ├──────┘      └──────┤      │
 *                                      └──────┘                    └──────┘
 */
_______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,          KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
_______,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,          KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,
_______,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,          KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  _______,
_______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,          KC_N,     KC_M,     _______,  _______,  _______,  _______,
                    _______,  _______,                                               _______,  _______,
                                   _______,  _______,                 _______,  _______,
                                   _______,  _______,                 _______,  _______,
                                   _______,  _______,                 _______,  _______
)

const uint16_t PROGMEM lower_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_5x6(
/*
 *                      ┌──────┬──────┬──────┐                        ┌──────┬──────┬──────┐
 *               ┌──────┤  F3  │  F1  │  F9  │                        │  F0  │  F2  │  F4  ├──────┐
 * ┌──────┬──────┤  F5  ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  F6  ├──────┬──────┐
 * │ F11  │  F7  ├──────┤      │      │      │                        │  /   │  7   │  8   ├──────┤  F8  │ F12  │
 * ├──────┼──────┤      ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  9   ├──────┼──────┤
 * │ F13  │QWERTY├──────┤Setts.│      │      │                        │  *   │  4   │  5   ├──────┤  -   │ F14  │
 * ├──────┼──────┤      ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤  6   ├──────┼──────┤
 * │      │      ├──────┤Colem │      │      │                        │  ,   │  1   │  2   ├──────┤  +   │  ]   │
 * ├──────┼──────┤PrScrn├──────┼──────┴──────┘                        └──────┴──────┼──────┤  3   ├──────┼──────┤
 * │      │Pause ├──────┤Insert│       ┌──────┐                      ┌──────┐       │  0   ├──────┤  /   │      │
 * └──────┴──────┤      ├──────┘┌──────┤      │                      │Enter ├──────┐└──────┤  .   ├──────┴──────┘
 *               └──────┘       │ BACK │      │                      │      │Raise │       └──────┘
 *                              │      ├──────┘ ┌──────┐    ┌──────┐ └──────┤      │
 *                              └──────┘┌──────┐│      │    │      │┌──────┐└──────┘
 *                                      │      ├┴─────┬┘    └┬─────┴┤ 0/⌃  │
 *                                      ├──────┤      │      │      ├──────┤
 *                                      │      ├──────┘      └──────┤      │
 *                                      └──────┘                    └──────┘
 */
KC_F11,   KC_F7,    KC_F5,    KC_F3,    KC_F1,    KC_F9,         KC_F10,   KC_F2,    KC_F4,    KC_F6,    KC_F8,    KC_F12,
KC_F13,   TO_QWE,   _______,  _______,  _______,  _______,       KC_NLCK,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  KC_F14,
_______,  _______,  _______,  SETTINGS, _______,  _______,       KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_RBRC,
_______,  KC_PAUS,  KC_PSCR,  TO_COL,   _______,  _______,       KC_PCMM,  KC_P1,    KC_P2,    KC_P3,    KC_PSLS,  _______,
                    _______,  KC_INS,                                                KC_P0,    KC_PDOT,
                                   TO_COL,   _______,                 KC_PENT,  RAISE,
                                   _______,  _______,                 _______,  _______,
                                   _______,  _______,                 _______,  RCTL_T(KC_P0)
)

const uint16_t PROGMEM upper_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_5x6(
/*
 *                      ┌──────┬──────┬──────┐                        ┌──────┬──────┬──────┐
 *               ┌──────┤ F13  │ F11  │ F19  │                        │ F10  │ F12  │ F14  ├──────┐
 * ┌──────┬──────┤ F15  ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤ F16  ├──────┬──────┐
 * │ F21  │ F17  ├──────┤  Up  │      │ PgUp │                        │  🔉  │  ⏭   │  ⏯   ├──────┤ F18  │ F22  │
 * ├──────┼──────┤      ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤      ├──────┼──────┤
 * │ F23  │WhlUp ├──────┤ Down │Right │ End  │                        │  ⏮   │      │      ├──────┤      │ F24  │
 * ├──────┼──────┤ Left ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤      ├──────┼──────┤
 * │  [   │ Home ├──────┤      │      │ PgDn │                        │  🔊  │      │      ├──────┤      │      │
 * ├──────┼──────┤      ├──────┼──────┴──────┘                        └──────┴──────┼──────┤      ├──────┼──────┤
 * │      │WhlDn ├──────┤      │       ┌──────┐                      ┌──────┐       │      ├──────┤      │      │
 * └──────┴──────┤      ├──────┘┌──────┤      │                      │      ├──────┐└──────┤      ├──────┴──────┘
 *               └──────┘       │Lower │      │                      │      │ BACK │       └──────┘
 *                              │      ├──────┘ ┌──────┐    ┌──────┐ └──────┤      │
 *                              └──────┘┌──────┐│      │    │      │┌──────┐└──────┘
 *                                      │      ├┴─────┬┘    └┬─────┴┤      │
 *                                      ├──────┤      │      │      ├──────┤
 *                                      │      ├──────┘      └──────┤      │
 *                                      └──────┘                    └──────┘
 */
KC_F21,   KC_F17,   KC_F15,   KC_F13,   KC_F11,   KC_F19,        KC_F20,   KC_F12,   KC_F14,   KC_F16,   KC_F18,   KC_F22,
KC_F23,   KC_WH_U,  _______,  KC_UP,    _______,  KC_PGUP,       KC_VOLD,  KC_MNXT,  KC_MPLY,  _______,  _______,  KC_F24,
KC_LBRC,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,        KC_MPRV,  _______,  _______,  _______,  _______,  _______,
_______,  KC_WH_D,  _______,  _______,  _______,  KC_PGDN,       KC_VOLU,  _______,  _______,  _______,  _______,  _______,
                    _______,  _______,                                               KC_EQL,   _______,
                                   TO_LOW,   _______,                 _______,  TO_COL,
                                   _______,  _______,                 _______,  _______,
                                   _______,  _______,                 _______,  _______
)

const uint16_t PROGMEM settings_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_5x6(
/* (All lighting controls and animations)
 *                      ┌──────┬──────┬──────┐                        ┌──────┬──────┬──────┐
 *               ┌──────┤      │      │      │                        │      │      │      ├──────┐
 * ┌──────┬──────┤      ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤      ├──────┬──────┐
 * │      │      ├──────┤ Sat+ │      │      │                        │  🔅  │  ⏭   │Toggle├──────┤      │      │
 * ├──────┼──────┤      ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤Static├──────┼──────┤
 * │      │      ├──────┤ Sat- │ Hue+ │      │                        │  ⏮   │Breath│Rainbo├──────┤      │      │
 * ├──────┼──────┤ Hue- ├──────┼──────┼──────┤                        ├──────┼──────┼──────┤Swirl ├──────┼──────┤
 * │      │      ├──────┤      │      │      │                        │  🔆  │Knight│Altern├──────┤Snake │      │
 * ├──────┼──────┤      ├──────┼──────┴──────┘                        └──────┴──────┼──────┤Twinkl├──────┼──────┤
 * │      │      ├──────┤      │       ┌──────┐                      ┌──────┐       │      ├──────┤      │      │
 * └──────┴──────┤      ├──────┘┌──────┤      │                      │      ├──────┐└──────┤      ├──────┴──────┘
 *               └──────┘       │      │      │                      │      │      │       └──────┘
 *                              │      ├──────┘ ┌──────┐    ┌──────┐ └──────┤      │
 *                              └──────┘┌──────┐│      │    │      │┌──────┐└──────┘
 *                                      │      ├┴─────┬┘    └┬─────┴┤      │
 *                                      ├──────┤      │      │      ├──────┤
 *                                      │      ├──────┘      └──────┤      │
 *                                      └──────┘                    └──────┘
 */
_______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  RGB_SAI,  _______,  _______,       RGB_VAD,  RGB_MOD,  RGB_TOG,  RGB_M_P,  _______,  _______,
_______,  _______,  RGB_HUD,  RGB_SAD,  RGB_HUI,  _______,       RGB_RMOD, RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, _______,
_______,  _______,  _______,  _______,  _______,  _______,       RGB_VAI,  RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  _______,
                    _______,  _______,                                               _______,  _______,
                                   _______,  _______,                 _______,  _______,
                                   _______,  _______,                 _______,  _______,
                                   _______,  _______,                 _______,  _______
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = colemak_map,
  [_QWERTY] = qwerty_map,

  // These differ in their handling by the LOWER and RAISE custom-keycodes. See below.
  [_LOWER] = lower_map,
  [_RAISE] = raise_map,
  [XLOWER] = lower_map,
  [XRAISE] = raise_map,

  [_SETTINGS] = settings_map

};

// Light LEDs 10-12 in red when QWERTY is active
const rgblight_segment_t PROGMEM qwerty_layer_LEDs_left[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 3, HSV_RED}
);
const rgblight_segment_t PROGMEM qwerty_layer_LEDs_right[] = RGBLIGHT_LAYER_SEGMENTS(
    {21, 3, HSV_RED}
);
// Light LED 10 in blue when LOWER is active
const rgblight_segment_t PROGMEM lower_layer_LEDs[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 3, HSV_AZURE}
);
// Light LED 11 in orange when RAISE is active
const rgblight_segment_t PROGMEM raise_layer_LEDs[] = RGBLIGHT_LAYER_SEGMENTS(
    {21, 3, 18, 255, 255}
);

// Now define the array of layers. Later layers take precedence.
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer_LEDs_left,
    qwerty_layer_LEDs_right,
    lower_layer_LEDs,
    raise_layer_LEDs
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));

    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, XLOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, XRAISE));
    return state;
}

// Enable `IGNORE_MOD_TAP_INTERRUPT`, but only for the RGUI/QUOT tap-hold combination. Requires
// `IGNORE_MOD_TAP_INTERRUPT_PER_KEY` in `config.h`.
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
          case RGUI_T(KC_QUOT):
               return true;
          default:
               return false;
     }
}

/* The below implements this state-machine:
 *
 *                                 ┌─────────┐
 *                                 │ DEFAULT │
 *               ┏+KC_LOWER━━━━━━━━│         │━━━━━━+KC_RAISE━━━┓
 *               ┃                 └─────────┘                  ┃
 *               ┃                      △                       ┃
 *               ┃                      │                       ┃
 *               ▼         -KC_LOWER    │    -KC_RAISE          ▼
 *          ┌─────────┐────(1st tap)────●────(1st tap)─────┌─────────┐
 *          │ _LOWER  │                 │                  │ _RAISE  │
 *      ┌──▷│         │                 │                  │         │◁─┐
 *      │   └─────────┘────+KC_LOWER────┴────+KC_RAISE─────└─────────┘  │
 *      │        ┃                                              ┃       │
 *      │        ┃                                              ┃       │
 *      │   +KC_RAISE                                      +KC_LOWER    │
 * -KC_RAISE     ┃                                              ┃  -KC_LOWER
 *      │        ▼                                              ▼       │
 *      │  ┌──────────┐                                   ┌──────────┐  │
 *      │  │  XRAISE  │                                   │  XLOWER  │  │
 *      └──│          │                                   │          │──┘
 *         └──────────┘                                   └──────────┘
 */

// A map of "exclusive layers", i.e. ones that tap-toggle won't leave enabled together, to a higher-
// index duplicate thereof, above all other "exclusive layers" that may switch to it.
const uint8_t exclusive_map[] = {
     [_LOWER] = XLOWER,
     [_UPPER] = XUPPER
}

void exclusive_tap_toggle(uint8_t layer, uint8_t exclusive_of, keyrecord_t *record) {
     uint8_t alt_layer = exclusive_map[layer];
     uint8_t alt_excl = exclusive_map[exclusive_of];

     keyevent_t event = record->event;
     uint8_t tap_count = record->tap.count;

     if (event.pressed) {
          if (layer_state_is(layer)) {
               layer_invert(layer);
               return;

          if (layer_state_is(exclusive_of)) {
               layer_invert(layer);
               return;

          // unreachable, i think? would have to press a key that you're holding to be here, lol
          // } else if (layer_state_is(alt_layer)) {
          //      layer_invert(alt_layer);
          //      return;

          } else if (tap_count < TAPPING_TOGGLE) {
               layer_invert(layer);
          }

     } else {
          if (tap_count <= TAPPING_TOGGLE) {
               layer_invert(layer);
          }
     }
     }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
     case LOWER: exclusive_tap_toggle(_LOWER, _UPPER, record); break;
     case UPPER: exclusive_tap_toggle(_UPPER, _LOWER, record); break;
     }
     return true;
};
