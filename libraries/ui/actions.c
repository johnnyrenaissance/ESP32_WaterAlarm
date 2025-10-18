#include "actions.h"
#include "structs.h"
#include <lvgl.h>


void action_snooze_alarm(lv_event_t* e) {
	LV_LOG_USER("in snooze");
	objects_t *objects = (objects_t *) lv_event_get_user_data(e);
	lv_obj_t *txt_grey = objects->txt_grey;

    lv_label_set_text(txt_grey, "Pushed");


    // TODO: Implement action snooze_alarm here
}
