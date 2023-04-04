#include <iostream>
#include<string>
#include "Hogwarts.h"
#include "Student.h"

Hogwarts::Hogwarts(): numberOfStudents(0), students(nullptr)
{
}


Hogwarts::Hogwarts(const Hogwarts& other)
{
	copy(other);
}

Hogwarts& Hogwarts::operator=(const Hogwarts& other)
{
	if (this != &other)
		this->erase();
		this->copy(other);
}

Hogwarts::~Hogwarts()
{
	erase();
}

void Hogwarts::erase()
{
	delete[] students;
}

void Hogwarts::copy(const Hogwarts& other)
{
	numberOfStudents = other.numberOfStudents;
	capacity = other.capacity;
	this->students = new Student[capacity];
	for (int i = 0; i < capacity; i++) {
		students[i] = other.students[i];
	}
}

void Hogwarts::addStudent(const Student& student) {
	if (capacity == numberOfStudents + 1) {
		if (capacity != 0) {
			capacity *= 2;
		}
		else {
			capacity = 2;
		}
	}
	Student* copy = new Student[capacity];
	for (int i = 0; i < numberOfStudents; i++) {
		copy[i] = students[i];
	}
	delete[] this->students;
	this->students = copy;
}

std::ostream& operator<<(std::ostream& out, const Hogwarts& hogwarts){
	for (int i = 0; i < hogwarts.numberOfStudents; i++) {
		out << hogwarts.students[i].getName() << " from " << hogwarts.students[i].getHouse();
	}
}
