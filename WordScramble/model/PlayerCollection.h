#ifndef PLAYERCOLLECTION_H
#define PLAYERCOLLECTION_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include "PlayerNode.h"
#include "Utils.h"
namespace model
{

class PlayerCollection
{
    private:
        PlayerNode *timeHead;
        PlayerNode *scoreHead;
        template <typename T>
        void sortedInsert(PlayerNode* &head, Player* player, T (PlayerNode::*dataPtr)(), PlayerNode* (PlayerNode::*nextNodePtr)(), void (PlayerNode::*setNodePtr)(PlayerNode*));
        void destructCollection(PlayerNode* &head, PlayerNode* (PlayerNode::*nextNodePtr)());
    public:
        PlayerCollection();
        virtual ~PlayerCollection();
        void add(Player* player);
        PlayerNode** const getScoreHead();
        PlayerNode** const getTimeHead();
        int getHighScore();
};
}
#endif // PLAYERCOLLECTION_H
