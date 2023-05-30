#ifndef classQuestion
#define classQuestion
#include "Question.h"
class ClassQuestions: public Question{
	std::string answer;
	std::string myAnswer;
public:
	ClassQuestions(const std::string& answer, const std::string& question, int grade);
	void YesNoQuestion();
};

#endif // !classQuestion

