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
#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

#define ENCODER_RESOLUTION 4

#define TAPPING_TERM 190
#define PERMISSIVE_HOLD

// Automatically enable sniping-mode on the pointer layer.
#define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_LOWER // mouse control layer
// ----- Touchpad Configuration -----
#define DILEMMA_MINIMUM_DEFAULT_DPI 350
#define DILEMMA_DEFAULT_DPI_CONFIG_STEP 150
// ----- High-resolution scroll -----
//#define DILEMMA_DRAGSCROLL_REVERSE_Y  // disabled as it only supports DRAGSCROLL modeS
#define DILEMMA_DRAGSCROLL_DPI 80

// Lighting settings
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP

// Tri Layer (uses default, no need to re-define)
//#define TRI_LAYER_LOWER_LAYER 1
//#define TRI_LAYER_UPPER_LAYER 2
//#define TRI_LAYER_ADJUST_LAYER 3
