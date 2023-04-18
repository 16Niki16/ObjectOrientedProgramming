#include "Plant.h"
#include<iostream>
#include <fstream>
#include <cstring>

char default_place[] = "neutral";
const int BUFF_SIZE = 1024;
const int PlantLivingPlace = strlen(" Living place: ");
const int Watering = strlen(" Watering: ");
char def_days[] = "3";

int getIndexPlant(char* arr, int size, char letter) { //getting the index of L
	for (int i = 0; i < size; i++) {
		if (arr[i] == letter) {
			return i;
		}
	}
}

void Plant::erase()
{
	delete[] typePlant;
	delete[] plantLP;
	delete[] daysWatering;
}

void Plant::copy(const Plant& obj) {
	typePlant = new char[strlen(obj.typePlant)+1];
	strcpy_s(typePlant, strlen(obj.typePlant) + 1, obj.typePlant);
	daysWatering = new char[strlen(obj.daysWatering) + 1];
	strcpy_s(daysWatering, strlen(obj.daysWatering) + 1, obj.daysWatering);
	plantLP = new char[strlen(obj.plantLP) + 1];
	strcpy_s(plantLP, strlen(obj.plantLP) + 1, obj.plantLP);
}

Plant::Plant(const char* name) : typePlant(new char[strlen(name) + 1]), plantLP(new char[strlen(default_place) + 1]), daysWatering(new char[strlen(def_days) + 1]) {
	strcpy_s(typePlant, strlen(name) + 1, name);
	strcpy_s(plantLP, strlen(default_place) + 1, default_place);
	strcpy_s(daysWatering, strlen(def_days) + 1, def_days);
}

Plant::~Plant(){erase();}

Plant::Plant(const Plant& obj){copy(obj);}

Plant& Plant::operator=(const Plant& obj)
{
	if (this != &obj) {
		this->erase();
		this->copy(obj);
	}
	return *this;
}

void Plant::ExtractInfo(char* filename){
	bool isSaved = true, isFirst = true;
	std::ifstream iFile;
	iFile.open(filename, std::ios::in);
	iFile.seekg(0, std::ios::beg);
	while (!iFile.eof()) {
		char buff[BUFF_SIZE];
		iFile.getline(buff, BUFF_SIZE);
		int lastIndexOfWord = getIndexPlant(buff, BUFF_SIZE, 'L'); //extracting the name of plant from the file
		char* newArray = new char[lastIndexOfWord - 12];
		int indexInNewArray = 0;
		for (int i = 12; i < lastIndexOfWord - 1; i++) {
			newArray[indexInNewArray] = buff[i];
			++indexInNewArray;
		}
		newArray[indexInNewArray] = '\0';

		int result = strcmp(this->typePlant, newArray);

		if (result == 0 && isFirst) { //checking for similar plant 
			isSaved = false;
			isFirst = false;
	
			int indexLiv = lastIndexOfWord + PlantLivingPlace - 1;
			int lastIndexLiv = getIndexPlant(buff, BUFF_SIZE, 'W'); 
			char* LivArray = new char[lastIndexLiv - indexLiv];//extracting information for living place
			indexInNewArray = 0;
			for (int i = indexLiv; i < lastIndexLiv - 1; i++) {
				LivArray[indexInNewArray] = buff[i];
				++indexInNewArray;
			}
			LivArray[indexInNewArray] = '\0';
			this->plantLP = new char[strlen(LivArray) + 1];
			strcpy_s(this->plantLP, strlen(LivArray) + 1, LivArray);

			int indexW = lastIndexLiv + Watering - 1;
			int lastIndexW = getIndexPlant(buff, BUFF_SIZE, '\0'); 
			char* WatArray = new char[lastIndexW - indexW + 1]; //extracting days for watering
			indexInNewArray = 0;

			for (int i = indexW; i < lastIndexW; i++) {
				WatArray[indexInNewArray] = buff[i];
				++indexInNewArray;
			}

			WatArray[indexInNewArray] = '\0';
			this->daysWatering = new char[strlen(WatArray) + 1];
			strcpy_s(this->daysWatering, strlen(WatArray) + 1, WatArray);
			delete[] LivArray;
			delete[] WatArray;
		}
		delete[] newArray;
	}
	if (isSaved) {
			throw std::exception("plant not found");
	}
	else {
		std::cout << this->plantLP << " " << this->daysWatering;
	}
	iFile.close();
	}