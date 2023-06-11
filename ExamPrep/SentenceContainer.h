#ifndef sentenceContainer_H_
#define sentenceContainer_H_
#include"Sentence.h"
#include "EnglishSentence.h"
#include "Word.h"
#include<vector>
class SentenceContainer{
	std::vector<Sentence*> sentences;
public:

	void addSentence(Sentence* sentence);
	int getSize();
	Sentence* getObject(int index);
};
#endif // !sentenceContainer_H_



