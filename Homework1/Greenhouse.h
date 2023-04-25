<<<<<<< HEAD
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
	friend std::ostream& operator<<(std::ostream& out, const Greenhouse& obj);
	friend std::istream& operator>>(std::istream& in, Greenhouse& obj);

	//left place in rows
	int leftSunny = placeSunny;
	int leftShady = placeShady;
	int leftNeutral = placeNeutral;

	//get positions in file
	int getSunny = 0;
	int getNeutral = 0; 
	int getShady = 0; 

	//methods for Greenhouse
	void makingNewFileForGreenhouse(char* filename);
	bool isSavedPlant(char* filename);
	void InsertPlantInGreenhouse(char* filename, char* catalogueName);
	int writeInTempfile(char* filename,char* livingPlace);
	void LeftPlaceToBePut(char* filename);
	void getPositions(char* filename);
	void placeToWrite(char* filename, char* catalogueName);
	void numberOfPlants(char* filename);
};

#endif

=======
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

>>>>>>> 707bb5d8fa520b41fd0ee7c0dd981773f9f90d44
