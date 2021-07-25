/** Title : Algorithm to find min number of docs in the health center
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 3
* Description : Main class
*/

#include <iostream>
#include "simulator.h"
#include <cstdlib>
using namespace std;

int main()
{
    int arr [] = {2, 1, 20, 1, 10, 2, 40, 1, 14}; // first element is num of patients
    Simulator sim;

    int numOfDocs = sim.findNumOfDocs(arr);
    int numOfPatients = arr[0];
    PatientNode** arrToTrackDocAvail;
    int arrDocSize = 0;


    for(int i = 0; i < numOfPatients; i += 1)
    {
        arrToTrackDocAvail[i] = NULL;
        arrDocSize++;
    }

    int restNumOfPatients = sim.size();
    int index = 1;
    for(int i = restNumOfPatients; i > 0; i--)
    {
        bool equall = true;
        while( equall)
        {
            PatientNode* tempPatient = new PatientNode(arr[index], arr[index+1], arr[index+2], arr[index+3], NULL, NULL);
            sim.addPatient(tempPatient);
            index = index + 4;
            PatientNode* tempPatient2 = new PatientNode(arr[index], arr[index+1], arr[index+2], arr[index+3], NULL, NULL);
            if(tempPatient->getArrivalTime() != tempPatient2->getArrivalTime())
                equall = false;
            restNumOfPatients--;
        }

        PatientNode* temp = sim.peek();

        for(int j = 0; j < arrDocSize; j++){
            if(arrToTrackDocAvail[j] == NULL){
                arrToTrackDocAvail[j] = sim.deletePatient();
                cout << "Doctor " << j << " takes patient " << arrToTrackDocAvail[j]->getId() << " at minute " << arrToTrackDocAvail[j]->getArrivalTime() << "wait: 0 mins" << endl;
            }
        }
        int docDoneTreat = 10000000000000;
        int docNum = 0;
        for(int k = 0; k < arrDocSize; k++)
        {
            int docSpent = abs(arrToTrackDocAvail[k]->getTreatmentTime() - arrToTrackDocAvail[k]->getArrivalTime());
                if(docSpent < docDoneTreat){
                    docDoneTreat = docSpent;
                    docNum = k;
                }

                arrToTrackDocAvail[k] = sim.deletePatient();
                cout << "Doctor " << k << " takes patient " << arrToTrackDocAvail[k]->getId() << " at minute " << arrToTrackDocAvail[k]->getArrivalTime() << "wait: 0 mins" << endl;
        }

    }

    return 0;
}
