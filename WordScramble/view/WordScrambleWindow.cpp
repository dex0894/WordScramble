#include "WordScrambleWindow.h"

namespace view
{

//
// Constructs a wordscramble window creating and initializing all the widgets that will be displayed
//
// @precondition width > 0 AND height > 0
// @postcondition none
//
// @param width The width of the window
// @param height The height of the window
// @param title The title to display for the window
//
WordScrambleWindow::WordScrambleWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    this->possibleWordsOutputLabel = new Fl_Output(135, 50, 0, 0, "Possible Words");
    this->possibleWordsTextBuffer = new Fl_Text_Buffer();
    this->possibleWordsTextDisplay = new Fl_Text_Display(20, 60, 500, 200);
    this->possibleWordsTextDisplay->textfont(FL_COURIER);
    this->possibleWordsTextDisplay->buffer(possibleWordsTextBuffer);

    this->scrambledWordOutputLabel = new Fl_Output(340, 285, 0, 0, "Scrambled Letters");
    this->scrambledWordTextBuffer = new Fl_Text_Buffer();
    this->scrambledWordTextDisplay = new Fl_Text_Display(175, 300, 200, 40);
    this->scrambledWordTextDisplay->textfont(FL_COURIER);
    this->scrambledWordTextDisplay->buffer(scrambledWordTextBuffer);


    end();
}

WordScrambleWindow::~WordScrambleWindow()
{
    //dtor
}
}
