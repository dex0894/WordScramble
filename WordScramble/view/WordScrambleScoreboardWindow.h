#ifndef WORDSCRAMBLESCOREBOARDWINDOW_H
#define WORDSCRAMBLESCOREBOARDWINDOW_H

#include "WordScrambleWindow.h"
#include "WordScrambleSettingsWindow.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <string>
using namespace std;
#include "WordScrambleScoreboardController.h"
using namespace controller;

namespace view
{

class WordScrambleScoreboardWindow : public Fl_Window
{
private:
    WordScrambleScoreboardController controller;
    Fl_Text_Buffer* scoreboardTextBuffer;
    Fl_Button* clearScoreBoardBtn;
    Fl_Text_Display* scoreboardTextDisplay;
    string scoreSortDisplay;
    string timeSortDisplay;
    bool clearClicked = false;
    static const int FIRST_RADIO_BUTTON = 0;
    static const int SECOND_RADIO_BUTTON = 1;
    static const int CURRENT_GROUP = 1;
    static const int SELECTION_TYPES_PER_GROUP = 2;
    static const int TOTAL_SORTING_METHODS = CURRENT_GROUP * SELECTION_TYPES_PER_GROUP;
    vector<string> sortType = {"Sort by Score", "Sort by Time"};
    Fl_Group *sortRadioGroup;
    Fl_Round_Button *sortRadioGroupButton[TOTAL_SORTING_METHODS];
    void buildAndDisplayRadioBtn();
    void sortMethodChanged();
    void clearTextSource();
    void setScoreboardText(string text);
    string* sortRadioSelectedLabels[TOTAL_SORTING_METHODS];
public:
    WordScrambleScoreboardWindow(int width, int height, const char* title);
    virtual ~WordScrambleScoreboardWindow();
    static void cbSortMethodChanged(Fl_Widget* widget, void* data);
    static void cbClearButton(Fl_Widget* widget, void* data);
    void setScoreDisplay(string text);
    void setTimeDisplay(string text);

};
}
#endif // WORDSCRAMBLESCOREBOARDWINDOW_H
