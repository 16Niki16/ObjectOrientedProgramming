#include "Sentence.h"
#include<iostream>

void Sentence::addWord(Word obj)
{
	char* temporarySentence = new char[strlen(sentence) + strlen(obj.getWord()) + 1];
	strcpy_s(temporarySentence, strlen(sentence) + 1,sentence);
	strcpy_s(temporarySentence + strlen(sentence), strlen(sentence) + strlen(obj.getWord()) + 1, obj.getWord());
	delete[] temporarySentence;
}

unsigned Sentence::sentenceLenght()
{
	return strlen(sentence);
}

char Sentence::getChar(int index)
{
	return sentence[index];
}

Sentence* Sentence::clone()
{
	return new Sentence(*this);
}

void Sentence::print()
{
	std::cout << sentence<<std::endl;
}

void Sentence::erase()
{
	delete[] sentence;
}

void Sentence::copy(const Sentence& obj)
{
	sentence = new char[strlen(obj.sentence) + 1];
	strcpy_s(sentence, strlen(obj.sentence) + 1, obj.sentence);
}

Sentence::Sentence() : sentence(nullptr){}

Sentence::Sentence(const char* sentence1) : sentence(new char[strlen(sentence1)+1])
{
	strcpy_s(sentence, strlen(sentence1) + 1, sentence1);
}

Sentence::~Sentence()
{
	erase();
}

Sentence::Sentence(const Sentence& obj)
{
	copy(obj);
}

Sentence& Sentence::operator=(const Sentence& obj)
{
	if (this != &obj) {
		this->erase();
		this->copy(obj);
	}
	return *this;
}

void Sentence::setSentence(char* sentence)
{
	this->erase();
	this->sentence = new char[strlen(sentence)+1];
	strcpy_s(this->sentence, strlen(sentence) + 1, sentence);
}

char* Sentence::getSentence()
{
	return sentence;
}

std::ostream& operator<<(std::ostream& out, const Sentence& sentence)
{
	for (int i = 0; i < strlen(sentence.sentence); i++) {
		out << sentence.sentence[i];
	}
	return out;
}
