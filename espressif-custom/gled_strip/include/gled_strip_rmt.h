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
#include "gled_strip_rmt_encoder.h"

#define GLED_STRIP_RMT_DEFAULT_RESOLUTION 10000000 // 10MHz resolution
#define GLED_STRIP_RMT_DEFAULT_TRANS_QUEUE_SIZE 4

#if CONFIG_IDF_TARGET_ESP32 || CONFIG_IDF_TARGET_ESP32S2
#define LED_STRIP_RMT_DEFAULT_MEM_BLOCK_SYMBOLS 64
#else
#define LED_STRIP_RMT_DEFAULT_MEM_BLOCK_SYMBOLS 48
#endif

#define RMT_DEVICE_TAG "RMT_DEVICE"

// /**
//  * @brief LED Strip RMT configuration
//  */
// typedef struct
// {
//     rmt_channel_handle_t rmt_chan; // RMT Channel Handle
//     rmt_clock_source_t clk_src;    // RMT clock source
//     uint32_t resolution_hz;        // RMT tick resolution, if set to zero, a default resolution (10MHz) will be applied
//     size_t mem_block_symbols;      // How many RMT symbols can one RMT channel hold at one time. Set to 0 will fallback to use the default size.
//     uint8_t with_dma;              // whether to enable the DMA feature
// } gled_strip_rmt_config_t;

/**
 * @brief LED Strip RMT Device Object
 */
typedef struct
{
    gled_strip_rmt_encoder *strip_encoder;  // RMT Strip Encoder Handle
    uint8_t bytes_per_pixel;                // Bytes per pixel
    uint8_t pixel_buffer[3 * MAX_NUM_LEDS]; // Pixel buffer to store pixel values
    struct
    {
        rmt_channel_handle_t rmt_chan; // RMT Channel Handle
        rmt_clock_source_t clk_src;    // RMT clock source
        uint32_t resolution_hz;        // RMT tick resolution, if set to zero, a default resolution (10MHz) will be applied
        size_t mem_block_symbols;      // How many RMT symbols can one RMT channel hold at one time. Set to 0 will fallback to use the default size.
        uint8_t with_dma;              // whether to enable the DMA feature
        uint8_t invert_out;            // Invert output signal
    } rmt_config;
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
