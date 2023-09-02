#include "Button.h"

button_t create_button(uint8_t pin, uint8_t is_input_pullup)
{
    button_t new_button = malloc(sizeof(Button));

    new_button->pin = pin;
    pinMode(pin, (is_input_pullup) ? INPUT_PULLUP : INPUT);

    new_button->last_state = 0;
    new_button->pushed = 0;
    // new_button->button_pressed = 0;
    
    return new_button;
}

void update_button(button_t button)
{
	// If button 1 state is not same as the last state, update
	uint8_t reading = !digitalRead(button->pin);
	button->pushed = (button->last_state == 0 && reading == HIGH) ? 1 : 0;
    button->last_state = reading;
}

uint8_t was_pushed(button_t button)
{
    return button->pushed;
}

uint8_t is_pressed(button_t button)
{
    // return button->pressed;
    return 0;
}