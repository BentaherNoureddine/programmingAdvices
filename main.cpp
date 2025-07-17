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




void fibonacciRec(short n,short prev1,short prev2) {

    short feb =0;
    if (n>0) {
        feb=prev2+prev1;
        prev2=prev1;
        prev1 =feb;
        cout<<feb<<" ";
        fibonacciRec(n-1,prev1,prev2);
    }


}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    fibonacciRec(10,0,1);





    return 0;
}
