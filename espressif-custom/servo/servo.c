#include "servo.h"

void servo_set(ledc_channel_t channel, float angle)
{
    // Convert angle to duty cycle
    uint32_t duty = (angle / 180) * (SERVO_MAX_PULSEWIDTH - SERVO_MIN_PULSEWIDTH) + SERVO_MIN_PULSEWIDTH;

    // Write duty cycle
    ledc_set_duty(LEDC_LOW_SPEED_MODE, channel, duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, channel);
}
