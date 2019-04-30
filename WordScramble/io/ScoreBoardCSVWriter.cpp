#include "ScoreBoardCSVWriter.h"

namespace io
{

//Creates a new ScoreBoardCSVWriter
//@precondition none
//@postcondition none
ScoreBoardCSVWriter::ScoreBoardCSVWriter()
{
    //ctor
}

//Destructs the  object when its lifetime ends.
ScoreBoardCSVWriter::~ScoreBoardCSVWriter()
{
    //dtor
}

void ScoreBoardCSVWriter::writeToCSV(string content)
{
    ofstream file(SCOREBOARD_FILE_NAME);

    if(file.is_open())
    {
        file << content;
        file.close();
    }
    else
    {
        cerr << "Unable to write to file" << endl;
    }
}

}
