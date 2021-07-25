/* * Title : Algorithm Efficiency and Sorting
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 1
* Description : Implementation of the sorting algorithms.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "sorting.h"



using namespace std;

Sorting::Sorting() {}

void Sorting::insertionSort(int* arr, int size, int& compCount, int& moveCount){
    insertionSortHelper(arr, 0, size - 1, compCount, moveCount);
}

void Sorting::mergeSort(int* arr, int size, int& compCount, int& moveCount){
    mergeSortHelper(arr, 0, size - 1, compCount, moveCount);
}

void Sorting::quickSort(int* arr, int size, int& compCount, int& moveCount){
    quickSortHelper(arr, 0, size - 1, compCount, moveCount);
}

void Sorting::insertionSortHelper(int *arr, int first, int last, int &compCount, int &moveCount)
{
    for (int unsorted = 1; unsorted < last; ++unsorted)
    {
        int nextItem = arr[unsorted];
        int loc = unsorted;

        for (  ; (loc > 0) && (arr[loc-1] > nextItem); --loc)
        {
            arr[loc] = arr[loc-1];
            moveCount++;
            compCount++;
        }

        arr[loc] = nextItem;

        moveCount++;
        compCount++;
    }
}

void Sorting::mergeSortHelper(int *arr, int first, int last, int &compCount, int &moveCount)
{
    if (first < last)
    {
        int mid = (first + last)/2; 	// index of mid index
        mergeSortHelper(arr, first, mid, compCount, moveCount);
        mergeSortHelper(arr, mid+1, last, compCount, moveCount);
        // merges the two halves
        merge(arr, first, mid, last, compCount, moveCount);
    }
}  // end mergeSort

void Sorting::merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount)
{

    int tempArray[last+1]; 	// temporary array

    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); ++index)
    {
        if (theArray[first1] < theArray[first2])
        {
            tempArray[index] = theArray[first1];
            ++first1;
            compCount++;
            moveCount++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            ++first2;
            moveCount++;
        }

        compCount++;
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = theArray[first1];
        moveCount++;
    }


    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = theArray[first2];
        moveCount++;
    }

    // copy the result back into the original array
    for (index = first; index <= last; ++index)
    {
        theArray[index] = tempArray[index];
        moveCount++;
    }


}  // end merge

void Sorting::quickSortHelper(int *arr, int first, int last, int &compCount, int &moveCount)
{
    // Precondition: theArray[first..last] is an array.
    // Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

    if (first < last)
    {
        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quickSortHelper(arr, first, pivotIndex-1, compCount, moveCount);
        quickSortHelper(arr, pivotIndex+1, last, compCount, moveCount);
    }
}

void Sorting::partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount)
{
    // Precondition: theArray[first..last] is an array; first <= last.
    // Postcondition: Partitions theArray[first..last] such that:
    // S1 = theArray[first..pivotIndex-1] < pivot
    // theArray[pivotIndex] == pivot
    // S2 = theArray[pivotIndex+1..last] >= pivot

    // place pivot in theArray[first]
    swap(theArray[first], theArray[last], moveCount);

    int pivot = theArray[first]; // copy pivot

    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown)
    {
        // Invariant: theArray[first+1..lastS1] < pivot
        // theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        if (theArray[firstUnknown] < pivot)    	// belongs to S1
        {
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1], moveCount);
            compCount++;
            moveCount++;
        }	// else belongs to S2
        else
            compCount++;
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1], moveCount);
    pivotIndex = lastS1;
    moveCount++;
}


void Sorting::swap( int& n1, int& n2, int &moveCount)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
    moveCount += 3;
}

void Sorting:: performanceAnalysis(int size)
{
    int* arrInsert;
    int* arrMerge;
    int* arrQuick;


    // --------------------------------------------------/* RANDOM */------------------------------------------
    srand((unsigned)time(0));

    arrInsert = new int[size];
    arrMerge = new int[size];
    arrQuick = new int[size];

    for(int i = 0; i < size; i++)
    {
        arrInsert[i] = (rand()%1000000)+1;
        arrMerge[i] = arrInsert[i];
        arrQuick[i] = arrInsert[i];
    }
    //Store the starting time

    cout << "---Checking Random Integers---" << endl;
    double durationInsertRand;
    clock_t startTime1 = clock();
    //Code block
    int compCountInsertRand = 0;
    int moveCountInsertRand = 0;
    insertionSort(arrInsert, size , compCountInsertRand, moveCountInsertRand);
    //Compute the number of seconds that passed since the starting time
    durationInsertRand = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
    cout << "(Insertion Sort: random array) Execution took " << durationInsertRand << " milliseconds. \n" <<
            "No. Comparisons: " << compCountInsertRand << "   No. Moves: " << moveCountInsertRand <<endl;
    delete[] arrInsert;

    double durationMergeRand;
    clock_t startTime2 = clock();
    //Code block
    int compCountMergeRand = 0;
    int moveCountMergeRand = 0;
    mergeSort(arrMerge, size, compCountMergeRand, moveCountMergeRand);
    //Compute the number of seconds that passed since the starting time
    durationMergeRand = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
    cout << "(Merge Sort: random array) Execution took " << durationMergeRand << " milliseconds. \n" <<
            "No. Comparisons: " << compCountMergeRand << "   No. Moves: " << moveCountMergeRand <<endl;
    delete[] arrMerge;

    double durationQuickRand;
    clock_t startTime3 = clock();
    //Code block
    int compCountQuickRand = 0;
    int moveCountQuickRand = 0;
    quickSort(arrQuick, size, compCountQuickRand, moveCountQuickRand);
    //Compute the number of seconds that passed since the starting time
    durationQuickRand = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
    cout << "(Quick Sort: random array) Execution took " << durationQuickRand << " milliseconds. \n" <<
            "No. Comparisons: " << compCountQuickRand << "   No. Moves: " << moveCountQuickRand <<endl;
    delete[] arrQuick;

    // --------------------------------------------------/* Ascending Order */------------------------------------------
    //Store the starting time

    cout << endl;
    cout << "---Checking Ascending Integers---" << endl;

    arrInsert = new int[size];
    arrMerge = new int[size];
    arrQuick = new int[size];

    for(int i = 0; i < size; i++)
    {
        arrInsert[i] = i;
        arrMerge[i] = arrInsert[i];
        arrQuick[i] = arrInsert[i];
    }

    double durationInsertAsc;
    clock_t startTime4 = clock();
    //Code block
    int compCountInsertAsc = 0;
    int moveCountInsertAsc = 0;
    insertionSort(arrInsert, size, compCountInsertAsc, moveCountInsertAsc);
    //Compute the number of seconds that passed since the starting time
    durationInsertAsc = 1000 * double( clock() - startTime4 ) / CLOCKS_PER_SEC;
    cout << "(Insertion Sort: ascending array) Execution took " << durationInsertAsc << " milliseconds. \n" <<
            "No. Comparisons: " << compCountInsertAsc << "   No. Moves: " << moveCountInsertAsc <<endl;
    delete[] arrInsert;

    double durationMergeAsc;
    clock_t startTime5 = clock();
    //Code block
    int compCountMergeAsc = 0;
    int moveCountMergeAsc = 0;
    mergeSort(arrMerge, size, compCountMergeAsc, moveCountMergeAsc);
    //Compute the number of seconds that passed since the starting time
    durationMergeAsc = 1000 * double( clock() - startTime5 ) / CLOCKS_PER_SEC;
    cout << "(Merge Sort: ascending array) Execution took " << durationMergeAsc << " milliseconds. \n" <<
            "No. Comparisons: " << compCountMergeAsc << "   No. Moves: " << moveCountMergeAsc <<endl;
    delete[] arrMerge;

    double durationQuickAsc;
    clock_t startTime6 = clock();
    //Code block
    int compCountQuickAsc = 0;
    int moveCountQuickAsc = 0;
    quickSort(arrQuick, size, compCountQuickAsc, moveCountQuickAsc);
    //Compute the number of seconds that passed since the starting time
    durationQuickRand = 1000 * double( clock() - startTime6 ) / CLOCKS_PER_SEC;
    cout << "(Quick Sort: ascending array) Execution took " << durationQuickRand << " milliseconds. \n" <<
            "No. Comparisons: " << compCountQuickAsc << "   No. Moves: " << moveCountQuickAsc <<endl;
    delete[] arrQuick;


    // --------------------------------------------------/* Descending Order */------------------------------------------
    //Store the starting time

    cout << endl;
    cout << "---Checking Descending Integers---" << endl;

    arrInsert = new int[size];
    arrMerge = new int[size];
    arrQuick = new int[size];

    int index = 0;
    for(int i = size-1; i >= 0; i--)
    {
        arrInsert[index] = i;
        arrMerge[index] = arrInsert[index];
        arrQuick[index] = arrInsert[index];
        index++;
    }

    double durationInsertDesc;
    clock_t startTime7 = clock();
    //Code block
    int compCountInsertDesc = 0;
    int moveCountInsertDesc = 0;
    insertionSort(arrInsert, size, compCountInsertDesc, moveCountInsertDesc);
    //Compute the number of seconds that passed since the starting time
    durationInsertDesc = 1000 * double( clock() - startTime7 ) / CLOCKS_PER_SEC;
    cout << "(Insertion Sort: descending array) Execution took " << durationInsertDesc << " milliseconds. \n" <<
            "No. Comparisons: " << compCountInsertDesc << "   No. Moves: " << moveCountInsertDesc <<endl;
    delete[] arrInsert;

    double durationMergeDesc;
    clock_t startTime8 = clock();
    //Code block
    int compCountMergeDesc = 0;
    int moveCountMergeDesc = 0;
    mergeSort(arrMerge, size, compCountMergeDesc, moveCountMergeDesc);
    //Compute the number of seconds that passed since the starting time
    durationMergeDesc = 1000 * double( clock() - startTime8 ) / CLOCKS_PER_SEC;
    cout << "(Merge Sort: descending array) Execution took " << durationMergeDesc << " milliseconds. \n" <<
            "No. Comparisons: " << compCountMergeDesc << "   No. Moves: " << moveCountMergeDesc <<endl;
    delete[] arrMerge;

    double durationQuickDesc;
    clock_t startTime9 = clock();
    //Code block
    int compCountQuickDesc = 0;
    int moveCountQuickDesc = 0;
    quickSort(arrQuick, size, compCountQuickDesc, moveCountQuickDesc);
    //Compute the number of seconds that passed since the starting time
    durationQuickDesc = 1000 * double( clock() - startTime9 ) / CLOCKS_PER_SEC;
    cout << "(Quick Sort: descending array) Execution took " << durationQuickDesc << " milliseconds. \n" <<
            "No. Comparisons: " << compCountQuickDesc << "   No. Moves: " << moveCountQuickDesc <<endl;
    delete[] arrQuick;

}
