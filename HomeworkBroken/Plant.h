#ifndef Plant_H_
#define Plant_H_
#include "PlantsBook.h"
class Plant {
	char* typePlant;
	char* plantLP;
	char* daysWatering;

	void erase();
	void copy(const Plant& obj);
public:
	//constructors
	Plant(const char* name);
	~Plant();
	Plant(const Plant& obj);
	Plant& operator=(const Plant& obj);

	//move operators
	Plant(Plant&& obj);
	Plant& operator=(Plant&& obj);

	//operators >> & <<
	//friend std::ostream& operator<<(std::ostream& out, const Plant& obj);
	//friend std::istream& operator>>(std::istream& in, Plant& obj);

	//methods for B
	void ExtractInfo(char* filename);

};
#endif

