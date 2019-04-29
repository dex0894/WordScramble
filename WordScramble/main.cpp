#include "view/WordScrambleWindow.h"
#include "view/WordScrambleStartWindow.h"
using namespace view;



int main (int argc, char ** argv)
{
    srand(time(NULL));
   // WordScrambleWindow mainWindow(540, 500, "Word Scramble by Kevin Flynn and Dexter Tarver");
    //mainWindow.show();
    WordScrambleStartWindow mainWindow(460, 300, "Word Scramble by Kevin Flynn and Dexter Tarver");
    mainWindow.show();
    int exitCode = Fl::run();
    return exitCode;
}
