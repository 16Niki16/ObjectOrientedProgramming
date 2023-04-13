#ifndef plantsbook_H_
#define plantsbook_H_
//#include <string>
class PlantsBook {
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
	
	//move constructor and operator=
	PlantsBook(PlantsBook&&);
	PlantsBook operator=(PlantsBook&& obj);

	//methods(getters not used yet)
	char* getNameOfPlant();
	char* getLivingPlace();
	int detDays();

	//methods for A
	void makingFile(char* filename);
	void sortOfPlants(char* filename);
	bool isAlreadySaved(char* filename);
	void addingNewSpecies(char* filename);
};
#endif
