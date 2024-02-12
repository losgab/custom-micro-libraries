#include "gled_strip_rmt.h"

static esp_err_t gled_strip_new_rmt_device(gled_strip_t *ret_strip)
{
    ESP_RETURN_ON_FALSE(ret_strip == NULL, ESP_ERR_INVALID_ARG, RMT_DEVICE_TAG, "Strip Not NULL");

    // Allocate memory for RMT device
    gled_strip_rmt_device *new_device = malloc(sizeof(gled_strip_rmt_device));
    ESP_RETURN_ON_FALSE(new_device == NULL, ESP_ERR_NO_MEM, RMT_DEVICE_TAG, "No Memory left for RMT device");

    // Create new strip RMT encoder
    ESP_RETURN_ON_ERROR(rmt_new_led_strip_encoder(new_device->strip_encoder), RMT_DEVICE_TAG, "Create LED strip encoder failed");

    new_device->bytes_per_pixel = 3;

    // RMT Config
    rmt_tx_channel_config_t rmt_chan_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .gpio_num = ret_strip->pin,
        .mem_block_symbols = LED_STRIP_RMT_DEFAULT_MEM_BLOCK_SYMBOLS,
        .resolution_hz = GLED_STRIP_RMT_DEFAULT_RESOLUTION,
        .trans_queue_depth = GLED_STRIP_RMT_DEFAULT_TRANS_QUEUE_SIZE,
        .flags.with_dma = 1,
        .flags.invert_out = 1,
    };
    ESP_RETURN_ON_ERROR(rmt_new_tx_channel(&rmt_chan_config, &new_device->rmt_config.rmt_chan), RMT_DEVICE_TAG, "Create RMT TX channel failed");
    new_device->rmt_config.clk_src = RMT_CLK_SRC_DEFAULT;
    new_device->rmt_config.resolution_hz = GLED_STRIP_RMT_DEFAULT_RESOLUTION;
    new_device->rmt_config.mem_block_symbols = LED_STRIP_RMT_DEFAULT_MEM_BLOCK_SYMBOLS;
    new_device->rmt_config.with_dma = 1;
    new_device->rmt_config.invert_out = 1;

    // Direct RMT device pointer to new device that was just created
    ret_strip->rmt_device = new_device;

    // Link interface functions to RMT backend functionality
    ret_strip->set_pixel = gled_strip_rmt_set_pixel;
    ret_strip->refresh = gled_strip_rmt_refresh;
    ret_strip->clear = gled_strip_rmt_clear;
    ret_strip->del = gled_strip_rmt_del;
    return ESP_OK;
}

static esp_err_t gled_strip_rmt_set_pixel(gled_strip_t *strip, uint16_t index, uint8_t red, uint8_t green, uint8_t blue)
{
    gled_strip_rmt_device *rmt_device = strip->rmt_device;
    ESP_RETURN_ON_FALSE(index < strip->num_leds, ESP_ERR_INVALID_ARG, RMT_DEVICE_TAG, "Given Index out of initialised number of LEDs");
    uint32_t start = index * rmt_device->bytes_per_pixel;
    // In thr order of GRB, as LED strip like WS2812 sends out pixels in this order
    // Only supports RGB pixels for now
    rmt_device->pixel_buffer[start + 0] = green;
    rmt_device->pixel_buffer[start + 1] = red;
    rmt_device->pixel_buffer[start + 2] = blue;
    return ESP_OK;
}

static esp_err_t gled_strip_rmt_refresh(gled_strip_t *strip)
{
    gled_strip_rmt_device *strip = strip->rmt_device;
    rmt_transmit_config_t tx_conf = {
        .loop_count = 0,
    };

    ESP_RETURN_ON_ERROR(rmt_enable(strip->rmt_config.rmt_chan), RMT_DEVICE_TAG, "enable RMT channel failed");
    ESP_RETURN_ON_ERROR(rmt_transmit(rmt_strip->rmt_chan, rmt_strip->strip_encoder, rmt_strip->pixel_buf,
                                     rmt_strip->strip_len * rmt_strip->bytes_per_pixel, &tx_conf), RMT_DEVICE_TAG, "transmit pixels by RMT failed");
    ESP_RETURN_ON_ERROR(rmt_tx_wait_all_done(rmt_strip->rmt_chan, -1), RMT_DEVICE_TAG, "flush RMT channel failed");
    ESP_RETURN_ON_ERROR(rmt_disable(rmt_strip->rmt_chan), RMT_DEVICE_TAG, "disable RMT channel failed");
    return ESP_OK;
}

static esp_err_t gled_strip_rmt_clear(gled_strip_t *strip)
{
    return ESP_OK;
}

static esp_err_t gled_strip_rmt_del(gled_strip_t *strip)
{
    return ESP_OK;
}
