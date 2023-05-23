#ifndef basePerson_H_
#define basePerson_H_
#include<string>
class BasePerson{
protected:
	std::string name;
public:
	BasePerson(std::string& name);
	virtual void display() const = 0;
	virtual ~BasePerson();
	virtual BasePerson* clone() const = 0;
};
#endif


