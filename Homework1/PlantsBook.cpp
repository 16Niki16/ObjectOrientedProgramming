#include "PlantsBook.h"
#include <fstream>
#include <iostream>
#include <cstring>

void PlantsBook::makingFile(char* filename) { //making our file, if we dont have one yet
	std::ofstream oFile;
	oFile.open(filename);
	if (!oFile) {
		throw std::exception("Didn't open the file");
	}
	oFile.close();
}

bool PlantsBook::isAlreadySaved(char* nameOfNewPlant, char* nameOfFile) {
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
		else if (searcingForPlant == nameOfNewPlant[indexOfNewPlant] && searcingForPlant != 'L') {
			//found another similar letter, name of plant will contail only small letters
			++indexOfNewPlant;
		}
		else if (searcingForPlant == nameOfNewPlant[indexOfNewPlant] && searcingForPlant == 'L') { 
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

void PlantsBook::sortOfPlants(char* nameOfNewPlant, char* nameOfFile) { 
	//we already have a method, which shows if there is already the same plant, so we just need to put it in the correct row
	std::fstream iFile;
	bool checkNewline = false;
	iFile.open(nameOfFile);
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
			else if (searchingForRow > nameOfNewPlant[indexOfNewPlant] && !checkNewline) { //between some plants
				before = true;
			}
			else if (searchingForRow < nameOfNewPlant[indexOfNewPlant] && !checkNewline) { //after the checking one
				after = true;
			}
			else if(searchingForRow == 'L') { //position Living place, reset the index
				checkNewline = true;
				indexOfNewPlant = 0;
			}
			else {
				++indexOfNewPlant;
			}
	}
	if (before) { // between some plants
		iFile.seekp(savingPreviousGetPosition, std::ios::beg);
		iFile <<"putting plant info here"<<std::endl;
	}
	else {
	//after or at the end of the file
		iFile.seekp(iFile.tellg(), std::ios::beg);
		iFile << "putting plant info here" << std::endl;
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
