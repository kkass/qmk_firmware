
#include "ergodox.h"
#include "led.h"
#include "debug.h"
#include "action_layer.h"
#include "action_code.h"

#define CTLG(kc)        RGUI(RCTL(kc))

#define _______ KC_TRNS

#define BASE                                             0 // default layer
#define SYMBOL                                           1
#define KEY_NAV                                          2
#define KEY_SEL                                          3 // key selection layer

// macros
#define MC_COPY_LINE                                     0
#define MC_CUT_LINE                                      1
#define MC_PASTE_LINE                                    2
#define MC_UNDO                                          3
#define MC_REDO                                          4
#define MC_SAVE                                          5
#define MC_LOCK                                          6


#define TD_ESC_CAPS                                      0
#define CT_SPC_ENT                                       1
#define CT_CPY_PST                                       2
#define CT_CLS_QIT                                       3
#define TD_AT_CLOSE                                      4
#define TD_VI_QUIT                                       5






const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0: Basic layer
 *
 * ,---------------------------------------------------.         ,---------------------------------------------------.
 * |   F13   |  F1  |  F2  |  F3  |  F4  |  F5  | Save |         | Save | Undo | Redo |      |      |      |   @   LK|
 * |---------+------+------+------+------+-------------|         |------+------+------+------+------+------+---------|
 * |CLOS QUIT|  ;:  |  ,<  |  .>  |   P  |   Y  |      |         |  _   |   F  |   G  |   C  |   C  |   R  |   #     |
 * |---------+------+------+------+------+------|      |         |  -   |------+------+------+------+------+---------|
 * | LShift  |   A  |   O  |   E  |   U  |   I  |------|         |------|   D  |   H  |   T  |   N  |   S  |\| RShift|
 * |---------+------+------+------+------+------| Hyper|         | TAB  |------+------+------+------+------+---------|
 * |`~ Cmd   |  '"  |   Q  |   Q  |   J  |   K  |      |         | Meh  |   B  |   M  |   W  |   V  |   Z  |/? Cmd   |
 * `---------+------+------+------+------+-------------'         `-------------+------+------+------+------+---------'
 *   |  CTL  |  ALT |  L1  | Left | Right|                                     |  Up  | Down |  L1  |  CTL |  ALT  |
 *   `-----------------------------------'                                     `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |  DEL |  L2  |       |Esc/Caps|      |
 *                                 ,------|------|------|       |--------+------+------.
 *                                 |      |  CP  | Home |       |  PgUp  |      |      |
 *                                 | BkSp |  PST |------|       |--------|Enter | Space|
 *                                 |      |  CT  | End  |       |  PgDn  |      |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = KEYMAP(
       // left hand
       KC_F13,        KC_F1,          KC_F2,         KC_F3,         KC_F4,         KC_F5,          TD(TD_VI_QUIT),
       TD(CT_CLS_QIT),KC_SCLN,        KC_COMM,       KC_DOT,        KC_P,          KC_Y,           _______,
       KC_LSHIFT,     KC_A,           KC_O,          KC_E,          KC_U,          KC_I,
       GUI_T(KC_GRV), KC_QUOT,        KC_Q,          KC_J,          KC_K,          KC_X,           KC_HYPR,

       // lower keys
                      KC_LCTRL,       KC_LALT,       TG(SYMBOL),    KC_LEFT,       KC_RGHT,

       // thumb cluster
                                                                                   KC_DEL,         TG(KEY_NAV),
                                                                                                   KC_HOME,
                                                                    KC_BSPC,       TD(CT_CPY_PST), KC_END,

       // right hand
       M(MC_SAVE),    M(MC_UNDO),     M(MC_REDO),    _______,       _______,       _______,         TD(TD_AT_CLOSE),
       KC_MINS,       KC_F,           KC_G,          KC_C,          KC_R,          KC_L,            KC_HASH,
                      KC_D,           KC_H,          KC_T,          KC_N,          KC_S,            SFT_T(KC_BSLS),
       MEH_T(KC_TAB), KC_B,           KC_M,          KC_W,          KC_V,          KC_Z,            GUI_T(KC_SLSH),

       // lower keys
                      KC_UP,          KC_DOWN,       OSL(SYMBOL),   KC_LCTRL,      KC_LALT,

       // thumb cluster
       TD(TD_ESC_CAPS), _______,
       KC_PGUP,
       KC_PGDN,         KC_ENT,         KC_SPC
    ),

/* Layer 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F13  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  ^F16  |   &  |   @  |   {  |   }  |   !  |   |  |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   F16  |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|   ?  |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   .  |   1  |   2  |   3  |   \  |    /   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTL  |  ALT |  L0  | Left | Right|                                       |   0  |   .  |  L0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | BkSp |      |------|       |------|  =   | Space|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMBOL] = KEYMAP(
       // left hand
       KC_F13,        KC_F1,          KC_F2,         KC_F3,         KC_F4,         KC_F5,          _______,
       LCTL(KC_F16),  KC_AMPR,        KC_AT,         KC_LCBR,       KC_RCBR,       KC_EXLM,        KC_PIPE,
       KC_F16,        KC_HASH,        KC_DLR,        KC_LPRN,       KC_RPRN,       KC_GRV,
       _______,       KC_PERC,        KC_CIRC,       KC_LBRC,       KC_RBRC,       KC_TILD,        KC_QUES,

       // lower keys
                      KC_LCTRL,       KC_LALT,       _______,       KC_LEFT,       KC_RGHT,

       // thumb cluster
                                                                                   _______,        _______,
                                                                                                   _______,
                                                                    KC_BSPC,       _______,        _______,

       // right hand
       _______,       KC_F6,          KC_F7,         KC_F8,         KC_F9,         KC_F10,         KC_F11,
       _______,       KC_UP,          KC_7,          KC_8,          KC_9,          KC_ASTR,        KC_F12,
                      KC_DOWN,        KC_4,          KC_5,          KC_6,          KC_PLUS,        _______,
       _______,       KC_DOT,         KC_1,          KC_2,          KC_3,          KC_BSLS,        KC_SLSH,

                      KC_0,           KC_DOT,        _______,       KC_EQL,        _______,

       // thumb cluster
       _______,       _______,
       _______,
       _______,       KC_EQL,        KC_SPC
),

/* Layer 2: Navigation Layer
 *
 * ,---------------------------------------------------.         ,---------------------------------------------------.
 * |         |      |      |      |      |      |      |         |      |      |      |      |      |      |         |
 * |---------+------+------+------+------+-------------|         |------+------+------+------+------+------+---------|
 * |         |      |      |      |      |      |      |         |      |      | Home |  Up  |  End |      | Cpy Line|
 * |---------+------+------+------+------+------|      |         |      |------+------+------+------+------+---------|
 * |         |      |      |      |      |      |------|         |------|      | Left | Dovn | Right|      | Cut Line|
 * |---------+------+------+------+------+------|      |         |      |------+------+------+------+------+---------|
 * |   Cmd   |      |      |      |      |      |      |         |      |      | PgDn |      | PgUp |      | Pst Line|
 * `---------+------+------+------+------+-------------'         `-------------+------+------+------+------+---------'
 *   |  CTL  |  ALT |      |      |      |                                     |      |      |      |      |      |
 *   `-----------------------------------'                                     `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |  L0  |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[KEY_NAV] = KEYMAP(
       // left hand
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,
       KC_LGUI,_______,_______,_______,_______,_______,_______,
               // bottom row
               KC_LCTRL, KC_LALT,_______,_______,_______,
                                       // thumb cluster
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______,        _______,    _______,    _______,    _______,        _______,
       _______, _______,        KC_HOME,    KC_UP,      KC_END,     _______,        M(MC_COPY_LINE),
                _______,        KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,        M(MC_CUT_LINE),
       _______, _______,        KC_PGDN,    _______,    KC_PGUP,    _______,        M(MC_PASTE_LINE),
                // bottom row
                _______, _______, _______,  _______,    _______,
       // thumb cluster
       _______, _______,
       _______,
       _______, _______, _______
),

// key selection layer
/* Keymap :
 *
 * ,---------------------------------------------------.         ,---------------------------------------------------.
 * |         |      |      |      |      |      |      |         |      |      |      |      |      |      |         |
 * |---------+------+------+------+------+-------------|         |------+------+------+------+------+------+---------|
 * |         |      |      |      |      |      |      |         |      |      |      |      |      |      |         |
 * |---------+------+------+------+------+------|      |         |      |------+------+------+------+------+---------|
 * |         |      |      |      |      |      |------|         |------|      |      |      |      |      |         |
 * |---------+------+------+------+------+------|      |         |      |------+------+------+------+------+---------|
 * |         |      |      |      |      |      |      |         |      |      |      |      |      |      |         |
 * `---------+------+------+------+------+-------------'         `-------------+------+------+------+------+---------'
 *   |       |      |      |      |      |                                     |      |      |      |      |      |
 *   `-----------------------------------'                                     `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[KEY_SEL] = KEYMAP(
       // left hand
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
               // bottom row
               _______,_______,_______,_______,_______,
                                       // thumb cluster
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______,       _______,             _______,       _______,       _______,        _______,              _______,
       RSFT(KC_PGUP), RSFT(KC_PGDN),       RSFT(KC_HOME), RSFT(KC_UP),   RSFT(KC_END),   RSFT(KC_PGUP),        M(MC_COPY_LINE),
                      RSFT(RCTL(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(RCTL(KC_RIGHT)), M(MC_CUT_LINE),
       RSFT(KC_PGDN), _______,             RCTL(KC_C),    RCTL(KC_X),    RCTL(KC_V),     _______,              M(MC_PASTE_LINE),
                // bottom row
                _______, _______, _______,  _______,    _______,
       // thumb cluster
       _______, _______,
       _______,
       _______, _______, _______
),

};


//Tap Dance Definitions

void copy_paste(qk_tap_dance_state_t *state, void *user_data)
{
  if ( state->count == 1 )
  {
    // Copy
    register_code(KC_LGUI);
    register_code(KC_C);
    unregister_code(KC_C);
    unregister_code(KC_LGUI);
  }
  else if ( state->count == 2 )
  {
    // Paste
    register_code(KC_LGUI);
    register_code(KC_V);
    unregister_code(KC_V);
    unregister_code(KC_LGUI);
  }
  else if ( state->count == 3 )
  {
    // Cut
    register_code(KC_LGUI);
    register_code(KC_X);
    unregister_code(KC_X);
    unregister_code(KC_LGUI);
  }
}

void close_quit(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    // Close Window
    register_code(KC_LGUI);
    register_code(KC_W);
    unregister_code(KC_W);
    unregister_code(KC_LGUI);
  }
  else if (state->count == 3)
  {
    // Quit App
    register_code(KC_LGUI);
    register_code(KC_Q);
    unregister_code(KC_Q);
    unregister_code(KC_LGUI);
  }
}

#define type_code(X)  register_code(X); unregister_code(X)

void vi_quit(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 1)
  {
    // VI Write
    type_code(KC_ESC);
    wait_ms(30);
    register_code(KC_LSHIFT);
    type_code(KC_SCLN);
    unregister_code(KC_LSHIFT);
    type_code(KC_W);
    type_code(KC_ENT);
  }
  else if (state->count == 2)
  {
    // VI Write Quit
    type_code(KC_ESC);
    wait_ms(30);
    register_code(KC_LSHIFT);
    type_code(KC_SCLN);
    unregister_code(KC_LSHIFT);
    type_code(KC_W);
    type_code(KC_Q);
    type_code(KC_ENT);
  }
  else if (state->count == 3)
  {
    // VI Quit Out
    type_code(KC_ESC);
    wait_ms(30);
    register_code(KC_LSHIFT);
    type_code(KC_SCLN);
    unregister_code(KC_LSHIFT);
    type_code(KC_Q);
    register_code(KC_LSHIFT);
    type_code(KC_1);
    unregister_code(KC_LSHIFT);
    type_code(KC_ENT);
  }
}

void at_lock(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 1)
  {
    // Send @
    register_code(KC_LSFT);
    register_code(KC_2);
    unregister_code(KC_2);
    unregister_code(KC_LSFT);
  }
  else if (state->count == 2)
  {
    // Lock screen
    register_code(KC_LCTL);
    register_code(KC_LSFT);
    //register_code(KC_EJCT);
    //register_code(0x7f);
    register_code(KC_PWR);
    wait_ms(500);
    unregister_code(KC_PWR);
    //unregister_code(KC_EJCT);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
  }
}

void esc_caps(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 1)
  {
    // Send ESC
    register_code(KC_ESC);
    unregister_code(KC_ESC);
  }
  else if (state->count == 2)
  {
    // Send Caps Lock
    register_code(KC_CAPS);
    wait_ms(500);
    unregister_code(KC_CAPS);
  }
}


qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_FN(esc_caps),
  [CT_SPC_ENT]   = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [CT_CPY_PST]   = ACTION_TAP_DANCE_FN(copy_paste),
  [CT_CLS_QIT]   = ACTION_TAP_DANCE_FN(close_quit),
  [TD_AT_CLOSE]  = ACTION_TAP_DANCE_FN(at_lock),
  [TD_VI_QUIT]   = ACTION_TAP_DANCE_FN(vi_quit)
};

#define MACRO_ON_PRESS(ID, ...) \
    case ID: \
        if (record->event.pressed) { \
            return MACRO(__VA_ARGS__, END); \
        } \
        break;


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {

        MACRO_ON_PRESS(MC_COPY_LINE, T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(C), U(LCTL));
        MACRO_ON_PRESS(MC_CUT_LINE, T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(X), U(LCTL));
        MACRO_ON_PRESS(MC_PASTE_LINE, T(ENTER), D(LCTL), T(V), U(LCTL));
        MACRO_ON_PRESS(MC_UNDO, D(LGUI), T(Z), U(LGUI));
        MACRO_ON_PRESS(MC_REDO, D(LGUI), D(LSHIFT), T(Z), U(LSHIFT), U(LGUI));
        MACRO_ON_PRESS(MC_SAVE, D(LGUI), T(S), U(LGUI));
        MACRO_ON_PRESS(MC_LOCK, D(LCTL), D(LSFT), D(EJCT), W(10), U(EJCT), U(LSFT), U(LCTL));

    }
    return MACRO_NONE;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

    return;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case SYMBOL:
            ergodox_right_led_2_on();
            break;
        case KEY_NAV:
        case KEY_SEL:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }
    return;
};
