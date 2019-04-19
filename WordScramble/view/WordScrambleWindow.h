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
#include <Fl/Fl_File_Chooser.H>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "../controller/WordScrambleController.h"
using namespace controller;

namespace view
{


class WordScrambleWindow : public Fl_Window
{
private:
    Fl_Output *possibleWordsOutputLabel;
    Fl_Text_Buffer *possibleWordsTextBuffer;
    Fl_Text_Display *possibleWordsTextDisplay;

    Fl_Output *scrambledWordOutputLabel;
    Fl_Text_Buffer *scrambledWordTextBuffer;
    Fl_Text_Display *scrambledWordTextDisplay;

    Fl_Input *wordEntry;

    Fl_Button* shuffleButton;
    Fl_Button* restartButton;
    Fl_Button* submitButton;
    WordScrambleController controller;


public:
    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();

    static void cbShuffle(Fl_Widget* widget, void* data);
    static void cbSubmit(Fl_Widget* widget, void* data);

    void setPossibleWordsText(const string& outputText);
    void setScrambledWordText(const string& outputText);


};
}
#endif // WORDSCRAMBLEWINDOW_H
