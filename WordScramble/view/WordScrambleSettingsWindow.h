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
    // Defines the sorting methods that can be used to sort the methods.
    //
    enum TimeLimit {ONE_MINUTE = 60, TWO_MINUTES = 120, THREE_MINUTES = 180};

    enum LetterLimit { FOUR_LETTERS = 4, FIVE_LETTERS = 5, SEVEN_LETTERS = 7};

private:

    static const int CURRENT_GROUP = 1;
    static const int FIRST_RADIO_BUTTON = 0;
    static const int SECOND_RADIO_BUTTON = 1;
    static const int SELECTION_TYPES_PER_GROUP = 3;
    static const int TOTAL_SORTING_METHODS = CURRENT_GROUP * SELECTION_TYPES_PER_GROUP;

    vector<string> timeLimitType = {"1 minute", "2 minute", "3 minutes"};
    vector<string> wordAmountType = {"7 letters", "5 letters", "4 letters"};

    vector<string> sortingTypes = {"Time", "Letters"};
    string* radioSelectedLabels[TOTAL_SORTING_METHODS];

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

    void okHandler();
    void cancelHandler();


public:
    WordScrambleSettingsWindow();
    virtual ~WordScrambleSettingsWindow();
    int getLetterCount();
    int getTotalTime();
    static void cbTimeLimitMethodChanged(Fl_Widget* widget, void* data);
    static void cbLetterLimitMethodChanged(Fl_Widget* widget, void* data);

};
}
#endif // WORDSCRAMBLESETTINGSWINDOW_H
