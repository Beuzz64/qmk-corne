/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "sendstring_french.h"
#include "keymap_french.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.					,-----------------------------------------------------.
		KC_TAB, FR_A, FR_Z, FR_E, FR_R, FR_T, FR_Y, FR_U, FR_I, FR_O, FR_P, KC_BSPC,
		//|--------+--------+--------+--------+--------+--------|					|--------+--------+--------+--------+--------+--------|
		KC_LSFT, FR_Q, FR_S, FR_D, FR_F, FR_G, FR_H, FR_J, FR_K, FR_L, FR_M, FR_QUOT,
		//|--------+--------+--------+--------+--------+--------|					|--------+--------+--------+--------+--------+--------|
		MO(3), FR_W, FR_X, FR_C, FR_V, FR_B, FR_N, FR_COMM, FR_DOT, FR_SLSH, FR_EXLM, KC_LGUI,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		KC_LALT, KC_LCTL, KC_SPC, KC_ENT, MO(1), MO(2)
		//`--------------------------'  `--------------------------'

		),

	[1] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.					,-----------------------------------------------------.
		KC_TAB, FR_ASTR, KC_P7, KC_P8, KC_P9, KC_PGUP, FR_MINS, KC_HOME, KC_UP, KC_END, FR_AMPR, KC_BSPC,
		//|--------+--------+--------+--------+--------+--------|					|--------+--------+--------+--------+--------+--------|
		KC_LSFT, FR_PIPE, KC_P4, KC_P5, KC_P6, KC_PGDN, FR_PLUS, KC_LEFT, KC_DOWN, KC_RGHT, FR_HASH, FR_BSLS,
		//|--------+--------+--------+--------+--------+--------|					|--------+--------+--------+--------+--------+--------|
		MO(3), KC_P0, KC_P1, KC_P2, KC_P3, FR_UNDS, FR_EQL, FR_LABK, FR_RABK, FR_DLR, FR_PERC, KC_LGUI,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		KC_LALT, KC_LCTL, KC_SPC, KC_ENT, KC_NO, MO(3)
		//`--------------------------'  `--------------------------'

		),

	[2] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.					,-----------------------------------------------------.
		KC_TAB, KC_F1, KC_F2, KC_F4, KC_F5, KC_F11, FR_MINS, FR_LBRC, FR_RBRC, FR_CIRC, FR_UGRV, KC_BSPC,
		//|--------+--------+--------+--------+--------+--------|					|--------+--------+--------+--------+---------+--------|
		KC_LSFT, KC_1, KC_2, KC_3, KC_4, KC_5, FR_DQUO, FR_LPRN, FR_RPRN, FR_EACU, FR_AGRV, FR_AT,
		//|--------+--------+--------+--------+--------+--------|					|--------+--------+--------+--------+---------+--------|
		MO(3), KC_6, KC_7, KC_8, KC_9, KC_0, FR_EQL, FR_LCBR, FR_RCBR, FR_EGRV, FR_CCED, KC_LGUI,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		KC_LALT, KC_LCTL, KC_SPC, KC_ENT, MO(3), KC_NO
		//`--------------------------'  `--------------------------'

		),

	[3] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.					,-----------------------------------------------------.
		RGB_TOG, KC_BTN4, KC_BTN5, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_WH_U,
		//|--------+--------+--------+--------+--------+--------|					|--------+--------+--------+--------+--------+--------|
		KC_BTN3, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, KC_BRIU, KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_WH_D,
		//|--------+--------+--------+--------+--------+--------|					|--------+--------+--------+--------+--------+--------|
		KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, KC_BRID, KC_CAPS, KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		KC_LALT, KC_LCTL, KC_SPC, KC_ENT, KC_NO, KC_NO
		//`--------------------------'  `--------------------------'

		),
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
	if (!is_keyboard_master())
	{
		return OLED_ROTATION_180; // flips the display 180 degrees if offhand
	}
	return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void)
{
	oled_write_P(PSTR("Layer: "), false);
	switch (layer_state)
	{
	case L_BASE:
		oled_write_ln_P(PSTR("Default"), false);
		break;
	case L_LOWER:
		oled_write_ln_P(PSTR("Lower"), false);
		break;
	case L_RAISE:
		oled_write_ln_P(PSTR("Raise"), false);
		break;
	case L_ADJUST:
	case L_ADJUST | L_LOWER:
	case L_ADJUST | L_RAISE:
	case L_ADJUST | L_LOWER | L_RAISE:
		oled_write_ln_P(PSTR("Adjust"), false);
		break;
	}
}

char keylog_str[24] = {};

const char code_to_name[60] = {
	' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
	'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
	'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
	'#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record)
{
	char name = ' ';
	if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX))
	{
		keycode = keycode & 0xFF;
	}
	if (keycode < 60)
	{
		name = code_to_name[keycode];
	}

	// update keylog
	snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
			 record->event.key.row, record->event.key.col,
			 keycode, name);
}

enum combos
{
	L_LAYER_3,
	R_LAYER_3,

	ZE_ESCAPE,
	SH_ESCAPE,
	F24_ESCAPE,

	FIRST_NAME,
	BIRTH_DATE,
	LAST_NAME,

	MAIL_1,
	MAIL_2,
	MAIL_3,
	MAIL_4,

	BOOT,

	COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM l_layer_3[] = {FR_COMM, FR_DOT, FR_SLSH, FR_EXLM, COMBO_END};
const uint16_t PROGMEM r_layer_3[] = {FR_W, FR_X, FR_C, FR_V, COMBO_END};

const uint16_t PROGMEM ze_escape[] = {FR_Z, FR_E, COMBO_END};
const uint16_t PROGMEM sh_escape[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM f24_escape[] = {KC_F2, KC_F4, COMBO_END};

const uint16_t PROGMEM first_name[] = {FR_Q, FR_S, FR_D, FR_F, FR_J, COMBO_END};
const uint16_t PROGMEM birth_date[] = {FR_Q, FR_S, FR_D, FR_F, FR_L, COMBO_END};
const uint16_t PROGMEM last_name[] = {FR_Q, FR_S, FR_D, FR_F, FR_K, COMBO_END};

const uint16_t PROGMEM mail_1[] = {FR_Q, FR_S, FR_D, FR_F, FR_U, COMBO_END};
const uint16_t PROGMEM mail_2[] = {FR_Q, FR_S, FR_D, FR_F, FR_I, COMBO_END};
const uint16_t PROGMEM mail_3[] = {FR_Q, FR_S, FR_D, FR_F, FR_O, COMBO_END};
const uint16_t PROGMEM mail_4[] = {FR_Q, FR_S, FR_D, FR_F, FR_P, COMBO_END};

const uint16_t PROGMEM boot[] = {KC_BTN4, KC_BTN5, COMBO_END};

combo_t key_combos[] = {
	[R_LAYER_3] = COMBO(l_layer_3, MO(3)),
	[L_LAYER_3] = COMBO(r_layer_3, MO(3)),

	[ZE_ESCAPE] = COMBO(ze_escape, KC_ESC),
	[SH_ESCAPE] = COMBO(sh_escape, KC_ESC),
	[F24_ESCAPE] = COMBO(f24_escape, KC_ESC),

	[FIRST_NAME] = COMBO_ACTION(first_name),
	[BIRTH_DATE] = COMBO_ACTION(birth_date),
	[LAST_NAME] = COMBO_ACTION(last_name),
	[MAIL_1] = COMBO_ACTION(mail_1),
	[MAIL_2] = COMBO_ACTION(mail_2),
	[MAIL_3] = COMBO_ACTION(mail_3),
	[MAIL_4] = COMBO_ACTION(mail_4),

	[BOOT] = COMBO(boot, QK_BOOTLOADER),
};

void process_combo_event(uint16_t combo_index, bool pressed)
{
	switch (combo_index)
	{
	case FIRST_NAME:
		if (pressed)
		{
			SEND_STRING("Amaury");
		}
		break;
	case LAST_NAME:
		if (pressed)
		{
			SEND_STRING("Peterschmitt");
		}
		break;
	case BIRTH_DATE:
		if (pressed)
		{
			SEND_STRING("25/10/2000");
		}
		break;
	case MAIL_1:
		if (pressed)
		{
			SEND_STRING("yruama.peters@gmail.com");
		}
		break;
	case MAIL_2:
		if (pressed)
		{
			SEND_STRING("yruama.peterschmitt@gmail.com");
		}
		break;
	case MAIL_3:
		if (pressed)
		{
			SEND_STRING("peterschmi@cy-tech.fr");
		}
		break;
	case MAIL_4:
		if (pressed)
		{
			SEND_STRING("apeterschmi@oxyl.fr");
		}
		break;
	}
}

void oled_render_keylog(void)
{
	oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status)
{
	/* Show Ctrl-Gui Swap options */
	static const char PROGMEM logo[][2][3] = {
		{{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
		{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
	};
	if (status)
	{
		oled_write_ln_P(logo[0][0], false);
		oled_write_ln_P(logo[0][1], false);
	}
	else
	{
		oled_write_ln_P(logo[1][0], false);
		oled_write_ln_P(logo[1][1], false);
	}
}

void oled_render_logo(void)
{
	static const char PROGMEM crkbd_logo[] = {
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
		0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
		0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
		0};
	oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void)
{
	if (is_keyboard_master())
	{
		oled_render_layer_state();
		oled_render_keylog();
	}
	else
	{
		oled_render_logo();
	}
	return false;
}

#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
	{KC_BSPC, KC_DEL}, // Shift Backspace is Delete

	{FR_COMM, FR_SCLN}, // Shift , is ;
	{FR_DOT, FR_COLN},	// Shift . is : 
	{FR_SLSH, FR_TILD}, // Shift / is ~
	{FR_EXLM, FR_QUES}, // Shift ! is ?
	{FR_QUOT, FR_DQUO}, // Shift ' is ""

	{FR_ASTR, FR_GRV}, // Shift * is `
	{FR_DLR, FR_EURO}, // Shift $ is €
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
	sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!process_custom_shift_keys(keycode, record))
	{
		return false;
	}

	if (record->event.pressed)
	{
		set_keylog(keycode, record);
	}
	return true;
}
#endif // OLED_ENABLE
