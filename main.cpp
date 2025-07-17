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




bool isTypical(int mat[3][3], int mat2[3][3]) {

    bool typical = true;
    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            if (mat[i][j]!=mat2[i][j]) {
                return false;
            }
        }
    }
    return typical;

}

void printResult(int mat[3][3], int mat2[3][3]) {

    isTypical(mat,mat2)? cout<< "Yes : matrices ARE typycal." : cout<<"No : matrices are NOT typical." ;

}


int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3];
    int matrix2[3][3];

     fillMat(matrix,3,3);
     printMat(matrix,3,3);

     fillMat(matrix2,3,3);
     printMat(matrix2,3,3);

     printResult(matrix,matrix2);





    return 0;
}
