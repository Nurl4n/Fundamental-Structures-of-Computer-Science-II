/** Title : Algorithm to find min number of docs in the health center
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 3
* Description : Source class for Simulator
*/

#include <iostream>
#include "simulator.h"
using namespace std;

Simulator::Simulator()
{
    maxHeap = new MaxHeap();
}

void Simulator::addPatient(PatientNode* patien)
{
    maxHeap->insert(patien);
}

PatientNode* Simulator::deletePatient()
{
    return maxHeap->extractMax();
}

int Simulator::findNumOfDocs(int* arr)
{
    int totalTreatTime = 0;
    int totalArrivalTime = 0;
    int numOfDocs;
    int arrSize = 0;
    int* temp;
    for(int i = 1; i < arr[0]; i++){
        temp[arrSize] = arr[i];
        arrSize++;
    }

    for(int i = 0; i < arrSize; i += 4)
    {
        totalArrivalTime += temp[i + 2];
        totalTreatTime += temp[i + 3];
    }
    numOfDocs = (totalTreatTime - totalArrivalTime) / arr[0];
    if(numOfDocs * arr[0] < (totalTreatTime - totalArrivalTime))
        numOfDocs++;
}

PatientNode* Simulator::peek()
{
    return maxHeap->peek();
}

int Simulator::size(){
    return maxHeap->size();
}
