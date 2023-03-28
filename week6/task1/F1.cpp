#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include "F1.h"

void F1Team::writeInFile(std::ofstream& stream){
    if (!stream.is_open()) 
        throw std::exception("Error in opening the file");

    stream.write((char*)this, sizeof(F1Team));
    stream.close();
}

void F1Team::readFromFile(std::ifstream& stream){
    if (!stream.is_open())
        throw std::exception("Error in opening the file");
    
    stream.read((char*)this, sizeof(F1Team));
    stream.close();
}

