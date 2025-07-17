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

bool exists(int mat[3][3],short rows,short cols,int number) {

    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
           if (mat[i][j]==number) {
               return true;
           }
        }
    }
    return false;
}

void printIntersected(int mat[3][3],int mat2[3][3],short rows,short cols) {

    cout <<"Intersected Numbers are :"<<endl;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (exists(mat2,rows,cols,mat[i][j])) {
                cout <<mat[i][j] <<"  ";
            }
        }
    }
}



int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    int matrix2[3][3]= {{7,0,0},{0,1,0},{0,0,1}};

    cout <<"Matrix 1:"<<endl;
    printMat(matrix,3,3);
    cout<<"Matrix 2:"<<endl;
    printMat(matrix2,3,3);
    printIntersected(matrix,matrix2,3,3);
    return 0;
}
