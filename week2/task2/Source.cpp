#include <iostream>
#include <cmath>
#include "Header.h"


void Triangle::initialize(int a, int b, int c) {
	AB = c;
	AC = b; 
	BC = a;
}
bool Triangle::checkPrav() {
	if (AB * AB == BC * BC + AC * AC || AB * AB + BC * BC == AC * AC || AB * AB + AC * AC == BC * BC) {
		return true;
	}
	return false;
}
bool Triangle::checkRavnobedren() {
	if (AB == BC || AB == AC || BC == AC){
		return true;
	}
	return false;
}
double Triangle::area() {
	int p = (AB + BC + AC)/2;
	double area = sqrt(p*(p - AB)*(p - BC)*(p - AC));
	return area;
}
int Triangle::perimeter() {
	int perimeter = AB + BC + AC;
	return perimeter;
}
void Triangle::height() {
	double areaTr = area();
	double heightAB = 1.00 * (areaTr * 2 / AB);
	double heightAC = 1.00 * (areaTr * 2 / AC);
	double heightBC = 1.00 * (areaTr * 2 / BC);
	std::cout << "height AB: " << heightAB << std::endl << "height AC: " << heightAC << std::endl << "height BC: " << heightBC << std::endl;

}
