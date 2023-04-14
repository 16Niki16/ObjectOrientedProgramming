#include <iostream>
#include "PlantsBook.h"
#include<fstream>
int main() {
	char filename[] = "PlantsBook.txt";
	PlantsBook obj("aabulip", "sunny", 2);
	//obj.makingFile(filename);
	//obj.writeInFile(filename);
	obj.addingNewSpecies(filename);
	
	//std::cout << std::boolalpha<< obj.isAlreadySaved(filename);
}