#ifndef WORDSCRAMBLEUSERINFOWINDOW_H
#define WORDSCRAMBLEUSERINFOWINDOW_H
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
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
#include <Fl/Fl_Progress.H>
#include <Fl/Fl_File_Chooser.H>
#include "OKCancelWindow.h"
#include <string>
using namespace std;
#include "Player.h"
using namespace model;

namespace view
{
class WordScrambleUserInfoWindow : public OKCancelWindow
{
private:

    Fl_Input *firstName;
    Fl_Input *lastName;
    Player* player;
    int score;
    int time;
public:
    WordScrambleUserInfoWindow();
    virtual ~WordScrambleUserInfoWindow();
    string getFirstName();
    string getLastName();
    void setPlayerTime(int time);
    void setPlayerScore(int score);
    Player* getPlayer();
    void okHandler();
    void cancelHandler();


};
}
#endif // WORDSCRAMBLEUSERINFOWINDOW_H
