#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include <Sensor.h>

class PressureSensor {

    private:
        // Default value for pressure - 0.5V
        static const int DEFAULT_READING_MIN = 102;
        // Default value for max pressure - 4.5V
        static const int DEFAULT_READING_MAX = 921;

        int pin;
        int maxPressure;
        int minReading = DEFAULT_READING_MIN;
        int maxReading = DEFAULT_READING_MAX
        
    public:

        /**
         * Constructor
         *
         * @param pin - analog pin number
         * @param maxPressure - max pressure in kPa
         */
        PressureSensor(int pin, int maxPressure);

        /**
         * Constructor
         *
         * @param pin - analog pin number
         * @param maxPressure - max pressure in kPa
         * @param minReading - the analog value at zero pressure
         */
        PressureSensor(int pin, int maxPressure, int minReading);

        /**
         * Constructor
         *
         * @param pin - analog pin number
         * @param maxPressure - max pressure in kPa
         * @param minReading - the analog value at zero pressure
         * @param maxReading - the analog value at maximal pressure
         */
        PressureSensor(int pin, int maxPressure, int minReading, int maxReading);

        /**
         * Reads new value from the sensor - returns in kPa
         */
        int read();
};

#endif