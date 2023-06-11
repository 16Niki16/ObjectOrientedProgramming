#include "Word.h"
#include<iostream>

Word::Word(const char* word1)
{
    if (strlen(word1) > 20) {
        throw std::exception("Too long word");
    }
    strcpy_s(word, strlen(word1) + 1, word1);
}

char Word::operator[](int index)
{
    if (index > strlen(this->word) -1)
        throw std::exception("index doesn`t exist");
    return word[index];
}

char* Word::operator+(const char symbol)
{
    if (strlen(word) <= 20)
        word[strlen(word)] = symbol;
        word[strlen(word) + 1] = '\0';
    return word;
}

int Word::operator<=(Word word2){
    int lenght = 0;
    if (strlen(this->word) < strlen(word2.word)) {
        lenght = strlen(this->word);
    }
    else {
        lenght = strlen(word2.word);
    }
    for (int i = 0; i < lenght; i++) {
        if (this->word[i] < word2.word[i]) {
            return -1;
        }
        else if (this->word[i] > word2.word[i]) {
            return 1;
        }
    }
    if (lenght < strlen(this->word)) {
        return 1;
    }
    else if (lenght < strlen(word2.word)) {
        return -1;
    }
    else if (lenght == strlen(word2.word) && lenght == strlen(this->word)) {
        return 0;
    }
}

char* Word::getWord()
{
    return word;
}

char Word::getCharWord(int index)
{
    return word[index];
}
