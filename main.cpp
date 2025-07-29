#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
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



int getDifferenceInDays(Period period,bool includeEndDate=false) {

    return getDifferenceInDays(period.startPeriod,period.endPeriod,includeEndDate);
}



int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    cout<<"Enter Period 1"<<endl;
    Period period1=readPeriod();



    cout<<"Period Length is : "<<getDifferenceInDays(period1)<<endl;
    cout<<"Period Length (Including End Date) is : "<<getDifferenceInDays(period1,true)<<endl;

    return 0;
}
