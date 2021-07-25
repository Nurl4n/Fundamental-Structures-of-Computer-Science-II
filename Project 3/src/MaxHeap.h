/** Title : Algorithm to find min number of docs in the health center
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 3
* Description : Header class for Max Heap
*/

#ifndef MAXHEAP_H_INCLUDED
#define MAXHEAP_H_INCLUDED

#include "PatientNode.h"

class MaxHeap{
public:
    MaxHeap();
    void insert(PatientNode* patient); // inserts integer into heap
    PatientNode* peek(); // returns the value of the max element
    PatientNode* extractMax(); // retrieves and removes the max element
    int size(); // returns the number of elements in the heap
    void printHeap();

protected:
    void heapRebuild(int root);		// Converts the semiheap rooted at
                                    // index root into a heap
private:
    PatientNode** items;	// array of heap items
	int numOfElements; // number of heap items
};


#endif // MAXHEAP_H_INCLUDED
