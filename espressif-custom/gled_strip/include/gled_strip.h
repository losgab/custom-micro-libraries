/**
 * Convenience Library for Addressable LED Strips & Colours
 *
 * - Defines interface functions for entire LED library
 * - Defines initialisation function for LED strip that configures all functionality
 *   including RMT device and RMT encoder.
 *
 *  @author Gabriel Thien 2024
 */
#pragma once

#include "gled_strip_rmt.h"
#include "gled_strip_colours.h"
#include <driver/gpio.h>

#define MAX_NUM_LEDS 50

/**
 * @brief LED Strip pixel format / LED Model
 */
typedef enum
{
    LED_PIXEL_FORMAT_GRB,
    LED_PIXEL_FORMAT_GRBW,
    LED_PIXEL_FORMAT_INVALID
} pixel_format_t;

// /**
//  * @brief Configuration struct
//  */
// typedef struct
// {
//     gpio_num_t pin;                      // GPIO Pin used by the LED Strip
//     uint16_t max_leds;                   // Max number of LEDS attached on LED strip
//     pixel_format_t format;               // Pixel format of the LED Strip
//     gled_strip_rmt_config_t *rmt_config; // RMT configuration
// } gled_config;

/**
 * @brief LED Strip Object & Interface function definition
 */
typedef struct
{
    gpio_num_t pin;                    // GPIO Pin used by the LED Strip
    uint16_t max_leds;                 // Max number of LEDS attached on LED strip
    pixel_format_t format;             // Pixel format of the LED Strip
    gled_strip_rmt_device *rmt_device; // RMT Device

    /**
     * Interface definitions are linked by RMT device initialisation
    */

    /**
     * @brief Interface function for setting colour of entire strip
     *
     * @param strip LED strip handle
     * @param index Index of the LED to set
     * @param colour Colour from enumeration
     *
     * @return ESP_OK on success, otherwise an error code
     */
    esp_err_t (*set_pixel)(gled_strip_t *strip, uint16_t index, colour_t colour);

    /**
     * @brief Interface function for refreshing LED strip
     *
     * @param strip LED strip handle
     *
     * @return ESP_OK on success, otherwise an error code
     */
    esp_err_t (*refresh)(gled_strip_t *strip);

    /**
     * @brief Interface function for turning off LED strip
     *
     * @param strip LED strip handle
     *
     * @return ESP_OK on success, otherwise an error code
     */
    esp_err_t (*clear)(gled_strip_t *strip);

    /**
     * @brief Interface function for deleting gled strip resources
     * 
     * @param strip LED strip handle
     * 
     * @return ESP_OK on success, otherwise an error code
    */
   esp_err_t (*del)(gled_strip_t *strip);
} gled_strip_t;

/////////////////////////////////////////////////////////////
//////////////// USERLAND API FUNCTIONS /////////////////////
/////////////////////////////////////////////////////////////

/**
 * @brief Sets colour of the entire LED strip
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
