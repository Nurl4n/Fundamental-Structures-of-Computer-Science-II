/** Title : Algorithm for implementing Binary Search Tree and N-gram
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 2
* Description : Header class for Binary Search Tree Node
*/

#ifndef BSTNODE_H_INCLUDED
#define BSTNODE_H_INCLUDED
#include <iostream>
using namespace std;

class BSTNode
{
public:
    BSTNode() {}
    BSTNode(const string key, BSTNode *left, BSTNode *right);
    string getKey();
    int getCount();
    void setCount();

    string key;
    int freqCount;
    BSTNode *left;
    BSTNode *right;

    friend class BST;
};

#endif // BSTNODE_H_INCLUDED
