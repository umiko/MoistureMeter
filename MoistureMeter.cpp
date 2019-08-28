//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//Implementation of the moisture meter

#include "MoistureMeter.hpp"

MoistureMeter::MoistureMeter(int sensorVinPin, int sensorOutPin, int moistureMaxBaseline) : m_vin(sensorVinPin), m_aout(sensorOutPin), m_baseline_water(moistureMaxBaseline), m_baseline_updated(moistureMaxBaseline)
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
    if (m_baseline_water < result && m_baseline_updated < result)
        setBaseline(result);

    return result;
}

float MoistureMeter::measureMoisturePercentage()
{
    return static_cast<float>(measureMoisture()) / m_baseline_updated;
}

//Sets the sensors vin pins voltage to high or low
void MoistureMeter::toggleVin(bool active)
{
    digitalWrite(m_vin, active ? HIGH : LOW);
}

void MoistureMeter::printConfig()
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

void MoistureMeter::setBaseline(int new_baseline)
{
    Serial.print("Baseline updated! ");
    Serial.print(m_baseline_updated);
    Serial.print(" -> ");
    Serial.println(new_baseline);

    m_baseline_updated = new_baseline;
}