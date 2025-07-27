#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

#include "myLibrary.h"
#include "read_save_print_clientData.h"
using namespace fileClientData;

#include "myMathLibrary.h"
#include "myInputLibrary.h"

using namespace myInputLib;
using namespace MyLib;

using namespace myMathLib;
using namespace std;




void numberOfDaysFromTo(short day,short month,int year) {

    int totalDays=0;
    for (short i=1;i<=month-1;i++) {
        totalDays+=getNumberOfDaysInMonth(year,month);
    }
    totalDays+=day;
    cout<<"Number of Days from the beginning of the year is "<<totalDays;
}



int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    short day=readShort("Please Enter a Day ");
    int month=readShort("Please Enter a Month ");
    int year=readInt("Please Enter a year ");

    numberOfDaysFromTo(day,month,year);










    return 0;
}
