#include "bsp/audio.h"
#include "bsp/esp-bsp.h"
#include "esp_log.h"
#include "driver/gpio.h"

static const char *TAG = "bsp_audio";

esp_err_t bsp_audio_poweramp_enable(bool enable)
{
    gpio_set_level((gpio_num_t)BSP_POWER_AMP_GPIO, enable ? 1 : 0);
    ESP_LOGI(TAG, "Усилитель NS4150B (PA_CTRL GPIO %d): %s", BSP_POWER_AMP_GPIO, enable ? "ВКЛ" : "ВЫКЛ");
    return ESP_OK;
}

esp_err_t bsp_audio_init(void)
{
    const gpio_config_t pa_cfg = {
        .pin_bit_mask = (1ULL << BSP_POWER_AMP_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = GPIO_PULLDOWN_ENABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
    };
    gpio_config(&pa_cfg);
    gpio_set_level((gpio_num_t)BSP_POWER_AMP_GPIO, 0);
    bsp_i2c_init();
    ESP_LOGI(TAG, "Аудиоподсистема I2S готова (MCLK=%d, BCLK=%d, WS=%d, DOUT=%d, DIN=%d)",
             BSP_I2S_MCLK_GPIO, BSP_I2S_BCLK_GPIO, BSP_I2S_WS_GPIO, BSP_I2S_DOUT_GPIO, BSP_I2S_DIN_GPIO);
    return ESP_OK;
}
