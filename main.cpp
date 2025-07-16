#include <iomanip>
#include <iostream>
#include "myMathLibrary.h"

using namespace myMathLib;
using namespace std;


void fillMat(int mat[3][3],short rows,short cols)  {


    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            mat[i][j] =getRandomNumber(1,100);

        }
    }

}

void printMat(int mat[3][3],short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout <<setw(5) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void fillWithMulti(int mat[3][3],int mat2[3][3],int mat3[3][3]) {

    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            mat3[i][j] = mat[i][j] * mat2[i][j];
        }
    }
}

int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3];
     int matrix2[3][3];
     int matrix3[3][3];

     cout<< "Matrix 1"<<endl;
     fillMat(matrix,3,3);
     printMat(matrix,3,3);
     cout<< "matrix 2"<<endl;
     fillMat(matrix2,3,3);
     printMat(matrix2,3,3);

     fillWithMulti(matrix,matrix2,matrix3);
     cout<< "Result"<<endl;
     printMat(matrix3,3,3);
    return 0;
}
