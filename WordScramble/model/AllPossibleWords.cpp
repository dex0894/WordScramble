#include "AllPossibleWords.h"
namespace model
{
AllPossibleWords::AllPossibleWords(vector<string> dictionary, string randomLetters)
{
    this->possibleWords = map<string, string>();
    this->determineValidWords(dictionary, randomLetters);
}

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

        bool correctLetterLength = currWord.length() >= 3;
        if( allUnMatchedLetters == string::npos && correctLetterLength && isAPossibleWord(currWord, randomLetters))
        {
            this->possibleWords.insert (pair<string,string>(currWord,currWord));
        }
    }
}

bool AllPossibleWords::isAPossibleWord(string selectedWord, string randomLetters)
{
    bool result = true;
    std::transform(randomLetters.begin(), randomLetters.end(), randomLetters.begin(), ::tolower);
    for(char currLetter: selectedWord){
        size_t currLetterCount = letterCount(selectedWord,currLetter);
        size_t rdmLetterCount = letterCount(randomLetters, currLetter);
        if(currLetterCount > rdmLetterCount){
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



map<string, string> AllPossibleWords:: getPossibleWords()
{
    return this->possibleWords;
}


bool AllPossibleWords:: isAPossibleWord(string input)
{
    return this->possibleWords.count(input);
}

}
