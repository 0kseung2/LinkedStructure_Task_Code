//
//  Lab06_1.cpp
//  Lab06
//
//  Modified by Jeman Park on 2024/05/01.
//

#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {

    /* Feel free to edit codes below (test with more cases) */
    UnsortedType<int> uList;
    
    uList.appendItem(5);
    uList.appendItem(3);
    uList.appendItem(7);
    uList.appendItem(2);
    uList.appendItem(13);
    uList.appendItem(1);
    
    uList.printList();
    
    // [    1,  13,  2,  7,  3,  5  ]
    
    
    uList.removeItem(6);
    uList.removeItem(5);
    uList.printList();
    // [    1,  13,  2,  7,  3  ]
    
    
    cout << "[getItem]: " << uList.getItem(0) << endl;
    // [getItem]: 1
    cout << "[getItem]: " << uList.getItem(7) << endl;
    // [getItem]: -1
    cout << "[getItem]: " << uList.getItem(3) << endl;
    // [getItem]: 7
    
    return 0;
}
