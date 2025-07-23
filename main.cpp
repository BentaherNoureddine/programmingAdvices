#include <iomanip>
#include <iostream>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"
using namespace myInputLib;

using namespace myMathLib;
using namespace std;



string removePunc(string s) {

    string s2;
    bool n;
    for (short i=0;i<s.length();i++) {
        if (std::ispunct(s[i])==false) {
            s2+=s[i];
        }
    }
    return s2;
}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


    string s=readString("Original String :\n");
    cout<<"Punctuations Removed: "<<endl<<removePunc(s);




    return 0;
}
