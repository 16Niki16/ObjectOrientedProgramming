#include "Car.h"

void Car::erase()
{
	std::cout << "destructor" << std::endl;
	for (int i = 0; i < CarPart::numberOfParts; i++) {
		delete[] this->part[i];
	}
}

void Car::copy(const Car& obj)
{
	this->producer = obj.producer;
	this->model = obj.model;
	this->part = new CarPart * [CarPart::numberOfParts];
	for (int i = 0; i < CarPart::numberOfParts; i++) {
		this->part[i] = obj.part[i];
	}
}

Car::Car(std::string producer, std::string model, CarPart** part) : producer(producer), model(model) {
	this->part = new CarPart * [CarPart::numberOfParts];
	for (int i = 0; i < CarPart::numberOfParts; i++) {
		this->part[i] = part[i];
	}
}

Car::~Car()
{
	erase();
}

Car::Car(const Car& obj)
{
	copy(obj);
}

Car& Car::operator=(const Car& obj)
{
	if (this != &obj) {
		this->erase();
		this->copy(obj);
	}
	return *this;
}

void Car::addCarPart(CarPart& newPart)
{
	++CarPart::numberOfParts;
	CarPart** tempArray = new CarPart * [CarPart::numberOfParts];
	for (int i = 0; i < CarPart::numberOfParts - 1; i++) {
		tempArray[i] = this->part[i];
	}
	tempArray[CarPart::numberOfParts - 1] = &newPart;
	for (int i = 0; i < CarPart::numberOfParts - 1; i++) {
		delete[] this->part[i];
	}
	std::cout << "vika go:1 ";
	this->part = new CarPart * [CarPart::numberOfParts];
	std::cout << "vika go:2 ";
	for (int i = 0; CarPart::numberOfParts; i++) {
		this->part[i] = tempArray[i];
	}
	for (int i = 0; i < CarPart::numberOfParts; i++) {
		delete[] tempArray[i];
	}
}

void Car::DisplayCarParts()
{
	std::string tire = "Tire";
	std::string engine = "Engine";
	std::string piston = "Piston";
	std::string fuelTank = "Fuel tank";
	std::cout << "tire";
	for (int i = 0; i < CarPart::numberOfParts; i++) {
		CarPart* CPptr = this->part[i];
		CPptr->display();
	}
}

