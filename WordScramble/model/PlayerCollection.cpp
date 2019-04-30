#include "PlayerCollection.h"

namespace model
{

//
//Creates a new Player Collection
//
//@precondition none
//@postcondition scoreHead == null, timeHead == null
PlayerCollection::PlayerCollection()
{
    this->scoreHead = nullptr;
    this->timeHead = nullptr;
}

//
//Destructs the PlayerCollection at the end of its lifetime
//
//@precondition none
//@postcondition none
//
PlayerCollection::~PlayerCollection()
{
    this->destructCollection(this->scoreHead, NEXT_SCORE_FUNC_PTR);
}

//
//Adds a Player to the PlayerCollection
//
//@precondition none
//@postcondition PlayerCollection size == prevSize + 1
//
//@param player the player that is being added
//
void PlayerCollection::add(Player* player)
{
    this->sortedInsert(this->scoreHead, player, GET_SCORE_FUNC_PTR, NEXT_SCORE_FUNC_PTR, SET_NEXT_SCORE_FUNC_PTR);
    this->sortedInsert(this->timeHead, player, GET_TIME_FUNC_PTR, NEXT_TIME_FUNC_PTR, SET_NEXT_TIME_FUNC_PTR);
}

template <typename T>
void PlayerCollection::sortedInsert(PlayerNode* &head, Player* player, T (PlayerNode::*dataPtr)(), PlayerNode* (PlayerNode::*nextNodePtr)(), void (PlayerNode::*setNodePtr)(PlayerNode*))
{
    PlayerNode *newPlayer = new PlayerNode(player);
    PlayerNode *currPlayer;
    PlayerNode *prevPlayer;

    if(head == nullptr || (head->*dataPtr)() <= (newPlayer->*dataPtr)())
    {
        (newPlayer->*setNodePtr)(head);
        head = newPlayer;
    }
    else
    {
        currPlayer = head;
        while(currPlayer != nullptr && (currPlayer->*dataPtr)() > (newPlayer->*dataPtr)())
        {
            prevPlayer = currPlayer;
            currPlayer = (currPlayer->*nextNodePtr)();
        }
        (newPlayer->*setNodePtr)(currPlayer);
        (prevPlayer->*setNodePtr)(newPlayer);
    }
}

void PlayerCollection::destructCollection(PlayerNode* &head, PlayerNode* (PlayerNode::*nextNodePtr)())
{
    PlayerNode* current = head;
    PlayerNode* next;
    while(current != nullptr)
    {
        next = (current->*nextNodePtr)();
        delete current;
        current = next;
    }
    next = nullptr;
}

//
//Gets the score head
//
//@precondition none
//@postcondition none
//
//@return the score head
PlayerNode** const PlayerCollection::getScoreHead()
{
    return &this->scoreHead;
}

//
//Gets the time head
//
//@precondition none
//@postcondition none
//
//@return the time head
PlayerNode** const PlayerCollection::getTimeHead()
{
    return &this->timeHead;
}

//
//Gets the high score from the collection
//
//@precondition none
//@postcondition none
//
//@return the high score
int PlayerCollection::getHighScore()
{
    return this->scoreHead->getScore();
}

}
