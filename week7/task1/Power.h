#ifndef POWER_H
#define POWER_H
#include <string>

class Power {
	std::string name; 
	int damage;
public:
	Power();
	Power(const std::string& name, int damage);

	const std::string& getName();
	int getDamage();
	

	bool operator<(const Power& other);
};

#endif