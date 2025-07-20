#include <iomanip>
#include <iostream>
#include "myMathLibrary.h"
#include "myInputLibrary.h"
using namespace myInputLib;

using namespace myMathLib;
using namespace std;




char invertChar(char c) {

    return isupper(c)? tolower(c):toupper(c);
}

void invertString(string& word) {

    for (int i=0;i<word.length();i++) {
        word[i]=invertChar(word[i]);
    }
}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    string str = readString("Please enter your string");
    invertString(str);
    cout<< "String after conversion"<<endl;
    cout<<str;



    return 0;
}
