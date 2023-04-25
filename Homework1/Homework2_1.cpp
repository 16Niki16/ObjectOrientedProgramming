<<<<<<< HEAD
#include <iostream>
#include <iomanip>
#include<fstream>

#include "PlantsBook.h"
#include "Plant.h"
#include "Greenhouse.h"

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
	//the name of plant and living place have to be with small letters!!!
	
	char filename[] = "PlantsBook.txt";
	char filenameGreenhouse[] = "Greenhouse1.txt";
	//PlantsBook obj("tulip", "shady", 555); //adding to the catalogue of plants
	//obj.addingNewSpecies(filename);

	//Plant objPlant("tulip");
	//objPlant.ExtractInfo(filename); //extract info about the plant we want if it exist int the catalogue
	
	//Greenhouse objGreenhouse("iaaalipa",3,3,3); //sometimes there is a problem with empty new lines in the file
	//objGreenhouse.placeToWrite(filenameGreenhouse,filename);
	//objGreenhouse.numberOfPlants(filenameGreenhouse); //returns the number of plants in different places
=======
#include <iostream>
#include <iomanip>
#include "PlantsBook.h"
#include "Plant.h"
#include "Greenhouse.h"
#include<fstream>
int main() {
	char filename[] = "PlantsBook.txt";
	char filenameGreenhouse[] = "Greenhouse.txt";
	//PlantsBook obj("iaaalipa", "neutral", 555);
	//obj.makingFile(filename); // using if we dont have file yet
	//obj.addingNewSpecies(filename);
	//obj.sortOfPlants(filename);
	//obj.writeInNewFile(filename);
	//Plant objPlant("iaaalipa");
	//objPlant.ExtractInfo(filename);
	Greenhouse objGreenhouse("gaaalipa",2,2,2);
	//objGreenhouse.makingNewFileForGreenhouse(filenameGreenhouse); //using if we dont have file yet
	objGreenhouse.InsertPlantInGreenhouse(filenameGreenhouse,filename);
	std::cout<<std::boolalpha<<objGreenhouse.isSavedPlant(filename);
>>>>>>> 707bb5d8fa520b41fd0ee7c0dd981773f9f90d44
}