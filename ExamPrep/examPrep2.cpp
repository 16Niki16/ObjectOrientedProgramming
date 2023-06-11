#include <iostream>
#include"addPrintFunction.h"
#include"EnglishSentence.h"
#include "Sentence.h"
#include "SentenceContainer.h"
#include "Word.h"
#include <iostream>
#include <vector>
int main(){
    Word obj("word1");
    Word obj1("word2");
    Word obj2("word3");
    Word obj3("word4");
    std::vector<Word> words;
    words.push_back(obj);
    words.push_back(obj1);
    words.push_back(obj2);
    words.push_back(obj3);
    Sentence sentence1("Niki e mnogo gotin");
    EnglishSentence sentence2("Niki e oshte po gotin");
    SentenceContainer sentences;
    sentences.addSentence(&sentence1);
    sentences.addSentence(&sentence2);
    addPrintFunction objPrint;
    objPrint.addAndPrint(sentences,words);
    objPrint.print(sentences);
}
