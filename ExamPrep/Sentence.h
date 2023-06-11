#ifndef sentence_H_
#define sentence_H_
#include "Word.h"
#include<iostream>
class Sentence{
	char* sentence;

	void erase();
	void copy(const Sentence& obj);
public:
	Sentence();
	Sentence(const char* sentence1);
	virtual ~Sentence();
	Sentence(const Sentence& obj);
	Sentence& operator=(const Sentence& obj);
	void setSentence(char* sentence);
	char* getSentence();

	virtual void addWord(Word obj);
	unsigned sentenceLenght();
	friend std::ostream& operator<<(std::ostream& out, const Sentence& sentence);
	char getChar(int index);
	virtual Sentence* clone();
	virtual void print();

};
#endif // !sentence_H_


