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

#include <vector>
#include <string>
using namespace std;

namespace view
{

class WordScrambleSettingsWindow : public OKCancelWindow
{
private:
    int letterCount;
    int totalTime;
    void createAndDisplayRadioButtons();
    void okHandler();
    void cancelHandler();


public:
    WordScrambleSettingsWindow();
    virtual ~WordScrambleSettingsWindow();
    int getLetterCount();
    int getTotalTime();
    static void cbSortingMethodChanged(Fl_Widget* widget, void* data);
};
}
#endif // WORDSCRAMBLESETTINGSWINDOW_H
