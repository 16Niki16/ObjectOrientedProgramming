#include<iostream>
#include "Header.h"
void Shop::checkingNumber(int number) {
	if(maxNumber<number){
		throw std::exception("error");
	}
	numberWaffles = number;
}
void Shop::checkingForSale(int number) {
	if (numberWaffles <number) {
		throw std::exception("error");
	}
	numberWaffles -= number;
}
void Shop::print(Waffle waffle) {
	int promenliva = numberWaffles * waffle.gram;
	std::cout << "Number of Waffles" << numberWaffles<<std::endl;
	std::cout << "Marka of Waffles" << waffle.marka << std::endl;
	std::cout <<"Weight of Waffles" << promenliva << std::endl;
}
void Shop::polojenie() {
	double incomeExpenses = income - expenses;
	std::cout << incomeExpenses;
}

