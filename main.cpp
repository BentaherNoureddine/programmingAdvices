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


int getNumberOfDaysInMonth(int year,short month) {
    if (month==2) {
        return isLeapYear(year)?29:28;
    }

    if (month%2==0) {
        return 30;
    }
    return 31;
}

int getNumberOfHoursInMonth(int year,short month) {
    return getNumberOfDaysInMonth(year,month)*24;
}

int getNumberOfMinutesInMonth(int year,short month) {
    return getNumberOfHoursInMonth(year,month)*60;
}


int getNumberOfSecondsInMonth(int year,short month) {
    return getNumberOfMinutesInMonth(year,month)*60;
}

void printTimesOfYear(int year,short month) {
    cout<<"Number of Days in Year "<<year<<" is "<<getNumberOfDaysInMonth(year,month)<<endl;
    cout<<"Number of Hours in Year "<<year<<" is "<<getNumberOfHoursInMonth(year,month)<<endl;
    cout<<"Number of Minutes in Year "<<year<<" is "<<getNumberOfMinutesInMonth(year,month)<<endl;
    cout<<"Number of Seconds in Year "<<year<<" is "<<getNumberOfSecondsInMonth(year,month)<<endl;
}





int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int year=readInt("Please Enter a year to check");
    short month =readShort("Please enter a Month to check");
    printTimesOfYear(year,month);










    return 0;
}
