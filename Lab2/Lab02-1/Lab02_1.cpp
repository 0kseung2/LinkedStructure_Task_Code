//
//  Lab02_1.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/03/19.
//

#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {
    UnsortedType uList;
    
    /* Feel free to edit codes below (test with various cases) */

    uList.appendItem(4);
    uList.appendItem(3);
    uList.appendItem(2);
    uList.appendItem(7);
    uList.PrintList();
    // Correct Output: [ 4 3 2 7 ]
    
    uList.insertItem(1, 15);
    uList.PrintList();
    // Correct Output: [ 4 15 2 7 3 ]

    uList.removeItem(3);
    uList.PrintList();
    // Correct Output: [ 4 15 2 7 ]
   
    uList.updateItem(1, 5);
    uList.PrintList();
    // Correct Output: [ 4 5 2 7 ]
    
    uList.insertItem(3, 11);
    uList.PrintList();
    // Correct Output: [ 4 5 2 11 7 ]
    
    uList.clear();
    uList.PrintList();
    // Correct Output: [ EMPTY LIST ]



    // You don't have to do anything with the codes above (just for reference)
    
    uList.appendItem(4);
    uList.appendItem(3);
    uList.appendItem(14);
    uList.appendItem(12);
    uList.appendItem(11);
    uList.appendItem(7);
    uList.appendItem(24);
    uList.appendItem(6);
    uList.appendItem(1);
    uList.PrintList();
    // Correct Output: [4 3 14 12 11 7 24 6 1 ]
    
    int cnt = uList.removeItemsEndingWith(4);
    uList.PrintList();
    // Correct Output: [1 3 6 12 11 7 ]
    cout << cnt << " items removed" << endl;
    // Correct Output: 3 items removed
    
    
    cnt = uList.removeItemsEndingWith(8);
    uList.PrintList();
    // Correct Output: [1 3 6 12 11 7 ]
    cout << cnt << " items removed" << endl;
    // Correct Output: 0 items removed
    
    return 0;
}
