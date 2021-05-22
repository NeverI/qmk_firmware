/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(SYMB, KC_SPC):
            return 50;
        case LT(NUMB, KC_BSPC):
            return 50;
        default:
            return TAPPING_TERM;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Combomap
 *
 * ,-------------------------------------------------.       ,------------------------------------------.
 * |         |        |          |          |        |      |         |         |       |          |    |
 * |-WHDOWN-----RMB-------MMB--------LMB-------WHUP--|      |--MLEFT-----MDOWN-----MUP-----MRIGHT-------|
 * |         |        |          |          |        |      |         |         |       |          |    |
 * |------------HOME-----PGDOWN-----PAGEUP-----END---|      |--LEFT------DOWN------UP------RIGHT--------|
 * |         |        |          |          |        |      |         |         |       |          |    |
 * `-------------------------------------------------'		  `-------------------------------------------'
 *  .-------------------------.           .-----------------.
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------'
 */

/* Keymap 0: Basic layer
 *
 * ,----------------------------------.       ,---------------------------------.
 * |     Q    |  W  |  F  |  P  |  B  |      |  J  |  K  |  U  |  Y  |     ;    |
 * |----------------------------------|      |----------------------------------|
 * |  SHFT/A  |  R  |  S  |  T  |  G  |      |  M  |  N  |  E  |  I  |  SHFT/O  |
 * |----------------------------------|		   |----------------------------------|
 * |  CTRL/Z  |  X  |  C  |  D  |  V  |      |  H  |  L  |  ,  |  .  |  CTRL/-  |
 * `----------------------------------'		   `----------------------------------'
 * .--------------------------------------.  .-------------------------------------.
 * |  ESC/META  |  SPC(SYM)  |  ENT/ALT  |  |  ESC/META  |  BSPC(NUM)  |  TAB/ALT  |
 * '--------------------------------------'  '-------------------------------------'
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q,  			 			 KC_W, KC_F, KC_P, KC_B,  	KC_J, KC_K, KC_U,    KC_Y, 	 ALGR(KC_COMM),
    MT(MOD_LSFT, KC_A),KC_R, KC_S, KC_T, KC_G,  	KC_M, KC_N, KC_E,    KC_I, 	 MT(MOD_LSFT, KC_O),
    MT(MOD_LCTL, KC_Z),KC_X, KC_C, KC_D, KC_V,  	KC_H, KC_L, KC_COMM, KC_DOT, MT(MOD_LCTL, KC_SLSH),

 		MT(MOD_LGUI, KC_ESC), LT(SYMB, KC_SPC), MT(MOD_LALT, KC_ENT),	 // Left
		MT(MOD_LGUI, KC_ESC), LT(NUMB, KC_BSPC),  MT(MOD_LALT, KC_TAB)	 // Right
    ),
/* Keymap 1: Symbols layer
 * ,-----------------------------------.       ,---------------------------------.
 * |      \    |  "  |  <  |  >  |  `  |      |  |  |  Ü  |  Ú  |  Ű  |     Ő    |
 * |-----------------------------------|      |----------------------------------|
 * |  SHFT/Á   |  '  |  [  |  ]  |  ^  |      |  $  |  /  |  É  |  Í  |  SHFT/Ó  |
 * |-----------------------------------|		  |----------------------------------|
 * |  CTRL/DEL |  ~  |  {  |  }  |  #  |      |  &  |  %  |  !  |  @  |  CTRL/Ö  |
 * `-----------------------------------'		   `---------------------------------'
 * .--------------------------------------.  .-------------------------------------.
 * |  ESC/META  |  SPC(SYM)  |  ENT/ALT  |  |  ESC/META  |  BSPC(NUM)  |  TAB/ALT  |
 * '--------------------------------------'  '-------------------------------------'
 */
[SYMB] = LAYOUT_gergoplex(
    ALGR(KC_Q),            LSFT(KC_2), ALGR(KC_M), ALGR(KC_DOT), ALGR(KC_7),   // Left
      ALGR(KC_W),    KC_MINS,    KC_RBRC,    KC_BSLS,    KC_0,              // Right
    MT(MOD_LSFT, KC_QUOT), LSFT(KC_1), ALGR(KC_F), ALGR(KC_G),   ALGR(KC_3),   // Left
      ALGR(KC_SCLN), LSFT(KC_6), KC_SCLN,    ALGR(KC_J), MT(MOD_LSFT, KC_EQL), // Right
    MT(MOD_LSFT, KC_DEL),  ALGR(KC_1), ALGR(KC_B), ALGR(KC_N),   ALGR(KC_X),  // Left
      ALGR(KC_C),    LSFT(KC_5), LSFT(KC_4), ALGR(KC_V), MT(MOD_LCTL, KC_LBRC),   // Right

      KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Combomap
 *
 * ,----------------------------------------------.       ,------------------------------------------.
 * |      |          |           |           |    |      |         |         |       |          |    |
 * |--------VOLDOWN------MUTE--------VOLUP--------|      |-------------------------------------------|
 * |      |          |           |           |    |      |         |         |       |          |    |
 * |--------PREVTRK-----PLYSTOP-----NEXTTRK-------|      |-------------------------------------------|
 * |      |          |           |           |    |      |         |         |       |          |    |
 * `----------------------------------------------'		    `------------------------------------------'
 *  .-------------------------.                              .-----------------.
 *  |        |       |        |                              |        |    |   |
 *  '-------------------------'                              '-----------------'
 */
/* Keymap 2: Pad/Function layer
 * ,---------------------------------------.      ,------------------------------------.
 * |     F10    |  F7  |  F8  |  F9  |  /  |      |  (  |  7  |  8  |  9  |      )     |
 * |---------------------------------------|      |------------------------------------|
 * |  SHFT/F11  |  F4  |  F5  |  F6  |  =  |      |  *  |  4  |  5  |  6  |   SHFT/0   |
 * |--------------------------+------------|		  |------------------------------------|
 * |  CTRL/F12  |  F1  |  F2  |  F3  |  %  |      |  +  |  1  |  2  |  3  |  CTRL/ENT  |
 * `---------------------------------------'		  `------------------------------------'
 * .--------------------------------------.  .-------------------------------------.
 * |  ESC/META  |  SPC(SYM)  |  ENT/ALT  |  |  ESC/META  |  BSPC(NUM)  |  TAB/ALT  |
 * '--------------------------------------'  '-------------------------------------'
 */
[NUMB] = LAYOUT_gergoplex(
    KC_F10,               KC_F7, KC_F8, KC_F9, LSFT(KC_6),    LSFT(KC_8),     KC_7, KC_8, KC_9, LSFT(KC_9),
    MT(MOD_LSFT, KC_F11), KC_F4, KC_F5, KC_F6, LSFT(KC_7),    ALGR(KC_SLSH),  KC_4, KC_5, KC_6, MT(MOD_LSFT, KC_GRV),
    MT(MOD_LCTL, KC_F12), KC_F1, KC_F2, KC_F3, LSFT(KC_5),    LSFT(KC_3),     KC_1, KC_2, KC_3, MT(MOD_LCTL, KC_ENT),

    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
    )
};
