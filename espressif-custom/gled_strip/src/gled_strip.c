#include "gled_strip.h"

esp_err_t new_gled_strip(gled_strip_t *strip)
{
    // TO DO: Fill in parameter fields

    // TO DO: Pass strip to RMT device 
    // for configuring rmt 
    // creation for linking backend functions to interface functions
    /**
     * TO DO:
     * Pass rmt_config to RMT device to configure
    */
    return ESP_OK;
}

// void led_strip_set_colour(led_strip_handle_t strip, uint8_t num_leds, colour_t colour)
// {
//     for (uint8_t a = 0; a < num_leds; a++)
//     {
//         // printf("Setting LED %d to %d, %d, %d\n", a, colour[0], colour[1], colour[2]);
//         led_strip_set_pixel(strip, a, palette[colour][0], palette[colour][0], palette[colour][0]);
//     }
//     led_strip_refresh(strip);
// }
