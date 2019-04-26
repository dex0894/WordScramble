#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H
#include "../model/LetterGenerator.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 #include <algorithm>
 #include <vector>
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
    vector<string> wordCollection;
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
    bool isAValidWord(string selectedWord);

};
}
#endif // WORDSCRAMBLECONTROLLER_H
