#include <Arduino.h>

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