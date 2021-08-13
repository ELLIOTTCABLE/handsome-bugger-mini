#pragma once

#define TAPPING_TERM 175
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#define TAPPING_TOGGLE 2

#define USE_SERIAL

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#undef RGBLED_NUM
#define RGBLED_NUM 24
#define RGBLED_SPLIT { 12, 12 }

// Reverse the secondary hand so it continues from the middle instead of the outside edge
#define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12 }

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

// #define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE

// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST

// Leave the last three LEDs exclusively for RGBLIGHT_LAYERS
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM (RGBLED_NUM - 3)

// Stay in the "blueish" area of the spectrum
#define RGBLIGHT_RAINBOW_SWIRL_RANGE 127

#define RGBLIGHT_SLEEP
// #define RGBLIGHT_SPLIT

// Rows are doubled-up
