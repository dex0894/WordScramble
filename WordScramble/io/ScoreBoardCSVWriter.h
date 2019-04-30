#ifndef SCOREBOARDCSVWRITER_H
#define SCOREBOARDCSVWRITER_H

#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

namespace io
{
class ScoreBoardCSVWriter
{
private:
public:
    ScoreBoardCSVWriter();
    virtual ~ScoreBoardCSVWriter();
    void writeToCSV(string content);
};
}
#endif // SCOREBOARDCSVWRITER_H
