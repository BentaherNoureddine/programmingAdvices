#include <iomanip>
#include <iostream>
#include "myMathLibrary.h"
#include "myInputLibrary.h"
using namespace myInputLib;

using namespace myMathLib;
using namespace std;




void printFirstLetter(string letter) {

    cout<<letter[0]<<endl;

    for (short i=1;i<letter.length();i++) {
        if (letter[i]==' ') {
            cout<<letter[i+1]<<endl;;
        }
    }

}



int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    string str = readString("Please enter your string");
    printFirstLetter(str);



    return 0;
}
