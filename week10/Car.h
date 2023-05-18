#ifndef Car_H_
#define Car_H_
#include "CarPart.h"
#include "Part.h"
class Car {
	std::string producer;
	std::string model;
	CarPart** part;

	void erase();
	void copy(const Car& obj);
public:
	Car(std::string producer, std::string model, CarPart** part);
	~Car();
	Car(const Car& obj);
	Car& operator=(const Car& obj);

	void addCarPart(CarPart& part);
	void DisplayCarParts();
};
#endif // !Car_H_


