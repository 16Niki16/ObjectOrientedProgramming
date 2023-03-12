#ifndef HEADER_H_
#define HEADER_H_
const int K = 21;
class Waffle {
public:
	char marka[21]; 
	int gram;
private:
	double price; 
	double priceClient;
public:
	void initialiseWaffle(char marka[21], int gram, double price, double priceClient) {
		for (int i = 0; i < 21; i++)
			this->marka[i] = marka[i];
		this->gram = gram;
		this->price = price;
		this->priceClient = priceClient;
	}
};

class Shop {
public:
	Waffle waffle;
	int numberWaffles;
	int maxNumber;
private:
	int income;
	int expenses;
public:
	void initialiseShop(Waffle object, int numberWaffles, int maxNumber, int income, int expenses) {
		this->waffle = object;
		this->numberWaffles = numberWaffles;
		this->maxNumber = maxNumber;
		this->income = income;
		this->expenses = expenses;
	}
	void checkingNumber(int number);
	void checkingForSale(int number);
	void print(Waffle waffle);
	void polojenie();
};
#endif
