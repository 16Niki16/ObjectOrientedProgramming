#include<iostream>
#include<string>
#include "Bank.h"

Bank::Bank(){
	const int default_capacity = 2;
	const int default_id = 1000;
	account = new Account*[default_capacity];
	capacity = default_capacity;
	numberOfPeople = 0;
	currentID = default_id;
}

void Bank::erase() { 
	for (int i = 0; i < numberOfPeople; i++)
		delete[] account[i];
	delete[] account;
}

void Bank::copy(const Bank& obj) {
	capacity = obj.capacity;
	numberOfPeople = obj.numberOfPeople;
	currentID = obj.currentID;

	account = new Account * [capacity];
	for (int i = 0; i < numberOfPeople; i++)
		account[i] = new Account(*(obj.account[i]));
}

Bank::~Bank() { erase(); }

Bank::Bank(const Bank& obj) { copy(obj); }

Bank& Bank::operator=(const Bank& obj)
{
	if (this != &obj) {
		erase();
		copy(obj);
	}
	return *this;
}

int Bank::findIndex(int id){
	for (int i = 0; i < numberOfPeople; i++) {
		if (account[i]->getID() == id) {
			return i;
		}
	}
	return -1;
}

void Bank::Transfer(int id, double sum) {
	int index = findIndex(id);
	if (index == -1)
		throw std::exception("invalid account");
	else if (account[index]->balance < sum) {
		throw std::exception("too much money");
	}
	else {
		account[index]->balance -= sum;
	}
}

void Bank::Deposit(int id, double sum) {
	int index = findIndex(id);
	if (index == -1 || sum < 0) {
		throw std::exception("there is not such an id");
	}
	else {
		account[index]->balance += sum;
	}
}

void Bank::SentToPerson(int IDsender, int IDrecipient, double sum) {
	int sender = findIndex(IDsender);
	int recipient = findIndex(IDrecipient);
	if (sender == recipient || sender == -1 || recipient == -1) {
		throw std::exception("invalid account or accounts");
	}
	else if (sum > account[sender]->balance) {
		throw std::exception("Not enough money");
	}
	else {
		account[sender]->balance -= sum;
		account[recipient]->balance += sum;
	}

}

int Bank::makingNewAccount(std::string newCustomer){
	
	if (numberOfPeople == capacity) {
		resizeAray();
	}
	account[numberOfPeople] = new Account(newCustomer, currentID);
	currentID++;
	numberOfPeople++;
	return currentID - 1;
}

void Bank::resizeAray(){
	Account** temp = new Account * [capacity * 2];
	for (int i = 0; i < numberOfPeople; i++) {
		temp[i] = account[i];
	}
	capacity *= 2;
	delete[] account;
	account = temp;
	/*for (int i = 0; i < numberOfPeople; i++) { ///////защо не трием паметта тук???
		delete[] temp[i];
	}
	delete[] temp;*/
}

void sortNames(Account** sortArray, int numberOfPeople) {
	for (int i = 0; i < numberOfPeople - 1; i++) {
		for (int j = 0; j < numberOfPeople - i - 1; j++) {
			if (sortArray[j]->getOwner() > sortArray[j + 1]->getOwner()) {
				Account* temp = sortArray[j];
				sortArray[j] = sortArray[j + 1];
				sortArray[j + 1] = temp;
			}
		}
	}
}

void Bank::printAccounts() {
	
	Account** sortArr = new Account * [numberOfPeople];
	for (int i = 0; i < numberOfPeople; i++) {
		sortArr[i] = account[i];
	}
	sortNames(sortArr,numberOfPeople);

	for (int i = 0; i < numberOfPeople; i++) {
		sortArr[i]->printData();
	}
}

/*Bank::Bank(Bank&& obj) {
	account = obj.account;
	currentID = obj.currentID;
	capacity = obj.capacity;
	numberOfPeople = obj.numberOfPeople;
	obj.account = nullptr;
	obj.currentID = 0;
	obj.capacity = 0;
	obj.numberOfPeople = 0;
}*/

/*Bank& Bank::operator=(Bank&& obj)
{
	if (this != &obj) {
		this->erase();
		account = obj.account;
		currentID = obj.currentID;
		capacity = obj.capacity;
		numberOfPeople = obj.numberOfPeople;
		obj.currentID = 0;
		obj.account = nullptr;
		obj.capacity = 0;
		obj.numberOfPeople = 0;
	}
	return *this;
}*/
