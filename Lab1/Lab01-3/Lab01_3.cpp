//
//  Lab01_3.cpp
//  Lab01
//
//  Modified by Jeman Park on 2024/03/12.
//

#include <iostream>
#include "SquareMatrix.h"

using namespace std;

int main() {
    SquareMatrix A;
    SquareMatrix B;
    SquareMatrix C;
    SquareMatrix D;
    
    
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            A.StoreValue(i, j, 2);
        }
    }
    
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            B.StoreValue(i, j, 1);
        }
    }
    
    /* Feel free to edit codes below (test with more cases) */
    
    cout << "A: " << endl;
    A.printMatrix();
    //    ---- n ----
    //  | 2 2 .... 2 2
    //  | 2 2 .... 2 2
    //  n ... .... ...
    //  | 2 2 .... 2 2
    //  | 2 2 .... 2 2
    
    cout << "B: " << endl;
    B.printMatrix();
    //    ---- n ----
    //  | 1 1 .... 1 1
    //  | 1 1 .... 1 1
    //  n ... .... ...
    //  | 1 1 .... 1 1
    //  | 1 1 .... 1 1
    
    cout << "A add B: " << endl;
    C = A.Add(B);
    C.printMatrix();
    //    ---- n ----
    //  | 3 3 .... 3 3
    //  | 3 3 .... 3 3
    //  n ... .... ...
    //  | 3 3 .... 3 3
    //  | 3 3 .... 3 3
    
    cout << "A subtract B: " << endl;
    C = A.Subtract(B);
    C.printMatrix();
    //     ---- n ----
    //   | 1 1 .... 1 1
    //   | 1 1 .... 1 1
    //   n ... .... ...
    //   | 1 1 .... 1 1
    //   | 1 1 .... 1 1
    
    cout << "copy A into D: " << endl;
    D.Copy(A);
    D.printMatrix();
    //    ---- n ----
    //  | 2 2 .... 2 2
    //  | 2 2 .... 2 2
    //  n ... .... ...
    //  | 2 2 .... 2 2
    //  | 2 2 .... 2 2
    
    cout << "empty A: " << endl;
    A.MakeEmpty();
    A.printMatrix();
    //    ---- n ----
    //  | 0 0 .... 0 0
    //  | 0 0 .... 0 0
    //  n ... .... ...
    //  | 0 0 .... 0 0
    //  | 0 0 .... 0 0
    
    return 0;
}
