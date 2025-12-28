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
    LAYER_POINTER,
};

// Automatically enable sniping-mode on the pointer layer.
#define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_LOWER // mouse control layer

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define MT_CT_Z MT(MOD_LCTL, KC_Z)
#define MT_SF_V MT(MOD_LSFT, KC_V)
#define MT_RALE MT(MOD_LALT | MOD_RALT, KC_ENT)
#define LT_LO_S LT(1, KC_SPC)
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

#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#define DUAL_FUNC_0 LT(9, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       DUAL_FUNC_0,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, MT_CT_Z,    KC_X,    KC_C, MT_SF_V, LT_RA_B,    LT_RA_N, MT_SF_M, KC_COMM,  KC_DOT, MT_CTSL, KC_RSFT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_LGUI, KC_LALT, MT_RALE, LT_LO_S,    LT_LO_S, MT_RALS, KC_LALT, KC_RGUI
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, MS_WHUP, MS_DRGS,   MS_UP, MS_SNIP, MS_WHDO,    XXXXXXX, MS_DPIR, MS_DPIF, MS_SNIR, MS_SNIF,  KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, MS_WH_L, MS_LEFT, MS_DOWN, MS_RGHT, MS_WH_R,    XXXXXXX, MS_BTN1, MS_BTN2, MS_BTN3, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, MS_BTN4, MS_BTN3, MS_BTN2, MS_BTN1, MS_BTN5,    XXXXXXX, MS_BTN4, MS_BTN5, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______, XXXXXXX, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT, XXXXXXX, BL_TOGG, BL_DOWN,   BL_UP, BL_STEP,    XXXXXXX, UG_VALD, UG_VALU, UG_TOGG, XXXXXXX, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,    XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_EJCT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,    XXXXXXX,KC_PASTE, KC_COPY,  KC_CUT, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, _______, _______, XXXXXXX,    _______, XXXXXXX, XXXXXXX, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN3, MS_BTN1, MS_BTN2, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

        case DUAL_FUNC_0:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_EQUAL);
                } else {
                unregister_code16(KC_EQUAL);
                }
            } else {
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

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLEE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_LOWER]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_RAISE]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
