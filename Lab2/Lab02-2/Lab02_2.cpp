//
//  Lab02_2.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/03/19.
//

#include <iostream>
#include "SortedType.h"
//#include "mergeList.h"
using namespace std;


int main() {
    
    SortedType sList;

    /* Feel free to edit codes below (test with more cases) */

    sList.insertItem(15);
    sList.insertItem(1);
    sList.insertItem(11);
    sList.insertItem(7);
    sList.insertItem(3);
    sList.insertItem(6);
    sList.insertItem(23);
    sList.insertItem(16);

    sList.PrintList();
    // Correct Output: [1 3 6 7 11 15 16 23 ]
    
    sList.removeItem(7);
    sList.removeItem(1);
    sList.PrintList();
    // Correct Output: [ 3 6 11 15 16 23 ]
    
    
   
    cout << "[BinarySearch]: the result of input '6' is " << sList.BinarySearch(6) << endl;
    // Correct Output: [BinarySearch]: the result of input '6' is 1
    cout << "[BinarySearch]: the result of input '15' is " << sList.BinarySearch(15) << endl;
    // Correct Output: [BinarySearch]: the result of input '15' is 3
    cout << "[BinarySearch]: the result of input '12' is " << sList.BinarySearch(12) << endl;
    // Correct Output: [BinarySearch]: the result of input '12' is -1
    cout << "[BinarySearch]: the result of input '25' is " << sList.BinarySearch(25) << endl;
    // Correct Output: [BinarySearch]: the result of input '25' is -1
    

    cout << "[BinarySearchNearest]: the result of input '23' is " << sList.BinarySearchNearest(23) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '23' is 5
    cout << "[BinarySearchNearest]: the result of input '4' is " << sList.BinarySearchNearest(4) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '4' is 0
    cout << "[BinarySearchNearest]: the result of input '20' is " << sList.BinarySearchNearest(19) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '19' is 4
    cout << "[BinarySearchNearest]: the result of input '20' is " << sList.BinarySearchNearest(20) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '20' is 5
    cout << "[BinarySearchNearest]: the result of input '27' is " << sList.BinarySearchNearest(27) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '27' is 5
    cout << "[BinarySearchNearest]: the result of input '0' is " << sList.BinarySearchNearest(0) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '0' is 0


    return 0;
}
