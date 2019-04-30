#include "WordScrambleSettingsWindow.h"

namespace view
{

WordScrambleSettingsWindow::WordScrambleSettingsWindow() : OKCancelWindow(330, 215, "Settings")
{
    const int X_INPUT_LOCATION = 110;
    begin();
    this->setOKLocation(70, 180);
    this->setCancelLocation(190, 180);

    this->timeLimitOutput = new Fl_Output(115, 25, 0, 0, "Time Limit:");

    this->createAndDisplayTimeLimitRadioButtons();

    this->letterLimitOutput = new Fl_Output(285, 25, 0, 0, "Letter Amount:");
    this->createAndDisplayLetterAmountRadioButtons();
    end();
}

WordScrambleSettingsWindow::~WordScrambleSettingsWindow()
{
    for(int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        delete this->timeLimitRadioSelectedLabels[i];
        delete this->timeLimitRadioGroupButton[i];
        delete this->letterLimitRadioGroupButton[i];
    }
    delete this->timeLimitRadioGroup;
    delete this->letterCountRadioGroup;
    delete this->timeLimitOutput;
    delete this->letterLimitOutput;
}

//
//Returns the letter count from the window
//
//@precondition none
//@postcondition none
//
//@return the letter count
int WordScrambleSettingsWindow::getUpdatedLetterLimit()
{
    return this->LetterLimitSelection;
}

//
//Returns the total time from the window
//
//@precondition none
//@postcondition none
//
//@return the total time
int WordScrambleSettingsWindow::getUpdatedTimeLimit()
{
    return this->timeLimitSelection;
}

void WordScrambleSettingsWindow::createAndDisplayTimeLimitRadioButtons()
{
    const int X_RADIO_GROUP = 35;
    const int Y_RADIO_GROUP = 45;
    const int WIDTH_RADIO_GROUP = 400;
    const int HEIGHT_RADIO_GROUP = 100;

    this->timeLimitRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->timeLimitRadioGroup->begin();

    for (int i=0; i<CURRENT_GROUP; i++)
    {
        for (int j = 0; j<SELECTION_TYPES_PER_GROUP; j++)
        {
            string label = this->timeLimitType[j];
            int offset = (i*SELECTION_TYPES_PER_GROUP) + j;
            this->timeLimitRadioSelectedLabels[offset] = new string(label);
            this->timeLimitRadioGroupButton[offset] = new Fl_Round_Button(X_RADIO_GROUP + i*160, Y_RADIO_GROUP + j*25, 12, 12, timeLimitRadioSelectedLabels[offset]->c_str());
            this->timeLimitRadioGroupButton[offset]->type(FL_RADIO_BUTTON);
            this->timeLimitRadioGroupButton[offset]->callback(cbTimeLimitMethodChanged, this);
        }
    }

    this->timeLimitRadioGroup->end();

    this->timeLimitRadioGroupButton[FIRST_RADIO_BUTTON]->set();
    this->timeLimitSelection = ONE_MINUTE;
}

void WordScrambleSettingsWindow::createAndDisplayLetterAmountRadioButtons()
{
    const int X_RADIO_GROUP = 185;
    const int Y_RADIO_GROUP = 45;
    const int WIDTH_RADIO_GROUP = 400;
    const int HEIGHT_RADIO_GROUP = 100;

    this->letterCountRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->letterCountRadioGroup->begin();

    for (int i=0; i<CURRENT_GROUP; i++)
    {
        for (int j = 0; j<SELECTION_TYPES_PER_GROUP; j++)
        {
            string label = this->wordAmountType[j];
            int offset = (i*SELECTION_TYPES_PER_GROUP) + j;
            this->letterLimitRadioSelectedLabels[offset] = new string(label);
            this->letterLimitRadioGroupButton[offset] = new Fl_Round_Button(X_RADIO_GROUP + i*160, Y_RADIO_GROUP + j*25, 12, 12, letterLimitRadioSelectedLabels[offset]->c_str());
            this->letterLimitRadioGroupButton[offset]->type(FL_RADIO_BUTTON);
            this->letterLimitRadioGroupButton[offset]->callback(cbLetterLimitMethodChanged, this);
        }
    }
    this->letterCountRadioGroup->end();
    this->letterLimitRadioGroupButton[1]->set();
    this->LetterLimitSelection = SIX_LETTERS;
}

//
// Callback when a radio button for settings has changed
//
// @precondition widget != 0 AND data != 0
// @postcondition getLetterLimit == value of new letter limit selected
//
// @param widget The widget that initiatied the callback
// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
//
void WordScrambleSettingsWindow::cbTimeLimitMethodChanged(Fl_Widget* widget, void* data)
{
    WordScrambleSettingsWindow* window = (WordScrambleSettingsWindow*)data;
    window->timeLimitMethodChanged();


}

//
// Callback when a radio button for settings has changed
//
// @precondition widget != 0 AND data != 0
// @postcondition getLetterLimit == value of new letter limit selected
//
// @param widget The widget that initiatied the callback
// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
//
void WordScrambleSettingsWindow::cbLetterLimitMethodChanged(Fl_Widget* widget, void* data)
{
    WordScrambleSettingsWindow* window = (WordScrambleSettingsWindow*)data;
    window->letterLimitMethodChanged();
}

void WordScrambleSettingsWindow::letterLimitMethodChanged()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        if (this->letterLimitRadioGroupButton[i]->value())
        {
            if(i == FIRST_RADIO_BUTTON)
            {
                this->LetterLimitSelection = SEVEN_LETTERS;
            }
            else if( i == SECOND_RADIO_BUTTON)
            {
                this->LetterLimitSelection = FIVE_LETTERS;
            }
            else
            {
                this->LetterLimitSelection = SIX_LETTERS;
            }

        }
    }
}

void WordScrambleSettingsWindow::timeLimitMethodChanged()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        if (this->timeLimitRadioGroupButton[i]->value())
        {
            if(i == FIRST_RADIO_BUTTON)
            {
                cout << "Selected " << endl;
                this->timeLimitSelection = ONE_MINUTE;
            }
            else if( i == SECOND_RADIO_BUTTON)
            {
                this->timeLimitSelection = TWO_MINUTES;
            }
            else
            {
                this->timeLimitSelection = THREE_MINUTES;
            }
        }
    }
}

void WordScrambleSettingsWindow::okHandler()
{
    this->hide();
}

void WordScrambleSettingsWindow::cancelHandler()
{
    this->hide();
}
}
