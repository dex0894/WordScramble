#ifndef ALLPOSSIBLEWORDS_H
#define ALLPOSSIBLEWORDS_H
#include "Utils.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

namespace model {
class AllPossibleWords
{
    private:
        map<string, string> possibleWords;
        void determineValidWords(vector<string> dictionary, string randomLetters);
        bool isAValidWord(string word, string randomLetters);
        int letterCount(string word, char letter);
        bool isAPossibleWord(string selectedWord, string randomLetters);
    public:
        AllPossibleWords(vector<string> dictionary, string randomLetters);
        virtual ~AllPossibleWords();
        bool isAPossibleWord(string input);
        map<string, string> getPossibleWords();
};

}

#endif // ALLPOSSIBLEWORDS_H
