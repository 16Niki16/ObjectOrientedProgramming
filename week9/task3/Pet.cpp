#include "Pet.h"
#include <iostream>

void Pet::erase()
{
	delete[] nameOwner;
}

void Pet::copy(const Pet& obj)
{
	nameOwner = new char(strlen(obj.nameOwner) + 1);
	strcpy_s(nameOwner,strlen(obj.nameOwner)+1,obj.nameOwner);
	telNumber = obj.telNumber;
}

Pet::Pet(char* nameOwnerM, unsigned telNumber, char* name, unsigned age) : nameOwner(new char(strlen(nameOwnerM)+1)),telNumber(telNumber),Animal(name,age)
{
	strcpy_s(nameOwner, strlen(nameOwnerM) + 1, nameOwnerM);
}

Pet::~Pet()
{
	erase();
}

Pet::Pet(const Pet& obj) : Animal(obj)
{
	copy(obj);
}

Pet& Pet::operator=(const Pet& obj)
{
	if (this != &obj) {
		Animal::operator=(obj);
		this->erase();
		this->copy(obj);
	}
	return *this;
}

void Pet::print()
{
	std::cout << this->nameOwner << " " << this->telNumber << " " << this->getName() << " " << this->getAge() << std::endl;
}

void Pet::changeName(char* name)
{
	this->changeName(name);
}

void Pet::setNewOwner(char* newNameOwner)
{
	this->erase();
	nameOwner = new char(strlen(newNameOwner) + 1);
	strcpy_s(nameOwner, strlen(newNameOwner) + 1, newNameOwner);
}
