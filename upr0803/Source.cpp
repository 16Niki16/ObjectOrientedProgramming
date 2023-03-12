#include <iostream>
#include "Header.h"
void TimeStamp::createSeconds() {
	std::cin >> seconds;
}
void TimeStamp::print() {
	std::cout << hours << ":" << minutes << ":" << seconds<<std::endl;
}
void TimeStamp::sbor(int seconds1, int seconds2) {
	int seconds = seconds1 + seconds2;
	if (seconds >= 60) {
		this->minutes += 1;
		seconds -= 60;
		this->seconds = seconds;
	}
}