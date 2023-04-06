#include<iostream>
#include<string>
#include "Bank.h"
#include "Account.h"

Bank::Bank(): account(nullptr), currentID(0){}

void Bank::erase(){delete[] account;}

void Bank::copy(Bank const& obj){
	account = obj.account;
	currentID = obj.currentID;
}

Bank::~Bank(){erase();}

Bank::Bank(Bank const& obj){copy(obj);}

Bank& Bank::operator=(Bank const& obj)
{
	if (this != &obj) {
		erase();
		copy(obj);
	}
	return *this;
}

Bank::Bank(Bank&& obj)
{
	account = obj.account;
	currentID = obj.currentID;
	obj.account = nullptr;
	obj.currentID = 0;
}

Bank& Bank::operator=(Bank&& obj)
{
	if (this != &obj) {
		this->erase();
		account = obj.account;
		currentID = obj.currentID;
		obj.currentID = 0;
		obj.account = nullptr;
	}
	return *this;
}

int Bank::findIndex(int id)
{
	for (int i = 0; i < this->currentID; i++) {
		if (account[i].getID() == id) {
			return id;
		}
	}
	return -1;
}

void Bank::Transfer(int id, double sum){	
	if (findIndex(id) == -1)
		throw std::exception("invalid account");
	else if(this->account->balance  - sum < 0) {
		throw std::exception("too much money");
	}
	else {
		this->account->balance -= sum;
	}
}

void Bank::Deposit(int id, double sum){
	if (findIndex(id) == -1)
		throw std::exception("there is not such an id");
	else 
		this->account->balance += sum;
}

void Bank::SentToPerson(int IDsender, int IDrecipient, double sum){
	int sender = findIndex(IDsender);
	int recipient = findIndex(IDrecipient);
	if (sender == recipient || sender == -1 || recipient == -1) {
		throw std::exception("invalid account or accounts");
	}
	else if(sum - account[sender].balance < 0) {
		throw std::exception("Not enough money");
	}
	else {
		account[sender].balance -= sum;
		account[recipient].balance += sum;
	}

}

void Bank::printAccounts(){
	std::cout << account->getID();
}
