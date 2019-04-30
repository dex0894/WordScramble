#ifndef WORDSCRAMBLEWINDOW_H
#define WORDSCRAMBLEWINDOW_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>
#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <Fl/Fl_Progress.H>
#include <Fl/Fl_File_Chooser.H>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <ctype.h>
#include "Utils.h"
#include "WordScrambleUserInfoWindow.h"
#include "../controller/WordScrambleController.h"
using namespace controller;

namespace view
{


class WordScrambleWindow : public Fl_Window
{
private:
    int timeLimit = 60;
    int totalLetters = 6;
    static const int POINT_DEDUCTION = -10;
    static constexpr float ONE_FOURTHS_PROGRESS = 0.25;
    static constexpr float THREE_FOURTHS_PROGRESS = 0.75;
    int currentTime;
    void validWordEntered(string word);
    Fl_Output *possibleWordsOutputLabel;
    Fl_Text_Buffer *possibleWordsTextBuffer;
    Fl_Text_Display *possibleWordsTextDisplay;
    Fl_Output *timeRemainingLabel;
    Fl_Progress *actualClock;
    Fl_Output *totalScoreLabel;

    Fl_Text_Buffer *totalScoreTextBuffer;
    Fl_Text_Display *totalScoreTextDisplay;

    Fl_Output *validWordsOutputLabel;
    Fl_Text_Buffer *validWordsTextBuffer;
    Fl_Text_Display *validWordsTextDisplay;

    Fl_Output *scrambledWordOutputLabel;
    Fl_Text_Buffer *scrambledWordTextBuffer;
    Fl_Text_Display *scrambledWordTextDisplay;
    Fl_Input *wordEntry;
    Fl_Button* shuffleButton;
    Fl_Button* restartButton;
    Fl_Button* submitButton;
    Fl_Button* newGameButton;
    WordScrambleController controller;
    void determineProgressBarColor( WordScrambleWindow* window);
    void displayRequestForUserInfo(void *data);


public:
    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();

    static void cbShuffle(Fl_Widget* widget, void* data);
    static void cbSubmit(Fl_Widget* widget, void* data);
    static void cbNewGame(Fl_Widget* widget, void* data);
    static void cbTimer(void* data);
    static void cbWordEntry(Fl_Widget* widget, void* data);

    void setTotalPointsText(const string& outputText);
    void setPossibleWordsText(const string& outputText);
    void setScrambledWordText(const string& letters);
    void setValidWordsText(const string& outputText);
    void updateSettings(int newTimeLimit, int newLetterLimt);


};
}
#endif // WORDSCRAMBLEWINDOW_H
