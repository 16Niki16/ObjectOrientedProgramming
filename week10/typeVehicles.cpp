#include "typeVehicles.h"
#include <iostream>

void Car::copy(const Car& obj)
{
	nameOfProducer = new char[strlen(obj.nameOfProducer) + 1];
	strcpy_s(nameOfProducer, strlen(obj.nameOfProducer) + 1, obj.nameOfProducer);
}

void Car::erase()
{
	delete[] nameOfProducer;
}

Car::Car(const char* nameOFProducer1, int id, int numberOfSeats, int MaxSpeed, double PriceForRent) : nameOfProducer(new char[strlen(nameOFProducer1) + 1]), Vehicle(id,numberOfSeats,MaxSpeed,PriceForRent) {
	strcpy_s(nameOfProducer, strlen(nameOFProducer1) + 1, nameOFProducer1);
}

Car::~Car(){erase();}

Car::Car(const Car& obj):Vehicle(obj){copy(obj);}

Car& Car::operator=(const Car& obj)
{
	if (this != &obj) {
		this->erase();
		this->copy(obj);
	}
	return *this;
}

Jeep::Jeep(bool is4X4, int id, int numberOfSeats, int MaxSpeed, double PriceForRent) : is4X4(is4X4),Vehicle(id,numberOfSeats,MaxSpeed,PriceForRent){}

Bus::Bus(int luggagePlace, int id, int numberOfSeats, int MaxSpeed, double PriceForRent) : luggagePlace(luggagePlace),Vehicle(id,numberOfSeats,MaxSpeed,PriceForRent){}
