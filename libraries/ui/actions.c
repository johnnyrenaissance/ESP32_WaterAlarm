#include "actions.h"
#include "structs.h"
#include <lvgl.h>


void action_snooze_alarm(lv_event_t* e) {
	LV_LOG_USER("in snooze");
	objects_t *objects = (objects_t *) lv_event_get_user_data(e);
	lv_obj_t *txt_grey = objects->txt_grey;

    //lv_label_set_text(txt_grey, "Pushed");
	cv.is_snoozed = true;

	// Set the alarm to 1,000,000 microseconds (1 second)
	// `true` for autoreload, `0` for unlimited count
	//timerAlarm(cv.timer, 3600000000, false, 0);
	timerAlarm(cv.timer, 10000000, false, 0);

    // TODO: Implement action snooze_alarm here
}
