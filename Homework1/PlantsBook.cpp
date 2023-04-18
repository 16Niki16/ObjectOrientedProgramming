#include "PlantsBook.h"
#include <fstream>
#include <iostream>
#include <cstring>

char default_Place[] = "neutral";
const int BUFF_SIZE = 1024;
char PlantName[] = "Plant name: ";
char LivingPlace[] = " Living place: ";
char Watering[] = " Watering: ";

void PlantsBook::erase() // destroy method
{
	delete[] nameOfPlant;
	delete[] livingPlace;
}

void PlantsBook::copy(const PlantsBook& obj) { //copy method
	nameOfPlant = new char[strlen(obj.nameOfPlant) + 1];
	strcpy_s(nameOfPlant, strlen(obj.nameOfPlant), obj.nameOfPlant);
	livingPlace = new char[strlen(obj.livingPlace) + 1];
	strcpy_s(livingPlace, strlen(obj.livingPlace), obj.livingPlace);
	days = obj.days;
}

PlantsBook::PlantsBook(const char* nameOfNewPlant) : nameOfPlant(new char[strlen(nameOfNewPlant) + 1]), livingPlace(new char[strlen(default_Place) + 1]), days(3) {//default constructor
	strcpy_s(nameOfPlant, strlen(nameOfNewPlant) + 1, nameOfNewPlant);
	strcpy_s(livingPlace, strlen(default_Place) + 1, default_Place);
}

PlantsBook::PlantsBook(const char* nameOfNewPlant, const char* NewLivingPlace, int days) : nameOfPlant(new char[strlen(nameOfNewPlant) + 1]), livingPlace(new char[strlen(NewLivingPlace) + 1]), days(days) {
	strcpy_s(nameOfPlant, strlen(nameOfNewPlant) + 1, nameOfNewPlant);
	strcpy_s(livingPlace, strlen(NewLivingPlace) + 1, NewLivingPlace);
}

PlantsBook::~PlantsBook() { this->erase(); } // destructor

PlantsBook::PlantsBook(const PlantsBook& obj) { //copy constructor
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

void PlantsBook::makingFile(char* filename) { //making our file, if we dont have one yet
	if (strlen(filename) > 128)
		throw std::exception("too long name for file");
	std::ofstream oFile;
	oFile.open(filename, std::ios::out | std::ios::app);
	if (!oFile.is_open()) {
		throw std::exception("Didn't open the file");
	}
	oFile.close();
}

bool PlantsBook::isAlreadySaved(char* nameOfFile) {
	std::ifstream iFile;
	bool samePlant = false, checkNewLine = false;
	iFile.open(nameOfFile, std::ios::in);
	if (!iFile.is_open()) {
		throw std::exception("file not opened");
	}
	iFile.seekg(0, std::ios::beg); //placing get at the start
	char searcingForPlant;
	int indexOfNewPlant = 0, skippingPlName = 0;
	while (!iFile.eof()) {
		iFile.get(searcingForPlant);
		if (checkNewLine) { // waiting for new line in the file
			if (searcingForPlant == '\n') {
				checkNewLine = false;
				skippingPlName = 0;
			}
		}
		else if (skippingPlName < 12) {
			skippingPlName++;
		}
		else if (searcingForPlant == this->nameOfPlant[indexOfNewPlant]) {
			//found another similar letter, name of plant will contail only small letters
			++indexOfNewPlant;
		}
		else if (searcingForPlant == ' ' && indexOfNewPlant == strlen(nameOfPlant)) {
		} //skipping interval
		else if (searcingForPlant == 'L' && indexOfNewPlant == strlen(nameOfPlant)) { //checking if it is L
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

int PlantsBook::getIndex(char* arr, int size, char letter) { //getting the index of L
	for (int i = 0; i < size; i++) {
		if (arr[i] == letter) {
			return i;
		}
	}
}

void PlantsBook::sortOfPlants(char* nameOfFile) {
	//we already have a method, which shows if there is already the same plant, so we just need to put it in the correct row
	std::fstream iFile;
	iFile.open(nameOfFile, std::ios::in);

	if (!iFile.is_open()) { throw std::exception("file not opened"); }

	iFile.seekg(0, std::ios::beg); //placing get at the start

	bool isEndOfFile = true;
	int gPos = iFile.tellg();
	while (!iFile.eof()) {
		char buff[BUFF_SIZE];
		iFile.getline(buff, BUFF_SIZE, '\n');
		int lastIndexOfWord = getIndex(buff, BUFF_SIZE, 'L');
		//std::cout << buff << std::endl;
		char* newArray = new char[lastIndexOfWord - 12];
		int indexInNewArray = 0;
		for (int i = 12; i < lastIndexOfWord - 1; i++) {
			newArray[indexInNewArray] = buff[i];
			++indexInNewArray;
		}
		newArray[indexInNewArray] = '\0';
		std::cout << newArray << " ";
		int result = strcmp(this->nameOfPlant, newArray);

		std::cout << "pos now: " << gPos << std::endl;
		if (result == -1) {

			iFile.close();

			temporaryFile(gPos, nameOfFile);
			isEndOfFile = false;
			break;
		}
		delete[] newArray;
		gPos = iFile.tellg();
	}
	if (isEndOfFile) {
		std::cout << "kraj";
		iFile.close();
		writeInNewFile(nameOfFile);
	}

}

void PlantsBook::addingNewSpecies(char* filename) { //adding new plant with using the methods above
	if (isAlreadySaved(filename)) {
		throw std::exception("You have already saved this plant");
	}
	else {
		sortOfPlants(filename);
	}
}

void PlantsBook::temporaryFile(int putPosition, char* filename) { //sorting the elements
	char tempFileName[] = "tempFile.txt";
	std::fstream tempFile;
	tempFile.open(tempFileName, std::ios::out | std::ios::in);

	if (!tempFile.is_open()) { throw std::exception("file not opened"); }

	std::fstream iFile;
	iFile.open(filename, std::ios::out | std::ios::in | std::ios::app);

	if (!iFile.is_open()) { throw std::exception("file not opened"); }

	int sizeToReach = 0;
	char symbol;
	bool write = true;
	while (!iFile.eof()) {
		int getPos = iFile.tellg();
		if (putPosition == getPos && write) {
			tempFile << "Plant name: " << this->nameOfPlant << " Living place: " << this->livingPlace << " Watering: " << this->days << '\n';
			write = false;
		}
		else {
			iFile.get(symbol);
			tempFile << symbol;
		}
	}
	tempFile.close();
	iFile.close();
	copyFile(tempFileName, filename);
}

void PlantsBook::writeInNewFile(char* filename) {
	std::ofstream oFile;
	oFile.open(filename, std::ios::out | std::ios::app);
	oFile << "Plant name: " << this->nameOfPlant << " Living place: " << this->livingPlace << " Watering: " << this->days << '\n';
	oFile.close();
}

void PlantsBook::copyFile(char* name1, char* name2) {

	std::ifstream tempFile;
	tempFile.open(name1, std::ios::in);
	if (!tempFile.is_open()) {
		throw std::exception("file not opened");
	}

	std::ofstream iFile;
	iFile.open(name2);
	if (!iFile.is_open()) {
		throw std::exception("file not opened");
	}
	while (!tempFile.eof()) { //test
		char buff[BUFF_SIZE];
		tempFile.getline(buff, BUFF_SIZE);
		iFile << buff << std::endl;
	}
	tempFile.close();
	iFile.close();
}