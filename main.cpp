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


short numberOfVacationDays(stDate startVoc,stDate endVoc) {

    short days=0;
    while (compareDates(startVoc,endVoc)) {
        if (isBusinessDay(startVoc)) {
            days++;
            startVoc=increaseDateByXDays(startVoc,1);
        }else {
            startVoc=increaseDateByXDays(startVoc,1);
        }
    }
    return days;

}




int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    cout<<"Vacation Starts :"<<endl;
    stDate startVac=readDate();
    cout<<"Vacation Ends : "<<endl;
    stDate endVac=readDate();
    cout<<"Vacation from : "<<getDayString(startVac)<<endl;
    cout<<"Vacation To : "<<getDayString(endVac)<<endl;
    cout<<"\n\n\n Actual Vacation days is : "<<numberOfVacationDays(startVac,endVac)<<endl;





    return 0;
}
