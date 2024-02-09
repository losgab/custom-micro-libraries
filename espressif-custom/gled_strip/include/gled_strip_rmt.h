/**
 * RMT Backend driver for LED Strip Library for ESP-IDF
 *
 * @author Gabriel Thien 2024
 */
#pragma once

#include <esp_err.h>
#include <driver/rmt_types.h>
#include <driver/rmt_tx.h>

#include "gled_strip.h"

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
 * @brief LED Strip RMT Control
 */
typedef struct
{
    rmt_encoder_handle_t strip_encoder;
    uint8_t bytes_per_pixel;
    uint8_t pixel_buf[];
} gled_strip_rmt_obj;

/**
 * TO BE COMPLETED!!!!!!!!!!!
*/

static esp_err_t gled_strip_new_rmt_device(gled_strip_t *strip);

static esp_err_t gled_strip_rmt_set_pixel(led_strip_t *strip, uint16_t index, colour_t colour)

static esp_err_t gled_strip_rmt_set_colour(led_strip_t *strip, colour_t colour)

static esp_err_t gled_strip_rmt_refresh(led_strip_t *strip)

static esp_err_t gled_strip_rmt_clear(led_strip_t *strip)

