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
    this->generateRandomLetters();
}

//
// Destructor that cleans up all allocated resources
//
WordScrambleController::~WordScrambleController()
{
    //dtor
}
//
// loads all words in dictionary into a vector
//
//@precondition none
//@postcondition none

void WordScrambleController::readFile()
{
    this->wordCollection =  this->reader.readFile();
}
//
// Generates a random string of six letters and then
//generates all possible words from those random letters
//
//@precondition none
//@postcondition none
//
void WordScrambleController::generateRandomLetters()
{
    LetterGenerator letterGenerator;
    int currentLetterLength = 6;
    this-> randomLetters = letterGenerator.generateRandomLetters(currentLetterLength);
    this->determineAllPossibleWords();
}

void WordScrambleController::determineAllPossibleWords()
{
    TextFileReader textFileReader;
    vector<string> dictionary = textFileReader.readFile();
    AllPossibleWords allPossibleWord(dictionary, this->randomLetters);
    this->allPossibleWords = allPossibleWord.getPossibleWords();
}
//
// gets the random letters that were generated
//
//@precondition none
//@postcondition none
//
//@return the random letters in a string format
string WordScrambleController:: getRandomLetters()
{
    return this->randomLetters;
}

//
//Adds the valid word into words that have been entered and
//removes that word from all possible words
//
//@precondition none
//@postcondition none
void WordScrambleController::addValidWordEntered(string word)
{
    word = toLower(word);
    this->allPossibleWords.erase(word);
    this->allValidWordsEntered.push_back(word);
}
//
//Clears all words that have be entered
//
//@precondition none
//@postcondition none
void WordScrambleController::clearAllValidWordsEntered()
{
    this->allValidWordsEntered.clear();
}

//
// displays all words that have been entered by user
//
//@precondition none
//@postcondition none
//
//@return all words that have been entered
string WordScrambleController::displayAllValidWordsEntered()
{
    string output;
    for(string currWord: this->allValidWordsEntered)
    {
        output += currWord + "\n";
    }
    return output;
}
//
// displays all words that are possible based on
// the random letters generated
//
//@precondition none
//@postcondition none
//
//@return output of all words that are possible based random letters
string WordScrambleController::allPossibleWordsFromLetters()
{
    string output;
    for (map<string,string>::iterator it=this->allPossibleWords.begin(); it!=this->allPossibleWords.end(); ++it)
    {
        output += it->second + "\n";
    }

    return output;
}


//
// Checks if the word entered is a possible word based on the
//random letters
//
//@precondition none
//@postcondition none
//
//@return true if it is valid false if otherwise
bool WordScrambleController::isAValidWord(string selectedWord)
{
    selectedWord = toLower(selectedWord);

    return this->allPossibleWords.count(selectedWord);
}

//
// Shuffles the the random letters characters
//
//@precondition none
//@postcondition none
void WordScrambleController::shuffleStrings()
{
    random_shuffle(this->randomLetters.begin(), this->randomLetters.end());
}

}
