#include "Question.h"
#include <iostream>
Question::Question(const std::string& question, int grade) : question(question), grade(grade){}
Question::~Question()
{
}
void Question::ask()
{
	std::string answer;
	std::cout << question<<std::endl;
	std::getline(std::cin, answer);
}

int Question::Grade()
{
	return grade;
}

void Question::print() const
{
	std::cout << question;
}

bool Question::validYesNoAnswer(const std::string& ans)
{
	if (ans.compare("yes") == 0  || ans.compare("no") == 0)
		return true;
	return false;
}

bool Question::correctYesNoAnswer(const std::string& ans, bool correct_is_yes)
{
	if (correct_is_yes == true && ans.compare(YES) == 0 || correct_is_yes == false && ans.compare(NO) == 0)
			return true;
		return false;
}

void Question::setGrade(int grade)
{
	this->grade = grade;
}
