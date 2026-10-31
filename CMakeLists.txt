idf_component_register(SRCS "src/bsp_common.c"
                            "src/bsp_display.c"
                            "src/bsp_touch.c"
                            "src/bsp_audio.c"
                       INCLUDE_DIRS "include"
                       REQUIRES esp_driver_gpio esp_driver_i2c esp_driver_ledc esp_lcd esp_timer heap
                       PRIV_REQUIRES esp_lvgl_port esp_lcd_touch_gt911 esp_codec_dev)
