#include <iomanip>
#include <iostream>
#include "myMathLibrary.h"

using namespace myMathLib;
using namespace std;


void fillMat(int mat[3][3],short rows,short cols)  {

    short num=1;
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            mat[i][j] =num;
            num++;
        }
    }

}

void printMat(int mat[3][3],short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout <<setw(4) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void swap(short &a, short &b) {
    short temp = a;
    a = b;
    b = temp;
}

void transposeMatrix(int mat[3][3],short rows, short cols) {

    for (short i = 0; i < rows; i++) {
        for (short j = i; j < cols; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

}

int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3];

     cout<< "the following matrix is a 3x3 ordered matrix:"<<endl;
     fillMat(matrix,3,3);
     printMat(matrix,3,3);
     cout<< "the following matrix is the transposed matrix:"<<endl;
     transposeMatrix(matrix,3,3);
     printMat(matrix,3,3);
    return 0;
}
