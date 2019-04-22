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
            cout << "Passed" << endl;
            ///TODO: add further modification to data that is store in map
            this->possibleWords.insert (pair<string,string>(currWord,currWord));
        }
    }
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
