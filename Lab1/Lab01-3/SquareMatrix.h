//
//  SquareMatrix.h
//  Lab01
//
//  Modified by Jeman Park on 2024/03/12.
//

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#define MATRIX_SIZE 10
// You can change the value of "MATRIX_SIZE" above
// But do NOT change the defnition of the class below

class SquareMatrix
{
    
public:
    void MakeEmpty();
    void printMatrix();
    void StoreValue(int, int, int);
    SquareMatrix Add(SquareMatrix m);
    SquareMatrix Subtract(SquareMatrix m);
    void Copy(SquareMatrix m);
    
    
private:
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
};

#endif
