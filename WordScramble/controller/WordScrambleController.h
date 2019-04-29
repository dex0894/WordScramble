#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

#include "Utils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
#include "TextFileReader.h"
using namespace io;
#include "../model/LetterGenerator.h"
#include "../model/AllPossibleWords.h"
using namespace model;
#include "OutputFormatter.h"
using namespace format;

namespace controller
{

class WordScrambleController
{

private:
    TextFileReader reader;
    OutputFormatter formatter;
    LetterGenerator letterGenerator;
    vector<string> dictionary;
    vector<string> allValidWordsEntered;
    map<string,string> allPossibleWords;
    string randomLetters;
    void readFile();
    void removeSpaces();
    void determineAllPossibleWords();
    int totalScore;
    int currentScore;

public:
    WordScrambleController();
    virtual ~WordScrambleController();
    void generateRandomLetters(int letterCount);
    void shuffleStrings();
    string getRandomLetters();
    bool isAValidWord(string selectedWord);
    void updateScore(string score);
    string displayAllValidWordsEntered();
    string allPossibleWordsFromLetters();
    void addValidWordEntered(string word);
    void clearAllValidWordsEntered();
    int getTotalScore();
    void updateTotalScore(int addedValue);

};
}
#endif // WORDSCRAMBLECONTROLLER_H
