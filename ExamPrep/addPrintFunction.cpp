#include "addPrintFunction.h"

void addPrintFunction::addAndPrint(SentenceContainer& sentences, std::vector<Word> words)
{
	for (int i = 0; i < sentences.getSize(); i++) {
		for (int j = 0; j < words.size(); j++) {
			sentences.getObject(i)->addWord(words[i]);
		}
	}
}

void addPrintFunction::print(SentenceContainer& sentences)
{
	for (int i = 0; i < sentences.getSize(); i++) {
		sentences.getObject(i)->print();
	}
}
