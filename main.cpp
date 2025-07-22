#include <iomanip>
#include <iostream>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"
using namespace myInputLib;

using namespace myMathLib;
using namespace std;





string trimLeft(string s) {


    for (short i=0;i<s.length();i++) {
        if (s[i]!=' ') {
            return s.substr(i,s.length()-i);
        }
    }
    return "";
}


string trimRight(string s) {
    for (short i=s.length()-1;i>=0;i--) {
        if (s[i]!=' ') {
            return s.substr(0,i+1);
        }
    }
    return "";
}

void trim(string& s) {

    s=trimLeft(s);
    s=trimRight(s);
}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


    string s = readString("Enter a string");
    cout <<"String ="<<s<<endl;
    cout <<"Trim left ="<<trimLeft(s)<<endl;
    cout <<"Trim Right ="<<trimRight(s)<<endl;
    cout <<"Trim =";
    trim(s);
    cout <<s;



    return 0;
}
