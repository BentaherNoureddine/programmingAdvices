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





bool validScalar(int mat[3][3],short rows,short cols) {

    bool valid=true;
    int number=mat[0][0];
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (j==i && (mat[i][j]!=number)) {
                return false;
            }
            if (j!=i &&(mat[i][j]!=0)) {
                return false;
            }
        }
    }
    return valid;
}

void printResult(int mat[3][3],short rows,short cols) {

    validScalar(mat,rows,cols) ?  cout<< "Yes : Matrix is Scalar" : cout<<"No Matrix is NOT Scalar";

}


int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3]= {{1,0,0},{0,1,0},{0,0,1}};



     printMat(matrix,3,3);



     printResult(matrix,3,3);





    return 0;
}
