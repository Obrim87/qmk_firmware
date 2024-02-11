// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define XXX KC_NO

#define LAYOUT_miryoku(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT(\
XXX, XXX, XXX, XXX, XXX, XXX,                XXX, XXX, XXX, XXX, XXX, XXX,\
XXX, K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24, XXX,      XXX, K25, K26, K27, K28, K29, XXX,\
          XXX, XXX, K32, K33, K34,      K35, K36, K37, XXX, XXX\
)

#if defined(KEYBOARD_sofle_rev1)
// Add RGB underglow and top facing lighting
        #define RGB_DI_PIN D3
        #define RGBLED_NUM 70 
        #define OLED_TIMEOUT 15000
        #define OLED_BRIGHTNESS 120
        #define OLED_UPDATE_INTERVAL 10
        #define SPLIT_WPM_ENABLE
        #define SPLIT_OLED_ENABLE
        #define SPLIT_LED_STATE_ENABLE
        //#define NO_ACTION_TAPPING bugged, will disable layers if turned on
        #define NO_ACTION_ONESHOT
        #define RGBLED_SPLIT \
        { 36, 36 }
        #ifdef RGB_MATRIX_ENABLE
                #define DRIVER_LED_TOTAL RGBLED_NUM
                #define RGB_MATRIX_SPLIT RGBLED_SPLIT
                #define SPLIT_TRANSPORT_MIRROR
        #else
                //#define RGBLIGHT_ANIMATIONS
                //#define RGBLIGHT_EFFECT_RAINBOW_MOOD
                #define RGBLIGHT_EFFECT_STATIC_GRADIENT
                #define RGBLIGHT_LIMIT_VAL 120
                #define RGBLIGHT_HUE_STEP  10
                #define RGBLIGHT_SAT_STEP  17
                #define RGBLIGHT_VAL_STEP  17
        #endif
#endif     
#define DYNAMIC_KEYMAP_LAYER_COUNT 6