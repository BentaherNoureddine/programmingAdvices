#pragma once
#include <iostream>

#include "read_save_print_clientData.h"
using namespace std;

namespace MyLib{


  void test(){
    cout <<"Hello from MyLib!" << endl;
  }

  string removePuncFromString(string s) {

    string s2;
    bool n;
    for (short i=0;i<s.length();i++) {
      if (std::ispunct(s[i])==false) {
        s2+=s[i];
      }
    }
    return s2;
  }

  int getNumberOfDaysInMonth(int year,short month) {
    if (month<1||month>12) {
      return 0;
    }
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month==2)?(__isleap(year)?29:28):days[month-1];
  }

  int getNumberOfHoursInMonth(int year,short month) {
    return getNumberOfDaysInMonth(year,month)*24;
  }

  int getNumberOfMinutesInMonth(int year,short month) {
    return getNumberOfHoursInMonth(year,month)*60;
  }


  int getNumberOfSecondsInMonth(int year,short month) {
    return getNumberOfMinutesInMonth(year,month)*60;
  }

  void printTimesOfYear(int year,short month) {
    cout<<"Number of Days in Year "<<year<<" is "<<getNumberOfDaysInMonth(year,month)<<endl;
    cout<<"Number of Hours in Year "<<year<<" is "<<getNumberOfHoursInMonth(year,month)<<endl;
    cout<<"Number of Minutes in Year "<<year<<" is "<<getNumberOfMinutesInMonth(year,month)<<endl;
    cout<<"Number of Seconds in Year "<<year<<" is "<<getNumberOfSecondsInMonth(year,month)<<endl;
  }



  string getDate(int year,short month,short day) {
    return to_string(day)+"/"+to_string(month)+"/"+to_string(year);
  }


  short getDayNumber(short day, short month, int year) {
    short a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
  }


  void  getDayOrderAndName(int year,short month,short day) {
    string days[]={"Sun","Mon","Tue","Wed","Thir","Fri","Satur",};


    cout<<"Day order :"<<getDayNumber(day,month,year)<<endl;
    cout<<"Day Name  :"<<days[getDayNumber(day,month,year)];


  }


  void dayNameOfWeek(int year,short month,short day) {

    cout<<"Date      :"<<getDate(year,month,day)<<endl;
    getDayOrderAndName(year,month,day);
  }



void fillFirstWeek(short calender[5][7],short firstDay) {

    for (short i=0;i<7;i++) {
        if (i<firstDay) {
            calender[0][i]=0;
        }
    }
    short j=1;
    for (short i=firstDay;i<7;i++) {
        calender[0][i]=j++;
    }

}

void fillWeeks(short calender[5][7],short numberOfDays) {
    short counter=calender[0][6];
    for (short i=1;i<=4;i++) {
        for (short j=0;j<7;j++) {
            if (counter+1>numberOfDays) {
                break;
            }
            calender[i][j]=++counter;
        }
    }
}

void fillRestOfTheWeek(short calender[5][7],short month,int year) {
    if (calender[4][6]!=getNumberOfDaysInMonth(year,month)) {
        for (short j=6;j>getDayNumber(getNumberOfDaysInMonth(year,month),month,year);j--) {
            calender[4][j]=0;
        }
    }


}



void printCalender(short calender[5][7]) {
    for (short i=0;i<5;i++) {
        cout<<"\t\t";
        for (short j=0;j<7;j++) {
            if (calender[i][j]==0) {
                cout<<" \t\t";
            }else {
                cout<<calender[i][j]<<"\t\t";
            }

        }
        cout<<endl;
    }
}




void printDaysOfMonth(int year,short month) {
    int numberOfDays= getNumberOfDaysInMonth(year,month);
    short firstDay=getDayNumber(1,month,year);
    short calender[5][7];
    calender[0][firstDay-1]=1;
    fillFirstWeek(calender,firstDay);
    fillWeeks(calender,numberOfDays);
    fillRestOfTheWeek(calender,month,year);
    printCalender(calender);
}


string getMonthName(short month) {
    string months[]={"","Jan","Fev","Mar","Apr","Mai","Jun","Jul","aug","Sep","Oct","Nov","Dec"};
    return months[month];
}


void monthCalendar(int year,short month) {

    cout<<"\t\t________________________________"<<getMonthName(month)<<"________________________________\n"<<endl;
    cout<<"\t\tSun\t\tMon\t\tTue\t\tWed\t\tThu\t\tFri\t\tSat"<<endl;
    printDaysOfMonth(year,month);
    cout<<"\t\t__________________________________________________________________________________________\n\n"<<endl;


}


    void yearCalendar(int year) {

      cout<<"\t\t_____________________________________________________________\n"<<endl;
      cout<<"\t\t\t\t\tCalendar - "<<year<<endl;
      cout<<"\t\t_____________________________________________________________\n"<<endl;
      for (short i=1;i<=12;i++) {
          monthCalendar(year,i);
      }


  }

    int numberOfDaysFromTo(short day,short month,int year) {

      int totalDays=0;
      for (short i=1;i<=month-1;i++) {
          totalDays+=getNumberOfDaysInMonth(year,month);
      }
      totalDays+=day;
      return  totalDays;
  }









  

}