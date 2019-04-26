#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H
#include "../model/LetterGenerator.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "../model/AllPossibleWords.h"
#include "TextFileReader.h"
using namespace io;
using namespace model;

namespace controller
{

class WordScrambleController
{

private:
    TextFileReader reader;
    vector<string> dictionary;
    string randomLetters;
    void readFile();
    void removeSpaces();

public:
    WordScrambleController();
    virtual ~WordScrambleController();
    string generateRandomLetters();
    void shuffleStrings();
    string getRandomLetters();
    string allPossibleWordsFromLetters();
    bool isInDictionary(string word);

};
}
#endif // WORDSCRAMBLECONTROLLER_H
