#include "gled_strip_rmt.h"

static esp_err_t gled_strip_new_rmt_device(gled_strip_t *strip)
{
    ESP_RETURN_ON_FALSE(strip == NULL, ESP_ERR_INVALID_ARG, RMT_DEVICE_TAG, "Strip Not NULL");

    // Allocate memory for RMT device
    gled_strip_rmt_device *new_device = malloc(sizeof(gled_strip_rmt_device));
    ESP_RETURN_ON_FALSE(new_device == NULL, ESP_ERR_NO_MEM, RMT_DEVICE_TAG, "No Memory left for RMT device");

    // Create new strip RMT encoder
    ESP_RETURN_ON_ERROR(rmt_new_led_strip_encoder(new_device->strip_encoder), RMT_DEVICE_TAG, "Create LED strip encoder failed");

    new_device->bytes_per_pixel = 3;

    // Link interface functions to RMT backend functionality
    strip->set_pixel = gled_strip_rmt_set_pixel;
    strip->refresh = gled_strip_rmt_refresh;
    strip->clear = gled_strip_rmt_clear;
    strip->del = gled_strip_rmt_del;
    return ESP_OK;
}

static esp_err_t gled_strip_rmt_set_pixel(gled_strip_t *strip, uint16_t index, colour_t colour)
{
    return ESP_OK;
}

static esp_err_t gled_strip_rmt_refresh(gled_strip_t *strip)
{
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
