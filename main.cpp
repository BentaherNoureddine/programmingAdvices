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

int colSum(int mat[3][3],short colNumber,short rows) {
    int sum = 0;
    for (short i = 0; i < rows; i++){
        sum += mat[i][colNumber];
    }
    return sum;

}

void sumMatColsInArray(int mat[3][3],int arr[3],short rows, short cols) {
    for (short i = 0; i < cols; i++) {
        arr[i] = colSum(mat,i,rows);
    }
}

void printColSum(int arr[3]) {

    for (short i=0;i<3;i++) {
        cout << "Sum of column "<<i+1 << " is "<< arr[i]<<endl;
    }
}

int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3];
    int arr[3];
     fillMat(matrix);
     printMat(matrix);
     sumMatColsInArray(matrix,arr,3,3);
     printColSum(arr);


    return 0;
}
