#include "WordScrambleScoreboardWindow.h"

namespace view
{

WordScrambleScoreboardWindow::WordScrambleScoreboardWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->buildAndDisplayRadioBtn();
    this->scoreboardTextBuffer = new Fl_Text_Buffer();
    this->scoreboardTextDisplay = new Fl_Text_Display(20, 60, 500, 200);
    this->scoreboardTextDisplay->textfont(FL_COURIER);
    this->scoreboardTextDisplay->buffer(this->scoreboardTextBuffer);
    this->scoreboardTextBuffer->text(this->controller.getScoreBoardInfo().c_str());
    end();
}

WordScrambleScoreboardWindow::~WordScrambleScoreboardWindow()
{
    this->scoreboardTextDisplay->buffer(0);
    delete this->scoreboardTextBuffer;
    delete this->scoreboardTextDisplay;
    for(int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        delete this->sortRadioSelectedLabels[i];
        delete this->sortRadioGroupButton[i];
        delete this->sortRadioGroupButton[i];
    }
    delete this->sortRadioGroup;

}

void WordScrambleScoreboardWindow::buildAndDisplayRadioBtn()
{
    const int X_RADIO_GROUP = 10;
    const int Y_RADIO_GROUP = 10;
    const int WIDTH_RADIO_GROUP = 400;
    const int HEIGHT_RADIO_GROUP = 100;

    this->sortRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);
    this->sortRadioGroup->begin();
    for (int i=0; i<CURRENT_GROUP; i++)
    {
        for (int j = 0; j<SELECTION_TYPES_PER_GROUP; j++)
        {
            string label = this->sortType[j];
            int offset = (i*SELECTION_TYPES_PER_GROUP) + j;
            this->sortRadioSelectedLabels[offset] = new string(label);
            this->sortRadioGroupButton[offset] = new Fl_Round_Button(X_RADIO_GROUP + i*160, Y_RADIO_GROUP + j*25, 12, 12, sortRadioSelectedLabels[offset]->c_str());
            this->sortRadioGroupButton[offset]->type(FL_RADIO_BUTTON);
            this->sortRadioGroupButton[offset]->callback(cbSortMethodChanged, this);
        }
    }
    this->sortRadioGroup->end();
    this->sortRadioGroupButton[FIRST_RADIO_BUTTON]->set();
}

//
// Callback when a radio button for sort has changed
//
// @precondition widget != 0 AND data != 0
// @postcondition none
//
// @param widget The widget that initiatied the callback
// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
//
void WordScrambleScoreboardWindow::cbSortMethodChanged(Fl_Widget* widget, void* data)
{
    WordScrambleScoreboardWindow* window = (WordScrambleScoreboardWindow*)data;
    window->sortMethodChanged();
}

void WordScrambleScoreboardWindow::sortMethodChanged()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        if (this->sortRadioGroupButton[i]->value())
        {
            if(i == FIRST_RADIO_BUTTON)
            {
                this->controller.setScoreBoardSortByScore(true);
                this->scoreboardTextBuffer->text(this->controller.getScoreBoardInfo().c_str());
            }
            else if( i == SECOND_RADIO_BUTTON)
            {
                this->controller.setScoreBoardSortByScore(false);
                this->scoreboardTextBuffer->text(this->controller.getScoreBoardInfo().c_str());
            }
        }
    }
}


}
