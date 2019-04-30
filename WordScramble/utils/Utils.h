#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
#include "Player.h"
#include "PlayerNode.h"
using namespace model;

const string toUpper(string text);
const string toLower(string text);
const string hideText(string text);
size_t letterCount(string word, char letter);
const int calculateScoreByWord(string word);
typedef int (PlayerNode::*ScoreFunc)();
typedef int (PlayerNode::*TimeFunc)();
typedef PlayerNode* (PlayerNode::*NextNodeFunc)();
typedef void (PlayerNode::*SetNodeFunc)(PlayerNode*);
static const ScoreFunc GET_SCORE_FUNC_PTR = &PlayerNode::getScore;
static const TimeFunc GET_TIME_FUNC_PTR = &PlayerNode::getTime;
static const NextNodeFunc NEXT_SCORE_FUNC_PTR = &PlayerNode::getNextScoreNode;
static const NextNodeFunc NEXT_TIME_FUNC_PTR = &PlayerNode::getNextTimeNode;
static const SetNodeFunc SET_NEXT_SCORE_FUNC_PTR = &PlayerNode::setNextScoreNode;
static const SetNodeFunc SET_NEXT_TIME_FUNC_PTR = &PlayerNode::setNextTimeNode;
#endif // UTILS_H
