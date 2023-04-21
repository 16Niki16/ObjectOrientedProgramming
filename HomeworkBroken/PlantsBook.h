#ifndef plantsbook_H_
#define plantsbook_H_
//#include <string>
class PlantsBook {
#include <iostream>
	char* nameOfPlant;
	char* livingPlace;
	int days;
	void erase();
	void copy(const PlantsBook& obj);
public:
	//constructors
	PlantsBook(const char* nameOfNewPlant);
	PlantsBook(const char* nameOfNewPlant, const char* livingPlace, int days);
	~PlantsBook();
	PlantsBook(const PlantsBook& obj);
	PlantsBook& operator=(const PlantsBook& obj);

	//move semantics
	PlantsBook(PlantsBook&& obj);
	PlantsBook& operator=(PlantsBook&& obj);

	//operators >> & <<
	//friend std::ostream& operator<<(std::ostream& out, const PlantsBook& obj);
	//friend std::istream& operator>>(std::istream& in, PlantsBook& obj);

	//methods for A
	void makingFile(char* filename);
	void sortOfPlants(char* filename);
	bool isAlreadySaved(char* filename);
	void addingNewSpecies(char* filename);
	void writeInNewFile(char* filename);
	void temporaryFile(int pPos, char* filename);
	void copyFile(char* name1, char* name2);
	int getIndex(char* arr, int size, char letter);
};
#endif