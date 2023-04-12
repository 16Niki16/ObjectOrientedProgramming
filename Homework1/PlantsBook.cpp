#include "PlantsBook.h"
#include <fstream>
#include <iostream>
#include <cstring>

void makingFile(char* filename) {
	std::ofstream oFile;
	oFile.open(filename);
	if (!oFile) {
		throw std::exception("Didn't open the file");
	}
	oFile.close();
}

bool isAlreadySaved(char* nameOfNewPlant, char* nameOfFile) {
	std::ifstream iFile;
	bool sameLetter = false;
	iFile.open(nameOfFile);
	if (!iFile) {
		throw std::exception("file not opened");
	}
	iFile.seekg(0, std::ios::beg);
	char searcingForPlant;
	int indexOfNewPlant = 0; 
	while (iFile.get(searcingForPlant)) {
		if (searcingForPlant == nameOfNewPlant[indexOfNewPlant]) {
			++indexOfNewPlant;
		}
		else {
			indexOfNewPlant = 0;
		}
	}
}

void sortOfPlants(char* nameOfNewPlant, char* nameOfFile) {
	std::fstream iFile;
	int i = 0;
	int positionOfGet = 0, tempGetPosition = 0;
	iFile.open(nameOfFile);
	char searchingForRow;
	bool isEndOfName = false, before = false, after = false;
	iFile.seekg(0, std::ios::beg);
	while (iFile.get(searchingForRow)) {
		if (searchingForRow != 'P' && !isEndOfName) {
			if (searchingForRow > nameOfNewPlant[i]) {
				after = true;
			}
			else if (searchingForRow < nameOfNewPlant[i]) {
				before = true;
			}
		}
		else if (!isEndOfName && searchingForRow == 'P') {
			isEndOfName = true;
		}
		else if (isEndOfName && searchingForRow == '\n') {
			isEndOfName = false;
			i = -1;
			if (after || before) {
				break;
			}
		}
		++i;
	}
	iFile.close();
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
