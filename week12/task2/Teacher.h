#ifndef teacher_H_
#define teacher_H_
#include "Person.h"
class Teacher: virtual public Person{
	std::string nameField;
public:
	Teacher(std::string& name, std::string& nameField);
	BasePerson* clone() const override;

};
#endif // !teacher_H_



