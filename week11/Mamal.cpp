#include "Mamal.h"
#include<iostream>


Mamal::Mamal(const char* name, int weight, typeEat type, placeSleep place, const char* adopter1, int eatKg)
	: adopter(new char[strlen(adopter1)+1]), Animal(name,weight,type, place, eatKg){
	strcpy_s(adopter, strlen(adopter1) + 1, adopter1);
}

Mamal::~Mamal()
{
	delete[] adopter;
}
