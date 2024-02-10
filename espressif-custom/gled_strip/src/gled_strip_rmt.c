#include "gled_strip_rmt.h"

static esp_err_t gled_strip_new_rmt_device(gled_strip_t *strip)
{
    if (strip == NULL)
        return ESP_ERR_INVALID_ARG;

    return ESP_OK;
}

static esp_err_t gled_strip_rmt_set_pixel(gled_strip_t *strip, uint16_t index, colour_t colour)
{
    return ESP_OK;
}

static esp_err_t gled_strip_rmt_set_colour(gled_strip_t *strip, colour_t colour)
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
