#include "Part.h"

Tire::Tire(std::string namePart, std::string manufacturer, unsigned yearOfProduction, int id, int width, int profile, int diameter)
	: width(width), profile(profile), diameter(diameter), CarPart(namePart, manufacturer, yearOfProduction, id)
{
}

void Tire::display()
{
	std::cout << this->getNamePart() << " " << this->getManufacturer() << " " << this->getYearOfProduction() << " " << this->getID() << this->width << " " << this->profile << " " << this->diameter << std::endl;
}

Piston::Piston(std::string namePart, std::string manufacturer, unsigned yearOfProduction, int id, int diameter, int hod)
	: diameter(diameter), hod(hod), CarPart(namePart, manufacturer, yearOfProduction, id) {}

void Piston::display()
{
	std::cout << this->getNamePart() << " " << this->getManufacturer() << " " << this->getYearOfProduction() << " " << this->getID() << this->diameter << " " << this->hod << std::endl;
}

int Piston::getDiameter()
{
	return diameter;
}

int Piston::getHod()
{
	return hod;
}

Engine::Engine(std::string namePart, std::string manufacturer, unsigned yearOfProduction, int id, int power, std::vector<Piston> pistons)
	: power(power), pistons(pistons), CarPart(namePart, manufacturer, yearOfProduction, id) {}

void Engine::display()
{
	std::cout << this->getNamePart() << " " << this->getManufacturer() << " " << this->getYearOfProduction() << " " << this->getID() << " " << this->power << " ";
	for (int i = 0; i < pistons.size(); i++) {
		std::cout << "piston number " << i + 1 << " " << pistons[i].getDiameter() << " " << pistons[i].getHod() << std::endl;
	}
}

template<typename T>
 FuelTank<T>::FuelTank(std::string namePart, std::string manufacturer, unsigned yearOfProduction, int id, int volume, T type) : volume(volume), type(type), CarPart(namePart, manufacturer, yearOfProduction, id)
{
}

template<typename T>
 void FuelTank<T>::display()
{
	std::cout << this->getNamePart() << " " << this->getManufacturer() << " " << this->getYearOfProduction() << " " << this->getID() << " " << this->volume << " " << type << std::endl;
}


