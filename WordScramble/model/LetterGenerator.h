#ifndef LETTERGENERATOR_H
#define LETTERGENERATOR_H
#include <string>

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;



namespace model {
class LetterGenerator
{
    public:

        LetterGenerator();

        virtual ~LetterGenerator();

        string generateRandomLetters(int length);

    protected:

    private:
};

}

#endif // LETTERGENERATOR_H
