/** Title : Algorithm for implementing Red Black Tree
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 4
* Description : Header class for Red Black Tree Node
*/

#ifndef RBTNODE_H_INCLUDED
#define RBTNODE_H_INCLUDED

#include <iostream>
using namespace std;

class RBTNode
{
public:
    RBTNode();
    RBTNode(const string key, string colour, RBTNode *left, RBTNode *right, RBTNode* par);
    string getKey();
    int getFreq();
    void setFreq();
    void setColour(string c);
    string getColour();
private:
    string key;
    int freqCount;
    string colour;
    RBTNode *parent;
    RBTNode *leftChild;
    RBTNode *rightChild;

    friend class RBT;
};


#endif // RBTNODE_H_INCLUDED
