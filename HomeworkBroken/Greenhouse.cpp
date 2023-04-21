#include "Greenhouse.h"
#include <fstream>
#include <iostream>
#include <cstring>

const int BUFF_SIZE = 1024;
const int PlantLivingPlace = strlen(" Living place: ");

void Greenhouse::erase(){delete[] nameOfPlant;}

void Greenhouse::copy(const Greenhouse& obj)
{
	nameOfPlant = new char[strlen(obj.nameOfPlant) + 1];
	strcpy_s(nameOfPlant, strlen(obj.nameOfPlant) + 1, obj.nameOfPlant);
	placeSunny = obj.placeSunny;
	placeNeutral = obj.placeNeutral;
	placeShady = obj.placeShady;
}

Greenhouse::Greenhouse(const char* name, int placeSunny, int placeNeutral, int placeShady) : nameOfPlant(new char[strlen(name) + 1]), placeSunny(placeSunny),placeNeutral(placeNeutral), placeShady(placeShady), PlantsBook(name)
{
	strcpy_s(this->nameOfPlant, strlen(name) + 1, name);
}

Greenhouse::~Greenhouse() { this->erase(); }

Greenhouse::Greenhouse(const Greenhouse& obj) : PlantsBook(obj){this->copy(obj);}//copy constructor

Greenhouse& Greenhouse::operator=(const Greenhouse& obj)
{
	if (this != &obj) {
		PlantsBook::operator=(obj);
		this->erase();
		this->copy(obj);
	}
	return *this;
	
}

Greenhouse::Greenhouse(Greenhouse&& obj) : PlantsBook(obj)
{
	nameOfPlant = obj.nameOfPlant;
	placeNeutral = obj.placeNeutral;
	placeSunny = obj.placeSunny;
	placeShady = obj.placeShady;
	obj.nameOfPlant = nullptr;
	obj.placeNeutral = 0; 
	obj.placeShady = 0;
	obj.placeSunny = 0;
}

Greenhouse& Greenhouse::operator=(Greenhouse&& obj){
	if (this != &obj) {
		this->erase();
		nameOfPlant = obj.nameOfPlant;
		placeNeutral = obj.placeNeutral;
		placeShady = obj.placeShady;
		placeSunny = obj.placeSunny;
		obj.nameOfPlant = nullptr;
		obj.placeNeutral = 0;
		obj.placeShady = 0;
		obj.placeSunny = 0;
	}
	return *this;
}


void Greenhouse::makingNewFileForGreenhouse(char* filename)
{
	std::ofstream oFile;
	oFile.open(filename);
	if (!oFile.is_open()) {
		throw std::exception("file is not opened");
	}
	oFile << "sunny:\nneutral:\nshady:\n";
}

bool Greenhouse::isSavedPlant(char* filename){
	if (!isAlreadySaved(filename))
		return false;
	return true;
}

void Greenhouse::InsertPlantInGreenhouse(char* filename, char* catalogueName)
{
	std::ifstream iFile;
	iFile.open(catalogueName, std::ios::in);
	if (!iFile.is_open()) {
		throw std::exception("catalogue file not opened");
	}

	if (!isSavedPlant(catalogueName))
		throw std::exception("information about plant not found");

	while (!iFile.eof()) {
		char buff[BUFF_SIZE];
		iFile.getline(buff, BUFF_SIZE);
		int lastIndexOfWord = getIndex(buff, BUFF_SIZE, 'L'); //extracting the name of plant from the file
		char* newArray = new char[lastIndexOfWord - 12];
		int indexInNewArray = 0;
		for (int i = 12; i < lastIndexOfWord - 1; i++) {
			newArray[indexInNewArray] = buff[i];
			++indexInNewArray;
		}
		newArray[indexInNewArray] = '\0';
		std::cout << newArray << std::endl;
		int result = strcmp(this->nameOfPlant, newArray);

		if (result == 0) {
			int indexLiv = lastIndexOfWord + PlantLivingPlace - 1;
			int lastIndexLiv = getIndex(buff, BUFF_SIZE, 'W');
			char* LivArray = new char[lastIndexLiv - indexLiv + 1];//extracting information for living place
			indexInNewArray = 0;
			for (int i = indexLiv; i < lastIndexLiv; i++) {
				if(i == lastIndexLiv - 1)
					LivArray[indexInNewArray] = ':';
				else
					LivArray[indexInNewArray] = buff[i];
				++indexInNewArray;
			}
			LivArray[indexInNewArray] = '\0';
			writeInTempfile(filename, LivArray);
			delete[] LivArray;
		}
		delete[] newArray;
	}
	
	iFile.close();
}

int Greenhouse::writeInTempfile(char* filename, char* livingPlace) //writing and copying the information
{
	char tempFile[] = "tempFileGreenhouse.txt";
	std::ofstream oFile;
	oFile.open(tempFile, std::ios::out);
	if (!oFile.is_open()) {
		throw std::exception("file not opened yet");
	}
	
	std::ifstream iFile;
	iFile.open(filename, std::ios::in);
	if (!iFile.is_open()) {
		throw std::exception("file not opened yet");
	}
	while (!iFile.eof()) {
		char buff[BUFF_SIZE];
		iFile.getline(buff, BUFF_SIZE);
		int result = strcmp(buff, livingPlace);
		if (result == 0) {
			oFile << buff << std::endl << this->nameOfPlant<<std::endl;
		}
		else {
			oFile << buff<<std::endl;
		}
	}
		iFile.close();
		oFile.close();
		copyFile(tempFile, filename);
}

void Greenhouse::LeftPlaceToBePut(char* filename)
{
	std::ifstream iFile;
	iFile.open(filename);
	if (!iFile.is_open()) {
		throw std::exception("can't open the file");
	}
	bool sunny = false, shady = false, neutral = false;
	int takenSunny = 0, takenShady = 0, takenNeutral = 0;
	while (!iFile.eof()) {
		char buff[BUFF_SIZE];
		iFile.getline(buff, BUFF_SIZE);
		int resultSunny = strcmp(buff, "sunny:");
		int resultShady = strcmp(buff, "shady:");
		int resultNeutral = strcmp(buff, "neutral:");
		if (resultNeutral == 0) {
			neutral = true;
			sunny = false;
			shady = false;
		}
		else if (resultShady == 0) {
			neutral = false;
			sunny = false;
			shady = true;
		}
		else if (resultSunny == 0) {
			neutral = false;
			sunny = true;
			shady = false;
		}
		else if (sunny) {
			++takenSunny;
		}
		else if (shady) {
			++takenShady;
		}
		else if (neutral) {
			++takenNeutral;
		}
	}
	iFile.close();
	leftSunny = placeSunny - takenSunny;
	leftNeutral = placeNeutral - takenNeutral;
	leftShady = placeShady - takenShady;
}

//operators >> && <<
//std::ostream& operator<<(std::ostream& out, const Greenhouse& obj) {}
//std::istream& operator>>(std::istream& in, Greenhouse& obj) {}