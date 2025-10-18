#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff81ff77), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff1d772a), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btnSnooze
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_snooze = obj;
            lv_obj_set_pos(obj, 31, 193);
            lv_obj_set_size(obj, 257, 29);
            lv_obj_add_event_cb(obj, action_snooze_alarm, LV_EVENT_PRESSED, &objects);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btntxtSnooze
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.btntxt_snooze = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Snooze");
                }
            }
        }
        {
            // pnl_grey
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_grey = obj;
            lv_obj_set_pos(obj, 183, 16);
            lv_obj_set_size(obj, 109, 141);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff376aeb), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // pnl_black
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.pnl_black = obj;
            lv_obj_set_pos(obj, 24, 16);
            lv_obj_set_size(obj, 109, 141);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff376aeb), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // txt_grey
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.txt_grey = obj;
            lv_obj_set_pos(obj, 221, 70);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FULL");
        }
        {
            // txt_black
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.txt_black = obj;
            lv_obj_set_pos(obj, 61, 70);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FULL");
        }
        {
            // lbl_black
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_black = obj;
            lv_obj_set_pos(obj, 59, 163);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Black");
        }
        {
            // lbl_grey
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_grey = obj;
            lv_obj_set_pos(obj, 223, 163);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Grey");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}
