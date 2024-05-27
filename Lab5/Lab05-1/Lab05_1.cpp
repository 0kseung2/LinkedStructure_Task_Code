//
//  Lab05_1.cpp
//  Lab05
//
//  Modified by Jeman Park on 2024/04/17.
//

#include <iostream>
#include "StackType.h"
using namespace std;



int main(int argc, const char * argv[]) {
    
    StackType tempStack;
    
    tempStack.push(5);
    tempStack.push(3);
    tempStack.push(11);
    tempStack.push(8);
    tempStack.push(21);
    tempStack.Print();
    //    (top)    21    8    11    3    5     ] 
    cout << "[SIZE]: " << tempStack.size() << endl;
    //  [SIZE]: 5
    
    tempStack.clear();
    tempStack.Print();
    // [EMPTY STACK]
    cout << "[SIZE]: " << tempStack.size() << endl;
    // [SIZE]: 0
    
    tempStack.push(16);
    tempStack.push(20);
    tempStack.push(30);
    tempStack.Print();
    // (top)    30    20    16     ]
    cout << "[SIZE]: " << tempStack.size() << endl;
    // [SIZE]: 3
    
    cout << "[POP]: " << tempStack.pop() << endl;
    cout << "[POP]: " << tempStack.pop() << endl;
    //    [POP]: 30
    //    [POP]: 20
    
    tempStack.Print();
    // (top)    16     ]
    cout << "[SIZE]: " << tempStack.size() << endl;
    // [SIZE]: 1
    
    return 0;
}
