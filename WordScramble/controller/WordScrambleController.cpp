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
    this->dictionary =  this->reader.readFile();
}

//
//Generates a collection of random letters
//
//@precondition none
//@postcondition none
//
//@return the collection of letters
//
string WordScrambleController::generateRandomLetters()
{
    LetterGenerator letterGenerator;
    int currentLetterLength = 6;
    this-> randomLetters = letterGenerator.generateRandomLetters(currentLetterLength);
    return this->randomLetters;
}

//
//Returns the current generated collection of letters
//
//@precondition none
//@postcondition none
//
//@return the current string of letters
//
string WordScrambleController:: getRandomLetters()
{
    return this->randomLetters;
}

//
//Returns a string of all the possible words that can be created from the generated letters
//
//@precondition none
//@postcondition none
//
//@return the string of possible words
//
string WordScrambleController::allPossibleWordsFromLetters()
{
    string output;
    AllPossibleWords allPossibleWord(this->dictionary, this->randomLetters);
    map<string,string> allPossibleWordsMap = allPossibleWord.getPossibleWords();
    for (map<string,string>::iterator it=allPossibleWordsMap.begin(); it!=allPossibleWordsMap.end(); ++it)
    {
        output += it->second + "\n";
    }

    return output;
}


//
//Shuffles the string of generated letters
//
//@precondition none
//@postcondition none
//
void WordScrambleController::shuffleStrings()
{
    random_shuffle(this->randomLetters.begin(), this->randomLetters.end());
}

//
//Checks if a passed in word is contained within the dictionary
//
//@precondition none
//@postcondition none
//
bool WordScrambleController::isInDictionary(string word)
{

    if (find(this->dictionary.begin(), this->dictionary.end(), word) != this->dictionary.end())
        {
            return true;
        }
        else
        {
            return false;
        }

}

}
