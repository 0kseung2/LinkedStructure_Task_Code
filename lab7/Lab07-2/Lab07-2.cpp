#include <iostream>
using namespace std;

// You can change SIZE_N
#define SIZE_N 4


static int mat[SIZE_N+1][SIZE_N+1];


int NumPaths_A(int row, int col) {
	if (row == 1 || col == 1)
		return 1;

	else {
		return NumPaths_A(row - 1, col) + NumPaths_A(row, col - 1);
	}
}


int NumPaths_B(int row, int col) {
    
    /* Implement the function here */
    // NumPaths_B does the same thing as NumPaths_A, but in a better way.
    // To prevent duplicated computations, it uses "mat"
    // All elements in "mat" are initialized as -1 (in "main()").
    // Thus,
    // 1) It must compute numPath (mat[row][col]) if mat[row][col] == -1
    // 2) It doesn't have to compute numPath (mat[row][col]) if it was done already.
    //    (if mat[row][col] != -1)
    // NumPaths_B must use "recursion" (similar to NumPaths_A but using "mat")

    // base case
    // row가 1이거나 col이 1일 때 1을 return
    // 만약 mat[][]의 값이 -1이 아니면 이미 구한 값이므로 mat[][] 리턴
    // general case
    // NumPaths_B(row-1, col) + mat[row][col-1]를 return

    if (mat[row][col] != -1) { // 이미 아는 값인 경우
        return mat[row][col];
    }
    else if (row == 1 || col == 1) { // 아직 모르는 값이지만 row나 col 값이 1인 경우
        mat[row][col] = 1;
        return mat[row][col];
    }
    else { // 아직 모르는 값인 경우
        mat[row][col] =  NumPaths_B(row - 1, col) + NumPaths_B(row, col - 1);
        return mat[row][col];
    }
    

    
    
}

int main() {
    
    cout << "----  NumPaths_A  ----" << endl;
	cout << NumPaths_A(SIZE_N, SIZE_N) << endl;
    // 20
    

	for (int i = 0; i < SIZE_N +1; i++) {
		for (int j = 0; j < SIZE_N +1; j++) {
			mat[i][j] = -1; // global 2차원 배열인 mat은 모든 요소 값이 -1로 설정된다.
		}
	}

    
    cout << "----  NumPaths_B  ----" << endl;
	cout << NumPaths_B(SIZE_N, SIZE_N) << endl;
    // 20
    
    cout << "----  Detailed Matrices  ----" << endl;
	for (int i = SIZE_N ; i > 0; i--) {
		for (int j = 1; j < SIZE_N + 1; j++) {
			cout << mat[i][j] << " ";
		}
        cout << endl;
	}
    //  1  4  10  20
    //  1  3   6  10
    //  1  2   3   4
    // -1  1   1   1
    
    
    

	return 0;
}
