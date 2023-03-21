#include<fstream>
#include<iostream>

int main() {
    std::ifstream if_stream;
    if_stream.open("task2.cpp");
    if (!if_stream.is_open()){
        throw std::exception("Not opened yet"); 
    } 

    std::cout << if_stream.rdbuf();
    if_stream.close();
}