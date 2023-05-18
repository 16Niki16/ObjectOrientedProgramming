#ifndef Part_H_
#define Part_H_
#include "CarPart.h"
#include <vector>
class Tire : public CarPart {
	int width;
	int profile;
	int diameter;
public:
	Tire(std::string namePart, std::string manufacturer, unsigned yearOfProduction, int id, int width, int profile, int diameter);
	void display() override;
};
class Piston : public CarPart {
	int diameter;
	int hod;
public:
	Piston(std::string namePart, std::string manufacturer, unsigned yearOfProduction, int id, int diameter, int hod);
	void display() override;
	int getDiameter();
	int getHod();
};
class Engine : public CarPart {
	int power;
	std::vector<Piston> pistons;
public:
	Engine(std::string namePart, std::string manufacturer, unsigned yearOfProduction, int id, int power, std::vector<Piston> pistons);
	void display() override;
};
template <typename T>
class FuelTank : public CarPart {
	int volume;
	T type;
public:
	FuelTank(std::string namePart, std::string manufacturer, unsigned yearOfProduction, int id, int volume, T type);
	void display() override;
};
#endif // !Part_H_



