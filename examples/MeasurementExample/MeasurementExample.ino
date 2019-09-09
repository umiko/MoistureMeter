//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//A small test application to test the classes

#include "moistureMeter.hpp"

moistureMeter m = {2, A0, 700};

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
  m.measureMoisture().print();
  delay(10000); // delay in between reads for stability
}