//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//Declaration of the Moisture Meter
#ifndef MOISTUREMETER_HPP
#define MOISTUREMETER_HPP
#include <Arduino.h>
#include "moistureMeasurement.hpp"

const int SAMPLE_SIZE = 500;

class moistureMeter
{
private:
    //this baseline has to be set by the user, as different output voltages yield different results
    int m_baseline_water{0};
    //according to the documentation of my sensor, the maximum range measured is from
    int m_baseline_updated{0};
    //the arduino output pin supplying voltage to the sensors vin
    int m_vin{0};
    //the analog read pin to get measurements
    int m_aout{0};
    //sets the output of m_vin to wither high or low, depending on active
    void toggleVin(bool active);

public:
    moistureMeasurement m_last_measurement{0, 0};
    moistureMeter();
    moistureMeter(int sensorVin, int sensorOut, int moistureMaxBaseline);
    ~moistureMeter();
    //returns the raw moisture value returned by the sensor
    moistureMeasurement measureMoisture();
    void printConfig();
    void setBaseline(int new_baseline);
};
#endif