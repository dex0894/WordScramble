#ifndef WORDSCRAMBLESTARTWINDOW_H
#define WORDSCRAMBLESTARTWINDOW_H

#include "WordScrambleWindow.h"
#include "WordScrambleSettingsWindow.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <string>
using namespace std;

namespace view
{


class WordScrambleStartWindow : public Fl_Window
{
private:
    static const int X_LOCATION = 180;
    Fl_Button* settingsButton;
    Fl_Button* highScoreButton;
    Fl_Button* startGameButton;
    Fl_Text_Display* gameTitle;
public:
    WordScrambleStartWindow(int width, int height, const char* title);
    virtual ~WordScrambleStartWindow();
    static void cbStartGame(Fl_Widget* widget, void* data);
    static void cbScoreBoard(Fl_Widget* widget, void* data);
    static void cbSettings(Fl_Widget* widget, void* data);


};
}
#endif // WORDSCRAMBLESTARTWINDOW_H
