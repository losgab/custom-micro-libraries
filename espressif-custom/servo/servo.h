#pragma once

#include "driver/ledc.h"

#define SERVO_MIN_PULSEWIDTH 500
#define SERVO_MAX_PULSEWIDTH 2500

#define servo_init(config) ledc_channel_config(config)

typedef ledc_channel_config_t servo_t;

/**
 * Note: Max 16 channels for PWM devices
 * Note: Servos are controlled via their PWM channels
 * Selectable: LEDC_CHANNEL_0 ~ LEDC_CHANNEL_15
*/

/**
 * @brief Set the servo position
 * 
 * @param config Servo Configuration
 * @param position Position to set
 * 
 * @return void
*/
void servo_set(ledc_channel_t channel, float angle);