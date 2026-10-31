#include "esp_log.h"
#include "bsp/esp-bsp.h"
#include "bsp/display.h"
#include "bsp/touch.h"
#include "bsp/audio.h"

static const char *TAG = "main";

void app_main(void)
{
    ESP_LOGI(TAG, "Запуск демо-приложения Guition JC1060P470C");
    bsp_i2c_init();
    bsp_audio_init();
    lv_disp_t *disp = bsp_display_start();
    bsp_touch_new(NULL);

    bsp_display_lock(0);
    lv_obj_t *scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x1E1E2E), 0);
    lv_obj_t *title = lv_label_create(scr);
    lv_label_set_text(title, "Guition JC1060P470C BSP");
    lv_obj_set_style_text_color(title, lv_color_hex(0x89B4FA), 0);
    lv_obj_set_style_text_font(title, &lv_font_montserrat_28, 0);
    lv_obj_align(title, LV_ALIGN_CENTER, 0, -40);

    lv_obj_t *status = lv_label_create(scr);
    lv_label_set_text(status, "ESP32-P4 v1.3 @ 360MHz | 32MB HEX PSRAM | 1024x600 IPS");
    lv_obj_set_style_text_color(status, lv_color_hex(0xA6ADC8), 0);
    lv_obj_align(status, LV_ALIGN_CENTER, 0, 20);
    bsp_display_unlock();
    ESP_LOGI(TAG, "Система работает в штатном режиме!");
}
