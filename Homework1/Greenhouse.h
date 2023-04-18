#ifndef greenhouse_H_
#define greenhouse_H_
#include "PlantsBook.h"
class Greenhouse: public PlantsBook{
	char* nameOfPlant;
	int placeSunny; 
	int placeNeutral; 
	int placeShady; 

	void erase();
	void copy(const Greenhouse& obj);
public:
	//constructors
	Greenhouse(const char* name, int placeSunny, int placeNeutral, int placeShady);
	~Greenhouse();
	Greenhouse(const Greenhouse& obj);
	Greenhouse& operator=(const Greenhouse& obj);

	//methods for Greenhouse
	void makingNewFileForGreenhouse(char* filename);
	bool isSavedPlant(char* filename);
	void InsertPlantInGreenhouse(char* filename, char* catalogueName);
	int writeInTempfile(char* filename,char* livingPlace);
};

#endif

