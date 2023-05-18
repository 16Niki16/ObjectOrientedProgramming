#include"CarPart.h"

CarPart::~CarPart() {}

CarPart::CarPart() : namePart(""), manufacturer(""), yearOfProduction(0), id(0) {}

CarPart::CarPart(std::string name, std::string manufacutrer, unsigned yearOfProduction, int id)
	: namePart(name), manufacturer(manufacutrer), yearOfProduction(yearOfProduction), id(id) {
}

int CarPart::getNumberOfParts()
{
	return numberOfParts;
}

std::string CarPart::getNamePart()
{
	return namePart;
}

std::string CarPart::getManufacturer()
{
	return manufacturer;
}

unsigned CarPart::getYearOfProduction()
{
	return yearOfProduction;
}

int CarPart::getID()
{
	return id;
}

