#ifndef englishSentence_H_
#define endlishSentence_H_
#include "Sentence.h"
class EnglishSentence:public Sentence{
public:
	EnglishSentence(const char* sentence);
	~EnglishSentence();
	void addWord(Word obj) override;
	bool checkSentence();
	bool checkWord(Word obj);
	Sentence* clone() override;
	void print() override;
};
#endif // !englishSentence_H_


