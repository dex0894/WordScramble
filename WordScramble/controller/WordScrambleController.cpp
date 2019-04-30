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
    this->loadDictionary();
    this->totalScore = 0;
}

//
// Destructor that cleans up all allocated resources
//
WordScrambleController::~WordScrambleController()
{
    //dtor
}

void WordScrambleController::loadDictionary()
{
    this->dictionary =  this->reader.readFile();

}

void WordScrambleController::loadScoreBoard()
{
    for (Player* player : this->scoreboardReader.parseCSVFile())
    {
        this->playerCollection.add(player);
    }
}

//
// Generates a random string of six letters and then
//generates all possible words from those random letters
//
//@precondition none
//@postcondition none
//
//@param letterCount the number of letters to generate
//
void WordScrambleController::generateRandomLetters(int letterCount)
{

    this->randomLetters = this->letterGenerator.generateRandomLetters(letterCount);
    this->determineAllPossibleWords();
    if(this->allPossibleWords.empty())
    {
        this->generateRandomLetters(letterCount);
    }
}

void WordScrambleController::determineAllPossibleWords()
{
    AllPossibleWords possibleWords(this->dictionary, this->randomLetters);
    this->allPossibleWords = possibleWords.getPossibleWords();
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
    return formatter.buildValidWordsOutput(this->allValidWordsEntered);
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
    return this->formatter.buildAllPossibleWordsOutput(this->allPossibleWords);
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


int WordScrambleController::getTotalScore()
{
    return this->totalScore;
}

void WordScrambleController::updateTotalScore(int addedValue)
{
    totalScore += addedValue;
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

//
//Updates the scoreboard with the new players
//
//@precondition none
//@postcondition none
//
void WordScrambleController::updateScoreBoard()
{
    this->scoreboardWriter.writeToCSV(this->formatter.getFileOutput(this->playerCollection.getScoreHead(), NEXT_SCORE_FUNC_PTR));
}

//
//Compares the players current score to the scoreboard's high score
//
//@precondition none
//@postcondition none
//
//@return true if new high score
bool WordScrambleController::newHighScore()
{
    int highScore = this->playerCollection.getHighScore();
    return this->totalScore > highScore;
}

//
//Adds a player to the collection
//
//@precondition none
//@postcondition none
//
//@param the player to add
void WordScrambleController::addPlayer(Player* player)
{
    this->playerCollection.add(player);
}

//Adds new player to player colllection
//@precondition
//@postcondition
//@param
void WordScrambleController:: addNewPlayer(string fistName, string lastName, int score, int time)
{
    loadScoreBoard();
    Player* newPlayer = new Player(fistName, lastName, score, time);
    addPlayer(newPlayer);
    updateScoreBoard();
}

}
