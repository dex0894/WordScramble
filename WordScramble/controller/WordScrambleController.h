#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H
#include "../model/LetterGenerator.h"
using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

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
};
}
#endif // WORDSCRAMBLECONTROLLER_H
