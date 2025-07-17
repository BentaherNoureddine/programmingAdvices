#include <iomanip>
#include <iostream>
#include "myMathLibrary.h"
#include "myInputLibrary.h"
using namespace myInputLib;

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


int getMin(int mat[3][3],short rows,short cols) {

    int min=mat[0][0];
    for (short i=0;i<rows;i++) {
        for (short j=0;j<cols;j++) {
            if (mat[i][j]<min) {
                min =mat[i][j];
            }
        }
    }
    return min;
}


int getMax(int mat[3][3],short rows,short cols) {

    int max=mat[0][0];
    for (short i=0;i<rows;i++) {
        for (short j=0;j<cols;j++) {
            if (mat[i][j]>max) {
                max =mat[i][j];
            }
        }
    }
    return max;
}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix[3][3]= {{1,2,3},{4,5,6},{7,8,9}};


    cout <<"Matrix 1:"<<endl;
    printMat(matrix,3,3);
    cout<<"Minimum Number is : "<<getMin(matrix,3,3)<<endl;
    cout<<"Maximum Number is : "<<getMax(matrix,3,3)<<endl;
    return 0;
}
