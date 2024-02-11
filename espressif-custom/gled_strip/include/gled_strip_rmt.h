/**
 * RMT Backend driver for LED Strip Library for ESP-IDF
 *
 * @author Gabriel Thien 2024
 */
#pragma once

#include <esp_err.h>
#include <driver/rmt_types.h>
#include <driver/rmt_tx.h>
#include <stdint.h>

#include "gled_strip.h"

#define LED_STRIP_RMT_DEFAULT_RESOLUTION 10000000 // 10MHz resolution
#define LED_STRIP_RMT_DEFAULT_TRANS_QUEUE_SIZE 4
#define RMT_TAG "RMT_CTRL"

/**
 * @brief LED Strip RMT configuration
 */
typedef struct
{
    rmt_channel_handle_t rmt_chan; // RMT Channel Handle
    rmt_clock_source_t clk_src;    // RMT clock source
    uint32_t resolution_hz;        // RMT tick resolution, if set to zero, a default resolution (10MHz) will be applied
    size_t mem_block_symbols;      // How many RMT symbols can one RMT channel hold at one time. Set to 0 will fallback to use the default size.
    uint8_t with_dma;              // whether to enable the DMA feature
} gled_strip_rmt_config_t;

/**
 * @brief LED Strip RMT control
 */
typedef struct
{
    rmt_encoder_handle_t *strip_encoder; // RMT Encoder Handle
    uint32_t resolution;                // RMT Encoder resolution, in Hz
    uint8_t bytes_per_pixel;            // Bytes per pixel
    uint8_t pixel_buffer[];             // Pixel buffer to store pixel values
} gled_strip_rmt_device;

/**
 * @brief Initialize RMT device with encoder, pixel control and RMT transmission
 * (ESP-IDF Remote Control)
 *
 * @param strip LED Strip handle
 *
 * @return esp_err_t ESP_OK on success
 */
static esp_err_t gled_strip_new_rmt_device(gled_strip_t *strip);

/**
 * @brief Set pixel colour of the LED strip. Does not refresh.
 * (ESP-IDF Remote Control)
 *
 * @param strip LED Strip handle
 * @param index Pixel index
 * @param colour Colour from enumeration
 *
 * @return esp_err_t ESP_OK on success
 */
static esp_err_t gled_strip_rmt_set_pixel(gled_strip_t *strip, uint16_t index, colour_t colour);

/**
 * @brief Sets colour of the entire LED strip. Refreshes immediately.
 * (ESP-IDF Remote Control)
 *
 * @param strip LED Strip handle
 * @param colour Colour from enumeration
 *
 * @return esp_err_t ESP_OK on success
 *
 */
static esp_err_t gled_strip_rmt_set_colour(gled_strip_t *strip, colour_t colour);

/**
 * @brief Transmit no loop TX configuration to LED strip to refresh LED strip
 * (ESP-IDF Remote Control)
 *
 * @param strip LED Strip handle
 *
 * @return esp_err_t ESP_OK on success
 */
static esp_err_t gled_strip_rmt_refresh(gled_strip_t *strip);

/**
 * @brief Clear all pixels to no colour & refreshes LED strip
 * (ESP-IDF Remote Control)
 *
 * @param strip LED Strip handle
 *
 * @return esp_err_t ESP_OK on success
 */
static esp_err_t gled_strip_rmt_clear(gled_strip_t *strip);
