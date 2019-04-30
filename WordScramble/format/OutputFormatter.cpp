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
string OutputFormatter::getScoreBoardOutput(PlayerNode** headRef,PlayerNode* (PlayerNode::*nextNodePtr)())
{
    this->summary.str("");
    PlayerNode* temp;
    temp = *headRef;
    this->buildScoreBoard(temp, nextNodePtr);
    return this->summary.str();
}

//
//Builds an output summary for the passed in list head and function pointer
//
//@precondition none
//@postcondition none
//
//@param headRef the reference to the head node of the PlayerCollection
//@param nextNodePtr the function to call to get the next node in the list
//
//@return the built summary output
//
string OutputFormatter::getFileOutput(PlayerNode** headRef,PlayerNode* (PlayerNode::*nextNodePtr)())
{
    this->fileOutput.str("");
    PlayerNode* temp;
    temp = *headRef;
    this->buildFileOutput(temp, nextNodePtr);
    return fileOutput.str();
}

void OutputFormatter::buildFileOutput(PlayerNode* head, PlayerNode* (PlayerNode::*nextNodePtr)())
{
    if(head == nullptr)
    {
        return;
    }
    this->fileOutput << head->getFirstName() << "," << head->getLastName()<< "," << to_string(head->getScore()) << ","  << head->getTime() << endl;
    this->buildFileOutput((head->*nextNodePtr)(), nextNodePtr);
}

void OutputFormatter::buildScoreBoard(PlayerNode* head, PlayerNode* (PlayerNode::*nextNodePtr)())
{
    if(head == nullptr)
    {
        return;
    }

    this->summary << left<< setw(10) << head->getFirstName() << setw(10)<< head->getLastName()  <<"Score: " << setw(10) << head->getScore() << "Time: " << head->getTime() << endl;
    this->buildScoreBoard((head->*nextNodePtr)(), nextNodePtr);

}

}
