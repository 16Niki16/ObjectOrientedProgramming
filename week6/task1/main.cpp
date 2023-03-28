#include <fstream>
#include <iostream>
#include "F1.h"
int main() {
    F1Car car = { "Ferrari", 2023, 0, 1.6 };
    F1Car car2 = { "RedBull", 2023, 3, 1.6 };
    F1Team team = { "Ferrari",car,car2};
    std::ofstream o_file("car.bin", std::ios::binary);
    team.writeInFile(o_file);
    o_file.close();
    std::ifstream i_file("car.bin", std::ios::binary);
    team.readFromFile(i_file);
    i_file.close();
   // std::cout << team.nameOfTeam << " " << team.cars->name<<" "<<team.cars->engine_capacity<<" "<<team.cars->year;
    return 0;
}