//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//Implementation of the moisture meter

#include "MoistureMeter.hpp"

MoistureMeter::MoistureMeter(int sensorVinPin, int sensorOutPin, int moistureMaxBaseline) : m_vin(sensorVinPin), m_aout(sensorOutPin), m_baseline_water(moistureMaxBaseline)
{
    pinMode(sensorVinPin, OUTPUT);
    pinMode(sensorOutPin, INPUT);
}

MoistureMeter::~MoistureMeter()
{
}

//supplies voltage to the sensor and measures the conductivity
int MoistureMeter::measureMoisture()
{
    int result = 0;
    toggleVin(true);
    delay(100);
    result = analogRead(m_aout);
    delay(100);
    toggleVin(false);
    return result;
}

//Sets the sensors vin pins voltage to high or low
void MoistureMeter::toggleVin(bool active)
{
    digitalWrite(m_vin, active ? HIGH : LOW);
}