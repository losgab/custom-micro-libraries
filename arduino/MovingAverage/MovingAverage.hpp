#include <Arduino.h>
/*
    Moving Average for Arduino (OOP)

    Convenience library for a moving average data denoiser.
	Implements a basic circular queue.

    Written by Gabriel Thien 2023
*/

#define WINDOW_SIZE 30

class MovingAverage
{
public:
	MovingAverage();
	void enqueue(int item);
	float calculateMovingAverage();
	uint8_t getCount();

private:
	int data[WINDOW_SIZE];
	int front;
	int rear;
	int count;
};