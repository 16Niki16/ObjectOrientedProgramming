#ifndef account_H_
#define account_H_
#include <string>
class Account {
	std::string owner;
	int id;
public:
	double balance;
	Account(std::string owner, int id);
	std::string getOwner();
	int getID();

};
#endif

