#include <iostream>
#include <iomanip>
#include "PlantsBook.h"
#include "Plant.h"
#include "Greenhouse.h"
#include<fstream>

const int BUFF_SIZE = 1024;

void printCatalogue(char* filename) { //printing catalogue with plants
	std::ifstream iFile;
	iFile.open(filename, std::ios::in);
	if (!iFile.is_open()) {
		throw std::exception("file not opened");
	}
	while (!iFile.eof()) {
		char buff[1024];
		iFile.getline(buff, BUFF_SIZE);
		std::cout<< buff<<std::endl;
	}
	iFile.close();
} 

int main() {
	char filename[] = "PlantsBook.txt";
	char filenameGreenhouse[] = "Greenhouse.txt";
	//PlantsBook obj("raaalipa", "neutral", 555);
	//obj.makingFile(filename); // using if we dont have file yet
	//obj.addingNewSpecies(filename);
	//obj.sortOfPlants(filename);
	//obj.writeInNewFile(filename);
	//Plant objPlant("iaaalipa");
	//objPlant.ExtractInfo(filename);
	Greenhouse objGreenhouse("saaalipa",10,10,10);
	//objGreenhouse.makingNewFileForGreenhouse(filenameGreenhouse); //using if we dont have file yet
	//objGreenhouse.InsertPlantInGreenhouse(filenameGreenhouse,filename);
	objGreenhouse.LeftPlaceToBePut(filenameGreenhouse);
	//std::cout << objGreenhouse.leftNeutral << " " << objGreenhouse.leftShady << " " << objGreenhouse.leftSunny;
	//std::cout<<std::boolalpha<<objGreenhouse.isSavedPlant(filename);
	//printCatalogue(filename);
}