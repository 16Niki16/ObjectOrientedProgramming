#include <iostream>
#include<string>
#include "Student.h"
#include "Power.h"
Student::Student() : name(name), health(100), power(nullptr), house("") {

}
Student::Student(const std::string& name) {
	this->name = name;
}

const std::string& Student::getName() const{
	return name;
}
const std::string& Student::getHouse() const{
	return house;
}
void Student::setHouse(const std::string& house){
	this->house = house;
}

int Student::getHealth() const{
	return health;
}
void Student::takeDamage(int damage) {
	health -= damage;
}
void Student::setPower(const Power* power) {
	this->power = power;
}
const Power* Student::getPower() const{
	return power;
}
bool Student::isAlive() {
	return health;
}
int Student::attack(int damage) {
	return this->takeDamage(damage);
}

