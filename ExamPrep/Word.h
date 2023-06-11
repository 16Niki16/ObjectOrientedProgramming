#ifndef word_H_
#define word_H_
class Word{
	char word[21];
public:
	Word(const char* word1);

	char operator[](int index);
	char* operator+(const char symbol);
	int operator<=(Word word2);
	char* getWord();
	char getCharWord(int index);
};
#endif


