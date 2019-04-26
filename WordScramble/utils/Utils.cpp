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
