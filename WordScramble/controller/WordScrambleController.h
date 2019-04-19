#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

using namespace std;

#include "TextFileReader.h"
using namespace io;

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

};
}
#endif // WORDSCRAMBLECONTROLLER_H
