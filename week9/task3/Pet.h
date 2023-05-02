#ifndef pet_H_
#define pet_H_
#include "Animal.h"
class Pet :public Animal {
	char* nameOwner;
	unsigned telNumber;
	
	void erase();
	void copy(const Pet& obj);
public:
	Pet(char* nameOwnerM, unsigned telNumber, char* name, unsigned age);
	~Pet();
	Pet(const Pet& obj);
	Pet& operator=(const Pet& obj);

	void print();
	void changeName(char* name);
	void setNewOwner(char* nameOwner);
};
#endif

