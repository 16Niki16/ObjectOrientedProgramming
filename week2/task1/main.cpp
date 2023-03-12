#include <iostream>
#include "Header.h"

int main(){
	Waffle obj;
	Shop obj1;
	char name[21] = "vafla marka\0";
	int order, shopping;
	//std::cin.getline(name, 21);
	obj.initialiseWaffle(name,50, 20, 10);
	obj1.initialiseShop(obj, 0, 10, 0, 0);
	std::cin >> order;
	obj1.checkingNumber(order);
	if (obj1.numberWaffles != 0) {
		std::cin >> shopping;
		obj1.checkingForSale(shopping);
}
	
}
