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
}