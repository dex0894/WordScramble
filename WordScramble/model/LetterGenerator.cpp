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
    char letters[] = "eeeeeeeeeeetttttttttooooooooaaaaaaiiiiiinnnnnnsssssshhhhhrrrrrllllddduuuwwwyyybbccffggmmppvvjkqxz";
    string randomLetters = "";
   // gets(letters);
    int len = strlen(letters);
    for(int i=0; i< length; i++)
    {
        cout << "Called" << endl;
        char letter = letters[rand() % len];
        randomLetters += toupper(letter);
    }
    cout << "end" << endl;
    return randomLetters;
}
}

