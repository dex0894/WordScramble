#include "WordScrambleController.h"

namespace controller
{


WordScrambleController::WordScrambleController()
{
    this->readFile();
}

WordScrambleController::~WordScrambleController()
{
    //dtor
}

void WordScrambleController::readFile()
{
    this->wordCollection =  this->reader.readFile();
}
}
