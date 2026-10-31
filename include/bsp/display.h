#pragma once

#include "esp_err.h"
#include "bsp/board_pins.h"
#include "esp_lcd_types.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

lv_disp_t *bsp_display_start(void);
bool bsp_display_lock(uint32_t timeout_ms);
void bsp_display_unlock(void);
esp_err_t bsp_display_set_brightness(uint8_t percent);

#ifdef __cplusplus
}
#endif
