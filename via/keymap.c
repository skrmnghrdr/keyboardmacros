/* Copyright 2023 Yiancar-Designs
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
#include "../../../lib/rdr_lib/rdr_common.h"

enum custom_keycodes {
    MY_ALT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_tkl_ansi( //defualt key layer 
        QK_GESC, KC_1,     KC_2,     KC_3,      KC_4,      KC_5,     KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,     KC_E,      KC_R,      KC_T,     KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        MO(1), KC_A,     KC_S,     KC_D,      KC_F,      KC_G,     KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT, KC_Z,     KC_X,     KC_C,      KC_V,      KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,             KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LGUI,  MO(2),                        KC_SPC,                                KC_RALT,  KC_APP,   KC_RCTL,  MO(3)
    ),
    [1] = LAYOUT_tkl_ansi( //caps layer
        QK_GESC, KC_1,     KC_2,     KC_3,      KC_4,      KC_5,     KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,
        KC_TAB,  KC_Q,     KC_W,     KC_E,      KC_R,      KC_T,     KC_Y,     KC_U,    KC_UP,     KC_LBRC,     KC_RBRC,     KC_LBRC,  KC_RBRC,  TG(0),
        KC_NO, LCTL(KC_A),     KC_S,     KC_D,      KC_PGDN,      KC_ENT,     KC_H,     KC_LEFT,    KC_DOWN,     KC_RGHT,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT, KC_Z,     KC_X,     KC_C,      KC_V,      KC_PGUP,     KC_N,     KC_M,    KC_COMM,  KC_DOT,             KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LALT,  KC_LGUI,                        KC_SPC,                                KC_RGUI,  KC_APP,   KC_RCTL,  MO(3)
    ),
    [2] = LAYOUT_tkl_ansi( //alt layer
        KC_GRV,  KC_F1,    KC_F2,    KC_F3,     LALT(KC_F4),     KC_F5,    KC_F6,    KC_F7,   KC_F8,    KC_F9,    KC_MUTE,   KC_VOLD,   KC_VOLU,   U_EE_CLR,
        KC_TAB,  KC_1,  KC_2,  KC_3,   KC_4,    KC_5,  KC_6,  KC_7, KC_8,     KC_9,     KC_0,     RGB_SPD,  RGB_SPI,  TG(0),
        KC_NO, TO(0),    TO(1),    KC_D,      KC_F,      KC_INS,   KC_HOME,  KC_PGUP, KC_MINS,     KC_EQL,     RGB_HUD,  RGB_HUI,            KC_ENT,
        KC_LSFT, LOGO_MOD, LOGO_HUI, RGB_SAD,   RGB_SAI,   KC_DEL,   KC_END,   KC_PGDN, RGB_VAD,  RGB_VAI,            KC_UP,              QK_BAT,
        KC_LCTL, KC_LGUI,   KC_NO,                        KC_SPC,                              KC_LEFT,  KC_DOWN,  KC_RGHT,  TG(3)
    ),
    [3] = LAYOUT_tkl_ansi( //fn key layer (keyboard things)
        QK_GESC,  KC_1,     KC_2,     KC_3,      KC_4,      KC_5,     KC_6,     KC_MPRV, MD_24G,  MD_BLE3,  TG(0),  MD_BLE1,  MD_BLE2,  U_EE_CLR,
        KC_TAB,  KC_Q,     KC_W,     KC_E,      KC_R,      KC_T,     KC_Y,  KC_PAUS, KC_I,     TG(0),     KC_P,     RGB_SPD,  RGB_SPI,  RGB_MOD,
        RGB_RTOG, KC_A,     KC_S,     KC_D,      KC_F,      KC_G,   KC_H,  KC_J, KC_K,     KC_PGUP,  RGB_HUD,  RGB_HUI,            KC_ENT,
        KC_LSFT, KC_Z,     KC_X,     KC_C,      KC_V,      KC_B,   KC_END,   KC_PGDN, RGB_VAD,  RGB_VAI,            RGB_SAI,              QK_BAT,
        KC_LCTL, KC_LGUI,  KC_LALT,                        KC_SPC,                              LOGO_MOD,  LOGO_HUI,  RGB_SAD,  KC_NO
    )
};
//KC_Q,     KC_W,     KC_E,      KC_R,      KC_T,     KC_Y,


void ctrl_hotkey(uint16_t keycode)
{
    uint8_t mods = get_mods();
    clear_mods(); //buy-i ang ctrl anay
    tap_code(keycode); //press end
    set_mods(mods);
    return;
}

bool process_record_user(uint16_t keycode, keyrecord_t * record)
{
    Usb_Change_Mode_Delay = 0;    
    Usb_Change_Mode_Wakeup = false;
    
    bool ctrl_held = get_mods() & MOD_BIT(KC_LCTL);
    //bool alt_held = get_mods() & MOD_BIT(KC_LALT);
    // CTRL hotkeys
    switch(keycode)
    {
        //! begin filter
        //alt keys first up here
        //! end filter



        /* end alt keyes */
        case KC_E:
            if(ctrl_held)
            {
                ctrl_hotkey(KC_END);
                return false; // don't send E
            }
            /*
            if (record->event.pressed) 
            {
                //! alt e
                if (get_mods() & MOD_BIT(KC_LALT)) 
                {
                    tap_code(KC_3);
                    return false; // Prevent KC_Q from being sent
                }
            } 
            break;
            */
           
        case KC_A:
            if(ctrl_held)
            {
                ctrl_hotkey(KC_HOME);
                return false; // don't send A
            }
            break;
    }

    return Key_Value_Dispose(keycode, record);
}


