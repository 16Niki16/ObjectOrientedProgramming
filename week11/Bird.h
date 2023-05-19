#ifndef bird_H_
#define bird_H_
#include<string>
#include "Animal.h"
class Bird : public Animal{
	std::string nameTown;
public:
	Bird(const char* name, int weight, typeEat type, placeSleep place, std::string nameTown ,int eatKg);
	~Bird() override;
	void print() override;
};
#endif // !bird_H_


