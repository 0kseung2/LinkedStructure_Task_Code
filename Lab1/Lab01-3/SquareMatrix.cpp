//
//  SquareMatrix.cpp
//  Lab01
//
//  Modified by Jeman Park on 2024/03/12.
//

#include <iostream>
#include "SquareMatrix.h"



void SquareMatrix::MakeEmpty()
{
    /* Implement the function here */
    // It sets all elements in "matrix" to 0
    // It returns nothing (void)
    /* Hint: it needs double 'for' loops to set all values (matrix[i][j]) in 2d-array */
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            this->matrix[i][j] = 0;
        }
    }








}


void SquareMatrix::printMatrix()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}


void SquareMatrix::StoreValue(int i , int j , int value)
{
    /* Implement the function here */
    // It sets the item at [i] row and [j] column to "value"
    // It returns nothing
    this->matrix[i][j] = value;




}




SquareMatrix SquareMatrix::Add(SquareMatrix m)
{
    SquareMatrix result;
    /* Implement the function here */
    // This function adds two matrices 'this' and input 'm'
    // The added vault will be storet in "result" and "result" will be returned
    // Hint: result[i][j] = matrix[i][j] + m.matrix[i][j]
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
        }
    }
    





    
    return result;
}



SquareMatrix SquareMatrix::Subtract(SquareMatrix m)
{
    SquareMatrix result;
    /* Implement the function here */
    // This function is similar to "Add" above, but it subtracts 'm' from 'this'.
    // It returns "result"
    /* Hint: result[i][j] = matrix[i][j] - m.matrix[i][j] */
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
        }
    }




    
    return result;
}



void SquareMatrix::Copy(SquareMatrix m)
{
    /* Implement the function here */
    // It copies 'm' into 'this'
    // It returns nothing (void)
    /* Hint: Copy all values of m.matrix to matrix */
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            this->matrix[i][j] = m.matrix[i][j];
        }
    }





    
}
