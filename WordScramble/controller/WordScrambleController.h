#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

#include "Utils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
#include "TextFileReader.h"
#include "ScoreBoardCSVReader.h"
#include "ScoreBoardCSVWriter.h"
using namespace io;
#include "../model/LetterGenerator.h"
#include "../model/AllPossibleWords.h"
#include "PlayerCollection.h"
using namespace model;
#include "OutputFormatter.h"
using namespace format;

namespace controller
{

class WordScrambleController
{
private:
    TextFileReader reader;
    ScoreBoardCSVReader scoreboardReader;
    ScoreBoardCSVWriter scoreboardWriter;
    PlayerCollection playerCollection;
    OutputFormatter formatter;
    LetterGenerator letterGenerator;
    vector<string> dictionary;
    vector<string> allValidWordsEntered;
    map<string,string> allPossibleWords;
    string randomLetters;
    void loadDictionary();
    void loadScoreBoard();
    void removeSpaces();
    void determineAllPossibleWords();

    int totalScore;
    int currentScore;
public:
    WordScrambleController();
    virtual ~WordScrambleController();
    void generateRandomLetters(int letterCount);
    void shuffleStrings();
    string getRandomLetters();
    bool isAValidWord(string selectedWord);
    void updateScore(string score);
    string displayAllValidWordsEntered();
    string allPossibleWordsFromLetters();
    void addValidWordEntered(string word);
    void clearAllValidWordsEntered();
    int getTotalScore();
    void updateTotalScore(int addedValue);
    void addPlayer(Player* player);
    void updateScoreBoard();
    bool newHighScore();
    void resetTotalScore();
    void addNewPlayer(string fistName, string lastName, int score, int time);
};
}
#endif // WORDSCRAMBLECONTROLLER_H
