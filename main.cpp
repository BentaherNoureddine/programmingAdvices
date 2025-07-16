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

void rowSum(int mat[3][3],int arr[3]) {
    int sum = 0;
    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            sum += mat[i][j];
        }
        arr[i] = sum;

    }

}

void printRowsSum(int arr[3]) {

    for (short i=0;i<3;i++) {
        cout << "Sum of row "<<i+1 << " is "<< arr[i]<<endl;
    }
}

int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3];
    int arr[3];
     fillMat(matrix);
     printMat(matrix);
     rowSum(matrix,arr);
     printRowsSum(arr);


    return 0;
}
