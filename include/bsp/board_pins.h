#pragma once

/* ==========================================================================
 * Аппаратная распиновка платы Guition JC1060P470C (ESP32-P4 v1.3)
 * ========================================================================== */

/* 1. Общая шина I2C (Main System I2C Bus) */
#define BSP_I2C_SDA_GPIO           (7)
#define BSP_I2C_SCL_GPIO           (8)
#define BSP_I2C_PORT               (0)
#define BSP_I2C_CLK_HZ             (400000)

/* 2. Сенсорная панель Goodix GT911 */
#define BSP_TOUCH_I2C_ADDR         (0x5D)
#define BSP_TOUCH_INT_GPIO         (-1)
#define BSP_TOUCH_RST_GPIO         (-1)

/* 3. Дисплейная панель MIPI-DSI (1024x600 IPS) */
#define BSP_LCD_H_RES              (1024)
#define BSP_LCD_V_RES              (600)
#define BSP_LCD_DSI_LANES          (2)
#define BSP_LCD_BACKLIGHT_GPIO     (26)
#define BSP_LCD_BL_LEDC_CHANNEL    (0)

/* 4. Аудиоподсистема I2S (Кодек ES8311 + Усилитель NS4150B) */
#define BSP_I2S_MCLK_GPIO          (13)
#define BSP_I2S_BCLK_GPIO          (12)
#define BSP_I2S_WS_GPIO            (10)
#define BSP_I2S_DOUT_GPIO          (9)
#define BSP_I2S_DIN_GPIO           (11)
#define BSP_POWER_AMP_GPIO         (20)

/* 5. Дополнительная периферия */
#define BSP_RTC_PCF8563_ADDR       (0x51)
