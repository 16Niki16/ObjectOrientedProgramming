#include "PlantsBook.h"
#include <fstream>
#include <iostream>
#include <cstring>

char default_Place[] = "neutral";

void PlantsBook::erase() // destroy method
{
	delete[] nameOfPlant;
	delete[] livingPlace;
}

void PlantsBook::copy(const PlantsBook& obj){ //copy method
	nameOfPlant = obj.nameOfPlant;
	livingPlace = obj.livingPlace;
	days = obj.days;
}

PlantsBook::PlantsBook(const char* nameOfNewPlant) : nameOfPlant(new char[strlen(nameOfNewPlant) + 1]), livingPlace(default_Place), days(3){//default constructor
	strcpy_s(nameOfPlant, strlen(nameOfNewPlant) + 1, nameOfNewPlant);

}

PlantsBook::PlantsBook(const char* nameOfNewPlant,const char* NewLivingPlace, int days) : nameOfPlant(new char[strlen(nameOfNewPlant) + 1]), livingPlace(new char[strlen(NewLivingPlace) + 1]), days(days) {
	strcpy_s(nameOfPlant, strlen(nameOfNewPlant) + 1, nameOfNewPlant);
	strcpy_s(livingPlace, strlen(NewLivingPlace) + 1, NewLivingPlace);
} 

PlantsBook::~PlantsBook(){this->erase();} // destructor

PlantsBook::PlantsBook(const PlantsBook& obj){ //copy constructor
	this->copy(obj);
}

PlantsBook& PlantsBook::operator=(const PlantsBook& obj) //operator=
{
	if (this != &obj) {
		this->erase();
		this->copy(obj);
	}
	return *this;
}

PlantsBook::PlantsBook(PlantsBook&& obj){ // move constructor
	nameOfPlant = obj.nameOfPlant;
	livingPlace = obj.livingPlace;
	days = obj.days;
	obj.nameOfPlant = nullptr;
	obj.days = 0; 
	obj.livingPlace = nullptr;
}

PlantsBook PlantsBook::operator=(PlantsBook&& obj){ //move operator=
	if (this != &obj) {
		this->erase();
		nameOfPlant = obj.nameOfPlant;
		livingPlace = obj.livingPlace;
		days = obj.days;
		obj.nameOfPlant = nullptr;
		obj.days = 0;
		obj.livingPlace = nullptr;
	}
	return *this;
}

char* PlantsBook::getNameOfPlant()
{
	return nameOfPlant;
} 

char* PlantsBook::getLivingPlace()
{
	return livingPlace;
}

int PlantsBook::detDays()
{
	return days;
}


void PlantsBook::makingFile(char* filename) { //making our file, if we dont have one yet
	if (strlen(filename) > 128)
		throw std::exception("too long name for file");
	std::ofstream oFile;
	oFile.open(filename);
	if (!oFile) {
		throw std::exception("Didn't open the file");
	}
	oFile.close();
}

bool PlantsBook::isAlreadySaved(char* nameOfFile) {
	std::ifstream iFile;
	bool samePlant = false, checkNewLine = false;
	iFile.open(nameOfFile);
	if (!iFile) {
		throw std::exception("file not opened");
	}
	iFile.seekg(0, std::ios::beg); //placing get at the start
	char searcingForPlant;
	int indexOfNewPlant = 0;
	while (iFile.get(searcingForPlant)) {
		if (checkNewLine) { // waiting for new line in the file
			if (searcingForPlant == '\n') {
				checkNewLine = false;
			}
		}
		else if (searcingForPlant == this->nameOfPlant[indexOfNewPlant] && searcingForPlant != 'L') {
			//found another similar letter, name of plant will contail only small letters
			++indexOfNewPlant;
		}
		else if (searcingForPlant == this->nameOfPlant[indexOfNewPlant] && searcingForPlant == 'L') {
			//the same content until Living place, so its already saved
			iFile.close();
			return true;
		}
		else { // reset the index and waiting for new line if there are not similar letters at positions
			indexOfNewPlant = 0;
			checkNewLine = true;
		}
	}
	iFile.close();
	return false;
}

void PlantsBook::sortOfPlants(char* nameOfFile) {
	//we already have a method, which shows if there is already the same plant, so we just need to put it in the correct row
	std::fstream iFile;
	bool checkNewline = false;
	iFile.open(nameOfFile);
	if (!iFile)
		throw std::exception("file not opened");
	char searchingForRow;
	bool isEndOfName = false, before = false, after = false;
	iFile.seekg(0, std::ios::beg);
	int indexOfNewPlant = 0, savingPreviousGetPosition = 0;
	while (iFile.get(searchingForRow)) {
		if (checkNewline) {
			if (searchingForRow == '\n') {
				checkNewline = false;
				if (before || after)
					break;
				else
					savingPreviousGetPosition = iFile.tellg(); //if it is before, we have to save the previous get position
			}
		}
		else if (searchingForRow > this->nameOfPlant[indexOfNewPlant] && !checkNewline) { //between some plants
			before = true;
		}
		else if (searchingForRow < this->nameOfPlant[indexOfNewPlant] && !checkNewline) { //after the checking one
			after = true;
		}
		else if (searchingForRow == 'L') { //position Living place, reset the index
			checkNewline = true;
			indexOfNewPlant = 0;
		}
		else {
			++indexOfNewPlant;
		}
	}
	if (before) { // between some plants
		iFile.seekp(savingPreviousGetPosition, std::ios::beg);
		
		iFile << "Plant name: "<<this->nameOfPlant<<" Living place: "<<this->livingPlace<<" Watering: "<<this->days<< std::endl;
	}
	else {
		//after or at the end of the file
		iFile.seekp(iFile.tellg(), std::ios::beg);
		iFile << "Plant name: " << this->nameOfPlant << " Living place: " << this->livingPlace << " Watering: " << this->days << std::endl;
	}
	iFile.close();
}

void PlantsBook::addingNewSpecies(char* filename) { //adding new plant with using the methods above
	if (isAlreadySaved(filename)) {
		throw std::exception("You have already saved this plant");
	}
	else {
		sortOfPlants(filename);
	}
}
