#include "view/WordScrambleWindow.h"
using namespace view;

int main (int argc, char ** argv)
{
    WordScrambleWindow mainWindow(540, 500, "Word Scramble by Kevin Flynn and Dexter Tarver");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
