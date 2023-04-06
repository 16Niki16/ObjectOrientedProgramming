#include<iostream>
#include<string>
#include "Account.h"

Account::Account(std::string owner, int id) : owner(owner), id(id), balance(0){}

std::string Account::getOwner(){return owner;}

int Account::getID(){return id;}

