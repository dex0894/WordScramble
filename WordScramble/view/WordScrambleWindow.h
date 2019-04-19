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
using namespace std;

namespace view
{


class WordScrambleWindow : public Fl_Window
{
private:
    Fl_Output *possibleWordsOutputLabel;
    Fl_Text_Buffer *possibleWordsTextBuffer;
    Fl_Text_Display *possibleWordsTextDisplay;

public:
    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();


};
}
#endif // WORDSCRAMBLEWINDOW_H
