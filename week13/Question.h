#ifndef question_H_
#define question_H_
#include<string>
const std::string YES = "yes";
const std::string NO = "no";
class Question{
	std::string question;
	int grade;
public:
	Question(const std::string& question, int grade);
	virtual ~Question();
	virtual void ask();
	int Grade();
	void print() const;
	static bool validYesNoAnswer(const std::string& ans);
	static bool correctYesNoAnswer(const std::string& ans, bool correct_is_yes);
	void setGrade(int grade);
};
#endif // !question_H_


