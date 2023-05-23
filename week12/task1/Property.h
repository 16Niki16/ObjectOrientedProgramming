#ifndef property_H_
#define property_H_
#include<string>
class Property{
	std::string owner;
	bool tangible;
public:
	Property(std::string& owner, bool tangible);
	virtual ~Property();
	std::string getOwner();
	bool getTangible();
};
#endif // !property_H_



