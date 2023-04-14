#include <iostream>
#include "PlantsBook.h"
#include<fstream>
int main() {
	char filename[] = "PlantsBook.txt";
	PlantsBook obj("gaaalipa", "sunny", 2);
	//obj.makingFile(filename);
	obj.addingNewSpecies(filename);
	//obj.sortOfPlants(filename);
	//obj.writeInNewFile(filename);
	//std::cout << std::boolalpha<< obj.isAlreadySaved(filename);
}