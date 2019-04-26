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
        if( allUnMatchedLetters == string::npos)
        {
            this->possibleWords.insert (pair<string,string>(currWord,currWord));
        }
    }
}

bool AllPossibleWords::isAPossibleWord(string selectedWord, string randomLetters)
{
    bool result = true;
    for(char currLetter: selectedWord){
        int currLetterCount = letterCount(selectedWord,currLetter);
        int rdmLetterCount = letterCount(randomLetters, currLetter);
        if(currLetterCount > rdmLetterCount){
            result = false;
        }
    }
    return result;
}
int AllPossibleWords::letterCount(string word, char letter)
{
    int allLettersUsed = std::count(word.begin(), word.end(), letter);
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
