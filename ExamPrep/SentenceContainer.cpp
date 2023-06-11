#include "SentenceContainer.h"
void SentenceContainer::addSentence(Sentence* sentence)
{
	this->sentences.push_back(sentence->clone());
}

int SentenceContainer::getSize()
{
	return sentences.size();
}

Sentence* SentenceContainer::getObject(int index)
{
	return sentences[index];
}
