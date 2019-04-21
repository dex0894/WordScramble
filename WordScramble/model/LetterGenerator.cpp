#include "LetterGenerator.h"

//Class created to generate random letters

namespace model
{

//Initializes a object of LetterGenerator
//
//@precondition none
//@postcondition none
LetterGenerator::LetterGenerator()
{
    //ctor
}
//Deconstruct's LetterGenerator when
//it loses scope
LetterGenerator::~LetterGenerator()
{
    //dtor
}

//Takes a int input and builds a string of
//random letters based on the length and creates a
//random string of letters
//@precondition length !< 0
//@postcondition none
//@param length is the length you wish to
// make the strings to be
string LetterGenerator:: generateRandomLetters(int length)
{
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    string randomLetters = "";
    for(int i=0; i< length; i++)
    {
        char letter = letters[rand() % 26];
        randomLetters += toupper(letter);
    }
    return randomLetters;
}
}

