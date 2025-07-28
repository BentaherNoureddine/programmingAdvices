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



void lastDayLastMonth(stDate date) {

    date.day==getNumberOfDaysInMonth(date.year,date.month)?cout<<"Yes, Day is Last Day in Month."<<endl:cout<<"No, Day is Not Last Day in Month."<<endl;


    date.month==12?cout<<"Yes, Month is Last Month in Year.":cout<<"No, Month is NOT last Month in Year."<<endl;
}





int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    stDate date1=readDate();
    lastDayLastMonth(date1);













    return 0;
}
