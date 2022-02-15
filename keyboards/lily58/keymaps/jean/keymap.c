#include QMK_KEYBOARD_H

enum layer_number {
  QWERTY = 0,
  LOWER = 1,
  RAISE = 2,
  ADJUST = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |= y + |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAP  |LSFT-A|   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |RSFT-;|  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  -   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |Space | /LOWER  /       \RAISE \  |Space |ADJUST|  `   |
 *                   |      |      |      |/ DEL   /         \Enter \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [QWERTY] = LAYOUT( \
    KC_ESC,   KC_1,         KC_2,    KC_3, KC_4, KC_5,                     KC_6, KC_7, KC_8,    KC_9,   KC_0,            KC_BSPC,\
    KC_TAB,   KC_Q,         KC_W,    KC_E, KC_R, KC_T,                     KC_Y, KC_U, KC_I,    KC_O,   KC_P,            KC_EQL,\
    KC_CAPS,  LSFT_T(KC_A), KC_S,    KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K,    KC_L,   RSFT_T(KC_SCLN), KC_QUOT,\
    KC_LCTRL, KC_Z,         KC_X,    KC_C, KC_V, KC_B, KC_LBRC,   KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,         KC_MINS,\
                   KC_LALT, KC_LGUI, KC_SPC, LT(LOWER, KC_DEL), LT(RAISE, KC_ENT), KC_SPC, MO(ADJUST), KC_GRV\
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  UP  |      | WREF |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LEFT | DOWN | RGHT |      |      |-------.    ,-------|      |      |      |      |      | BRIU |
 * |------+------+------+------+------+------|   /   |    | \ y | |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MYCM|      |      |      | BRID |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [LOWER] = LAYOUT( \
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,\
    XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_WREF, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIU,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_BSLS, XXXXXXX, KC_MYCM, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,\
                              XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      | HOME |  END | PGUP | PGDN |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | MUTE | VOLU | MPLY |      |      |                    |      |      |      | PAUS | PSCR |  INS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | MPRV | VOLD | MNXT |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      | CALC |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [RAISE] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_DEL,\
    XXXXXXX, KC_MUTE, KC_VOLU, KC_MPLY, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS, KC_PSCR, KC_INS,\
    XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | M_P  | M_B  | M_R  | M_SW | M_SN | M_K  |                    | M_X  | M_G  | M_T  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | TOG  | HUI  | MOD  | VAI  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | SAI  | HUD  | SAD  | VAD  |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |ADJUST| /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [ADJUST] = LAYOUT( \
    RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K,                   RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, RGB_TOG, RGB_HUI, RGB_MOD,  RGB_VAI,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, RGB_SAI, RGB_HUD, RGB_SAD,  RGB_VAD,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX\
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return state; //update_tri_layer_state(state, LOWER, RAISE, ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
