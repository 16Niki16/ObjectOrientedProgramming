#include "Vehicle.h"

Vehicle::Vehicle(int power, int weight) : power(power), weight(weight){}

Vehicle::~Vehicle()
{
}

int Vehicle::getPower()
{
    return power;
}

int Vehicle::getWeight()
{
    return weight;
}
