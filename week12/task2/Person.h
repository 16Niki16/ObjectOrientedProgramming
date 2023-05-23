#ifndef person_H_
#define person_H_
#include<string>
#include "BasePerson.h"
class Person : public BasePerson{
protected:
	int idPerson;
public:
	Person(std::string& name);
	static int id;
	BasePerson* clone() const  override;
	void display() const override;


};
#endif // !person_H_



