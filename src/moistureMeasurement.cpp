//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//definition of the measurement class

#include "moistureMeasurement.hpp"

int moistureMeasurement::m_measurement_count = 0;

moistureMeasurement::moistureMeasurement() : m_rawValue(0), m_baseline(0)
{
}

moistureMeasurement::moistureMeasurement(int rawValue, int baseline) : m_rawValue(rawValue), m_baseline(baseline)
{
  m_measurement_count++;
}

moistureMeasurement::~moistureMeasurement()
{
}

float moistureMeasurement::getMoistureInPercentage()
{
  return static_cast<float>(m_rawValue) / m_baseline;
}

void moistureMeasurement::print()
{
  if (Serial)
  {
    Serial.print("##### Measurement ");
    Serial.print(m_measurement_count);
    Serial.println(" #####");
    Serial.print("Raw Value: ");
    Serial.println(m_rawValue);
    Serial.print("Moisture Percentage: ");
    Serial.println(getMoistureInPercentage());
  }
}