#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

// Tap Dance declarations	//   One tap    |  Two taps
enum {						// -------------+-----------
	TD_QUOTES,				//	  '		    |	  "
	TD_SPACE_DOT,			//	 Space	    |	  . + Space
    TD_HOME_SHIFT_HOME,		//   Home       |	 Shift+Home	
    TD_END_SHIFT_END,		//   End        |	 Shift+End	
};

void dance_quotes_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_NUHS);
    } else {
        register_code16(S(KC_2));
    }
}

void dance_quotes_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_NUHS);
    } else {
        unregister_code16(S(KC_2));
    }
}

void dance_space_dot_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_SPC);
    } else {
        register_code(KC_DOT);
        register_code(KC_SPC);
    }
}

void dance_space_dot_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_SPC);
    } else {
        unregister_code(KC_DOT);
        unregister_code(KC_SPC);
    }
}

void dance_home_shift_home_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_HOME);
    } else {
        register_code16(S(KC_HOME));
    }
}

void dance_home_shift_home_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_HOME);
    } else {
        unregister_code16(S(KC_HOME));
    }
}

void dance_end_shift_end_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_END);
    } else {
        register_code16(S(KC_END));
    }
}

void dance_end_shift_end_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_END);
    } else {
        unregister_code16(S(KC_END));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_QUOTES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quotes_finished, dance_quotes_reset),
	[TD_SPACE_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_space_dot_finished, dance_space_dot_reset),
    [TD_HOME_SHIFT_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_home_shift_home_finished, dance_home_shift_home_reset),
    [TD_END_SHIFT_END] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_end_shift_end_finished, dance_end_shift_end_reset),    
};

enum custom_keycodes {
    _SELECTWORD = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   /  |           |  \   |   6  |   7  |   8  |   9  |   0  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   "  |           |  '   |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | AUshift|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|  =   |           |  |   |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  UP  | Shft,´ |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Gui | Alt  | AltGr|                                                     |   -  | LEFT | DOWN | RIGHT |
 *   `---------------------------'                                                     `----------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|Space |Enter |       |Enter | Del  +------.
 *                                 |      |  .   | L1   |       | L2   |      |      |
 *                                 | BkSp | 	 |		|       |      |      |  .   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 * Keymap 1
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   F1 |   F2 |   F3 |   F4 |   F5 |      |           |      |   F6 |   F7 |   F8 |   F9 |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   W  |LClick|  mUp |RClick| mwUp |           |      |      |      |      |      |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | save |mLeft |mDown |mRight|------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|mwDown|           |      |------+------+------+------+------+--------|
 * |        | undo | cut  | copy | paste|sWord |      |           |      |      |      |      |      | pgUP |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |                                                     |      | home |pgDown| end    |
 *   `---------------------------'                                                     `----------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|      |      |       |      |      +------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | 	 |		|       |      |      |   :  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 * Keymap 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |   [  |   ]  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   "  |      |   =  |   {  |   }  |      |           |      |      |   _  |      |      |   %  |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   @  |   *  |      |   (  |   )  |------|           |------|   #  |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |   <  |   >  |      |           |      |      |   -  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |                                                     |      |      |      |       |
 *   `---------------------------'                                                     `----------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|      |      |       |      |      +------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | 	 |		|       |      |      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
	[0] = LAYOUT_3key_2us(
				KC_ESC, 			KC_1, 			KC_2, 			KC_3, 			KC_4, 		KC_5, 		LSFT(KC_7), 															ALGR(KC_MINS),    KC_6, 	KC_7, 			KC_8, 		KC_9, 		            KC_0, 		SE_PLUS, 
				KC_TAB, 			KC_Q, 			KC_W, 			KC_E, 			KC_R, 		KC_T, 		S(KC_2), 												        		KC_NUHS,          KC_Y, 	KC_U, 			KC_I, 		KC_O, 		            KC_P, 		KC_LBRC, 
				KC_ASTG, 		    KC_A, 			KC_S, 			KC_D, 			KC_F, 		KC_G, 		S(KC_0),         														ALGR(KC_NUBS),    KC_H, 	KC_J, 			KC_K, 		KC_L, 		            KC_SCLN, 	KC_QUOT, 
				KC_LSFT, 			KC_Z, 			KC_X, 			KC_C, 			KC_V, 		KC_B, 																								  KC_N, 	KC_M, 			KC_COMM,	KC_DOT, 	            KC_UP, 		RSFT_T(KC_EQL), 
				KC_LCTL, 			KC_LGUI, 		KC_LALT, 		KC_RALT, 									KC_BSPC, TD(TD_SPACE_DOT), LT(1,KC_ENT), 		LT(2,KC_ENT), KC_DEL, KC_DOT, 									KC_SLSH, 	KC_LEFT,	            KC_DOWN, 	KC_RGHT),

	[1] = LAYOUT_3key_2us(
				KC_TRNS, 			KC_F1, 			KC_F2, 			KC_F3, 			KC_F4, 		KC_F5, 		KC_TRNS, 																	KC_TRNS, 		KC_F6, 		KC_F7, 			KC_F8, 		KC_F9, 	                KC_F10, 	KC_F11, 
				KC_TRNS, 			KC_TRNS, 		KC_TRNS, 		KC_MS_BTN1, 	KC_MS_UP, 	KC_MS_BTN2, KC_MS_WH_UP, 																KC_TRNS, 		KC_TRNS, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 	            KC_TRNS, 	KC_F12, 
				KC_TRNS, 			KC_TRNS, 		LCTL(KC_S), 	KC_MS_LEFT,		KC_MS_DOWN, KC_MS_RIGHT,KC_MS_WH_DOWN, 																KC_TRNS, 		KC_TRNS, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 	            KC_TRNS,    KC_TRNS, 
				KC_TRNS, 			LCTL(KC_Z), 	LCTL(KC_X), 	LCTL(KC_C), 	LCTL(KC_V), _SELECTWORD, 																							KC_TRNS, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 	            KC_PGUP, 	KC_TRNS, 
				KC_TRNS, 			KC_TRNS, 		KC_TRNS, 		KC_TRNS, 									KC_TRNS, KC_TRNS, KC_TRNS, 			        	KC_TRNS, KC_TRNS, S(KC_DOT), 								       	KC_TRNS, 	TD(TD_HOME_SHIFT_HOME), KC_PGDN, 	TD(TD_END_SHIFT_END)),
	
	[2] = LAYOUT_3key_2us(
				KC_TRNS, 			KC_F1, 			KC_F2, 			KC_F3, 			ALGR(KC_8), ALGR(KC_9),	KC_TRNS, 																KC_TRNS, 		KC_F6, 		KC_F7, 			KC_F8, 		KC_F9, 		            KC_F10, 	KC_F11, 
				KC_TRNS, 			KC_AT, 			KC_TRNS, 		LSFT(KC_0), 	ALGR(KC_7), ALGR(KC_0), KC_TRNS, 																KC_TRNS, 		KC_TRNS, 	LSFT(KC_SLSH), 	KC_TRNS, 	KC_TRNS, 		        LSFT(KC_5), KC_F12, 				
				KC_TRNS, 			SE_AT,		 	LSFT(KC_NUHS), 	KC_NO, 			S(KC_8), 	S(KC_9), 	KC_TRNS, 																KC_TRNS,    	LSFT(KC_3), KC_TRNS, 		KC_TRNS, 	KC_TRNS, 		        KC_TRNS, 	KC_TRNS, 				
				KC_TRNS, 			KC_TRNS, 		KC_TRNS, 		KC_NO, 			KC_NUBS, 	S(KC_NUBS), 																						KC_TRNS, 	KC_SLSH, 		KC_TRNS, 	KC_TRNS, 		        KC_TRNS, 	KC_TRNS, 			
				KC_TRNS, 			KC_TRNS, 		KC_TRNS, 		KC_NO, 										KC_TRNS, KC_TRNS, KC_TRNS, 			        	KC_ENT, KC_TRNS, KC_TRNS, 										KC_TRNS, 	KC_TRNS, 	            KC_TRNS, 	KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _SELECTWORD:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
                unregister_code(KC_LCTL); // ctrl + left
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_RIGHT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT); // ctrl + shift + right
                register_code(KC_LSFT);
                tap_code(KC_LEFT);
                unregister_code(KC_LSFT); // shift left
            }
            return false;        
    }
    return true;
}