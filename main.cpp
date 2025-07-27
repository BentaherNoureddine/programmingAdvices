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


void yearCalendar(int year) {

    cout<<"\t\t_____________________________________________________________\n"<<endl;
    cout<<"\t\t\t\t\tCalendar - "<<year<<endl;
    cout<<"\t\t_____________________________________________________________\n"<<endl;
    for (short i=1;i<=12;i++) {
        monthCalendar(year,i);
    }


}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int year=readInt("Please Enter a year ");

    yearCalendar(year);










    return 0;
}
