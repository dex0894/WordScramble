#include "OutputFormatter.h"

namespace format
{

//
//Creates a new output formatter
//
//@precondition none
//@postcondition none
//
OutputFormatter::OutputFormatter()
{
    //ctor
}

//
OutputFormatter::~OutputFormatter()
{
    //dtor
}

//
//Builds the output for all possible words
//
//@precondition none
//@postcondition none
//
//@param words the collection of words to build the output from
//
//@return the built output
string OutputFormatter::buildAllPossibleWordsOutput(map<string,string> words)
{
    ostringstream output;
    for (map<string,string>::iterator it=words.begin(); it!=words.end(); ++it)
    {
        output << it->second <<endl;
    }
    return output.str();
}

//
//Builds the output for all valid words
//
//@precondition none
//@postcondition none
//
//@return the built output
string OutputFormatter::buildValidWordsOutput(vector<string> words)
{
    ostringstream output;
    for(string currWord: words)
    {
        output << currWord << " " << calculateScoreByWord(currWord) << " " << "points"<< endl;
    }
    return output.str();
}

//
//Builds the output for the scoreboard
//
//@precondition none
//@postcondition none
//
//@return the built output
string OutputFormatter::buildScoreBoardOutput(vector<Player> players)
{
    ostringstream output;
    for(Player currPlayer: players)
    {
        output << setw(10) << left << currPlayer.getFirstName() << setw(10) << currPlayer.getLastName() << setw(10) << currPlayer.getScore() << "points"<< endl;
    }
    return output.str();
}
}
