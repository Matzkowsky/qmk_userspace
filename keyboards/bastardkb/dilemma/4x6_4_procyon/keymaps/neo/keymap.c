/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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
//#include "quantum.h"
// see also bastard-qmk/quantum/keycodes.h

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJUST,
};


#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define MT_CT_Z MT(MOD_LCTL, KC_Z)
#define MT_SF_V MT(MOD_LSFT, KC_V)
#define MT_RALE MT(MOD_LALT | MOD_RALT, KC_ENT)
#define LT_LO_S LT(1, KC_SPC)
#define LT_RA_S LT(2, KC_SPC)
#define LT_RA_B LT(2, KC_B)
#define LT_RA_N LT(2, KC_N)
#define MT_CTSL MT(MOD_LCTL | MOD_RCTL, KC_SLSH)
#define MT_SF_M MT(MOD_LSFT | MOD_RSFT, KC_M)
#define MT_RALS MT(MOD_LALT | MOD_RALT, KC_SPC)

#define MS_WHUP QK_MOUSE_WHEEL_UP   // Mouse wheel up
#define MS_UP   QK_MOUSE_CURSOR_UP  // Mouse up
#define MS_WHDO QK_MOUSE_WHEEL_DOWN // Mouse wheel down
#define MS_WH_L QK_MOUSE_WHEEL_LEFT
#define MS_LEFT QK_MOUSE_CURSOR_LEFT
#define MS_DOWN QK_MOUSE_CURSOR_DOWN
#define MS_RGHT QK_MOUSE_CURSOR_RIGHT
#define MS_WH_R QK_MOUSE_WHEEL_RIGHT
#define MS_BTN1 QK_MOUSE_BUTTON_1
#define MS_BTN2 QK_MOUSE_BUTTON_2
#define MS_BTN3 QK_MOUSE_BUTTON_3
#define MS_BTN4 QK_MOUSE_BUTTON_4
#define MS_BTN5 QK_MOUSE_BUTTON_5
#define MS_DPIF DPI_MOD    // Touch DPI forward
#define MS_DPIR DPI_RMOD   // Touch DPI reverse
#define MS_SNIF S_D_MOD    // Sniping DPI forward
#define MS_SNIR S_D_RMOD   // Sniping DPI reverse
#define MS_SNIP SNIPING    // Touch sniping mode
#define MS_DRGS DRGSCRL    // Touch drag scroll
#define MS_DRGT DRG_TOG    // Touch drag scroll toggle

#define PT_SLSH LT(LAYER_ADJUST, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#define FN_EQESC LT(9, KC_ESC)

#define CAPS_LOCK_DOUBLE_TAP_TIMEOUT 600 // sensible default to simulate holding both shift keys to enable CAPS_LOCK on Neo

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       FN_EQESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, MT_CT_Z,    KC_X,    KC_C, MT_SF_V,    KC_B,       KC_N, MT_SF_M, KC_COMM,  KC_DOT, MT_CTSL, KC_RSFT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_LGUI, KC_LALT, MT_RALE, LT_LO_S,    LT_RA_S, MT_RALS, KC_BSLS, KC_RGUI
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       MS_DPIF, MS_WHUP, MS_BTN4,  MS_UP,  MS_BTN5, MS_WHDO,    XXXXXXX, MS_BTN4, XXXXXXX, MS_BTN5, XXXXXXX,  KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       MS_DPIR, MS_WH_L, MS_LEFT, MS_DOWN, MS_RGHT, MS_WH_R,    MS_DRGT, MS_BTN1, MS_BTN2, MS_BTN3, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, MS_BTN3, MS_BTN2, MS_BTN1, MS_DRGS,    XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, XXXXXXX,    _______, _______, _______, _______
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       UG_TOGG,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       UG_VALU, KC_PGUP, KC_BSPC,   KC_UP,  KC_DEL, KC_PGDN,    KC_VOLU, KC_PSCR, XXXXXXX, XXXXXXX, KC_BRIU,  KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       UG_VALD, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,     KC_VOLD, KC_PASTE, KC_COPY, KC_CUT, KC_BRID, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, QK_GESC, KC_TAB,  KC_INS,   KC_ENT, KC_UNDO,    KC_MUTE, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,    XXXXXXX, _______, _______, _______
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_ADJUST] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    MS_DPIF, DT_DOWN,   DT_UP, DT_PRNT, XXXXXXX, MS_SNIF,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    MS_DPIR, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, MS_SNIR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN3, MS_BTN1, MS_BTN2, _______
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};
// clang-format on

bool     _simulate_shift_hold_active = false;
uint16_t _simulate_shift_hold_timer = 0;

// speed up bottom home-row shift keys a bit
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_V):
            return g_tapping_term -20;
        case MT(MOD_RSFT, KC_M):
            return g_tapping_term -20;
        default:
            return g_tapping_term;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        static bool tapped = false;
        static uint16_t tap_timer = 0;
        // Toggle caps lock on shift double tap
        if (keycode == KC_LSFT || keycode == KC_RSFT) {
            if (tapped && !timer_expired(record->event.time, tap_timer)) {
                // Key was double tapped withing tapping term.
                // clear_mods(); // just in case
                register_code(KC_LSFT);
                register_code(KC_RSFT);
                _simulate_shift_hold_active = true;
                _simulate_shift_hold_timer = timer_read();
                tapped = false;
                return false;
            }
            tapped = true; // tapped once
            tap_timer = record->event.time + TAPPING_TERM;
        } else {
            tapped = false;
        }
    }
    switch (keycode) {
        case QK_MODS ... QK_MODS_MAX:
            // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
            // applied to the mouse key that was pressed.
            if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
                if (record->event.pressed) {
                    add_mods(QK_MODS_GET_MODS(keycode));
                    send_keyboard_report();
                    wait_ms(2);
                    register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
                    return false;
                } else {
                    wait_ms(2);
                    del_mods(QK_MODS_GET_MODS(keycode));
                }
            }
            break;

        case FN_EQESC:
            // Send "=" when tapped, ESC when hold.
            if (record->tap.count > 0) {    // key is being tapped
                if (record->event.pressed) {
                    register_code16(KC_EQUAL);
                } else {
                    unregister_code16(KC_EQUAL);
                }
            } else {                        // key is being held
                if (record->event.pressed) {
                    register_code16(KC_ESCAPE);
                } else {
                    unregister_code16(KC_ESCAPE);
                }
            }
            return false;

        default:
            return true;
    }
    return true;
}

void matrix_scan_user(void) {
    if (_simulate_shift_hold_active) {
        if (timer_elapsed(_simulate_shift_hold_timer) > CAPS_LOCK_DOUBLE_TAP_TIMEOUT) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
            _simulate_shift_hold_active = false;
        }
    }
}

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    // Activate tri-layer also when using LT layer switch
    state = update_tri_layer_state(state, LAYER_LOWER, LAYER_RAISE, LAYER_ADJUST);
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#else
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, LAYER_LOWER, LAYER_RAISE, LAYER_ADJUST);
}
#endif     // POINTING_DEVICE_ENABLEE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);

static HSV _get_user_hsv_for_layer_index(uint8_t layer) {
    switch (layer) {
        case 1:
            return (HSV){HSV_AZURE};
        case 2:
            return (HSV){HSV_CHARTREUSE};
        case 3:
            return (HSV){HSV_ORANGE};
        case 4:
            return (HSV){HSV_GOLDENROD};
        case 5:
            return (HSV){HSV_WHITE};
        case 6:
            return (HSV){HSV_TURQUOISE};
        case 7:
        default:
            return (hsv_t){HSV_BLACK};
            break;
    };
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint8_t layer = get_highest_layer(layer_state);
    HSV hsv = _get_user_hsv_for_layer_index(layer);

    if (layer > 0) {
        // Set brightness to the configured interval brighter than current brightness, clamped to 255 (ie. uint8_t max value). This compensates for the dimmer appearance of the underglow LEDs.
        hsv.v         = MIN(rgb_matrix_get_val() + LAYER_INDICATOR_BRIGHTNESS_INC, 255);
    } else {
        hsv           = (hsv_t){HSV_BLACK};
    }
    const RGB rgb = hsv_to_rgb(hsv);

    for (int i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    // Set underglow LEDs to green if caps lock is enabled
    if (host_keyboard_led_state().caps_lock) {
        for (int i = led_min; i <= led_max; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                // set modifier-flagged LEDs to a pure a configured interval brighter than the current brightness, clamped to 255 (ie. uint8_t max value).
                rgb_matrix_set_color(i, MIN(rgb_matrix_get_val() + CAPSLOCK_INDICATOR_BRIGHTNESS_INC, 0), 255, 16);
            }
        }
    }
    return false;
}
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_LOWER]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_RAISE]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_ADJUST]    = {ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
