#ifndef employee_H_
#define employee_H_
#include<string>
#include<iostream>
class Employee {
	std::string name;
	double salary;
public:
	Employee(std::string name, double salary);
	friend std::ostream& operator<<(std::ostream& out, const Employee& employee);

	std::string getName(); 
	double getSalary();
};
#endif

