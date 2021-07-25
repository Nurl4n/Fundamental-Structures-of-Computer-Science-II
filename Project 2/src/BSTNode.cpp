/** Title : Algorithm for implementing Binary Search Tree and N-gram
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 2
* Description : Source code for Binary Search Tree Node
*/

#include "BSTNode.h"
#include <string>
#include <cstddef>

BSTNode::BSTNode(const string key, BSTNode *left = NULL, BSTNode *right = NULL) {
	this->key = key;
	this->left = left;
	this->right = right;
	this->freqCount = 0;
}

string BSTNode::getKey()
{
    return key;
}

int BSTNode::getCount()
{
    return freqCount;
}

void BSTNode::setCount()
{
    freqCount++;
}
