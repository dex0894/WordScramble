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
    void buildFileOutput(PlayerNode* head, PlayerNode* (PlayerNode::*nextNodePtr)());
    void buildScoreBoard(PlayerNode* head, PlayerNode* (PlayerNode::*nextNodePtr)());
    ostringstream fileOutput;
    ostringstream summary;
public:
    OutputFormatter();
    virtual ~OutputFormatter();
    string buildAllPossibleWordsOutput(map<string,string> words);
    string buildValidWordsOutput(vector<string> words);
    string getScoreBoardOutput(PlayerNode** headRef,PlayerNode* (PlayerNode::*nextNodePtr)());
    string getFileOutput(PlayerNode** headRef,PlayerNode* (PlayerNode::*nextNodePtr)());
};
}
#endif // OUTPUTFORMATTER_H
