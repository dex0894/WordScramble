#ifndef WORDSCRAMBLESETTINGSWINDOW_H
#define WORDSCRAMBLESETTINGSWINDOW_H

#include "OKCancelWindow.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace view
{

class WordScrambleSettingsWindow : public OKCancelWindow
{
public:
    //
    // Defines the time limit that determines how many minutes the user has tp left
    // to solve all possible words
    //
    enum TimeLimit {ONE_MINUTE = 60, TWO_MINUTES = 120, THREE_MINUTES = 180};
    //
    // Defines the letter limit that can determine how many random letters are allowed to be
    // used
    enum LetterLimit {FIVE_LETTERS = 5, SIX_LETTERS = 6,  SEVEN_LETTERS = 7};

private:

    static const int FIRST_RADIO_BUTTON = 0;
    static const int SECOND_RADIO_BUTTON = 1;
    static const int THIRD_RADIO_BUTTON = 2;
    static const int CURRENT_GROUP = 1;
    static const int SELECTION_TYPES_PER_GROUP = 3;
    static const int TOTAL_SORTING_METHODS = CURRENT_GROUP * SELECTION_TYPES_PER_GROUP;
    vector<string> timeLimitType = {"1 minute", "2 minute", "3 minutes"};
    vector<string> wordAmountType = {"7 letters", "6 letters", "5 letters"};

    string* timeLimitRadioSelectedLabels[TOTAL_SORTING_METHODS];
    string* letterLimitRadioSelectedLabels[TOTAL_SORTING_METHODS];


    Fl_Output *timeLimitOutput;
    Fl_Group *timeLimitRadioGroup;
    Fl_Group *letterCountRadioGroup;
    Fl_Output *letterLimitOutput;

    Fl_Round_Button *timeLimitRadioGroupButton[TOTAL_SORTING_METHODS];
    Fl_Round_Button *letterLimitRadioGroupButton[TOTAL_SORTING_METHODS];

    TimeLimit sortOrderSelection;

    TimeLimit timeLimitSelection;
    LetterLimit LetterLimitSelection;
    void createAndDisplayTimeLimitRadioButtons();
    void createAndDisplayLetterAmountRadioButtons();
    void letterLimitMethodChanged();
    void timeLimitMethodChanged();
    void determineLetterLimitSelection(int value);
    void determineTimeLimitSelection(int value);
    void okHandler();
    void cancelHandler();


public:
    WordScrambleSettingsWindow();
    virtual ~WordScrambleSettingsWindow();
    int getUpdatedLetterLimit();
    int getUpdatedTimeLimit();
    static void cbTimeLimitMethodChanged(Fl_Widget* widget, void* data);
    static void cbLetterLimitMethodChanged(Fl_Widget* widget, void* data);

};
}
#endif // WORDSCRAMBLESETTINGSWINDOW_H
