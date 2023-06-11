#include "EnglishSentence.h"
#include<iostream>

EnglishSentence::EnglishSentence(const char* sentence)
{
	if (checkSentence()) {
		Sentence(sentence);
	}
	else {
		throw std::exception("Not an English sentence");
	}
}

EnglishSentence::~EnglishSentence(){}

void EnglishSentence::addWord(Word obj)
{
	if(checkSentence() && checkWord(obj)){
	char* temporarySentence = new char[strlen(getSentence()) + strlen(obj.getWord()) + 1];
	strcpy_s(temporarySentence, strlen(getSentence()) + 1, getSentence());
	strcpy_s(temporarySentence + strlen(getSentence()), strlen(getSentence()) + strlen(obj.getWord()) + 1, obj.getWord());
	delete[] temporarySentence;
	}
	std::cout << "The sentence is not correct";
}

bool EnglishSentence::checkSentence()
{
	for (int i = 0; i < strlen(getSentence()); i++) {
		if (getChar(i) >= 'A' && getChar(i) <= 'Z' || getChar(i) >= 'a' && getChar(i) <= 'z' ||
			getChar(i) == ' ' || getChar(i) == ',' || getChar(i) == '!' || getChar(i) == '.') {
		}
		else {
			return false;
		}
	}
	return true;
}

bool EnglishSentence::checkWord(Word obj)
{
	for (int i = 0; i < strlen(obj.getWord()); i++) {
		if (obj.getCharWord(i) >= 'A' && obj.getCharWord(i) <= 'Z' || obj.getCharWord(i) >= 'a' && obj.getCharWord(i) <= 'z' ||
			obj.getCharWord(i) == ' ' || obj.getCharWord(i) == ',' || obj.getCharWord(i) == '!' || obj.getCharWord(i) == '.') {
		}
		else {
			return false;
		}
	}
	return true;
}

Sentence* EnglishSentence::clone()
{
	return new EnglishSentence(*this);
}

void EnglishSentence::print()
{
	std::cout << getSentence();
}
