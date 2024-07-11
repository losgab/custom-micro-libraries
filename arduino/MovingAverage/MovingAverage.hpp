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
	MovingAverage()
	{
		front = 0;
		rear = WINDOW_SIZE - 1;
		count = 0;
	}

	void enqueue(int item)
	{
		rear = (rear + 1) % WINDOW_SIZE;
		if (count >= WINDOW_SIZE)
		{
			front = (front + 1) % WINDOW_SIZE;
		}
		else
		{
			count++;
		}
		data[rear] = item;
	}
	float calculateMovingAverage()
	{
		float sum = 0;
		for (int i = 0; i < count; i++)
		{
			sum += data[(front + i) % WINDOW_SIZE];
		}
		// Serial.println(sum / count);
		return sum / count;
	}
	uint8_t getCount()
	{
		return count;
	}

private:
	int data[WINDOW_SIZE];
	int front;
	int rear;
	int count;
};