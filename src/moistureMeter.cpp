//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//Implementation of the moisture meter

#include "moistureMeter.hpp"

moistureMeter::moistureMeter(int sensorVinPin, int sensorOutPin, int moistureMaxBaseline) : m_vin(sensorVinPin), m_aout(sensorOutPin), m_baseline_water(moistureMaxBaseline), m_baseline_updated(moistureMaxBaseline)
{
    pinMode(sensorVinPin, OUTPUT);
    pinMode(sensorOutPin, INPUT);
}

moistureMeter::~moistureMeter()
{
}

//supplies voltage to the sensor and measures the conductivity
moistureMeasurement moistureMeter::measureMoisture()
{
    int result = 0;
    toggleVin(true);
    delay(10);
    result = analogRead(m_aout);
    delay(10);
    toggleVin(false);
    if (m_baseline_water < result && m_baseline_updated < result)
        setBaseline(result);
    m_last_measurement = {result, m_baseline_updated};
    return m_last_measurement;
}

//Sets the sensors vin pins voltage to high or low
void moistureMeter::toggleVin(bool active)
{
    digitalWrite(m_vin, active ? HIGH : LOW);
}

void moistureMeter::printConfig()
{
    if (Serial)
    {
        Serial.print("Initial Baseline: ");
        Serial.println(m_baseline_water);
        Serial.print("Updated Baseline: ");
        Serial.println(m_baseline_water);
        Serial.print("VinPin: ");
        Serial.println(m_vin);
        Serial.print("AoutPin: ");
        Serial.println(m_aout);
    }
}

void moistureMeter::setBaseline(int new_baseline)
{
    if (Serial)
    {
        Serial.print("Baseline updated! ");
        Serial.print(m_baseline_updated);
        Serial.print(" -> ");
        Serial.println(new_baseline);
    }
    m_baseline_updated = new_baseline;
}