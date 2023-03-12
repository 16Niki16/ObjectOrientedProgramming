#include <iostream>
#include <cstring>
const int K = 21;

struct Vegetable {
	char name[K];
	int weight;
	void inputVegetable();
};

struct Dressing {
	char name[K];
	double quantity; 
	char allergen[K];
	void inputDresing();
};

struct Salad{
	char name[K];
	Vegetable vegetable[3];
	Dressing dressing; 
	double price;
	void inputSalad();
	double getWeight();
	void printAllergen();
	void print();
	void analyseSalad(Salad salads[], int n);
};

void Vegetable::inputVegetable() {
	std::cin.getline(name, K);
	std::cin >> weight;
}

void Dressing::inputDresing() {
	std::cin.getline(name, K);
	std::cin >> quantity;
	std::cin.ignore();
	std::cin.getline(allergen, K);
}

void Salad::inputSalad() {
	std::cin.getline(name, K);
	for (int i = 0; i < 3; i++) {
		vegetable[i].inputVegetable();
		std::cin.ignore();
	}
	dressing.inputDresing();
	std::cin >> price;
}

double Salad::getWeight() {
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += vegetable[i].weight;
	}
	sum += dressing.quantity;
	return sum;
}

void Salad::printAllergen() {
	std::cout << dressing.name << std::endl;
}

void Salad::print() {
	std::cout << "Content: ";
	for (int i = 0; i < 3; i++) {
		std::cout << vegetable[i].name << " ";
	}
	std::cout << dressing.allergen<<std::endl;
	std::cout << "Price: " << price << std::endl;
	double sum = 0; 
	for (int i = 0; i < 3; i++) {
		sum += vegetable[i].weight;
	}
	std::cout << "Weight: "<<sum<<std::endl<<dressing.allergen;
}

void Salad::analyseSalad(Salad salads[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << salads[i].name<<" ";
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += salads[i].price;
	}
	std::cout << std::endl << "Total cost: " << sum<<" leva"<<std::endl << "Allergens: ";
	for (int i = 0; i < n; i++) {
		std::cout << salads[i].dressing.allergen<<" ";
	}
}

int main(){
	Salad salad1;
	salad1.inputSalad();

}
