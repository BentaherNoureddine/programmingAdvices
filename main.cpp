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



stDate getToday() {
    time_t t=time(0);
    tm* now=localtime(&t);

    stDate currentDate;
    currentDate.day=   now->tm_mday;
    currentDate.month=now->tm_mon+1;
    currentDate.year=now->tm_year+1900;
    return currentDate;
}

short getDayNumber(stDate date) {
    short a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + 12 * a - 2;

    return (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

bool isEndOfWeek(stDate date) {
    return getDayNumber(date)==7;
}

bool isWeekEnd(stDate date) {
    return getDayNumber(date)==6;
}

bool isBusinessDay(stDate date) {
    return !(isEndOfWeek(date)&&isWeekEnd(date));
}

short daysUntilTheEndOfWeek(stDate date) {
    short days=0;
    for (short i=getDayNumber(date);i<7;i++) {
        days++;
    }
    return days;
}

short daysUntilTheEndOfMonth(stDate date) {
    return getNumberOfDaysInMonth(date.year,date.month)-date.day;
}

short daysUntilTheEndOfYear(stDate date) {

    stDate endOfYear;
    endOfYear.year=date.year;
    endOfYear.month=12;
    endOfYear.day=31;
    short days=0;
    while (compareDates(date,endOfYear)) {
        days++;
        increaseDateByXDays(date,1);
    }
    return days;


}

string getTodayString(stDate date) {
    string days[]={"Sun","Mon","Tue","Wed","Thir","Fri","Satur",};

    return "Today is "+days[getDayNumber(date)]+" , "+printDate(date);
}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    stDate date=getToday();

    cout<<getTodayString(date);

    cout<<"is it end of week?"<<endl;
    isEndOfWeek(date)?cout<<"Yes it's end of week."<<endl:cout<<"No it s NOT end of week."<<endl;

    cout<<"is it weekend?"<<endl;
    isWeekEnd(date)?cout<<"Yes it's weekend."<<endl:cout<<"No it s NOT weekend."<<endl;


    cout<<"is it Business Day?"<<endl;
    isBusinessDay(date)?cout<<"Yes it's Business day."<<endl:cout<<"No it s NOT a business day."<<endl;

    cout<<"Days until end of week "<<daysUntilTheEndOfWeek(date)<<" Day(s)"<<endl;
    cout<<"Days until end of month "<<daysUntilTheEndOfMonth(date)<<" Day(s)"<<endl;
    cout<<"Days until end of year "<<daysUntilTheEndOfYear(date)<<" Day(s)"<<endl;



    return 0;
}
