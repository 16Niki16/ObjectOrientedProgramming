#include "ClassQuestions.h"
#include<iostream> 

ClassQuestions::ClassQuestions(const std::string& answer, const std::string& question, int grade) : answer(answer), Question(question, grade){}

void ClassQuestions::YesNoQuestion()
{
	print();
	std::string myAnswer;
	std::cin >> myAnswer;
	if (myAnswer.compare(answer) == 0) {
		std::cout << Grade() << std::endl;
		setGrade(Grade());
	}
	else {
		std::cout << "0 points" << std::endl;
		setGrade(0);
	}
}
