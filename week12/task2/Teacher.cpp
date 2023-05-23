#include "Teacher.h"

Teacher::Teacher(std::string& name, std::string& nameField)
	: Person(name), nameField(nameField){}

BasePerson* Teacher::clone() const
{
	return new Teacher(*this);
}
