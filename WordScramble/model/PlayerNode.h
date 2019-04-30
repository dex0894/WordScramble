#ifndef PLAYERNODE_H
#define PLAYERNODE_H

#include <string>
#include <iostream>
using namespace std;
#include "Player.h"

namespace model
{

class PlayerNode
{
private:
    string firstName;
    string lastName;
    int score;
    int timeAlloted;
    PlayerNode* nextScore;
    PlayerNode* nextTime;
public:
    PlayerNode();
    PlayerNode(Player* player);
    virtual ~PlayerNode();
    const string& getFirstName();
    const string& getLastName();
    int getScore();
    int getTime();
    PlayerNode* getNextScoreNode();
    PlayerNode* getNextTimeNode();
    void setNextScoreNode(PlayerNode* node);
    void setNextTimeNode(PlayerNode* node);
};
}
#endif // PLAYERNODE_H
