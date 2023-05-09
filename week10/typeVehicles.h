#ifndef typeVehicles_H_
#define typeVehicles_H_
#include "Vehicle.h"
class Jeep: public Vehicle {
	bool is4X4;
public:
	Jeep(bool is4X4,int id, int numberOfSeats, int MaxSpeed, double PriceForRent);
};
class Car : public Vehicle {
	char* nameOfProducer;
	void copy(const Car& obj);
	void erase();
public:
	Car(const char* nameOfProducer, int id, int numberOfSeats, int MaxSpeed, double PriceForRent);
	~Car() override;
	Car(const Car& obj);
	Car& operator=(const Car& obj);
};
class Bus: public Vehicle {
	int luggagePlace;
public:
	Bus(int luggagePlace, int id, int numberOfSeats, int MaxSpeed, double PriceForRent);
};
#endif // !typeVehicles_H_
