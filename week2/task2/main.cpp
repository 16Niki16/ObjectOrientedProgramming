#include <iostream>
#include "Header.h"
#include <iomanip>
int main(){
    Triangle obj;
    int AB, BC, AC;
    std::cin >> AB >> BC >> AC;
  //  obj = {AB,BC,AC};
    obj.initialize(BC,AC,AB);
    std::cout<<std::boolalpha<<obj.checkPrav();
}