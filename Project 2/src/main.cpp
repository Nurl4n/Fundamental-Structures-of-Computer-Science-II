#include <string>
#include <iostream>
#include "hw2.h"
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv)
{
    NgramTree tree;
    string fileName(argv[1]);
    int n = atoi(argv[2]);
    tree.generateTree(fileName, n);
    cout << "\nTotal " << n << "-gram count:"  << tree.getTotalNgramCount() << endl;
    tree.printNgramFrequencies();
    cout << n << "-gram tree is complete: "  << (tree.isComplete() ? "Yes" : "No") << endl;

    //Before insertion of new n-grams
    cout << "\nTotal " << n << "-gram count:"  << tree.getTotalNgramCount() << endl;

    //string filename = "text.txt";
    //tree.generateTree(filename, 4);
    tree.addNgram("samp");
    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");
    //tree.addNgram("")
    cout << "\nTotal " << 4 << "-gram count: " << tree.getTotalNgramCount() << endl;
    tree.printNgramFrequencies();
    cout<< 4 << "-gram tree is complete: "  << (tree.isComplete() ? "Yes" : "No") << endl;
    cout<< 4 << "-gram tree is full: "  << (tree.isFull() ? "Yes" : "No") << endl;


    return 0;
}
