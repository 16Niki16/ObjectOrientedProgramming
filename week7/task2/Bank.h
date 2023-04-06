#ifndef bank_H_
#define banl_H_
#include "Account.h"
class Bank {
	Account* account;
	int currentID;
public:
	Bank();
	void erase();
	void copy(Bank const& obj);
	~Bank();
	Bank(Bank const& obj);
	Bank& operator=(Bank const& obj);


};

#endif 

