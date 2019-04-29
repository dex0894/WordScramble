#include "AllPossibleWords.h"
namespace model
{
// Creates a object of AllPossibleWords class
//
//@precondition randomLetters != empty
//@postcondition this->possibleWords = dictionary
//@param dictionary is vector all words in the dictionary
//@param is the randomLetters that are used to find all possible words
AllPossibleWords::AllPossibleWords(vector<string> dictionary, string randomLetters)
{
    this->possibleWords = map<string, string>();
    this->determineValidWords(dictionary, randomLetters);
}

//Deconstructs AllPossibleWords when it loses scope
AllPossibleWords::~AllPossibleWords()
{
    //dtor
}
void AllPossibleWords:: determineValidWords(vector<string> dictionary, string randomLetters)
{
    for(string currWord: dictionary)
    {
        string upperCasedCurrWord = toUpper(currWord);
        size_t allUnMatchedLetters = upperCasedCurrWord.find_first_not_of(randomLetters);

        bool correctLetterLength = currWord.length() >= MINIMUM_LENGTH;
        if( allUnMatchedLetters == string::npos && correctLetterLength && isAPossibleWord(currWord, randomLetters))
        {
            this->possibleWords.insert (pair<string,string>(currWord,hideText(currWord)));
        }
    }
}

bool AllPossibleWords::isAPossibleWord(string selectedWord, string randomLetters)
{
    bool result = true;
    std::transform(randomLetters.begin(), randomLetters.end(), randomLetters.begin(), ::tolower);
    for(char currLetter: selectedWord)
    {
        size_t currLetterCount = letterCount(selectedWord,currLetter);
        size_t rdmLetterCount = letterCount(randomLetters, currLetter);
        if(currLetterCount > rdmLetterCount)
        {
            result = false;
        }
    }
    return result;
}


size_t AllPossibleWords::letterCount(string word, char letter)
{
    size_t allLettersUsed = std::count(word.begin(), word.end(), letter);
    return allLettersUsed;
}

//
//Gets the map of all possible words
//@precondition none
//@postcondition none
//
//@return map of all possible words
map<string, string> AllPossibleWords:: getPossibleWords()
{
    return this->possibleWords;
}

//
// Checks if input is part of the selected word
//
//@precondition none
//@postcondition none
//
//@param input the word you wish to find
//
//@return true if value is found false if otherwise
bool AllPossibleWords:: isAPossibleWord(string input)
{
    return this->possibleWords.count(input);
}

}
