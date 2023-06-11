#ifndef addPrintFunction_H_
#define addPrintFunction_H_
#include "EnglishSentence.h"
#include "Sentence.h"
#include "Word.h"
#include "SentenceContainer.h"
#include<vector>
class addPrintFunction{
public:
	void addAndPrint(SentenceContainer& sentences, std::vector<Word> words);
	void print(SentenceContainer& sentences);
};
#endif // !addPrintFunction_H_


