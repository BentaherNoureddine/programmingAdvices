#include <iomanip>
#include <iostream>
#include "myMathLibrary.h"

using namespace myMathLib;
using namespace std;


void fillMat(int mat[3][3])  {

    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            mat[i][j] = getRandomNumber(1, 100);
        }
    }

}

void printMat(int mat[3][3]) {
    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            cout <<setw(4) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int rowSum(int mat[3][3], int row) {
    int sum = 0;
    for (short i = 0; i < 3; i++) {
        sum += mat[row][i];
    }
    return sum;
}

void printRowsSum(int mat[3][3]) {

    for (short i=0;i<3;i++) {
        cout << "Sum of row "<<i << " is "<< rowSum(mat,i)<<endl;
    }
}

int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3];
     fillMat(matrix);
     printMat(matrix);
     printRowsSum(matrix);


    return 0;
}
