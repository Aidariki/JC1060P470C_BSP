#pragma once

#include "esp_err.h"
#include "bsp/board_pins.h"
#include "esp_lcd_touch.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t bsp_touch_new(esp_lcd_touch_handle_t *ret_touch);

#ifdef __cplusplus
}
#endif
