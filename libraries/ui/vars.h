#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum ThisWasAGarbageEnum_BadEEZ {
    FLOW_GLOBAL_VARIABLE_IS_BLACK_FULL = 0,
    FLOW_GLOBAL_VARIABLE_IS_GREY_FULL = 1,
    FLOW_GLOBAL_VARIABLE_LAST_BLACK_STATE = 2,
    FLOW_GLOBAL_VARIABLE_LAST_GREY_STATE = 3,
    FLOW_GLOBAL_VARIABLE_IS_SNOOZED = 4
};

// Native global variables

extern bool get_var_is_black_full();
extern void set_var_is_black_full(bool value);
extern bool get_var_is_grey_full();
extern void set_var_is_grey_full(bool value);
extern bool get_var_last_black_state();
extern void set_var_last_black_state(bool value);
extern bool get_var_last_grey_state();
extern void set_var_last_grey_state(bool value);
extern bool get_var_is_snoozed();
extern void set_var_is_snoozed(bool value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/