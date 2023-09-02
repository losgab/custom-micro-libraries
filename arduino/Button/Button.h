#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>
/*
    Buttons for Arduino

    Convenience library for observing button state changes.
    - Detects when a button was pushed
    - Detects if a button is held down (not implemented yet)

    Written by Gabriel Thien 2023
*/

typedef struct Button
{
    uint8_t pin;
    uint8_t last_state;
    uint8_t pushed;
    // uint8_t pressed;
} Button;

typedef Button* button_t;

/*
    Initialises a button attached to the specified pin
    (1 for true) is_input_pullup
*/
button_t create_button(uint8_t pin, uint8_t is_input_pullup);

/*
    Reads and updates the state of the button
*/
void update_button(button_t button);

/*
    Returns pressed state of button
    1 -> Pressed
    0 -> Not Pressed
*/
uint8_t was_pushed(button_t button);

/*
    Returns 1 if button is held down, else 0
    Dependent on debounce time
*/
uint64_t is_pressed(button_t button);