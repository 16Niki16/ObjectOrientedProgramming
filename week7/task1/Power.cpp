#include <iostream>
#include <string>
#include "Power.h"

const std::string& Power::getName() {
	return name;
}

int Power::getDamage() {
	return damage;
}

Power::Power(const std::string& name, int damage) {
	this->name = name;
	this->damage = damage;
}

bool Power::operator<(const Power& other) {
	if (this->damage < other.damage)
		return true;
	return false;
}

Power::Power() {

}

