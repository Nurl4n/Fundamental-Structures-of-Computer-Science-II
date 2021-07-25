/** Title : Algorithm to find min number of docs in the health center
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 3
* Description : Header class for Simulator
*/

#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED
#include "MaxHeap.h"

class Simulator{

public:
    Simulator();
    void addPatient(PatientNode* patient);
    PatientNode* deletePatient();
    int findNumOfDocs(int* arr);
    PatientNode* peek();
    int size();

private:
    MaxHeap* maxHeap;

};


#endif // SIMULATOR_H_INCLUDED
