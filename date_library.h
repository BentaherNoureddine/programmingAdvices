#pragma once


namespace dateLib{




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
    bool isLeapYear(short year) {
      return (year%4==0 && year%400==0)||year%100==0;
  }

    void leapYear(short year) {
      isLeapYear(year)?cout<<year<<" is Leap Year"<<endl:cout<<year<<" is NOT LEAP year"<<endl;
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


    void addDaysToDate(short day,short month,int year,short daysToAdd) {

      short nDays=numberOfDaysFromTo(day,month,year)+daysToAdd;
      short nMonth=1;

      while (true) {
          if (nDays>getNumberOfDaysInMonth(year,nMonth)) {
              nDays-=getNumberOfDaysInMonth(year,nMonth);
              if (nMonth+1==13) {
                  nMonth=1;
                  year++;
              }else {
                  nMonth++;
              }
          }else {
              break;
          }
      }
      cout<<nDays<<"/"<<nMonth<<"/"<<year;


  }
    struct stDate {
      short day;
      short month;
      int   year;
  };

    bool equalDates(stDate date1,stDate date2) {

        return (date1.year==date2.year)&&(date1.month==date2.month)&&(date1.day==date2.day);

    }

    bool compareDates(stDate date1,stDate date2) {

      return (date2.year>date1.year)?true:(date2.month>date1.month)?true:(date2.day>date1.day)&&(!equalDates(date1,date2));
  }



    stDate readDate() {
        stDate date;
        date.day=readShort("please enter a day");
        date.month=readShort("please enter a month");
        date.year=readInt("please enter a year");
        cout<<endl;
        return date;
    }




    bool latDayInMonth(stDate date) {
        return getNumberOfDaysInMonth(date.year,date.month)==date.day;
    }
    bool lastMonthInYear(stDate date) {
        return date.month==12;
    }

    void lastDayLastMonth(stDate date) {

        latDayInMonth(date)?cout<<"Yes, Day is Last Day in Month."<<endl:cout<<"No, Day is Not Last Day in Month."<<endl;


        lastMonthInYear(date)?cout<<"Yes, Month is Last Month in Year.":cout<<"No, Month is NOT last Month in Year."<<endl;
    }

    stDate addOneDay(stDate date) {

        stDate date1=date;
        if (latDayInMonth(date)&&lastMonthInYear(date)) {
            date1.day=1;
            date1.month=1;
            date1.year++;
        }
        else if (latDayInMonth(date1)) {
            date1.day=1;
            date1.month++;
        }else {
            date1.day++;
        }
        return date1;
    }

    void readDate1LessThanDate2(stDate& date1,stDate& date2) {

        date1 =readDate();

        do {
            date2=readDate();
        }while (!compareDates(date1,date2));
    }




    int getDifferenceInDays(stDate date1,stDate date2,bool endDay=false) {

        short days=0;
        if (compareDates(date1,date2)) {
            while (compareDates(date1,date2)) {
                date1=addOneDay(date1);
                days++;
            }
            return endDay?++days:days;
        }
        while (compareDates(date2,date1)) {
            date2=addOneDay(date2);
            days++;
        }
        return endDay?(++days*-1):(days*-1);

    }

    short getAgeInDays(stDate dateOfBirth) {
        time_t t=time(0);
        tm* now=localtime(&t);

        stDate currentDate;
        currentDate.day=   now->tm_mday;
        currentDate.month=now->tm_mon+1;
        currentDate.year=now->tm_year+1900;
        return getDifferenceInDays(dateOfBirth,currentDate);
    }



        string getDateString(stDate date) {
           return to_string(date.day)+"/"+to_string(date.month)+"/"+to_string(date.year)+"\n";
        }




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
    cout<<"01-Adding one day is :"<<getDateString(increaseDateByXDays(date,1));
    cout<<"02-Adding 10 days is :"<<getDateString(increaseDateByXDays(date,10));
    cout<<"03-Adding one week is :"<<getDateString(increaseDateByOneWeek(date));
    cout<<"04-Adding 10 weeks is :"<<getDateString(increaseDateByXWeek(date,10));
    cout<<"05-Adding one month is :"<<getDateString(increaseDateByOneMonth(date));
    cout<<"06-Adding 5 months is :"<<getDateString(increaseDateByXMonth(date,5));
    cout<<"07-Adding one Year is :"<<getDateString(increaseDateByOneYear(date));
    cout<<"08-Adding 10 years is :"<<getDateString(increaseDateByXYear(date,10));
    cout<<"09-Adding 10 years (faster) is :"<<getDateString(increaseDateByXYearFaster(date,10));
    cout<<"10-Adding one decade is :"<<getDateString(increaseDateByOnceDecade(date));
    cout<<"11-Adding 10 decades is :"<<getDateString(increaseDateByXDecade(date,10));
    cout<<"12-Adding 10 decades (faster) is :"<<getDateString(increaseDateByXDecadesFaster(date,10));
    cout<<"13-Adding one Century is :"<<getDateString(increaseDateByOnceCentury(date));
    cout<<"14-Adding one Millennium :"<<getDateString(increaseDateByOneMillennium(date));

}

    stDate decreaseDateByOneDay(stDate &date) {

    if (date.day==1) {
        //  1/1/2000
        if (date.month==1) {
            date.year--;
            date.month=12;
            date.day=getNumberOfDaysInMonth(date.year,date.month);
        }else {
            date.month--;
            date.day=getNumberOfDaysInMonth(date.year,date.month);
        }
        return date;
    }
    date.day--;
    return date;
}

stDate decreaseDateByXDays(stDate &date,short nbDays) {
    for (short i=0;i<nbDays;i++) {
        date=decreaseDateByOneDay(date);
    }
    return date;

}

stDate decreaseDateByOneWeek(stDate &date) {
    return decreaseDateByXDays(date,7);
}

stDate decreaseDateByXWeeks(stDate &date,short nbWeeks) {

    for (short i=0;i<nbWeeks;i++) {
        date=decreaseDateByOneWeek(date);
    }

    return date;
}

stDate decreaseDateByOneMonth(stDate &date) {
    return decreaseDateByXWeeks(date,4);
}

stDate decreaseDateByXMonths(stDate date,short nbMonths) {
    for (short i=0;i<nbMonths;i++) {
        date=decreaseDateByOneMonth(date);
    }
    return date;
}

stDate decreaseDateByOneYear(stDate date) {
    return decreaseDateByXMonths(date,12);
}

stDate decreaseDateByXYears(stDate date,short nbYears) {

    for (short i=0;i<nbYears;i++) {
        date=decreaseDateByOneYear(date);
    }
    return date;
}

stDate decreaseDateByXYearsFaster(stDate date,short nbYears) {
    date.year-=nbYears;
    return date;
}

stDate decreaseDateByOneDecade(stDate date) {
    return decreaseDateByXYears(date,10);
}

stDate decreaseDateByXDecades(stDate date,short nbDecades) {
    for (short i=0;i<nbDecades;i++){
        date=decreaseDateByOneDecade(date);
    }
    return date;
}

stDate decreaseDateByXDecadesFaster(stDate date,short nbDecades) {
    date.year-=nbDecades*10;
    return date;
}

stDate decreaseDateByOneCentury(stDate date) {
    return decreaseDateByXDecades(date,10);
}

stDate decreaseDateByOneMillennium(stDate date) {
    for (short i=0;i<10;i++) {
        date=decreaseDateByOneCentury(date);
    }
    return date;
}


void printAllDecreases(stDate date) {
    cout<<"Date After : "<<endl;
    cout<<"01-subtracting one day is :"<<getDateString(decreaseDateByXDays(date,1));
    cout<<"02-subtracting 10 days is :"<<getDateString(decreaseDateByXDays(date,10));
    cout<<"03-subtracting one week is :"<<getDateString(decreaseDateByOneWeek(date));
    cout<<"04-subtracting 10 weeks is :"<<getDateString(decreaseDateByXWeeks(date,10));
    cout<<"05-subtracting one month is :"<<getDateString(decreaseDateByOneMonth(date));
    cout<<"06-subtracting 5 months is :"<<getDateString(decreaseDateByXMonths(date,5));
    cout<<"07-subtracting one Year is :"<<getDateString(decreaseDateByOneYear(date));
    cout<<"08-subtracting 10 years is :"<<getDateString(decreaseDateByXYears(date,10));
    cout<<"09-subtracting 10 years (faster) is :"<<getDateString(decreaseDateByXYearsFaster(date,10));
    cout<<"10-subtracting one decade is :"<<getDateString(decreaseDateByOneDecade(date));
    cout<<"11-subtracting 10 decades is :"<<getDateString(decreaseDateByXDecades(date,10));
    cout<<"12-subtracting 10 decades (faster) is :"<<getDateString(decreaseDateByXDecadesFaster(date,10));
    cout<<"13-subtracting one Century is :"<<getDateString(decreaseDateByOneCentury(date));
    cout<<"14-subtracting one Millennium :"<<getDateString(decreaseDateByOneMillennium  (date));

}





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
        return getDayNumber(date)==6;
    }

    bool isWeekEnd(stDate date) {
        return getDayNumber(date)==5;
    }

    bool isBusinessDay(stDate date) {
        return !(isEndOfWeek(date)||isWeekEnd(date));
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

    string getDayString(stDate date) {
        string days[]={"Sun","Mon","Tue","Wed","Thir","Fri","Satur",};

        return "Today is "+days[getDayNumber(date)]+" , "+getDateString(date);
    }




    short numberOfVacationDays(stDate startVoc,stDate endVoc) {

        short days=0;
        while (compareDates(startVoc,endVoc)) {
            if (isBusinessDay(startVoc))
                days++;
            startVoc=increaseDateByXDays(startVoc,1);
        }

        return days;

    }

    stDate getReturnDate(stDate startVacDate,short numVacDays) {

        while (numVacDays>0) {
            if (isBusinessDay(startVacDate)) {
                increaseDateByXDays(startVacDate,1);
                numVacDays--;
            }else {
                increaseDateByXDays(startVacDate,1);
            }
        }
        return startVacDate;
    }

    bool isDate1AfterDate2(stDate date1,stDate date2) {
        return !compareDates(date1,date2)&&!equalDates(date1,date2);
    }


    struct Period {
        stDate startPeriod;
        stDate endPeriod;
    };


    short compareDatesAndGetShort(stDate date1,stDate date2) {

        return equalDates(date1,date2)?0:compareDates(date1,date2)?-1:1;
    }


    bool overlap(Period period1, Period period2) {

        return !(compareDatesAndGetShort(period2.endPeriod,period1.startPeriod)==-1||compareDatesAndGetShort(period2.startPeriod,period1.endPeriod)==1);

    }
    Period readPeriod() {
        Period period;
        cout<<"Enter Start Date"<<endl;
        period.startPeriod=readDate();
        cout<<"\n Enter ENd Date"<<endl;
        period.endPeriod=readDate();
        return  period;
    }

    int getDifferenceInDays(Period period,bool includeEndDate=false) {

        return getDifferenceInDays(period.startPeriod,period.endPeriod,includeEndDate);
    }


    enum enCompareDate {
        equal=0,before=-1,after=1,
    };


    bool isDateInPeriod(stDate date,Period period) {
        return !(compareDatesAndGetShort(date,period.startPeriod)==enCompareDate::before||compareDatesAndGetShort(date,period.endPeriod)==enCompareDate::after);
    }





    short getOverlapDaysCount(Period period1,Period period2) {

        short overlapCount=0;
        short period1Length =getDifferenceInDays(period1.startPeriod,period1.endPeriod);
        short period2Length =getDifferenceInDays(period2.startPeriod,period2.endPeriod);

        if (!overlap(period1,period2)) {
            return 0;
        }

        if (period1Length<period2Length) {
            while (!equalDates(period1.startPeriod,period1.endPeriod)) {
                if (isDateInPeriod(period1.startPeriod,period2)) {
                    overlapCount++;
                }
                period1.startPeriod=increaseDateByXDays(period1.startPeriod,1);
            }
        }else {
            while (!equalDates(period2.startPeriod,period1.endPeriod)) {
                if (isDateInPeriod(period2.startPeriod,period1)) {
                    overlapCount++;
                }
                period2.startPeriod=increaseDateByXDays(period2.startPeriod,1);
            }
        }


        return overlapCount;
    }


    bool validateDate(stDate date) {

        if (date.year<1) {
            return false;
        }

        if (date.month>12||date.month<1) {
            return false;

        }
        if (date.day>getNumberOfDaysInMonth(date.year,date.month)||date.day<1) {
            return false;
        }
        return true;

    }


    stDate getDateFromString(string str) {
        vector<string>vStrings;
        fileClientData::fillVectorWithStrings(vStrings,str,"/");

        stDate date;
        date.day=static_cast<short>(std::stoi(vStrings[0]));
        date.month=static_cast<short>(std::stoi(vStrings[1]));
        date.year=std::stoi(vStrings[2]);
        return date;
    }


    string formatDate(stDate date,string format) {

        format.replace(format.find("dd"),2,to_string(date.day));
        format.replace(format.find("mm"),2,to_string(date.month));
        format.replace(format.find("yyyy"),4,to_string(date.year));
        return format;
    }


}