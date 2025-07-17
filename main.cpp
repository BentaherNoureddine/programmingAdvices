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

bool isPalindrome(int mat[3][3],short rows,short cols) {

    for (short i=0;i<rows;i++) {
        if (mat[i][0]!=mat[i][cols-1]) {
            return false;
        }
    }
    return true;
}


void printPalindrome(int mat[3][3],short rows, short cols) {

    if (isPalindrome(mat,rows,cols)) {
        cout <<"Yes: Matrix is Palindrome";
    }else {
        cout <<"No: Matrix is NOT Palindrome";
    }
}



int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix[3][3]= {{1,2,1},{4,5,4},{1,2,1}};


    cout <<"Matrix 1:"<<endl;
    printMat(matrix,3,3);
    printPalindrome(matrix,3,3);
    return 0;
}
