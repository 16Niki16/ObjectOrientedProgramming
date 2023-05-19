#ifndef mamal_H_
#define mamal_H_
#include "Animal.h"
class Mamal: public Animal{
	char* adopter;
public:
	Mamal(const char* name, int weight, typeEat type, placeSleep place, const char* adopter, int eatKg);
	~Mamal() override;

};
#endif // !mamal_H_



