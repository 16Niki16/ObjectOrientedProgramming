#ifndef animal_H_
#define animal_H_

enum typeEat {
	HERBIVOROUS,
	PREDATOR,
	OMINOUS
};

enum placeSleep {
	FLOOR,
	TREES,
	WATER
};
class Animal{
	char* name;
	int weight;
	int eatKg;
	typeEat type;
	placeSleep place;

	void erase();
	void copy(const Animal& obj);
public:
	//constructors
	Animal(const char* name1, int weight, typeEat type, placeSleep place, int eat);
	virtual ~Animal();
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);

	int getEat();
	const char* getFood();
	virtual void print();

};
#endif // !animal_H_


