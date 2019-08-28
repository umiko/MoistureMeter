//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//Declaration of the Moisture Meter

#include <Arduino.h>

class MoistureMeter
{
private:
    //this baseline has to be set by the user, as different output voltages yield different results
    int m_baseline_water{700};
    //according to the documentation of my sensor, the maximum range measured is from
    int m_baseline_updated{700};
    //the arduino output pin supplying voltage to the sensors vin
    int m_vin{0};
    //the analog read pin to get measurements
    int m_aout{0};

    //sets the output of m_vin to wither high or low, depending on active
    void toggleVin(bool active);

public:
    MoistureMeter(int sensorVin, int sensorOut, int moistureMaxBaseline);
    ~MoistureMeter();
    //returns the raw moisture value returned by the sensor
    int measureMoisture();
    void printConfig();
    void setBaseline(int new_baseline);
    float measureMoisturePercentage();
};
