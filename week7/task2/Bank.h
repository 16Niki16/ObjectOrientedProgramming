#ifndef bank_H_
#define banl_H_
#include "Account.h"
class Bank {
	Account** account;
	int currentID;
	int capacity;
	int numberOfPeople;
public:

	Bank();
	void erase();
	void copy(const Bank& obj);
	~Bank();
	Bank(const Bank& obj);
	Bank& operator=(const Bank& obj);
	
	int findIndex(int id);
	void Transfer(int id, double sum);
	void Deposit(int id, double sum);
	void SentToPerson(int IDsender, int IDrecipient, double sum);
	void printAccounts();
	int makingNewAccount(std::string newCustomer);
	void resizeAray();
};

#endif
//Bank(Bank&& obj);
	//Bank& operator=(Bank&& obj);