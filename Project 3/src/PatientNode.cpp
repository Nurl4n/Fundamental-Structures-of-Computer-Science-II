/** Title : Algorithm to find min number of docs in the health center
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 3
* Description : Source class for Patient Node
*/

#include "PatientNode.h"
#include <cstddef>

PatientNode::PatientNode(const int id, const int priority, const int arrivalTime, const int treatmentTime, PatientNode *left = NULL, PatientNode *right = NULL) {
	this->id = id;
	this->priority = priority;
	this->arrivalTime = arrivalTime;
	this->treatmentTime = treatmentTime;
	this->left = left;
	this->right = right;
}

int PatientNode::getId()
{
    return id;
}

int PatientNode::getPriority()
{
    return priority;
}

int PatientNode::getArrivalTime()
{
    return arrivalTime;
}

int PatientNode::getTreatmentTime()
{
    return treatmentTime;
}
