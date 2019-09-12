//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//definition of the measurement class

#include "moistureMeasurement.hpp"

moistureMeasurement::moistureMeasurement(int rawValue, int baseline) : m_rawValue(rawValue), m_baseline(baseline)
{
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
    Serial.print("Raw Value: ");
    Serial.println(m_rawValue);
    Serial.print("Moisture Percentage");
    Serial.println(getMoistureInPercentage());
  }
}