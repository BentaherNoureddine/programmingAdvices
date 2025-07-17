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



short numberOfExists(int mat[3][3],short rows,short cols,short number) {

    short count =0;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
           if (mat[i][j]==number) {
               count++;
           }
        }
    }
    return count;
}




int main() {

    //Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

     int matrix[3][3]= {{1,0,0},{0,1,0},{0,0,1}};



     printMat(matrix,3,3);

     short number = readShort("Enter the number to count in matrix");
     cout <<"number " <<number <<" count is : "<<numberOfExists(matrix,3,3,number);





    return 0;
}
