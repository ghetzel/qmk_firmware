/* Copyright 2021 Elliot Powell
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_numpad_6x4(
        MO(1),   KC_VOLD, KC_VOLU, KC_KB_MUTE,
        KC_NO,   KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT ),

    [1] = LAYOUT_numpad_6x4(
        KC_TRNS, TG(3), KC_TRNS, KC_TRNS,
        TG(2),   KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, QK_BOOT),

    [2] = LAYOUT_numpad_6x4(
        TO(0),   KC_MRWD, KC_MFFD, KC_TRNS,
        TO(0),   KC_TRNS, KC_TRNS, KC_WH_U,
        KC_WH_L, KC_MS_U, KC_WH_R,
        KC_MS_L, KC_NO,   KC_MS_R, KC_WH_D,
        KC_WH_L, KC_MS_D, KC_WH_R,
        KC_BTN1,          KC_BTN2, KC_BTN3),

    [3] = LAYOUT_numpad_6x4(
        TO(0),   KC_TRNS, MI_OCTD, MI_OCTU,
        TO(0),   MI_Cs2,  MI_D2, MI_Ds2,
        MI_C2,   MI_A1,   MI_As1,
        MI_Gs1,  MI_F1,   MI_Fs1,  MI_B1,
        MI_E1,   MI_Cs1,  MI_D1,
        MI_C1,            MI_Ds1,  MI_G1)
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}