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

    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        toggleVin(true);

        delay(10);
        result += analogRead(m_aout);
        toggleVin(false);
        delay(10);
    }

    float avg = static_cast<float>(result) / static_cast<float>(SAMPLE_SIZE);

    Serial.println(avg);

    if (m_baseline_water < avg && m_baseline_updated < avg)
        setBaseline(avg);
    m_last_measurement = {avg, m_baseline_updated};
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