#ifndef electricCar_H_
#define electricCar_H_
#include "Car.h"
class ElectricCar: public Car{
public:
	void startEngine() override;
};
#endif // !electricCar_H_



