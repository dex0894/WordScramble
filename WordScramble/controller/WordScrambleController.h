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
#include "Utils.h"
using namespace io;
using namespace model;

namespace controller
{

class WordScrambleController
{

private:
    TextFileReader reader;
    vector<string> wordCollection;
    vector<string> allValidWordsEntered;
    map<string,string> allPossibleWords;
    string randomLetters;
    void readFile();
    void removeSpaces();
    void determineAllPossibleWords();

public:
    WordScrambleController();
    virtual ~WordScrambleController();
    void generateRandomLetters();
    void shuffleStrings();
    string getRandomLetters();
    bool isAValidWord(string selectedWord);
    void updateScore(string score);
    string displayAllValidWordsEntered();
    string allPossibleWordsFromLetters();
    void addValidWordEntered(string word);
    void clearAllValidWordsEntered();

};
}
#endif // WORDSCRAMBLECONTROLLER_H
