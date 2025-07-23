#include <iomanip>
#include <iostream>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"
using namespace myInputLib;

using namespace myMathLib;
using namespace std;


string getWord(string str,string sep) {

   return str.substr(0,str.find(sep));
}


void fillVectorWithStrings(vector<string>& vStrings,string str,string sep) {

    while (str.find(sep)!=string::npos) {

        vStrings.push_back(getWord(str,sep));
        str=str.substr(str.find(sep)+1,str.length());
        if (str.find(sep)==string::npos) {
            vStrings.push_back(str);
            break;
        }



    }
}

vector<string> reverseVector(vector<string>& vStrings) {

    vector<string> vString2;

    for (short i=vStrings.size()-1;i>=0;i--) {
        vString2.push_back(vStrings[i]);
    }
    return vString2;
}

void printVector(vector<string> vStrings) {

    for (string& str :vStrings ) {
        cout<<str<<" ";
    }
}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


    vector<string> vNames;
    fillVectorWithStrings(vNames,readString("Please Enter your String")," ");
    vNames=reverseVector(vNames);
    printVector(vNames);

    return 0;
}
