/** Title : Algorithm to find min number of docs in the health center
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 3
* Description : Header class for Patient Node
*/

#ifndef PATIENTNODE_H_INCLUDED
#define PATIENTNODE_H_INCLUDED

class PatientNode {
public:
        PatientNode() {}
        PatientNode(const int id, const int priority, const int arrivalTime, const int treatmentTime, PatientNode *left, PatientNode *right);
        int getId();
        int getPriority();
        int getArrivalTime();
        int getTreatmentTime();
private:
		int id;
		int priority;
		int arrivalTime;
		int treatmentTime;
		PatientNode *left;
		PatientNode *right;

        friend class BST;
};

#endif // PATIENTNODE_H_INCLUDED
