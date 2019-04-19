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
    this->controller = WordScrambleController();
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

    this->wordEntry = new Fl_Input(220, 375, 150, 25, "Enter Word:");

    this->shuffleButton = new Fl_Button(380, 300, 70, 40, "Shuffle");
    this->shuffleButton->callback(cbShuffle, this);
    this->submitButton = new Fl_Button(380, 375, 70, 25, "Submit");
    this->submitButton->callback(cbSubmit, this);

    ///TODO implement feature to set scrambled letters and possible words
    this->setPossibleWordsText("This will display all words possible from the scrambled letters.");
    this->setScrambledWordText(this->controller.generateRandomLetters());
    ///TODO
    end();
}

//
// Destructor that cleans up all allocated resources for the window
//
WordScrambleWindow::~WordScrambleWindow()
{
    delete this->possibleWordsOutputLabel;
    this->possibleWordsTextDisplay->buffer(0);
    delete this->possibleWordsTextBuffer;
    delete this->possibleWordsTextDisplay;

    delete this->scrambledWordOutputLabel;
    this->scrambledWordTextDisplay->buffer(0);
    delete this->scrambledWordTextBuffer;
    delete this->scrambledWordTextDisplay;

    delete this->shuffleButton;
    delete this->submitButton;

}

//
//Callback when the submit button is invoked
//
//@precondition widget != 0 AND data != 0
//@postcondition none
//
//@param widget the widget that initiated the callback
//@param data Any data that was passed with the call back, In this instance a pointer to the window.
//
void WordScrambleWindow::cbSubmit(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    cout << window->wordEntry->value() <<endl;
    ///TODO Implement submit function
}

//
//Callback when the shuffle button is invoked
//
//@precondition widget != 0 AND data != 0
//@postcondition none
//
//@param widget the widget that initiated the callback
//@param data Any data that was passed with the call back, In this instance a pointer to the window.
//
void WordScrambleWindow::cbShuffle(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
}

//
//Sets the possible words text box to display the possible words, given a scrambled set of letters
//
//@precondition none
//@postcondition none
//
//@param outputText the text to display
//
void WordScrambleWindow::setPossibleWordsText(const string& outputText)
{
    this->possibleWordsTextBuffer->text(outputText.c_str());
}

//
//Sets the scrambled word text box to display the selected word's letters
//
//@precondition none
//@postcondition none
//
//@param outputText the text to display
//
void WordScrambleWindow::setScrambledWordText(const string& outputText)
{

    this->scrambledWordTextBuffer->text(outputText.c_str());
}

}
