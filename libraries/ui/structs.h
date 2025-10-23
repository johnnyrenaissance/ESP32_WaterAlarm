#ifndef EEZ_LVGL_UI_STRUCTS_H
#define EEZ_LVGL_UI_STRUCTS_H

#include <stdbool.h>
#include "esp32-hal-timer.h"

typedef struct _objects_t {
    lv_obj_t* main;
    lv_obj_t* btn_snooze;
    lv_obj_t* btntxt_snooze;
    lv_obj_t* pnl_grey;
    lv_obj_t* pnl_black;
    lv_obj_t* txt_grey;
    lv_obj_t* txt_black;
    lv_obj_t* lbl_black;
    lv_obj_t* lbl_grey;
} objects_t;

extern objects_t objects;

typedef struct _control_vars {
    bool is_black_full;
    bool is_grey_full;
    bool last_black_state;
    bool last_grey_state;
    bool is_snoozed;
    hw_timer_t* timer;
} control_vars;

extern control_vars cv;

#if defined(EEZ_FOR_LVGL)

#include <eez/flow/flow.h>
#include <stdint.h>
#include <stdbool.h>

#include "vars.h"

using namespace eez;





#endif

#endif /*EEZ_LVGL_UI_STRUCTS_H*/
