#include "Utils.h"


//
// Converts and returns string in uppercase
//
// @precondition none
// @postcondition none
//
// @param text the text to convert to upper case
//
// @return Uppercase version of the string
//
const string toUpper(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::toupper);

    return text;
}

//
// Converts and returns string in lowercase
//
// @precondition none
// @postcondition none
//
// @param text the text to convert to lower case
//
// @return lower case version of the string
//
const string toLower(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;
}

//
//Replaces the char of a string with underscores hiding the text
//
//@precondition none
//@postcondition none
//
const string hideText(string text)
{
    string output;
    for(char currLetter: text)
    {
        output += "-";
    }
    return output;
}

//
// Gets the length of the string and determines
// the score based on the input
//
// @precondition none
// @postcondition none
//
// @param word the word you want to determine the score for
//
// @return integer based on the length of the word
//
const int calculateScoreByWord(string word)
{
    int score =  0;
    std::string::iterator space = std::remove(word.begin(), word.end(), ' ');
    word.erase(space, word.end());
    int length = word.length();
    if(length == 3)
    {
        score = 60;
    }
    else if(length == 4)
    {
        score = 120;
    }
    else if(length == 5)
    {
        score = 200;
    }
    else if(length == 6)
    {
        score = 300;
    }
    else {
        score = 420;
    }
    return score;
}


