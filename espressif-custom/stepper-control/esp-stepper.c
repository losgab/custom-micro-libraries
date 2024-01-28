#include "esp-stepper.h"

static esp_err_t esp_gstepper_init(esp_gstepper_t stepper)
{
    return ESP_OK;
}

static float convert_to_gstepper_angle(float target_angle, float step_resolution)
{
    float converted_gstepper_angle = roundf(target_angle / step_resolution) * step_resolution;
    return (float)((uint16_t)(convert_to_gstepper_angle * 10) / 10) // Ensures 1dpf accuracy.
}

static float gstepper_angle_steps_required(float converted_gstepper_angle, float step_resolution)
{
    return (float)(((uint16_t)((converted_gstepper_angle / step_resolution) * 10)) / 10);
}