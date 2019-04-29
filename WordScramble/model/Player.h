#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

namespace model
{


class Player
{
    private:
        string firstName;
        string lastName;
        int score;
    public:
        Player(const string firstName, const string lastName, int score);
        virtual ~Player();
        string getFirstName();
        string getLastName();
        int getScore();
};
}
#endif // PLAYER_H
