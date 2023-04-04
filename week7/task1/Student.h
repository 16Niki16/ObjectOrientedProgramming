#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "Power.h"


class Student {
	std::string name;
	std::string house; 
	const Power* power;
	int health;
public:
	Student();
	Student(const std::string& name);

	const std::string& getName() const;
	const std::string& getHouse() const;
	void setHouse(const std::string& house);
	int getHealth() const;
	void takeDamage(int damage);
	void setPower(const Power* power);
	const Power* getPower() const;
	bool isAlive();
	int attack(int damage);
};

#endif // STUDENT_H
