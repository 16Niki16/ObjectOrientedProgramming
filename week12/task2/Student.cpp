
#include "Student.h"
#include<iostream>

Student::Student(int FN, std::string& name) : FN(FN), Person(name){}

void Student::display() const
{
	std::cout << this->name << " " << this->FN<<" "<<this->idPerson<<std::endl;
}

BasePerson* Student::clone() const
{
	return new Student(*this);
}
