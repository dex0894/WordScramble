#ifndef TEXTFILEREADER_H
#define TEXTFILEREADER_H

#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

namespace io
{

class TextFileReader
{
private:
    vector<string> wordCollection;

public:
    TextFileReader();
    virtual ~TextFileReader();

    vector<string> readFile();

};
}
#endif // TEXTFILEREADER_H
