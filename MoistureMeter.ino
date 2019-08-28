#include "MoistureMeter.hpp"

MoistureMeter m = {2, A0, 700};

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  m.printConfig();
}

// the loop routine runs over and over again forever:
void loop()
{
  // read the input
  int sensorValue = m.measureMoisture();
  float percentage = m.measureMoisturePercentage();
  // print out the value you read:
  Serial.print("Raw Value: ");
  Serial.print(sensorValue);
  Serial.print(" Normalized: ");
  Serial.println(percentage);
  delay(10000); // delay in between reads for stability
}