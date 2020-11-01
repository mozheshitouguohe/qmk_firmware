#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

// Tap Dance declarations	//   One tap    |  Two taps
enum {						// -------------+-----------
 // TD_DOT_QMARK,			// 	  .		    |	  ?
	TD_QUOTES,				//	  '		    |	  "
	TD_SPACE_DOT,			//	 Space	    |	  . + Space
	TD_LBRC_LCBR,			//	  [         |     {
	TD_RBRC_RCBR,			//	  ]         |     }
	TD_LPRN_LT,				//	  (		    |	  <
	TD_RPRN_GT,				//	  )		    |	  >	
    TD_BSLSH_PIPE,			// Backslash    |	  |	
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

void dance_lbrc_lcbr_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(ALGR(KC_8));
    } else {
        register_code16(ALGR(KC_7));
    }
}

void dance_lbrc_lcbr_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(ALGR(KC_8));
    } else {
        unregister_code16(ALGR(KC_7));
    }
}

void dance_rbrc_rcbr_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(ALGR(KC_9));
    } else {
        register_code16(ALGR(KC_0));
    }
}

void dance_rbrc_rcbr_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(ALGR(KC_9));
    } else {
        unregister_code16(ALGR(KC_0));
    }
}

void dance_lprn_lt_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(S(KC_8));
    } else {
        register_code(KC_NUBS);
    }
}

void dance_lprn_lt_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(S(KC_8));
    } else {
        unregister_code(KC_NUBS);
    }
}

void dance_rprn_gt_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(S(KC_9));
    } else {
        register_code16(S(KC_NUBS));
    }
}

void dance_rprn_gt_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(S(KC_9));
    } else {
        unregister_code16(S(KC_NUBS));
    }
}

void dance_bslsh_pipe_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(ALGR(KC_MINS));
    } else {
        register_code16(ALGR(KC_NUBS));
    }
}

void dance_bslsh_pipe_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(ALGR(KC_MINS));
    } else {
        unregister_code16(ALGR(KC_NUBS));
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
	[TD_LBRC_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lbrc_lcbr_finished, dance_lbrc_lcbr_reset),
	[TD_RBRC_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rbrc_rcbr_finished, dance_rbrc_rcbr_reset),
	[TD_LPRN_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lprn_lt_finished, dance_lprn_lt_reset),
	[TD_RPRN_GT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rprn_gt_finished, dance_rprn_gt_reset),
    [TD_BSLSH_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_bslsh_pipe_finished, dance_bslsh_pipe_reset),
    [TD_HOME_SHIFT_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_home_shift_home_finished, dance_home_shift_home_reset),
    [TD_END_SHIFT_END] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_end_shift_end_finished, dance_end_shift_end_reset),    
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   /  |           | \ |  |   6  |   7  |   8  |   9  |   0  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * |  '  "  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |   <  |           |  >   |   N  |   M  |   ,  |   .  |  UP  | Shft,´ |
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
 */
	[0] = LAYOUT_3key_2us(
				KC_ESC, 			KC_1, 			KC_2, 			KC_3, 			KC_4, 		KC_5, 		LSFT(KC_7), 															TD(TD_BSLSH_PIPE), KC_6, 	KC_7, 			KC_8, 		KC_9, 		            KC_0, 		SE_PLUS, 
				KC_TAB, 			KC_Q, 			KC_W, 			KC_E, 			KC_R, 		KC_T, 		TD(TD_LBRC_LCBR), 														TD(TD_RBRC_RCBR), KC_Y, 	KC_U, 			KC_I, 		KC_O, 		            KC_P, 		KC_LBRC, 
				TD(TD_QUOTES), 		KC_A, 			KC_S, 			KC_D, 			KC_F, 		KC_G, 		TD(TD_LPRN_LT), 														TD(TD_RPRN_GT), KC_H, 		KC_J, 			KC_K, 		KC_L, 		            KC_SCLN, 	KC_QUOT, 
				KC_LSFT, 			KC_Z, 			KC_X, 			KC_C, 			KC_V, 		KC_B, 																								KC_N, 		KC_M, 			KC_COMM,	KC_DOT, 	            KC_UP, 		RSFT_T(KC_EQL), 
				KC_LCTL, 			KC_LGUI, 		KC_LALT, 		KC_RALT, 									KC_BSPC, TD(TD_SPACE_DOT), LT(1,KC_ENT), 		LT(2,KC_ENT), KC_DEL, KC_DOT, 									KC_SLSH, 	KC_LEFT,	            KC_DOWN, 	KC_RGHT),

	[1] = LAYOUT_3key_2us(
				KC_TRNS, 			KC_F1, 			KC_F2, 			KC_F3, 			KC_F4, 		KC_F5, 		KC_NO, 																	KC_TRNS, 		KC_F6, 		KC_F7, 			KC_F8, 		KC_F9, 	                KC_F10, 	KC_F11, 
				KC_TRNS, 			KC_TRNS, 		KC_TRNS, 		KC_MS_BTN1, 	KC_MS_UP, 	KC_MS_BTN2, KC_PGUP, 																KC_TRNS, 		KC_TRNS, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 	            KC_TRNS, 	KC_F12, 
				KC_TRNS, 			KC_TRNS, 		LCTL(KC_S), 	KC_MS_LEFT,		KC_MS_DOWN, KC_MS_RIGHT,KC_PGDN, 																KC_TRNS, 		KC_HOME, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 	            KC_TRNS,    KC_TRNS, 
				KC_TRNS, 			LCTL(KC_Z), 	LCTL(KC_X), 	LCTL(KC_C), 	LCTL(KC_V), KC_TRNS, 																							KC_END, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 	            KC_PGUP, 	KC_TRNS, 
				KC_TRNS, 			KC_TRNS, 		KC_TRNS, 		KC_TRNS, 										KC_TRNS, KC_TRNS, KC_TRNS, 				KC_TRNS, KC_TRNS, KC_TRNS, 								        	KC_TRNS, 	TD(TD_HOME_SHIFT_HOME), KC_PGDN, 	TD(TD_END_SHIFT_END)),
	
	[2] = LAYOUT_3key_2us(
				KC_NO, 				KC_F1, 			KC_F2, 			KC_F3, 			KC_F4, 		KC_F5, 		SE_QUOT, 																SE_PIPE, 		KC_F6, 		KC_F7, 			KC_F8, 		KC_F9, 		            KC_F10, 	KC_F12, 
				KC_NO, 				KC_AT, 			KC_NO, 			LSFT(KC_0), 	KC_NO, 		KC_NO, 		SE_LCBR, 																SE_RCBR, 		KC_NO, 		LSFT(KC_SLSH), 	KC_NO, 		KC_NO, 		            LSFT(KC_5), KC_NO, 				
				KC_NO, 				SE_AT,		 	LSFT(KC_NUHS), 	KC_NO, 			KC_NO, 		KC_NO, 		SE_LABK, 																S(SE_LABK), 	LSFT(KC_3), KC_NO, 			KC_NO, 		KC_NO, 		            KC_NO, 		KC_NO, 				
				KC_NO, 				KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 																								KC_NO, 		KC_SLSH, 		KC_NO, 		KC_NO, 		            KC_PGUP, 	KC_NO, 			
				KC_NO, 				KC_NO, 			KC_NO, 			KC_NO, 										KC_NO, KC_SPC, KC_ENT, 				KC_ENT, KC_DEL, KC_TRNS, 													KC_NO, 		KC_LEFT, 	            KC_PGDN, 	KC_RGHT)
};