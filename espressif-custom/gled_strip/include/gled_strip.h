/*
    Convenience Library for Addressable LED Strips & Colours

    @author Gabriel Thien 2024
*/
#pragma once

#include "gled_strip_rmt.h"
#include "gled_strip_colours.h"
#include <driver/gpio.h>

#define MAX_COLOURS 6
#define CHANNELS 3

/**
 * @brief LED Strip pixel format
 */
typedef enum
{
    LED_PIXEL_FORMAT_GRB,
    LED_PIXEL_FORMAT_GRBW,
} pixel_format_t;

/**
 * @brief LED Strip Data
 */
typedef struct
{
    gpio_num_t pin;                     // GPIO Pin used by the LED Strip
    uint16_t max_leds;                  // Max number of LEDS attached on LED strip
    pixel_format_t format;              // Pixel format of the LED Strip
    gled_strip_rmt_config_t rmt_config; // RMT configuration
    gled_strip_rmt_obj rmt_obj;          // RMT object
} gled_strip_t;

/**
 * @brief Interface function for setting colour of the LED strip
 *
 * @param strip LED strip handle
 * @param colour Colour from enumeration
 *
 * @return void
 */
void gled_strip_set_colour(gled_strip_t *strip, colour_t colour);

/**
 * @brief Interface function for setting colour of specified pixel of the LED strip
 *
 * @param strip LED strip handle
 * @param pixel Pixel number
 * @param colour Colour from enumeration
 *
 * @return void
 */
void gled_strip_set_pixel(gled_strip_t *strip, uint16_t pixel, colour_t colour);

/**
 * @brief Convenience function for refreshing LED strip
 *
 * @param strip LED strip handle
 *
 * @return void
 */
void gled_strip_refresh(gled_strip_t *strip);

/**
 * @brief Convenience function for turning off LED strip
 *
 * @param strip LED strip handle
 *
 * @return void
 */
void gled_strip_clear(gled_strip_t *strip);

