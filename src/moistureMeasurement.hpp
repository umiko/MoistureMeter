//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//A struct to save the last measurement taken, so it can be supplied at a later time again
#ifndef MOISTUREMEASUREMENT_CPP
#define MOISTUREMEASUREMENT_CPP
#include <Arduino.h>
#include <TimeLib.h>

class moistureMeasurement
{
public:
  time_t m_measuredAt{now()};
  int m_rawValue{0};
  int m_baseline{0};
  moistureMeasurement(int rawValue, int baseline);
  ~moistureMeasurement();
  float getMoistureInPercentage();
  void print();
};
#endif