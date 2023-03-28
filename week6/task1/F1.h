#ifndef _F1_
#define _F1_
#include<string>
#include<fstream>

class F1Car{
public:
    std::string name;
    int year;
    int wins;
    double engine_capacity;
};
class F1Team {
public:
    std::string nameOfTeam;
    F1Car cars[2];
    void writeInFile(std::ofstream& stream);
    void readFromFile(std::ifstream& stream);
};

#endif

