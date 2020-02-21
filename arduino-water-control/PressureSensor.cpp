#include "PressureSensor.h"

PressureSensor::PressureSensor(const int pin, const int maxPressure) {
	pinMode(this->pin = pin, INPUT);
    this->maxPressure = maxPressure;
}

PressureSensor::PressureSensor(const int pin, const int maxPressure, const int minReading) {
    this(pin, maxPressure);
    this->minReading = minReading;
    this->maxReading = DEFAULT_READING_MAX + minReading - DEFAULT_READING_MIN;
}

int PressureSensor::read() {
    static int input = analogRead(this->pin);
    static int pressure = ((input - this->minReading)*this->maxPressure)/(this->maxReading - this->minReading)

    // TODO: average it
    // TODO: dynamic offset with control reading
}
