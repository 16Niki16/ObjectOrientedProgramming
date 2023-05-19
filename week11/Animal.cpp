#include "Animal.h"
#include<iostream>

void Animal::erase()
{
    delete[] name;
}

void Animal::copy(const Animal& obj)
{
    name = new char[strlen(obj.name) + 1];
    strcpy_s(name, strlen(obj.name) + 1, obj.name);
    weight = obj.weight;
    type = obj.type;
    place = obj.place;
    eatKg = obj.eatKg;
}

Animal::Animal(const char* name1, int weight, typeEat type, placeSleep place, int eat) : eatKg(eat), name(new char[strlen(name1)+1]), weight(weight),type(type),place(place)
{
    strcpy_s(name, strlen(name1) + 1, name1);
}

Animal::~Animal()
{
    erase();
}

Animal::Animal(const Animal& obj)
{
    copy(obj);
}

Animal& Animal::operator=(const Animal& obj)
{
    if (this != &obj) {
        this->erase();
        this->copy(obj);
    }
    return *this;
}

int Animal::getEat()
{
    return ;
}

const char* Animal::getFood()
{
    switch (type) {
    case HERBIVOROUS:
        return "HERBIVOROUS";
    case PREDATOR:
        return "PREDATOR";
    case OMINOUS:
        return "OMINOUS";
    }
}

void Animal::print()
{
    std::cout << name << " " << weight << " " << eatKg << " " << this->getFood()<<" ";
}
