#include "Person.h"
#include<iostream>

Person::Person(std::string& name): BasePerson(name), idPerson(id){}

BasePerson* Person::clone() const
{
	return new Person(*this);
}

void Person::display() const
{
	std::cout << name << " " << idPerson << std::endl;
}
