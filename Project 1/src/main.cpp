/* * Title : Algorithm Efficiency and Sorting
* Author : Nurlan Farzaliyev
* ID : 21503756
* Section : 1
* Assignment : 1
* Description : Main class to test some of the sorting algorithms.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

using namespace std;

int main()
{
    Sorting test;
    cout << "-------------------------Size 20000----------------------" << endl;
    test.performanceAnalysis(20000);

    cout << "-------------------------Size 30000----------------------" << endl;
    test.performanceAnalysis(30000);

    cout << "-------------------------Size 40000----------------------" << endl;
    test.performanceAnalysis(40000);

    cout << "-------------------------Size 50000----------------------" << endl;
    test.performanceAnalysis(50000);

    cout << "-------------------------Size 60000----------------------" << endl;
    test.performanceAnalysis(60000);


    return 0;
}
