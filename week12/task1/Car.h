#ifndef car_H_
#define car_H_
#include "Property.h"
#include "Vehicle.h"
class Car: public Vehicle, Property{
	char* brand;
	char* model;

	void erase();
	void copy(const Car& obj);
public:
	Car(char* brand, char* model, bool tangible, int power, int weight, std::string& owner);
	~Car();
	Car(const Car& obj); 
	Car& operator=(const Car& obj);

	void startEngine() override;
};
#endif // !car_H_



