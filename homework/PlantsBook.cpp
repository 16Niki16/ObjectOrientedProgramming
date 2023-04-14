#include "PlantsBook.h"
#include <fstream>
#include <iostream>
#include <cstring>

char default_Place[] = "neutral";
const int BUFF_SIZE = 1024;

void PlantsBook::erase() // destroy method
{
	delete[] nameOfPlant;
	delete[] livingPlace;
}

void PlantsBook::copy(const PlantsBook& obj) { //copy method
	nameOfPlant = obj.nameOfPlant;
	livingPlace = obj.livingPlace;
	days = obj.days;
}

PlantsBook::PlantsBook(const char* nameOfNewPlant) : nameOfPlant(new char[strlen(nameOfNewPlant) + 1]), livingPlace(default_Place), days(3) {//default constructor
	strcpy_s(nameOfPlant, strlen(nameOfNewPlant) + 1, nameOfNewPlant);

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

PlantsBook::PlantsBook(PlantsBook&& obj) { // move constructor
	nameOfPlant = obj.nameOfPlant;
	livingPlace = obj.livingPlace;
	days = obj.days;
	obj.nameOfPlant = nullptr;
	obj.days = 0;
	obj.livingPlace = nullptr;
}

PlantsBook PlantsBook::operator=(PlantsBook&& obj) { //move operator=
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
	oFile.open(filename , std::ios::out | std::ios::app);
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
		//std::cout << searcingForPlant <<" "<< this->nameOfPlant[indexOfNewPlant]<< " "<<skippingPlName<<std::endl;
		if (checkNewLine) { // waiting for new line in the file
			if (searcingForPlant == '\n') {
				checkNewLine = false;
				skippingPlName = 0;
			}
		}
		else if (skippingPlName<12) {
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

int getIndex(char* arr, int size, char letter) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == letter) {
			return i;
		}
	}
	throw std::exception("mistake");
}

void PlantsBook::sortOfPlants(char* nameOfFile) {
	std::fstream iFile;
	iFile.open(nameOfFile, std::ios::in);
	if (!iFile.is_open()) {
		throw std::exception("file not opened");
	}
	iFile.seekg(0, std::ios::beg); //placing get at the start

	while (!iFile.eof()) {
		char buff[BUFF_SIZE];
		iFile.getline(buff, BUFF_SIZE);
		int lastIndexOfWord = getIndex(buff, BUFF_SIZE, 'L');
		char* newArray = new char[lastIndexOfWord - 12];
		for (int i = 12; i < lastIndexOfWord; i++) {
		
		}
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
	//std::cout << std::boolalpha << isAlreadySaved(filename);
}

void PlantsBook::writeInFile(char* filename, int putPosition){
	std::ofstream oFile;
	oFile.open(filename, std::ios::out | std::ios::app);
	oFile.seekp(putPosition, std::ios::beg);
	oFile << "Plant name: " << this->nameOfPlant << " Living place: " << this->livingPlace << " Watering: " << this->days << '\n';
	oFile.close();
}
/*std::cout << searcingForPlant << " " << this->nameOfPlant[indexOfNewPlant] << std::endl;
		if (checkNewLine) { // waiting for new line in the file
			if (searcingForPlant == '\n') {
				checkNewLine = false;
				skippingPlName = 0;
			}
			if (before || after) {
				break;
			}
			else {
				savingPreviousGetPosition = iFile.tellg();
			}
			//std::cout << "get pos: "<<savingPreviousGetPosition << std::endl;
		}
		else if (skippingPlName < 12) {
			skippingPlName++;
		}
		else if (searcingForPlant == this->nameOfPlant[indexOfNewPlant]) {
			//found another similar letter, name of plant will contail only small letters
			++indexOfNewPlant;
		}
		else if (searcingForPlant < this->nameOfPlant[indexOfNewPlant]) {
			after = true;
		}
		else if (searcingForPlant > this->nameOfPlant[indexOfNewPlant]) {
			before = true;
		}
		else if (searcingForPlant == ' ' && indexOfNewPlant == strlen(nameOfPlant)) {} //skipping interval
		else if (searcingForPlant == 'L' && indexOfNewPlant == strlen(nameOfPlant)) { //checking if it is L
			indexOfNewPlant = 0;
			checkNewLine = true;
		}
	}*/

//we already have a method, which shows if there is already the same plant, so we just need to put it in the correct row
	/*std::fstream iFile;
	bool checkNewline = false;
	iFile.open(nameOfFile, std::ios::in | std::ios::out | std::ios::app);
	if (!iFile.is_open())
		throw std::exception("file not opened");
	char searchingForRow;
	bool isEndOfName = false, before = false, after = false;
	iFile.seekg(0, std::ios::beg);
	int indexOfNewPlant = 0, savingPreviousGetPosition = 0, skippingPlName = 0;
	while (!iFile.eof()) {
		iFile.get(searchingForRow);
		if (checkNewline) {
			std::cout << std::boolalpha << before << " " << after << std::endl;
			if (searchingForRow == '\n') {
				checkNewline = false;
				skippingPlName = 0;
				if (before || after)
					break;
				else
					savingPreviousGetPosition = iFile.tellg(); //if it is before, we have to save the previous get position
				//std::cout << savingPreviousGetPosition << " ";
			}
		}
		else if (skippingPlName < 12) {
			skippingPlName++;
		}
		else if (searchingForRow > this->nameOfPlant[indexOfNewPlant] && indexOfNewPlant <strlen(this->nameOfPlant) && searchingForRow != 'L') { //between some plants
			before = true;
		}
		else if (searchingForRow < this->nameOfPlant[indexOfNewPlant] && indexOfNewPlant < strlen(this->nameOfPlant) && searchingForRow != 'L') { //after the checking one
			after = true;
		}
		else if (searchingForRow == 'L' && indexOfNewPlant == strlen(this->nameOfPlant)) { //position Living place, reset the index
			checkNewline = true;
			indexOfNewPlant = 0;
		}
		else {
			++indexOfNewPlant;
		}
	}*/