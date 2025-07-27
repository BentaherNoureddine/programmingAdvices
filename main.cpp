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



void convertDaysToDate(short day,short month,int year) {

    short nDays=numberOfDaysFromTo(day,month,year);
    short nMonth=1;

    while (true) {
        if (nDays>getNumberOfDaysInMonth(year,nMonth)) {
            nDays-=getNumberOfDaysInMonth(year,nMonth);
             nMonth++;


        }else {
            break;
        }
    }
    cout<<nDays<<"/"<<nMonth<<"/"<<year;


}



int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    short day=readShort("Please Enter a Day ");
    int month=readShort("Please Enter a Month ");
    int year=readInt("Please Enter a year ");

    convertDaysToDate(day,month,year);










    return 0;
}
