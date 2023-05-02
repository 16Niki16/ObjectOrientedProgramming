#include "Employee.h"

Employee::Employee(std::string name, double salary) : name(name), salary(salary){}

std::string Employee::getName()
{
	return name;
}

double Employee::getSalary()
{
	return salary;
}

std::ostream& operator<<(std::ostream& out, const Employee& employee)
{
	out << employee.name << " " << employee.salary<<'\n';
	return out; 
}
