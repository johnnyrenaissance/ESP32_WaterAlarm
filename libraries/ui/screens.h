#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>
#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif


enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/