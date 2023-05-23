#ifndef student_H_
#define student_H_
#include"Person.h"
class Student: virtual public Person{
	int FN;
public:
	Student(int FN, std::string& name);
	void display() const override;
	BasePerson* clone() const  override;
};

#endif // !student_H_

