#include "Player.h"

namespace model
{

//
//Creates a new player
//
//@precondition none
//@postcondition fistName == fistName, lastName == lastName, score == score
//
//@param firstName player's first name
//@param lastName player's last name
//@param score the player's score
//
Player::Player(const string firstName, const string lastName, int score)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->score = score;
}

//Destructs the player object at the end of its lifetime
Player::~Player()
{
    //dtor
}

//
//Returns the first name of the player
//
//@precondition none
//@postcondition none
//
//@return the player's first name
string Player::getFirstName()
{
    return this->firstName;
}

//
//Returns the last name of the player
//
//@precondition none
//@postcondition none
//
//@return the player's last name
string Player::getLastName()
{
    return this->lastName;
}

//
//Returns the score of the player
//
//@precondition none
//@postcondition none
//
//@return the player's score
int Player::getScore()
{
    return this->score;
}
}
