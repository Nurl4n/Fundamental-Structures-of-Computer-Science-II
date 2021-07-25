/** Title : Algorithm for implementing Binary Search Tree and N-gram
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 2
* Description : Source code for Binary Search Tree
*/

#include "hw2.h"
#include <iostream>
#include <cmath>

using namespace std;

NgramTree::NgramTree() : root(NULL) {}

NgramTree::~NgramTree()
{
    destroyTree(root);
}

void NgramTree::destroyTree(BSTNode *&treePtr)
{

    if (treePtr != NULL)
    {
        destroyTree(treePtr->left);
        destroyTree(treePtr->right);
        delete treePtr;
        treePtr = NULL;
    }
}

void NgramTree::addNgram(string ngram)
{
    insertNgram(root, ngram);
}

void NgramTree::insertNgram(BSTNode *&treePtr, string newNgram)
{

    if (treePtr == NULL)
    {
        treePtr = new BSTNode(newNgram, NULL, NULL);
        treePtr->freqCount += 1;
    }
    else if(newNgram.compare(treePtr->key) == 0)
        treePtr->freqCount += 1;
    else if (newNgram.compare(treePtr->key) < 0)
        insertNgram(treePtr->left, newNgram);
    else
        insertNgram(treePtr->right, newNgram);
}

void NgramTree::generateTree(string fileName, int n)
{
    string ngram;
    ifstream myFile;
    myFile.open(fileName.c_str());
    while(myFile >> ngram)
    {
        if(ngram.length() >= n)
        {
            for(int i = 0; i < ngram.length() - n + 1; i++)
                addNgram(ngram.substr(i, n));
        }
    }

    myFile.close();
}

int NgramTree::getTotalNgramCount()
{
    int totalCount = 0;
    if(!root)
        return totalCount;
    getTotalNgramCountHelper(root, totalCount);
    return totalCount;
}

void NgramTree::getTotalNgramCountHelper(BSTNode* treePtr, int& totalCount)
{
    if (treePtr != NULL)
    {
        getTotalNgramCountHelper(treePtr->left, totalCount);
        totalCount++;
        getTotalNgramCountHelper(treePtr->right, totalCount);
    }
}

void NgramTree::printNgramFrequencies()
{
    printNgramFrequenciesHelper(root);
}

void NgramTree::printNgramFrequenciesHelper(BSTNode* treePtr)
{
    if (treePtr != NULL)
    {
        printNgramFrequenciesHelper(treePtr->left);
        cout << "\"" << treePtr->key << "\"" << " appears " << treePtr->freqCount << " time(s)" << endl;
        printNgramFrequenciesHelper(treePtr->right);
    }
}


bool NgramTree::isComplete()
{
    if(!root)
        return false;
    bool balanced = true;
    isBalanced(root, balanced);
    if(!balanced)
        return false;
    bool complete = true;
    isCompleteHelper(root, complete);

    return complete;

}

bool NgramTree::isCompleteHelper(BSTNode* treePtr, bool& complete)
{
    if(treePtr)
    {
        if(treePtr->right && !treePtr->left)
            complete = false;
        isCompleteHelper(treePtr->left, complete);
        isCompleteHelper(treePtr->right, complete);
    }
}

void NgramTree::isBalanced(BSTNode* treePtr, bool& balanced)
{
    if(!treePtr)
        return;
    if(abs(getHeight(treePtr->left) - getHeight(treePtr->right)) > 1)
        balanced = false;
    isBalanced(treePtr->left, balanced);
    isBalanced(treePtr->right, balanced);
}


bool NgramTree::isFull()
{
    if(!root)
        return false;
    int totalNumOfNodes = pow(2,getHeight(root)) - 1;
    int totalNumOfNodesInTree = 0;
    isFullHelper(root, totalNumOfNodesInTree);
    //cout << "Inside isFull " << totalNumOfNodes << "     " << totalNumOfNodesInTree << endl;
    if(totalNumOfNodes == totalNumOfNodesInTree)
        return true;
    return false;

}

void NgramTree::isFullHelper(BSTNode* treePtr, int& totalNumOfNodesInTree)
{
    if(treePtr)
    {
        getTotalNgramCountHelper(treePtr->left, totalNumOfNodesInTree);
        totalNumOfNodesInTree++;
        getTotalNgramCountHelper(treePtr->right, totalNumOfNodesInTree);
    }
}

int NgramTree::getHeight(BSTNode * treePtr)
{
    if(!treePtr)
        return 0;
    return 1 + max(getHeight(treePtr->left), getHeight(treePtr->right));
}




