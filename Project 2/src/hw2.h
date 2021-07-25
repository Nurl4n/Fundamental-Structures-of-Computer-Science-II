/** Title : Algorithm for implementing Binary Search Tree and N-gram
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 2
* Description : Header class for Binary Search Tree
*/

#ifndef HW2_H_INCLUDED
#define HW2_H_INCLUDED

#include <iostream>
#include<iostream>
#include<fstream>
#include "hw2.h"
#include "BSTNode.h"
using namespace std;


class NgramTree
{
public:
    NgramTree();
    ~NgramTree();

    void addNgram(string ngram);
    int getTotalNgramCount();
    void printNgramFrequencies();
    bool isComplete();
    bool isFull();
    void generateTree(string fileName, int n);

private:
    BSTNode *root;

    void destroyTree(BSTNode *&treePtr);

    // helper function for void addNgram(string ngram);
    void insertNgram(BSTNode *&treePtr, string newNgram);

    // helper for int getTotalNgramCount();
    void getTotalNgramCountHelper(BSTNode* treePtr, int& totalCount);

    // helper for void printNgramFrequencies();
    void printNgramFrequenciesHelper(BSTNode* treePtr);

    // helpers for bool isFull();
    void isFullHelper(BSTNode* treePtr, int& totalNumOfNodes);
    int getHeight(BSTNode * treePtr);

    // helper for bool isComplete();
    bool isCompleteHelper(BSTNode* treePtr, bool& complete);
    void isBalanced(BSTNode* treePtr, bool& balanced);

};

#endif // HW2_H_INCLUDED
