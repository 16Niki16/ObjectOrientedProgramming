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

	//move semantics
	Greenhouse(Greenhouse&& obj);
	Greenhouse& operator=(Greenhouse&& obj);

	//operators << and >>
	//friend std::ostream& operator<<(std::ostream& out, const Greenhouse& obj);
	//friend std::istream& operator>>(std::istream& in, Greenhouse& obj);

	//left place in rows
	int leftSunny = 0;
	int leftShady = 0;
	int leftNeutral = 0;

	//methods for Greenhouse
	void makingNewFileForGreenhouse(char* filename);
	bool isSavedPlant(char* filename);
	void InsertPlantInGreenhouse(char* filename, char* catalogueName);
	int writeInTempfile(char* filename,char* livingPlace);
	void LeftPlaceToBePut(char* filename);
};

#endif

