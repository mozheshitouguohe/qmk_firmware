#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_3key_2us(
				KC_ESC, 			KC_1, 			KC_2, 			KC_3, 			KC_4, 		KC_5, 		LSFT(KC_7), 															RALT(KC_MINS), 	KC_6, 		KC_7, 			KC_8, 		KC_9, 		KC_0, 		KC_MINS, 
				KC_TAB, 			KC_Q, 			KC_W, 			KC_E, 			KC_R, 		KC_T, 		KC_NUBS, 																LSFT(KC_NUBS), 	KC_Y, 		KC_U, 			KC_I, 		KC_O, 		KC_P, 		KC_LBRC, 
				KC_CAPS, 			KC_A, 			KC_S, 			KC_D, 			KC_F, 		KC_G, 		LSFT(KC_8), 															LSFT(KC_9), 	KC_H, 		KC_J, 			KC_K, 		KC_L, 		KC_SCLN, 	KC_QUOT, 
				LSFT_T(KC_SLSH), 	KC_Z, 			KC_X, 			KC_C, 			KC_V, 		KC_B, 																								KC_N, 		KC_M, 			KC_COMM,	KC_DOT, 	KC_UP, 		RSFT_T(KC_NUHS), 
				KC_LCTL, 			KC_LGUI, 		KC_LALT, 		KC_RALT, 									KC_BSPC, KC_SPC, LT(1,KC_ENT), 		LT(2,KC_ENT), KC_DEL, KC_DOT, 												KC_SLSH, 	KC_LEFT,	KC_DOWN, 	KC_RGHT),

	[1] = LAYOUT_3key_2us(
				KC_NO, 				KC_F1, 			KC_F2, 			KC_F3, 			KC_F4, 		KC_F5, 		KC_NO, 																	RGB_TOG, 		KC_F6, 		KC_F7, 			KC_F8, 		KC_PSLS, 	KC_PAST, 	KC_PMNS, 
				KC_NO, 				KC_MS_BTN1, 	KC_MS_UP, 		KC_MS_BTN2, 	KC_NO, 		KC_NO, 		KC_PGUP, 																KC_PGUP, 		KC_NO, 		KC_NO, 			KC_P7, 		KC_P8, 		KC_P9, 		KC_PPLS, 
				KC_NO, 				KC_MS_LEFT, 	KC_MS_DOWN, 	KC_MS_RIGHT,	KC_NO, 		KC_NO, 		KC_PGDN, 																KC_PGDN, 		KC_HOME, 	KC_NO, 			KC_P4, 		KC_P5, 		KC_P6, 		KC_PCMM, 
				KC_NO, 				LCTL(KC_Z), 	LCTL(KC_X), 	LCTL(KC_C), 	LCTL(KC_V), KC_NO, 																								KC_END, 	KC_NO, 			KC_P1, 		KC_P2, 		KC_P3, 		LSFT(KC_0), 
				KC_NO, 				KC_NO, 			KC_NO, 			KC_NO, 										KC_TRNS, KC_NO, KC_NO, 				KC_NO, KC_NO, KC_NO, 														KC_P0, 		KC_P0, 		KC_PDOT, 	KC_PENT),
	
	[2] = LAYOUT_3key_2us(
				KC_NO, 				KC_F1, 			KC_F2, 			KC_F3, 			KC_F4, 		KC_F5, 		KC_NO, 																	KC_NO, 			KC_F6, 		KC_F7, 			KC_F8, 		KC_F9, 		KC_F10, 	KC_F12, 
				KC_NO, 				KC_AT, 			KC_NO, 			LSFT(KC_0), 	KC_NO, 		KC_NO, 		KC_NO, 																	KC_NO, 			KC_NO, 		LSFT(KC_SLSH), 	KC_NO, 		KC_NO, 		LSFT(KC_5), KC_NO, 				
				KC_NO, 				RALT(KC_2), 	LSFT(KC_NUHS), 	KC_NO, 			KC_NO, 		KC_NO, 		KC_NO, 																	KC_NO, 			LSFT(KC_3), KC_NO, 			KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 				
				KC_NO, 				KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 																								KC_NO, 		KC_SLSH, 		KC_NO, 		KC_NO, 		KC_PGUP, 	KC_NO, 			
				KC_NO, 				KC_NO, 			KC_NO, 			KC_NO, 										KC_NO, KC_SPC, KC_ENT, 				KC_ENT, KC_DEL, KC_TRNS, 													KC_NO, 		KC_LEFT, 	KC_PGDN, 	KC_RGHT)
};