#include<iostream>
#include<string>
#include "Account.h"

Account::Account(std::string owner, int id) : owner(owner), id(id), balance(0) {}

const std::string& Account::getOwner() { return owner; }

int Account::getID() { return id; }
void Account::printData()
{
	std::cout << "Owner: " << owner << "\nID: " << id << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}