#ifndef TEXTFILEREADER_H
#define TEXTFILEREADER_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

namespace io
{

static const string FILENAME = "dictionary.txt";

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
