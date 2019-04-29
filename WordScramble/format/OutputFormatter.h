#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include <iostream>
#include <locale>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;
#include "../model/AllPossibleWords.h"
#include "Player.h"
using namespace model;
#include "Utils.h"

namespace format
{


class OutputFormatter
{
private:
public:
    OutputFormatter();
    virtual ~OutputFormatter();
    string buildAllPossibleWordsOutput(map<string,string> words);
    string buildValidWordsOutput(vector<string> words);
    string buildScoreBoardOutput(vector<Player>);
};
}
#endif // OUTPUTFORMATTER_H
