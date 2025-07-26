#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"

using namespace myInputLib;

using namespace myMathLib;
using namespace std;



bool isLeapYear(short year) {
    return (year%100||year%400||year%4)==0;



}

void leapYear(short year) {
    isLeapYear(year)?cout<<year<<" is Leap Year"<<endl:cout<<year<<" is NOT LEAP year"<<endl;
}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    leapYear(readShort("Enter a Year"));










    return 0;
}
