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
}
