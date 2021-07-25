/** Title : Algorithm for implementing Red Black Tree
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 4
* Description : Source class for Red Black Tree Node
*/

#include "RBTNode.h"
#include <iostream>
#include <cstddef>

RBTNode::RBTNode()
{
    key = "";
    freqCount = 0;
    colour = "";
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
}

RBTNode::RBTNode(const string key, string colour, RBTNode *left = NULL, RBTNode *right = NULL, RBTNode* par = NULL) {
    this->key = key;
    this->colour = colour;
	this->leftChild = left;
	this->rightChild = right;
	this->parent = par;
	this->freqCount = 1;
}

string RBTNode::getKey()
{
    return key;
}

int RBTNode::getFreq()
{
    return freqCount;
}

void RBTNode::setFreq()
{
    freqCount++;
}

void RBTNode::setColour(string c)
{
    colour = c;
}

string RBTNode::getColour()
{
    return colour;
}
