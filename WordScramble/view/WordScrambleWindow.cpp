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
    this->controller.generateRandomLetters(TOTAL_LETTERS);
    this->possibleWordsOutputLabel = new Fl_Output(130, 50, 0, 0, "Possible Words");
    this->possibleWordsTextBuffer = new Fl_Text_Buffer();
    this->possibleWordsTextDisplay = new Fl_Text_Display(20, 60, 250, 200);

    this->timeRemainingLabel = new Fl_Output(65, 20, 0,0, "Time: ");
    this->actualClock = new Fl_Progress(65, 10, 115,25);
    this->actualClock->maximum(TIME_LIMIT);
    this->actualClock->color2(FL_GREEN);
    Fl::add_timeout(1.0,cbTimer,this);

    ///Todo: Implement a callback that has a timer that:
    /// A.) updates the progress the bar by one every second
    /// B.) changes the color of progress bar based on place (0-25% green, 26-75% yellow, 75-100% red)
    /// C:) max value should be a set to total seconds used example if timer is one minute then max should be 60
    this->totalScoreLabel = new Fl_Output(345, 20, 0,0, "Total Score: ");
    this->totalScoreTextBuffer = new Fl_Text_Buffer();
    this->totalScoreTextDisplay = new Fl_Text_Display(345, 10, 40,25);
    this->totalScoreTextDisplay->buffer(this->totalScoreTextBuffer);
    this->totalScoreTextDisplay->textfont(FL_COURIER);



    this->possibleWordsTextDisplay->textfont(FL_COURIER);
    this->possibleWordsTextDisplay->buffer(possibleWordsTextBuffer);

    this->validWordsOutputLabel = new Fl_Output(360, 50, 0, 0, "Valid Words");
    this->validWordsTextBuffer = new Fl_Text_Buffer();
    this->validWordsTextDisplay = new Fl_Text_Display(270, 60, 250, 200);
    this->validWordsTextDisplay->textfont(FL_COURIER);
    this->validWordsTextDisplay->buffer(validWordsTextBuffer);

    this->scrambledWordOutputLabel = new Fl_Output(340, 285, 0, 0, "Scrambled Letters");
    this->scrambledWordTextBuffer = new Fl_Text_Buffer();
    this->scrambledWordTextDisplay = new Fl_Text_Display(220, 300, 135, 40);
    this->scrambledWordTextDisplay->textfont(FL_COURIER);
    this->scrambledWordTextDisplay->textsize(25);
    this->scrambledWordTextDisplay->buffer(scrambledWordTextBuffer);

    this->wordEntry = new Fl_Input(220, 375, 150, 25, "Enter Word:");

    this->shuffleButton = new Fl_Button(380, 300, 70, 40, "Shuffle");
    this->shuffleButton->callback(cbShuffle, this);
    this->submitButton = new Fl_Button(380, 375, 70, 25, "Submit");
    this->submitButton->callback(cbSubmit, this);
    this->newGameButton = new Fl_Button(430, 10, 90, 40, "New Game");
    this->newGameButton->callback(cbNewGame, this);

    this->setScrambledWordText(this->controller.getRandomLetters());
    this->setPossibleWordsText(this->controller.allPossibleWordsFromLetters());
    this->setTotalPointsText(to_string(this->controller.getTotalScore()));
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

    delete this->totalScoreLabel;
    this->totalScoreTextDisplay->buffer(0);
    delete this->totalScoreTextBuffer;
    delete this->totalScoreTextDisplay;

    delete this->timeRemainingLabel;
    delete this->actualClock;

    delete this->shuffleButton;
    delete this->submitButton;
    delete this->newGameButton;

}


// Creates a timer that updates progress bar based on currentValue
// The timer stops once it equals the progress's bar max value
//@precondition none
//@postcondition none
//@param data Any data that was passed with the call back, In this instance a pointer to the window.

void WordScrambleWindow::cbTimer(void *data)
{
    static float count = 0;
    cout << count << endl;
    WordScrambleWindow* window = (WordScrambleWindow*)data;

    float currentValue = window->actualClock->value();
    count++;
    if(count > window->actualClock->maximum()){
        Fl::remove_timeout(cbTimer,data);
    }
    else {
        window->actualClock->value(currentValue + 1.0);
        window->determineProgressBarColor(window);
        Fl::repeat_timeout(1.0,cbTimer, data);
    }
}

void  WordScrambleWindow::determineProgressBarColor(WordScrambleWindow* window)
{
     float currValue = window->actualClock->value();
     float maxValue = window->actualClock->maximum();
     float progressOfBar = currValue / maxValue;
     if(progressOfBar > .25 && progressOfBar < .75){
        window->actualClock->color2(FL_YELLOW);
    }
    else if(progressOfBar >= .75) {
        window->actualClock->color2(FL_RED);
    }
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
    string word = window->wordEntry->value();
    string letterChoice = window->controller.getRandomLetters();
    word = toUpper(word);
    letterChoice = toUpper(letterChoice);
    bool allValidLetters = word.find_first_not_of(letterChoice) == std::string::npos;
    bool isAValidAmountOfLetters = word.length() >= 3;
    bool validAmountOfLetters = window->controller.isAValidWord(word);
    if(!allValidLetters || !validAmountOfLetters || !isAValidAmountOfLetters )
    {
        fl_alert("Invalid Word, 10 points will be deducted");
        window->controller.updateTotalScore(POINT_DEDUCTION);
        window->setTotalPointsText(to_string(window->controller.getTotalScore()));
    }
    else
    {
        window->validWordEntered(word);
        window->setPossibleWordsText(window->controller.allPossibleWordsFromLetters());
        window->setValidWordsText(window->controller.displayAllValidWordsEntered());
        window->setTotalPointsText(to_string(window->controller.getTotalScore()));
    }
}

void WordScrambleWindow::validWordEntered(string word)
{
    int score = calculateScoreByWord(word);
    this->controller.updateTotalScore(score);
    this->controller.addValidWordEntered(word);
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
    window->controller.shuffleStrings();
    window->setScrambledWordText(window->controller.getRandomLetters());
}

//
//Callback when the newGame button is invoked
//
//@precondition widget != 0 AND data != 0
//@postcondition none
//
//@param widget the widget that initiated the callback
//@param data Any data that was passed with the call back, In this instance a pointer to the window.
//
void WordScrambleWindow::cbNewGame(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    window->controller.generateRandomLetters(TOTAL_LETTERS);
    window->controller.clearAllValidWordsEntered();

    window->setScrambledWordText(window->controller.getRandomLetters());
    window->setPossibleWordsText(window->controller.allPossibleWordsFromLetters());
    window->setValidWordsText(window->controller.displayAllValidWordsEntered());
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
//Sets the possible words text box to display the possible words, given a scrambled set of letters
//
//@precondition none
//@postcondition none
//
//@param outputText the text to display
//
void WordScrambleWindow::setValidWordsText(const string& outputText)
{
    this->validWordsTextBuffer->text(outputText.c_str());
}


//
//Sets the possible words text box to display the possible words, given a scrambled set of letters
//
//@precondition none
//@postcondition none
//
//@param outputText the text to display
//
void WordScrambleWindow::setTotalPointsText(const string& outputText)
{
    this->totalScoreTextBuffer->text(outputText.c_str());
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
