#ifndef WORDSCRAMBLESCOREBOARDCONTROLLER_H
#define WORDSCRAMBLESCOREBOARDCONTROLLER_H

#include "ScoreBoardCSVReader.h"
#include "ScoreBoardCSVWriter.h"
using namespace io;
#include "Utils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
#include "PlayerCollection.h"
using namespace model;
#include "OutputFormatter.h"
using namespace format;


namespace controller
{

class WordScrambleScoreboardController
{
private:
    ScoreBoardCSVReader scoreboardReader;
    ScoreBoardCSVWriter scoreboardWriter;
    PlayerCollection playerCollection;
    OutputFormatter formatter;
    bool sortByScore = true;
    void loadScoreBoard();
public:
    WordScrambleScoreboardController();
    virtual ~WordScrambleScoreboardController();
    void setScoreBoardSortByScore(bool value);
    void clearScoreBoard();
    string getScoreBoardInfo();
};
}
#endif // WORDSCRAMBLESCOREBOARDCONTROLLER_H
