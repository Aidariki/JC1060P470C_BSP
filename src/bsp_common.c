#include "bsp/esp-bsp.h"
#include "esp_log.h"

static const char *TAG = "bsp_common";
static i2c_master_bus_handle_t s_i2c_bus_handle = NULL;

esp_err_t bsp_i2c_init(void)
{
    if (s_i2c_bus_handle != NULL) {
        return ESP_OK;
    }
    const i2c_master_bus_config_t bus_config = {
        .i2c_port = BSP_I2C_PORT,
        .sda_io_num = BSP_I2C_SDA_GPIO,
        .scl_io_num = BSP_I2C_SCL_GPIO,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };
    esp_err_t ret = i2c_new_master_bus(&bus_config, &s_i2c_bus_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Ошибка I2C: %s", esp_err_to_name(ret));
        return ret;
    }
    ESP_LOGI(TAG, "Шина I2C запущена (SDA=%d, SCL=%d)", BSP_I2C_SDA_GPIO, BSP_I2C_SCL_GPIO);
    return ESP_OK;
}

i2c_master_bus_handle_t bsp_i2c_get_handle(void)
{
    return s_i2c_bus_handle;
}
