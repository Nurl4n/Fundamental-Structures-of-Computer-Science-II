/* * Title : Algorithm Efficiency and Sorting
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 1
* Description : Header class for some of the sorting algorithms.
*/

#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

using namespace std;

class Sorting{

    public:
        Sorting();
        void insertionSort( int* arr, int size, int& compCount, int& moveCount );
        void mergeSort( int* arr, int size, int& compCount, int& moveCount );
        void quickSort( int* arr, int size, int& compCount, int& moveCount );
        void performanceAnalysis(int size);
    private:
        void insertionSortHelper(int *arr, int first, int last, int &compCount, int &moveCount);
        void mergeSortHelper(int *arr, int first, int last, int &compCount, int &moveCount);
        void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount);
        void swap( int& n1, int& n2, int &moveCount );
        void quickSortHelper(int *arr, int first, int last, int &compCount, int &moveCount);
        void partition(int theArray[], int first, int last,int &pivotIndex, int &compCount, int &moveCount);
};

#endif // SORTING_H_INCLUDED
