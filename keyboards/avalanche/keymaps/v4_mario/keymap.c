/*
qmk compile -kb avalanche/v3 -km default_v3
qmk flash -kb avalanche/v3 -km default_v3
*/

#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

enum layer {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

// #define FN_1 MO(_QWERTY)
// #define LFN_2 LT(_FN, KC_GRV)
// #define RFN_2 MO(_FN)
// #define LFN_3 LSFT_T(KC_EQL)
// #define RFN_3 RSFT_T(KC_MINS)
// #define EN_LALT LALT_T(KC_ENT)
// #define EN_RALT RALT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
                 KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSLS,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_BSPC, KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_RBRC,
                 KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_DEL,  KC_LGUI, KC_INS,  KC_BSPC, KC_N,   KC_M,   KC_COMM,   KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC__MUTE,KC_V,    KC_V,    KC_SPC,  KC_V,     KC_V,    KC_V,   KC_V,   KC_V,     KC_PSCR
    ),
    [_RAISE] = LAYOUT(
                 _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,                                     KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
        _______, _______, KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,                                      KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_F12,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_LOWER] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_BSPC,                                     KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, KC_LPRN,
        _______, _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,                                      KC_BSPC, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX, KC_RPRN,
                 _______, KC_0,    KC_7,    KC_8,    KC_9,    KC_DOT,  _______, _______, _______, _______, XXXXXXX, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_BSPC,                                     KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, KC_LPRN,
        _______, _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,                                      KC_BSPC, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX, KC_RPRN,
                 _______, KC_0,    KC_7,    KC_8,    KC_9,    KC_DOT,  _______, _______, _______, _______, XXXXXXX, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) { /* First encoder */
//         if (clockwise) {
//             tap_code(KC__VOLUP);
//         } else {
//             tap_code(KC__VOLDOWN);
//         }
//     } else if (index == 1) { /* Second encoder */
//         if (clockwise) {
//             tap_code(KC_PGUP);
//         } else {
//             tap_code(KC_PGDOWN);
//         }
//     }
//     return true;
// }

// #ifdef OLED_ENABLE
// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
//     };

//     oled_write_P(qmk_logo, false);
// }

// static void print_status_narrow(void) {
//     // Print current mode
//     oled_write_P(PSTR("\n\n"), false);

//     switch (get_highest_layer(layer_state)) {
//         // case 0:
//         //     oled_write_ln_P(PSTR("Qwty"), false);
//         //     break;
//         // case 1:
//         //     oled_write_ln_P(PSTR("Clmk"), false);
//         //     break;
//         default:
//             oled_write_P(PSTR("Avalanche V4\n"), false);
//             break;
//     }
//     oled_write_P(PSTR("\n\n"), false);
//     // Print current layer
//     oled_write_ln_P(PSTR("LAYER"), false);
//     switch (get_highest_layer(layer_state)) {
//         //case 0:
//         case 0:
//             oled_write_P(PSTR("Base\n"), false);
//             break;
//         case 1:
//             oled_write_P(PSTR("Raise"), false);
//             break;
//         case 2:
//             oled_write_P(PSTR("Lower"), false);
//             break;
//         case 3:
//             oled_write_P(PSTR("Num\n"), false);
//             break;
//         default:
//             oled_write_ln_P(PSTR("Undef"), false);
//     }
//     oled_write_P(PSTR("\n\n"), false);
//     led_t led_usb_state = host_keyboard_led_state();
//     oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
// }

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//         return OLED_ROTATION_180;
// }

// bool oled_task_user(void) {
//     if (is_keyboard_master()) {
//         print_status_narrow();
//     } else {
//         render_logo();
//     }
//     return false;
// }

// #endif

//      bool oled_task_user(void) {
//     // Host Keyboard Layer Status
//     oled_write_P(PSTR("Layer: "), false);

//     switch (get_highest_layer(layer_state)) {
//         case _QWERTY:
//             oled_write_P(PSTR("Default\n"), false);
//             break;
//         case _FN:
//             oled_write_P(PSTR("FN\n"), false);
//             break;
//         case _ADJ:
//             oled_write_P(PSTR("ADJ\n"), false);
//             break;
//         default:
//             // Or use the write_ln shortcut over adding '\n' to the end of your string
//             oled_write_ln_P(PSTR("Undefined"), false);
//     }

//     if (is_keyboard_master()) {
        
//     } else {
//         render_logo();  // Renders a static logo
//         oled_scroll_left();  // Turns on scrolling
//     }
//     return false;

//     // Host Keyboard LED Status
//     led_t led_state = host_keyboard_led_state();
//     oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
//     oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
//     oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
//     return false;
// }

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
// }