#ifndef SCOREBOARDCSVREADER_H
#define SCOREBOARDCSVREADER_H

#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

#include "Player.h"
using namespace model;
#include "Utils.h"

namespace io
{

class ScoreBoardCSVReader
{
private:
    const int LAST_NAME = 1;
    const int FIRST_NAME = 0;
    const int SCORE = 2;
    const int TIME = 3;
    const int MINIMUM_FIELDS = 4;
    const string FILE_ERROR = "Unable to locate file or file has not been specified.";
    vector<Player*> players;

public:
    ScoreBoardCSVReader();
    virtual ~ScoreBoardCSVReader();
    vector<Player*> parseCSVFile();
};
}
#endif // SCOREBOARDCSVREADER_H
