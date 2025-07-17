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



bool validDiagonal(int mat[3][3],short rows,short cols) {
    bool valid=true;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
         if (i==j) {
             if (mat[i][j]!=1) {
                 return false;
             }
         }
        }
    }
    return valid;
}

bool validIdentity(int mat[3][3],short rows,short cols) {

    bool valid=true;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (i==j && (j<cols || i<cols)) {
                i++;
                j++;
            }
            if (mat[i][j]!=0) {
                return false;
            }
        }
    }
    return valid;
}

void printResult(int mat[3][3],short rows,short cols) {

    if (validDiagonal(mat,rows,cols) && validDiagonal(mat,rows,cols)) {
        cout<< "Yes: Matrix is identity";
    }else {
        cout <<"No: Matrix is NOT identity";
    }

}


int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3]= {{1,0,0},{0,1,0},{0,0,1}};



     printMat(matrix,3,3);



     printResult(matrix,3,3);





    return 0;
}
