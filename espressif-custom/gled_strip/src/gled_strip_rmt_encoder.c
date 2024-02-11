#include "gled_strip_rmt_encoder.h"

static esp_err_t gled_new_strip_rmt_encoder(rmt_encoder_handle_t *ret_encoder)
{
    ESP_RETURN_ON_FALSE(ret_encoder == NULL, ESP_ERR_INVALID_ARG, RMT_ENCODER_TAG, "Encoder Not NULL");
    return ESP_OK;
}
