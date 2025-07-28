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



stDate increaseDateByXDays(stDate &date,short nbDays) {

    for (short i=1;i<=nbDays;i++) {
      date=addOneDay(date);
    }
    return date;


}

stDate increaseDateByOneWeek(stDate &date) {
    return increaseDateByXDays(date,7);
}

stDate increaseDateByXWeek(stDate &date,short nbWeeks) {
    for (short i=1;i<=nbWeeks;i++) {
       date=increaseDateByOneWeek(date);
    }
    return date;

}

stDate increaseDateByOneMonth(stDate &date) {
    return increaseDateByXWeek(date,4);
}

stDate increaseDateByXMonth(stDate &date,short nbMonths) {
    for (short i=0;i<nbMonths;i++) {
        date=increaseDateByOneMonth(date);
    }
    return date;
}

stDate increaseDateByOneYear(stDate &date) {
    return increaseDateByXMonth(date,12);
}

stDate increaseDateByXYear(stDate &date,short nbYears) {

    for (short i=0;i<nbYears;i++) {
        date=increaseDateByOneYear(date);
    }
    return date;
}

stDate increaseDateByXYearFaster(stDate &date,short nbYears) {
    date.year+=nbYears;
    return date;
}

stDate increaseDateByOnceDecade(stDate &date) {
    return increaseDateByXYear(date,10);
}

stDate increaseDateByXDecade(stDate &date,short nbDecades) {
    for (short i=0;i<nbDecades;i++) {
        date=increaseDateByOnceDecade(date);
    }
    return date;
}

stDate increaseDateByXDecadesFaster(stDate &date,short nbDecades) {
    return increaseDateByXYearFaster(date,nbDecades*10);
}

stDate increaseDateByOnceCentury(stDate &date) {
    return increaseDateByXDecadesFaster(date,10);
}

stDate increaseDateByOneMillennium(stDate &date) {
    for (short i=0;i<10;i++) {
        date=increaseDateByOnceCentury(date);
    }
    return date;
}



void printAllIncreases(stDate date) {
    cout<<"Date After : "<<endl;
    cout<<"01-Adding one day is :"<<printDate(increaseDateByXDays(date,1));
    cout<<"02-Adding 10 days is :"<<printDate(increaseDateByXDays(date,10));
    cout<<"03-Adding one week is :"<<printDate(increaseDateByOneWeek(date));
    cout<<"04-Adding 10 weeks is :"<<printDate(increaseDateByXWeek(date,10));
    cout<<"05-Adding one month is :"<<printDate(increaseDateByOneMonth(date));
    cout<<"06-Adding 5 months is :"<<printDate(increaseDateByXMonth(date,5));
    cout<<"07-Adding one Year is :"<<printDate(increaseDateByOneYear(date));
    cout<<"08-Adding 10 years is :"<<printDate(increaseDateByXYear(date,10));
    cout<<"09-Adding 10 years (faster) is :"<<printDate(increaseDateByXYearFaster(date,10));
    cout<<"10-Adding one decade is :"<<printDate(increaseDateByOnceDecade(date));
    cout<<"11-Adding 10 decades is :"<<printDate(increaseDateByXDecade(date,10));
    cout<<"12-Adding 10 decades (faster) is :"<<printDate(increaseDateByXDecadesFaster(date,10));
    cout<<"13-Adding one Century is :"<<printDate(increaseDateByOnceCentury(date));
    cout<<"14-Adding one Millennium :"<<printDate(increaseDateByOneMillennium(date));

}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    stDate date=readDate();
    printAllIncreases(date);














    return 0;
}
