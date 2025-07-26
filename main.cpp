#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
#include "read_save_print_clientData.h"
using namespace fileClientData;

#include "myMathLibrary.h"
#include "myInputLibrary.h"

using namespace myInputLib;


using namespace myMathLib;
using namespace std;


void printLeapYearTimes(int year) {
    cout<<"Number of Days in Year "<<year<<" is 366"<<endl;
    cout<<"Number of Hours in Year "<<year<<" is 8784"<<endl;
    cout<<"Number of Minutes in Year "<<year<<" is 527040"<<endl;
    cout<<"Number of seconds in Year "<<year<<" is 31622400"<<endl;

}

void printYearTimes(int year) {
    cout<<"Number of Days in Year "<<year<<" is 365"<<endl;
    cout<<"Number of Hours in Year "<<year<<" is 8760"<<endl;
    cout<<"Number of Minutes in Year "<<year<<" is 525600"<<endl;
    cout<<"Number of seconds in Year "<<year<<" is 31536000"<<endl;

}

void printTimesOfYear(int year) {
    if (isLeapYear(year)) {
        printLeapYearTimes(year);
    }else {
        printYearTimes(year);
    }
}





int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    printTimesOfYear(readInt("Please Enter a year to check"));










    return 0;
}
