//
//  Lab03_1.cpp
//  Lab03
//
//  Modified by Jeman Park on 2024/03/26.
//

#include <iostream>
#include "DoubleStackType.h"
using namespace std;



int main(int argc, const char * argv[]) {

    /* Feel free to edit codes below (test with more cases) */
    DoubleStack<int> DS(5);
    
    if (DS.Push(150) == -1){
        cout << "[ERROR] Stack is full. PUSH failed." << endl;
    }
    if (DS.Push(3) == -1){
        cout << "[ERROR] Stack is full. PUSH failed." << endl;
    }
    if (DS.Push(10) == -1){
        cout << "[ERROR] Stack is full. PUSH failed." << endl;
    }
    if (DS.Push(220) == -1){
        cout << "[ERROR] Stack is full. PUSH failed." << endl;
    }
    if (DS.Push(1050) == -1){
        cout << "[ERROR] Stack is full. PUSH failed." << endl;
    }
    if (DS.Push(23) == -1){
        cout << "[ERROR] Stack is full. PUSH failed." << endl;
    }
    // [ERROR] Stack is full. PUSH failed.
   
    DS.Print();
    // [ 3    10     | 1050    220    150     ]
    
    
    cout << DS.Pop(TOP_BIG) << endl;
    // 1050
    cout << DS.Pop(TOP_SMALL) << endl;
    // 10
    
    cout << DS.Pop(TOP_BIG) << endl;
    // 220
    cout << DS.Pop(TOP_BIG) << endl;
    // 150
    cout << DS.Pop(TOP_BIG) << endl;
    // -1
    
    DS.Print();
    // [ 3     |  ]
    
    cout << DS.Pop(TOP_SMALL) << endl;
    // 3
    cout << DS.Pop(TOP_SMALL) << endl;
    // -1
    
    DS.Print();
    // [  |  ]
    
    
    if (DS.Push(2030) == -1){
        cout << "[ERROR] Stack is full. PUSH failed." << endl;
    }
    if (DS.Push(6) == -1){
        cout << "[ERROR] Stack is full. PUSH failed." << endl;
    }
    DS.Print();
    // [ 6     | 2030     ]
        
    return 0;
}
