//
//  Lab06_2.cpp
//  Lab06
//
//  Modified by Jeman Park on 2024/05/01.
//

#include <iostream>
#include "SortedType.h"

using namespace std;

int main() {

    /* Feel free to edit codes below (test with more cases) */
    SortedType<int> sList;
    
    sList.insertItem(5);
    sList.insertItem(3);
    sList.insertItem(7);
    sList.insertItem(2);
    sList.insertItem(13);
    sList.insertItem(1);
    
    sList.printList();
    
    // [    1,  2,  3,  5,  7,  13  ]
    
    
    sList.removeItem(6);
    sList.removeItem(5);
    sList.printList();
    // [    1,  2,  3,  7,  13  ]
    
    
    cout << "[getItem]: " << sList.getItem(0) << endl;
    // [getItem]: 1
    cout << "[getItem]: " << sList.getItem(7) << endl;
    // [getItem]: -1
    cout << "[getItem]: " << sList.getItem(3) << endl;
    // [getItem]: 7
    
    return 0;
}
