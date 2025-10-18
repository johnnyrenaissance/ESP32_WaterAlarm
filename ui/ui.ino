#include <lvgl.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <XPT2046_Touchscreen.h>



// Touchscreen pins
#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS

// TODO: Replace with your screen resolution
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

bool touched = false;
bool coordinatesSet = false;

// TODO: Replace with your screen's touch controller
SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

TFT_eSPI tft = TFT_eSPI();
//TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight);
//TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

int x, y, z;

void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  // TODO: Replace with your custom touch-screen handling logic!

  TS_Point p = touchscreen.getPoint();
  touched = (p.z > 375);// && p.z < 415);

  //float x = 1.0f * p.x - 200.0f;
  //float y = 1.0f * p.y - 135.0f;
  //x = (x / 685.0f) * 240.0f;
  //y = (y / 735.0f) * 320.0f;

  //x = (x - 480.0f) * -1.0f - 240;
  //y = (y - 640.0f) * -1.0f - 320;

    x = map(p.x, 200, 3700, 1, screenWidth);
    y = map(p.y, 240, 3800, 1, screenHeight);
    z = p.z; // for debug
  printTouchToSerial(x, y, z);

  if(touched && !coordinatesSet)
  {
    data->state = LV_INDEV_STATE_PR;

    
    data->point.x = x;
    data->point.y = y;

    coordinatesSet = true; 
  }
  
  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
    coordinatesSet = false;
  }
}

// Print Touchscreen info about X, Y and Pressure (Z) on the Serial Monitor
void printTouchToSerial(int touchX, int touchY, int touchZ) {
  Serial.print("X = ");
  Serial.print(touchX);
  Serial.print(" | Y = ");
  Serial.print(touchY);
  Serial.print(" | Pressure = ");
  Serial.print(touchZ);
  Serial.println();
}

void setup()
{
  lv_init();

  // Start the SPI for the touchscreen and init the touchscreen
  touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  touchscreen.begin(touchscreenSPI);

  tft.begin();
  tft.setRotation(1);

  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

  // Register the custom display function
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init( &disp_drv );
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register( &disp_drv );

  // Register the custom touch-input handler
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register( &indev_drv );

  // Init EEZ-Studio UI
  ui_init();
}

void loop() {
  lv_timer_handler();
    Serial.begin(115200);



  // Update EEZ-Studio UI
  ui_tick();
}
