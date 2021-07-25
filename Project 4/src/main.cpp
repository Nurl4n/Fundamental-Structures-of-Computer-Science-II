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
using namespace std;

int main(int argc, char** argv)
{
    RBT tree;
    //string fileName(argv[1]);
    string fileName = "inputFile.txt";
    tree.generateTree(fileName);
    string arr1[] = {"a", "b", "c"};
    string arr2[] = {"d", "c", "b", "a"};
    //tree.generateTree(arr2, 4);

    ofstream outFile;
    outFile.open("statistics.txt");
    tree.printWordFrequencies();
    outFile << tree.printTotalWordCount() + "\n";
    outFile << tree.printHeight() + "\n";
    outFile << tree.printMostFrequent() + "\n";
    outFile << tree.printLeastFrequent() + "\n";
    outFile.close();

    return 0;
}
