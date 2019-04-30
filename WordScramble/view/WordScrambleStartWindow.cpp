#include "WordScrambleStartWindow.h"

namespace view
{

WordScrambleStartWindow::WordScrambleStartWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->newLetterLimit = 0;
    this->newTimeLimit = 0;
    begin();
    this->startGameButton = new Fl_Button(X_LOCATION, 120, 90, 25, "Start Game");
    this->startGameButton->callback(cbStartGame, this);
    this->highScoreButton = new Fl_Button(X_LOCATION, 160, 90, 27, "Score Board");
    this->highScoreButton->callback(cbScoreBoard, this);
    this->settingsButton = new Fl_Button(X_LOCATION, 200, 90, 27, "Settings");
    this->settingsButton->callback(cbSettings, this);
    this->gameTitle = new Fl_Text_Display(210, 100, 0, 0, "Word Scramble");
    this->gameTitle->labelsize(40);
    end();
}

//
// Destructor that cleans up all allocated resources for the window
//
WordScrambleStartWindow::~WordScrambleStartWindow()
{
    delete this->startGameButton;
    delete this->highScoreButton;
    delete this->gameTitle;
}

//
//Callback when the start game button is invoked
//
//@precondition widget != 0 AND data != 0
//@postcondition none
//
//@param widget the widget that initiated the callback
//@param data Any data that was passed with the call back, In this instance a pointer to the window.
//
void WordScrambleStartWindow::cbStartGame(Fl_Widget* widget, void* data)
{
    WordScrambleStartWindow* currentWindow = (WordScrambleStartWindow*)data;
    WordScrambleWindow gameWindow(540, 420, "Word Scramble by Kevin Flynn and Dexter Tarver");
    gameWindow.set_non_modal();
    if(currentWindow->newLetterLimit != 0 && currentWindow->newTimeLimit!= 0)
    {
        cout << currentWindow->newTimeLimit << endl;
        gameWindow.updateSettings(currentWindow->newTimeLimit, currentWindow->newLetterLimit);
    }
    gameWindow.show();

    while (gameWindow.shown())
    {
        Fl::wait();
        currentWindow->deactivate();
    }
    currentWindow->activate();
}

//
//Callback when the score board button is invoked
//
//@precondition widget != 0 AND data != 0
//@postcondition none
//
//@param widget the widget that initiated the callback
//@param data Any data that was passed with the call back, In this instance a pointer to the window.
//
void WordScrambleStartWindow::cbScoreBoard(Fl_Widget* widget, void* data)
{
    WordScrambleStartWindow* currentWindow = (WordScrambleStartWindow*)data;

}

//
//Callback when the settings button is invoked
//
//@precondition widget != 0 AND data != 0
//@postcondition none
//
//@param widget the widget that initiated the callback
//@param data Any data that was passed with the call back, In this instance a pointer to the window.
//
void WordScrambleStartWindow::cbSettings(Fl_Widget* widget, void* data)
{
    WordScrambleStartWindow* currentWindow = (WordScrambleStartWindow*)data;
    WordScrambleSettingsWindow settingsWindow;
    settingsWindow.set_modal();
    settingsWindow.show();
    while (settingsWindow.shown())
    {
        Fl::wait();
        currentWindow->deactivate();
    }
    currentWindow->activate();

    if(settingsWindow.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        currentWindow->newTimeLimit = settingsWindow.getUpdatedTimeLimit();
        currentWindow->newLetterLimit = settingsWindow.getUpdatedLetterLimit();
    }

}

}
