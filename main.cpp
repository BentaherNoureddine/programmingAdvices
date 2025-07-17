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




void printFibonacciUsingLoop(short n) {

    short prev1=1;
    short prev2=1;
    short fibo;
    cout <<1<<" "<<1<<" ";
    for (short i=0;i<n-2;i++) {
       fibo=prev1+prev2;
        prev1=prev2;
        prev2=fibo;
        cout <<fibo<<" ";
    }

}



int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    printFibonacciUsingLoop(10);





    return 0;
}
