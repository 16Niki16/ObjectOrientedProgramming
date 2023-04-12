#ifndef plantsbook_H_
#define plantsbook_H_
//#include <string>
class PlantsBook {
	char* nameOfPlant;
	char* livingPlace;
	int days;
public:
	char* getNameOfPlant();
	char* getLivingPlace();
	int detDays();
};

#endif // !plantsbook_H_

