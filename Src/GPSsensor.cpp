#include "GPSsensor.h"

GPSsensor::GPSsensor(int x)
{
  i = x;
}

int GPSsensor::ToString()
{
  return i;
}

int GPSsensor::GPIO()
{
  return M_POWR_GPIO_Port;
}
