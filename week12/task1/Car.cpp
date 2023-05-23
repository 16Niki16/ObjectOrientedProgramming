#include "Car.h"
#include <iostream>

void Car::erase()
{
	delete[] brand;
	delete[] model;
}

void Car::copy(const Car& obj)
{
	brand = new char[strlen(obj.brand) + 1];
	strcpy_s(brand, strlen(obj.brand) + 1, obj.brand);
	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);
}

Car::Car(char* brand1, char* model1, bool tangible, int power, int weight, std::string& owner)
: brand(new char[strlen(brand1) + 1]), model(new char[strlen(model1)+1]), Vehicle(power,weight),Property(owner,tangible){
	strcpy_s(brand, strlen(brand1) + 1, brand1);
	strcpy_s(model, strlen(model1) + 1, model1);
}

Car::~Car()
{
	erase();
}

Car::Car(const Car& obj) : Vehicle(obj), Property(obj){copy(obj);}

Car& Car::operator=(const Car& obj)
{
	if (this != &obj) {
		Vehicle::operator=(obj);
		Property::operator=(obj);
		erase(); 
		copy(obj);
	}
	return *this;
}

void Car::startEngine(){
	std::cout << "Vr";
	int temp = getPower();
	while (temp > 0) {
		std::cout << "o"; 
		temp -= 30;
	}
	std::cout << "m"<<std::endl;
}

