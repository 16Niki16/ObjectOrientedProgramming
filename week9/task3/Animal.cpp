#include "Animal.h"
#include <cstring>
#include <iostream>

Animal::Animal(char* nameM, unsigned age) : name(new char[strlen(nameM) + 1]), age(age)
{strcpy_s(name, strlen(nameM) + 1, nameM);}

void Animal::erase()
{
	delete[] name;
}

Animal::~Animal()
{
	erase();
}

void Animal::copy(const Animal& obj){
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	age = obj.age;
}



Animal::Animal(const Animal& obj){
	copy(obj);
}

Animal& Animal::operator=(const Animal& obj)
{
	if (this != &obj) {
		this->erase();
		this->copy(obj);
	}
	return *this;
}

char* Animal::getName()
{
	return name;
}

unsigned Animal::getAge()
{
	return age;
}

void Animal::setName(char* name)
{
	erase();
	this->name = new char(strlen(name) + 1);
	strcpy_s(this->name, strlen(name) + 1, name);
}
