#include "WordScrambleUserInfoWindow.h"
namespace view
{

//Created to make a object of WordScrambleUserInfoWindow
//@precondition none
//@postcondition none
WordScrambleUserInfoWindow::WordScrambleUserInfoWindow() : OKCancelWindow(300, 115, "Please Put Your Name")
{
    const int X_INPUT_LOCATION = 110;
    this->player = 0;
    begin();
    this->setOKLocation(80, 80);
    this->setCancelLocation(160, 80);

    this->firstName = new Fl_Input(115, 5, 150, 25, "First Name:");
    this->lastName = new Fl_Input(115, 45, 150, 25, "Last Name:");
    end();
}
// deconstructs  WordScrambleUserInfoWindow when it looses scope
WordScrambleUserInfoWindow::~WordScrambleUserInfoWindow()
{
    delete this->firstName;
    delete this->lastName;
}
//gets the user name
//@precondition none
//@postcondition none
//@return the user name
string WordScrambleUserInfoWindow::getFirstName()
{
    return this->firstName->value();
}
//gets the user name
//@precondition none
//@postcondition none
//@return the user name
string WordScrambleUserInfoWindow::getLastName()
{
    return this->lastName->value();
}

//
// The instance handler when OK is invoked
//
// @precondition none
// @postcondition getPlayer() == player object created from data user entered
//
void WordScrambleUserInfoWindow::okHandler()
{
    string firstName = this->firstName->value();
    string lastName = this->lastName->value();
    if(firstName.empty() || lastName.empty())
    {
        fl_alert("Please list information");

    }
    else
    {
        this->player = new Player(firstName, lastName, this->score, this->time);
        this->hide();
    }

}

//
// The instance handler when cancel is invoked
//
// @precondition none
// @postcondition getPlayer() == 0
//
void WordScrambleUserInfoWindow::cancelHandler()
{
    if (this->player)
    {
        delete this->player;
    }
    this->player = 0;
    this->hide();
}

//
//Sets the score for the current player
//
//@precondition none
//@postcondition score==score
//
void WordScrambleUserInfoWindow::setPlayerScore(int score)
{
    this->score = score;
}

//
//Sets the time for the current player
//
//@precondition none
//@postcondition time==time
//
void WordScrambleUserInfoWindow::setPlayerTime(int time)
{
    this->time = time;
}

//
//Gets the player
//
//@precondition none
//@postcondition none
//
Player* WordScrambleUserInfoWindow::getPlayer()
{
    return this->player;
}
}
