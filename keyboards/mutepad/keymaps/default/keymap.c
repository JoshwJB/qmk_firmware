// Copyright 2022 Joshua Barber (@JoshwJB)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

enum custom_keycodes {
    MUTE_GOOGLE_MEET = 0,
    MUTE_TEAMS = 1
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MUTE_GOOGLE_MEET:
        if (record->event.pressed) {
            SEND_STRING (SS_LCMD("d"));
        } else {
            // when keycode QMKBEST is released
        }
    case MUTE_TEAMS:
        if (record->event.pressed) {
            SEND_STRING (SS_LCTRL(SS_LSFT("m")));
        }
        break;
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        MUTE_TEAMS, KC_F23, KC_F24, KC_MPLY
    )
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (clockwise) {
		tap_code(KC_VOLU);
	} else {
		tap_code(KC_VOLD);
	}
    return true;
}

#endif
