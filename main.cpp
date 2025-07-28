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





int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    cout<<"Please Enter Your Date Of Birth"<<endl;
    stDate date1=readDate();
    stDate date2=readDate();

    cout<<"Difference is : "<<getDifferenceInDays(date1,date2)<<endl;;
    cout<<"Difference (including End Day) is :"<<getDifferenceInDays(date1,date2,true)<<endl;













    return 0;
}
