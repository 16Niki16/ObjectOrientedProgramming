#include "Bird.h"
#include<iostream>

Bird::Bird(const char* name, int weight, typeEat type, placeSleep place, std::string nameTown, int eatKg)
	: nameTown(nameTown), Animal(name,weight,type,place, eatKg){}

Bird::~Bird()
{
}

void Bird::print()
{
	Animal::print();
	std::cout << nameTown<<std::endl;
}
