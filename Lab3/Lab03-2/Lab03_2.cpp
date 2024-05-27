//
//  Lab03_2.cpp
//  Lab03
//
//  Created by Jeman Park on 2024/03/26.
//

#include <iostream>
#include <string>
#include "CheckMatching.h"
using namespace std;

int main() {

    /* Feel free to edit codes below (test with more cases) */
    
    char someString1[] = "((()))";
    if(checkMatching(someString1, int(strlen(someString1)))){
        cout << "[MATCHED]" << endl;
    }
    else{
        cout << "[UNMATCHED]" << endl;
    }
    // "[MATCHED]"
    
    char someString2[] = "((())";
    if(checkMatching(someString2, int(strlen(someString2)))){
        cout << "[MATCHED]" << endl;
    }
    else{
        cout << "[UNMATCHED]" << endl;
    }
    // "[UNMATCHED]"
    
    char someString3[] = "(qwer)[{asdf}]\0";
    if(checkMatching(someString3, int(strlen(someString3)))){
        cout << "[MATCHED]" << endl;
    }
    else{
        cout << "[UNMATCHED]" << endl;
    }
    // "[MATCHED]"
    
    
    char someString4[] = "(qwer[){asdf}]\0";
    if(checkMatching(someString4, int(strlen(someString4)))){
        cout << "[MATCHED]" << endl;
    }
    else{
        cout << "[UNMATCHED]" << endl;
    }
    // "[UNMATCHED]"


    char someString5[] = "((([]))))";
    if (checkMatching(someString5, int(strlen(someString5)))) {
        cout << "[MATCHED]" << endl;
    }
    else {
        cout << "[UNMATCHED]" << endl;
    }
    // "[UNMATCHED]"
    
    return 0;
}
