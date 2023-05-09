#include "Spark.h"

void Spark::erase()
{
	for (int i = 0; i < size; i++) {
		delete[] vehicle[i];
	}
	delete[] vehicle;
}

void Spark::copy(const Spark& obj)
{
	capacity = obj.capacity;
	size = obj.size;
	erase();
	vehicle = new Vehicle * [size];
	for (int i = 0; i < obj.size; i++) {
		vehicle[i] = obj.vehicle[i];
	}
}

Spark::Spark(Vehicle** vehicle1, int capacity, int size) : capacity(capacity), size(size)
{
	for (int i = 0; i < size; i++) {
		vehicle[i] = vehicle1[i];
	}
}

Spark::~Spark(){erase();}

Spark::Spark(const Spark& obj){copy(obj);}

Spark& Spark::operator=(const Spark& obj)
{
	if (this != &obj) {
		this->erase(); 
		this->copy(obj);
	}
	return *this;
}

void Spark::addVehicle(const Vehicle& obj){}
