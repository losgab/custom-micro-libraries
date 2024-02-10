/**
 * RMT Encoder  for LED Strip Library for ESP-IDF
 *
 * @author Gabriel Thien 2024
 */
#pragma once

#include <driver/rmt_encoder.h>

#define RMT_ENCODER_TAG "RMT_ENCODER"

/**
 * @brief Initialises a new RMT Encoder for interpreting LED strip signals into RMT frames
 * 
 * @param ret_encoder Pointer to the encoder handle to initialise
 * 
 * @return ESP_OK on success, otherwise an error code
*/
static esp_err_t rmt_new_led_strip_encoder(rmt_encoder_handle_t *ret_encoder);
