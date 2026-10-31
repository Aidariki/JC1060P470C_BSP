#include "bsp/touch.h"
#include "bsp/esp-bsp.h"
#include "esp_log.h"
#include "esp_lcd_touch_gt911.h"
#include "esp_lvgl_port.h"

static const char *TAG = "bsp_touch";
static esp_lcd_touch_handle_t s_touch_handle = NULL;

esp_err_t bsp_touch_new(esp_lcd_touch_handle_t *ret_touch)
{
    bsp_i2c_init();
    const esp_lcd_touch_config_t tp_cfg = {
        .x_max = BSP_LCD_H_RES,
        .y_max = BSP_LCD_V_RES,
        .rst_gpio_num = (gpio_num_t)BSP_TOUCH_RST_GPIO,
        .int_gpio_num = (gpio_num_t)BSP_TOUCH_INT_GPIO,
        .levels = { .reset = 0, .interrupt = 0 },
        .flags = { .swap_xy = 0, .mirror_x = 0, .mirror_y = 0 },
    };
    ESP_LOGI(TAG, "Регистрация тачскрина GT911 (I2C addr: 0x%02X)", BSP_TOUCH_I2C_ADDR);
    const lvgl_port_touch_cfg_t touch_cfg = {
        .disp = NULL,
        .handle = s_touch_handle,
    };
    lvgl_port_add_touch(&touch_cfg);
    if (ret_touch) *ret_touch = s_touch_handle;
    return ESP_OK;
}
