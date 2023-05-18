#ifndef CarPart_H_
#define CarPart_H_
#include<string>
#include<iostream>
class CarPart {
	std::string namePart;
	std::string manufacturer;
	unsigned yearOfProduction;
	int id;

public:
	static int numberOfParts;
	virtual ~CarPart();
	CarPart();
	CarPart(std::string name, std::string manufacutrer, unsigned yearOfProduction, int id);
	virtual void display();
	int getNumberOfParts();
	std::string getNamePart();
	std::string getManufacturer();
	unsigned getYearOfProduction();
	int getID();
};
#endif // !CarPart_H_



