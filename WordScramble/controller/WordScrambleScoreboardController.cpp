#include "WordScrambleScoreboardController.h"


namespace controller
{

//
//Constructs a new WordScramble Scoreboard Controller
//
//@precondition none
//@postcondition scoreboard is loaded
//
//
WordScrambleScoreboardController::WordScrambleScoreboardController()
{
    this->loadScoreBoard();
}

//
// Destructor that cleans up all allocated resources
//
WordScrambleScoreboardController::~WordScrambleScoreboardController()
{
    //dtor
}

void WordScrambleScoreboardController::loadScoreBoard()
{
    for (Player* player : this->scoreboardReader.parseCSVFile())
    {
        this->playerCollection.add(player);
    }
}

//
//Gets the information for the scoreboard
//
//@precondition none
//@postcondition none
//
//@return the information for the scoreboard
string WordScrambleScoreboardController::getScoreBoardInfo()
{
    if(this->sortByScore)
    {
        return this->formatter.getScoreBoardOutput(this->playerCollection.getScoreHead(), NEXT_SCORE_FUNC_PTR);
    }
    else
    {
        return this->formatter.getScoreBoardOutput(this->playerCollection.getTimeHead(), NEXT_TIME_FUNC_PTR);
    }
}

//
//Sets the value of the sort
//
//@precondition none
//@postcondition none
//
void WordScrambleScoreboardController::setScoreBoardSortByScore(bool value)
{
    this->sortByScore = value;
}

}
