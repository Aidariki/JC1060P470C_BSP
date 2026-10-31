#pragma once

#include "esp_err.h"
#include "bsp/board_pins.h"
#include "esp_codec_dev.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t bsp_audio_init(void);
esp_err_t bsp_audio_poweramp_enable(bool enable);

#ifdef __cplusplus
}
#endif
