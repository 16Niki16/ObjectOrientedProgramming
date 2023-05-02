#ifndef animal_H_
#define animal_H_
class Animal {
	char* name;
	unsigned age;

	void erase();
	void copy(const Animal& obj);
public:
	Animal(char* name, unsigned age);
	~Animal();
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);

	char* getName();
	unsigned getAge();

	void setName(char* name);
	
};
#endif // !animal_H_

