#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H
#include "../model/LetterGenerator.h"
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

    void readFile();

public:
    WordScrambleController();
    virtual ~WordScrambleController();
    string generateRandomLetters();
};
}
#endif // WORDSCRAMBLECONTROLLER_H
