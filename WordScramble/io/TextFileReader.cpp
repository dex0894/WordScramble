#include "TextFileReader.h"

namespace io
{


TextFileReader::TextFileReader()
{
    //ctor
}

TextFileReader::~TextFileReader()
{
    //dtor
}

//
//Reads in the file stored in resources
//
//@precondition none
//@postcondition none
//@return the read in file as a vector<string>
//
vector<string> TextFileReader::readFile()
{
    string line;
    ifstream file("dictionary.txt");

    if(!file)
    {
        cerr << "Error opening file" << endl;
    }

    while(getline(file, line))
    {
        this->wordCollection.push_back(line);

    }

    return this->wordCollection;
}
}
