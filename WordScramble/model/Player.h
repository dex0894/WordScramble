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
    int timeAlloted;
public:
    Player(const string firstName, const string lastName, int score, int time);
    virtual ~Player();
    string getFirstName();
    string getLastName();
    int getScore();
    int getTime();
};
}
#endif // PLAYER_H
