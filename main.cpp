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


int getNumberOfDays(int year) {
    return isLeapYear(year)? 366:365;
}

int getNumberOfHours(int year) {
    return getNumberOfDays(year)*24;
}

int getNumberOfMinutes(int year) {
    return getNumberOfHours(year)*60;
}


int getNumberOfSeconds(int year) {
    return getNumberOfMinutes(year)*60;
}

void printTimesOfYear(int year) {
    cout<<"Number of Days in Year "<<year<<" is "<<getNumberOfDays(year)<<endl;
    cout<<"Number of Hours in Year "<<year<<" is "<<getNumberOfHours(year)<<endl;
    cout<<"Number of Minutes in Year "<<year<<" is "<<getNumberOfMinutes(year)<<endl;
    cout<<"Number of Seconds in Year "<<year<<" is "<<getNumberOfSeconds(year)<<endl;
}





int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    printTimesOfYear(readInt("Please Enter a year to check"));










    return 0;
}
