/** Title : Algorithm to find min number of docs in the health center
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 3
* Description : Source class for Max Heap
*/

#include <iostream>
#include "MaxHeap.h"
using namespace std;

MaxHeap::MaxHeap()
{
    numOfElements = 0;
    items = new PatientNode*[numOfElements];
}

void MaxHeap::insert(PatientNode* newItem)
{
    // Place the new item at the end of the heap
    items[numOfElements] = newItem;

    // Trickle new item up to its proper position
    int place = size();
    int parent = (place - 1)/2;

    while((place > 0) && (items[place]->getPriority() >= items[parent]->getPriority()))
    {
        if(items[place]->getPriority() > items[parent]->getPriority())
        {
            PatientNode* temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        else if(items[place]->getArrivalTime() < items[parent]->getArrivalTime())
        {
            PatientNode* temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
    }
    ++numOfElements;
}

PatientNode* MaxHeap::peek()
{
    return items[0];
}

PatientNode* MaxHeap::extractMax()
{
    if (size() > 0)
    {
        PatientNode* rootItem = items[0];
        items[0] = items[--numOfElements];
        heapRebuild(0);
        return rootItem;
    }
}

void MaxHeap::heapRebuild(int root)
{
    int child = 2 * root + 1; 	// index of root's left child, if any
    if ( child < size() )
    {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1; 	// index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChild < size()) && (items[rightChild] > items[child]) )
            child = rightChild; 	// index of larger child

        // If root’s priority is smaller than larger child, swap values
        if ( items[root]->getPriority() < items[child]->getPriority())
        {
            PatientNode* temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }

        // If root’s priority is equal and arrival time is bigger than larger child, swap values
        else if ( items[root]->getPriority() == items[child]->getPriority())
        {
            if(items[root]->getArrivalTime() > items[child]->getArrivalTime())
            {
                PatientNode* temp = items[root];
                items[root] = items[child];
                items[child] = temp;

                // transform the new subtree into a heap
                heapRebuild(child);
            }
        }

    }
}

int MaxHeap::size()
{
    return numOfElements;
}

void MaxHeap::printHeap()
{
    for(int i = 0; i < size(); i++)
        cout << items[i] << " ";
}
