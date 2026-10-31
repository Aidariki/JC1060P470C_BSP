#include "bsp/display.h"
#include "bsp/board_pins.h"
#include "esp_log.h"
#include "esp_lvgl_port.h"
#include "driver/ledc.h"

static const char *TAG = "bsp_display";
static lv_disp_t *s_display = NULL;

static esp_err_t bsp_display_init_backlight(void)
{
    const ledc_timer_config_t timer_conf = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_10_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 5000,
        .clk_cfg = LEDC_AUTO_CLK,
    };
    ESP_ERROR_CHECK(ledc_timer_config(&timer_conf));

    const ledc_channel_config_t ch_conf = {
        .gpio_num = BSP_LCD_BACKLIGHT_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = (ledc_channel_t)BSP_LCD_BL_LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0,
        .hpoint = 0,
    };
    return ledc_channel_config(&ch_conf);
}

esp_err_t bsp_display_set_brightness(uint8_t percent)
{
    if (percent > 100) percent = 100;
    uint32_t duty = (1023 * percent) / 100;
    ledc_set_duty(LEDC_LOW_SPEED_MODE, (ledc_channel_t)BSP_LCD_BL_LEDC_CHANNEL, duty);
    return ledc_update_duty(LEDC_LOW_SPEED_MODE, (ledc_channel_t)BSP_LCD_BL_LEDC_CHANNEL);
}

lv_disp_t *bsp_display_start(void)
{
    if (s_display != NULL) {
        return s_display;
    }
    bsp_display_init_backlight();
    const lvgl_port_cfg_t lvgl_cfg = ESP_LVGL_PORT_INIT_CONFIG();
    ESP_ERROR_CHECK(lvgl_port_init(&lvgl_cfg));

    const lvgl_port_display_cfg_t disp_cfg = {
        .io_handle = NULL,
        .buffer_size = BSP_LCD_H_RES * 50,
        .double_buffer = true,
        .hres = BSP_LCD_H_RES,
        .vres = BSP_LCD_V_RES,
        .monochrome = false,
        .flags = {
            .buff_dma = false,
            .buff_spiram = true,
        }
    };
    s_display = lvgl_port_add_disp(&disp_cfg);
    bsp_display_set_brightness(80);
    ESP_LOGI(TAG, "Графический стек 1024x600 поднят в PSRAM!");
    return s_display;
}

bool bsp_display_lock(uint32_t timeout_ms)
{
    return lvgl_port_lock(timeout_ms);
}

void bsp_display_unlock(void)
{
    lvgl_port_unlock();
}
