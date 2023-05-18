#include <iostream>
#include "Car.h"

int CarPart::numberOfParts = 0;

int main()
{
	//int CarPart::numberOfParts = 0;
	std::string tire = "Tire";
	std::string engine = "Engine";
	std::string fueltank = "Fuel Tank";
	std::string piston = "Piston";
	std::string bmw = "BMW";
	//CarPart obj10(tire, bmw, 2010, 20);
	Tire obj(tire, bmw, 2003, 12354, 20, 10, 30);
	//obj.display();
	//Piston obj1(piston, bmw, 2010, 10, 10, 20);
	//obj1.display();
	//CarPart* parts[2] = { &obj,&obj1 };
	//Car objCar(bmw, "X6", parts);
	//objCar.DisplayCarParts();
}
