/** Title : Algorithm for implementing Red Black Tree
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 4
* Description : Header class for Red Black Tree
*/

#ifndef RBT_H_INCLUDED
#define RBT_H_INCLUDED

#include "RBTNode.h"
#include <iostream>
using namespace std;

class RBT{
public:
    RBT();
    void addWord(string key, string colour, RBTNode* par);
    void generateTree(string* arr, int size);
    void generateTree(string fileName);
    string printTotalWordCount();
    string printHeight();
    void printWordFrequencies();
    string printMostFrequent();
    string printLeastFrequent();
    void printStandartDeviation();

private:
    RBTNode* root;
    void addWordHelper(RBTNode*& rootPtr, string key, string colour, RBTNode*& par);
    int printHeightHelper(RBTNode* rootPtr);
    void printTotalWordCountHelper(RBTNode* rootPtr, int& totalCount);
    void printWordFrequenciesHelper(RBTNode* rootPtr, ofstream& fileName);
    void printMostFrequentHelper(RBTNode* rootPtr, string& mostFrequent, int& freq);
    void printLeastFrequentHelper(RBTNode* rootPtr, string& leastFrequent, int& freq);
    void printStandartDeviationHelper();
    void fixTree(RBTNode*& addedNode, RBTNode*& rootPtr);
    string getNodeColour(RBTNode* node);

};

#endif // RBT_H_INCLUDED
