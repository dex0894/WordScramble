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


string WordScrambleController::allPossibleWordsFromLetters()
{
    string output;
    TextFileReader textFileReader;
    vector<string> dictionary = textFileReader.readFile();
    AllPossibleWords allPossibleWord(dictionary, this->randomLetters);
    map<string,string> allPossibleWordsMap = allPossibleWord.getPossibleWords();
    if(allPossibleWordsMap.empty()){
        //allPossibleWordsFromLetters();
    }
    for (map<string,string>::iterator it=allPossibleWordsMap.begin(); it!=allPossibleWordsMap.end(); ++it)
    {
        output += it->second + "\n";
    }

    return output;
}

bool WordScrambleController::isAValidWord(string selectedWord)
{
    string output;
    TextFileReader textFileReader;
    vector<string> dictionary = textFileReader.readFile();
    vector<string>::iterator iteration = find (dictionary.begin(), dictionary.end(), selectedWord);
    return iteration == dictionary.end();
}

void WordScrambleController::shuffleStrings()
{
    random_shuffle(this->randomLetters.begin(), this->randomLetters.end());
}

}
