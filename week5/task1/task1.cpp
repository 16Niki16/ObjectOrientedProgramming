
#include <iostream>
#include<fstream>
int main(){
    std::ifstream if_stream;
    if_stream.open("filename.txt");
    if (!if_stream.is_open()){
        throw std::exception("Not opened yet");
    }
    if_stream.seekg(0,std::ios::end);
    std::cout << if_stream.tellg();
    if_stream.close();
}