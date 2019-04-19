#include "WordScrambleController.h"

namespace controller
{

//
//Constructs a new WordScramble Controller
//
//@precondition none
//@postcondition dictionary file read in.
//
//
WordScrambleController::WordScrambleController()
{
    this->readFile();
    this->randomLetters = "";
}

//
// Destructor that cleans up all allocated resources
//
WordScrambleController::~WordScrambleController()
{
    //dtor
}

void WordScrambleController::readFile()
{
    this->wordCollection =  this->reader.readFile();
}

// Generates a string of six
string WordScrambleController::generateRandomLetters()
{
    LetterGenerator letterGenerator;
    int currentLetterLength = 6;
    this-> randomLetters = letterGenerator.generateRandomLetters(currentLetterLength);
    return this->randomLetters;
}

string WordScrambleController:: getRandomLetters()
{
    return this->randomLetters;
}

void WordScrambleController::shuffleStrings()
{
    random_shuffle(this->randomLetters.begin(), this->randomLetters.end());
}

}
