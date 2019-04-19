#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

using namespace std;

#include "../model/LetterGenerator.h"
using namespace model;

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

    void readFile();

public:
    WordScrambleController();
    virtual ~WordScrambleController();
    string generateRandomLetters();
};
}
#endif // WORDSCRAMBLECONTROLLER_H
