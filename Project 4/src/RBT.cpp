/** Title : Algorithm for implementing Red Black Tree
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 4
* Description : Source class for Red Black Tree
*/
#include "RBT.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

RBT::RBT()
{
    root = NULL;
}

void RBT::addWord(string key, string colour, RBTNode* par)
{
    addWordHelper(root, key, colour, par);
}

void RBT::addWordHelper(RBTNode*& rootPtr, string key, string colour, RBTNode*& par)
{
    if(rootPtr == NULL)
    {
        rootPtr = new RBTNode(key, colour, NULL, NULL, par);
        fixTree(rootPtr, root);
    }
    else if(rootPtr->getKey() == key)
        rootPtr->setFreq();
    else if(key < rootPtr->getKey())
    {
        addWordHelper(rootPtr->leftChild, key, colour, rootPtr);
    }
    else if(key > rootPtr->getKey())
    {
        addWordHelper(rootPtr->rightChild, key, colour, rootPtr);
    }
}

void RBT::fixTree(RBTNode*& addedNode, RBTNode*& rootPtr)
{
    string cases = "";
    bool parentExists = false;
    bool grandParentExists = false;

    if(addedNode)
    {
        if(addedNode->parent)
        {
            parentExists = true;
            if(addedNode->parent->parent)
            {
                grandParentExists = true;
                RBTNode* grandParent = addedNode->parent->parent;

                if(grandParent->leftChild && grandParent->leftChild->leftChild && (grandParent->leftChild->leftChild->getKey() == addedNode->getKey()))
                    cases = "leftLeft";
                else if(grandParent->leftChild && grandParent->leftChild->rightChild && (grandParent->leftChild->rightChild->getKey() == addedNode->getKey()))
                    cases = "leftRight";
                else if(grandParent->rightChild &&  grandParent->rightChild->leftChild && (grandParent->rightChild->leftChild->getKey() == addedNode->getKey()))
                    cases = "rightLeft";
                else if(grandParent->rightChild && grandParent->rightChild->rightChild && (grandParent->rightChild->rightChild->getKey() == addedNode->getKey()))
                    cases = "rightRight";
            }
        }
        /* (Case 1) root is NULL*/
        if(!addedNode->parent) //  && rootPtr->leftChild == NULL && rootPtr->rightChild == NULL
        {
            addedNode->setColour("black");
        }
        /*(Case 3) addedNode is read, Parent is read, GrandParent is black, Uncle is red*/
        else if(parentExists && grandParentExists
                && getNodeColour(addedNode->parent->parent) == "black"
                && addedNode->parent->parent->rightChild
                && addedNode->parent->parent->leftChild
                && getNodeColour(addedNode->parent->parent->rightChild) == "red"
                && getNodeColour(addedNode->parent->parent->leftChild) == "red")
        {
            cout<<"inside case 3" << endl;
            RBTNode* grand = addedNode->parent->parent;
            RBTNode* tempParent = addedNode->parent;
            RBTNode* tempUncle = NULL;
            if(grand->leftChild->getKey() == addedNode->parent->getKey())
                tempUncle = addedNode->parent->parent->rightChild;
            else
                tempUncle = addedNode->parent->parent->leftChild;
            tempParent->setColour("black");
            tempUncle->setColour("black");
            grand->setColour("red");
            fixTree(grand, rootPtr);
        }
        /*(Case 4 - 1) addedNode is read, Parent is read, GrandParent is black, Uncle is black or does not exist*/
        else if(parentExists && grandParentExists && getNodeColour(addedNode->parent) == "red"
                && getNodeColour(addedNode->parent->parent) == "black"
                && getNodeColour(addedNode->parent->parent->rightChild) == "black"
                && cases == "leftLeft"){
            cout<<"inside case 4 - 1" << endl;
            RBTNode* grand = addedNode->parent->parent;
            RBTNode* parentGrand = grand->parent;
            RBTNode* tempParent = addedNode->parent;
            grand->parent = tempParent;
            grand->leftChild = tempParent->rightChild;
            tempParent->rightChild = grand;
            tempParent->parent = parentGrand;
            if(!parentGrand)
            {
                rootPtr = tempParent;
            }
            tempParent->setColour("black");
            tempParent->rightChild->setColour("red");
        }

        /*(Case 4 - 2) addedNode is read, Parent is read, GrandParent is black, Uncle is black or does not exist*/
        else if(parentExists && grandParentExists && getNodeColour(addedNode->parent) == "red"
                && getNodeColour(addedNode->parent->parent) == "black"
                && getNodeColour(addedNode->parent->parent->leftChild) == "black"
                && cases == "rightRight")
        {
            cout<<"inside case 4 - 2" << endl;
            RBTNode* grand = addedNode->parent->parent;
            RBTNode* parentGrand = grand->parent;
            RBTNode* tempParent = addedNode->parent;
            grand->parent = tempParent;
            grand->rightChild = tempParent->leftChild;
            tempParent->leftChild = grand;
            tempParent->parent = parentGrand;
            if(!parentGrand)
            {
                rootPtr = tempParent;
            }
            //addedNode->parent->leftChild = grand;
            tempParent->setColour("black");
            tempParent->leftChild->setColour("red");
        }
        /*(Case 5 - 1) addedNode is read, Parent is read, GrandParent is black, Uncle is black or does not exist*/
        else if(parentExists && grandParentExists && getNodeColour(addedNode->parent) == "red"
                && getNodeColour(addedNode->parent->parent) == "black"
                && getNodeColour(addedNode->parent->parent->rightChild) == "black"
                && cases == "leftRight")
        {
            cout<<"inside case 5 - 1" << endl;
            RBTNode* grand = addedNode->parent->parent;
            RBTNode* parentGrand = grand->parent;
            RBTNode* tempParent = addedNode->parent;

            tempParent->rightChild = addedNode->leftChild;
            grand->leftChild = addedNode;
            addedNode->parent = grand;
            tempParent->parent = addedNode;
            addedNode->leftChild = tempParent;
            RBTNode* temp = tempParent;
            tempParent = addedNode;
            addedNode = temp;
            delete temp;
            grand->parent = tempParent;
            grand->leftChild = tempParent->rightChild;
            tempParent->rightChild = grand;
            tempParent->parent = parentGrand;
            if(!parentGrand)
            {
                rootPtr = tempParent;
            }
            tempParent->setColour("black");
            tempParent->rightChild->setColour("red");
        }
        /*(Case 5 - 2) addedNode is read, Parent is read, GrandParent is black, Uncle is black or does not exist*/
        else if(parentExists && grandParentExists && getNodeColour(addedNode->parent) == "red"
                && getNodeColour(addedNode->parent->parent) == "black"
                && getNodeColour(addedNode->parent->parent->leftChild) == "black"
                && cases == "rightLeft")
        {
            cout<<"inside case 5 - 2" << endl;
            RBTNode* grand = addedNode->parent->parent;
            RBTNode* parentGrand = grand->parent;
            RBTNode* tempParent = addedNode->parent;

            //
            grand->rightChild = addedNode;
            addedNode->parent = grand;
            addedNode->rightChild = tempParent;
            addedNode->leftChild = NULL;
            tempParent->parent = addedNode;
            tempParent->leftChild = NULL;
            tempParent->rightChild = NULL;
            RBTNode* temp = tempParent;
            tempParent = addedNode;
            addedNode = temp;
            //delete temp;
            grand->parent = tempParent;
            grand->rightChild = tempParent->leftChild;
            tempParent->leftChild = grand;
            tempParent->parent = parentGrand;
            if(!parentGrand)
            {
                rootPtr = tempParent;
            }
            tempParent->setColour("black");
            tempParent->leftChild->setColour("red");
        }
    }
}

string RBT::getNodeColour(RBTNode* node)
{
    if(!node)
        return "black";
    return node->getColour();
}


void RBT::generateTree(string* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        addWord(arr[i], "red", NULL);
    }
}

void RBT::generateTree(string fileName)
{
    string word;
    ifstream myFile;
    myFile.open(fileName.c_str());
    while(myFile >> word)
    {
        cout << "inside generate tree -------------" << endl;
        int pos = word.find("'");
        if(pos == -1)
            addWord(word, "red", NULL);
        else{
            string b = word.substr(0, pos);
            string c = word.substr(pos+1);
            addWord(b, "red", NULL);
            addWord(c, "red", NULL);
        }
    }
    myFile.close();
}

string RBT::printHeight()
{
    string out;
    stringstream ss;
    ss << printHeightHelper(root);
    out = ss.str();
    return "Tree height: " + out;
}

int RBT::printHeightHelper(RBTNode* root)
{
    if(root == NULL)
        return 0;
    return 1 + max(printHeightHelper(root->leftChild), printHeightHelper(root->rightChild));
}

string RBT::printLeastFrequent()
{
    string leastFreq = "";
    //int freq = INT_MAX;
    int freq = 1000000000;
    printLeastFrequentHelper(root, leastFreq, freq);
    string out;
    stringstream ss;
    ss << freq;
    out = ss.str();
    return "Least frequent: " + leastFreq + " " + out;
}

void RBT::printLeastFrequentHelper(RBTNode* root, string& leastFrequent, int& freq)
{
    // finding least frequent word using inorder traversal
    if(root)
    {
        printLeastFrequentHelper(root->leftChild, leastFrequent, freq);
        if(root->getFreq() < freq)
        {
            leastFrequent = root->getKey();
            freq = root->getFreq();
        }
        printLeastFrequentHelper(root->rightChild, leastFrequent, freq);
    }
}

string RBT::printMostFrequent()
{
    string mostFreq = "";
    int freq = 0;
    printMostFrequentHelper(root, mostFreq, freq);
    string out;
    stringstream ss;
    ss << freq;
    out = ss.str();
    return "Most frequent: " + mostFreq + " " + out;
}

void RBT::printMostFrequentHelper(RBTNode* root, string& mostFrequent, int& freq)
{
    // finding most frequent word using inorder traversal
    if(root)
    {
        printMostFrequentHelper(root->leftChild, mostFrequent, freq);
        if(root->getFreq() > freq)
        {
            mostFrequent = root->getKey();
            freq = root->getFreq();
        }
        printMostFrequentHelper(root->rightChild, mostFrequent, freq);
    }
}

string RBT::printTotalWordCount()
{
    int totalWordCount = 0;
    printTotalWordCountHelper(root, totalWordCount);
    string out;
    stringstream ss;
    ss << totalWordCount;
    out = ss.str();
    return "Total word count: " + out;
}

void RBT::printTotalWordCountHelper(RBTNode* root, int& totalWordCount)
{
    // calculating total word count using inorder traversal
    if(root)
    {
        printTotalWordCountHelper(root->leftChild, totalWordCount);
        totalWordCount++;
        printTotalWordCountHelper(root->rightChild, totalWordCount);
    }
}

void RBT::printWordFrequencies()
{
    //ofstream outFile_(fileName.c_str()); //fileName.c_str()
    ofstream outFile;
    outFile.open("wordfreqs.txt");
    printWordFrequenciesHelper(root, outFile);
    outFile.close();
}

void RBT::printWordFrequenciesHelper(RBTNode* rootPtr, ofstream& fileName)
{
    // printing words with their frequencies using inorder traversal
    if(rootPtr)
    {
        printWordFrequenciesHelper(rootPtr->leftChild, fileName);
        string out;
        stringstream ss;
        ss << rootPtr->getFreq();
        out = ss.str();
        string line = "Word: " + rootPtr->getKey() + " , Frequency: " + out + " , Colour: " + rootPtr->getColour() + "\n";
        fileName << line;
        printWordFrequenciesHelper(rootPtr->rightChild, fileName);
    }
}

void RBT::printStandartDeviation()
{

}
















