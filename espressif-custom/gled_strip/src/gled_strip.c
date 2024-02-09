#include "gled_strip.h"

void led_strip_set_colour(led_strip_handle_t strip, uint8_t num_leds, colour_t colour)
{
    for (uint8_t a = 0; a < num_leds; a++)
    {
        // printf("Setting LED %d to %d, %d, %d\n", a, colour[0], colour[1], colour[2]);
        led_strip_set_pixel(strip, a, palette[colour][0], palette[colour][0], palette[colour][0]);
    }
    led_strip_refresh(strip);
}