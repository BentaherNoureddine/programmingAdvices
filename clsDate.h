// ProgrammingAdivces.com
// Mohammed Abu-Hadhoud
#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdio>
#include "clsString.h"

using namespace std;

class clsDate
{
private:
    short _Day   = 1;
    short _Month = 1;
    short _Year  = 1900;

public:
    // === Ctors ===
    clsDate()
    {
        time_t t = time(nullptr);
        tm* now  = localtime(&t);
        setDay(static_cast<short>(now->tm_mday));
        setMonth(static_cast<short>(now->tm_mon + 1));
        setYear(static_cast<short>(now->tm_year + 1900));
    }

    clsDate(string sDate)
    {
        vector<string> vDate = clsString::Split(sDate, "/");
        setDay(static_cast<short>(stoi(vDate[0])));
        setMonth(static_cast<short>(stoi(vDate[1])));
        setYear(static_cast<short>(stoi(vDate[2])));
    }

    clsDate(short Day, short Month, short Year)
    {
        setDay(Day);
        setMonth(Month);
        setYear(Year);
    }

    // Construct from day-order in year
    clsDate(short DateOrderInYear, short Year)
    {
        clsDate d = getDateFromDayOrderInYear(DateOrderInYear, Year);
        setDay(d.getDay());
        setMonth(d.getMonth());
        setYear(d.getYear());
    }

    // === Accessors ===
    void  setDay(short Day)     { _Day = Day; }
    short getDay()        const { return _Day; }

    void  setMonth(short Month) { _Month = Month; }
    short getMonth()      const { return _Month; }

    void  setYear(short Year)   { _Year = Year; }
    short getYear()       const { return _Year; }

    // === I/O ===
    static string dateToString(const clsDate& Date)
    {
        return to_string(Date.getDay()) + "/" +
               to_string(Date.getMonth()) + "/" +
               to_string(Date.getYear());
    }

    string dateToString() const { return dateToString(*this); }

    void print() const { cout << dateToString() << endl; }

    static clsDate getSystemDate()
    {
        time_t t = time(nullptr);
        tm* now  = localtime(&t);

        short y = static_cast<short>(now->tm_year + 1900);
        short m = static_cast<short>(now->tm_mon + 1);
        short d = static_cast<short>(now->tm_mday);

        return clsDate(d, m, y);
    }

    // === Validation & calendar facts ===
    static bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear() const { return isLeapYear(getYear()); }

    static short numberOfDaysInaMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12) return 0;
        static const short days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    short numberOfDaysInaMonth() const
    {
        return numberOfDaysInaMonth(getMonth(), getYear());
    }

    static short numberOfDaysInaYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365; // fixed
    }

    short numberOfDaysInaYear() const { return numberOfDaysInaYear(getYear()); }

    static int numberOfHoursInAYear(short Year)
    {
        return numberOfDaysInaYear(Year) * 24;
    }

    int numberOfHoursInAYear() const { return numberOfHoursInAYear(getYear()); }

    static int numberOfMinutesInAYear(short Year)
    {
        return numberOfHoursInAYear(Year) * 60;
    }

    int numberOfMinutesInAYear() const { return numberOfMinutesInAYear(getYear()); }

    static long long numberOfSecondsInAYear(short Year)
    {
        return static_cast<long long>(numberOfMinutesInAYear(Year)) * 60;
    }

    long long numberOfSecondsInAYear() const
    {
        return numberOfSecondsInAYear(getYear()); // fixed (no recursion)
    }

    static short numberOfHoursInAMonth(short Month, short Year)
    {
        return numberOfDaysInaMonth(Month, Year) * 24;
    }

    short numberOfHoursInAMonth() const
    {
        return numberOfDaysInaMonth(getMonth(), getYear()) * 24;
    }

    static int numberOfMinutesInAMonth(short Month, short Year)
    {
        return numberOfHoursInAMonth(Month, Year) * 60;
    }

    int numberOfMinutesInAMonth() const
    {
        return numberOfHoursInAMonth(getMonth(), getYear()) * 60;
    }

    static int numberOfSecondsInAMonth(short Month, short Year)
    {
        return numberOfMinutesInAMonth(Month, Year) * 60;
    }

    int numberOfSecondsInAMonth() const
    {
        return numberOfMinutesInAMonth(getMonth(), getYear()) * 60;
    }




    // === Day-of-week & names ===
    static short dayOfWeekOrder(short Day, short Month, short Year)
    {
        short a = static_cast<short>((14 - Month) / 12);
        int y = Year - a;
        int m = Month + (12 * a) - 2;
        // 0=Sun,1=Mon,...6=Sat
        return static_cast<short>((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
    }

    short dayOfWeekOrder() const
    {
        return dayOfWeekOrder(getDay(), getMonth(), getYear());
    }

    static string dayShortName(short DayOfWeekOrder)
    {
        static const string arrDayNames[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
        return arrDayNames[DayOfWeekOrder];
    }

    static string dayShortName(short Day, short Month, short Year)
    {
        return dayShortName(dayOfWeekOrder(Day, Month, Year));
    }

    string dayShortName() const { return dayShortName(getDay(), getMonth(), getYear()); }

    static string monthShortName(short MonthNumber)
    {
        static const string Months[12] =
            {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        return Months[MonthNumber - 1];
    }

    string monthShortName() const { return monthShortName(getMonth()); }







    // === Calendars ===
    static void printMonthCalendar(short Month, short Year)
    {
        int current = dayOfWeekOrder(1, Month, Year);
        int NumberOfDays = numberOfDaysInaMonth(Month, Year);

        printf("\n  _______________%s_______________\n\n", monthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (int i = 0; i < current; ++i) printf("     ");

        int i = current;
        for (int d = 1; d <= NumberOfDays; ++d)
        {
            printf("%5d", d);
            if (++i == 7) { i = 0; printf("\n"); }
        }
        printf("\n  _________________________________\n");
    }

    void printMonthCalendar() const { printMonthCalendar(getMonth(), getYear()); }

    static void PrintYearCalendar(int Year)
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");
        for (int m = 1; m <= 12; ++m) printMonthCalendar(static_cast<short>(m), static_cast<short>(Year));
    }

    void printYearCalendar() const { PrintYearCalendar(getYear()); }

    // === Date math ===
    static short daysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {
        short total = 0;
        for (short m = 1; m <= Month - 1; ++m)
            total = static_cast<short>(total + numberOfDaysInaMonth(m, Year));
        return static_cast<short>(total + Day);
    }

    short daysFromTheBeginingOfTheYear() const
    {
        return daysFromTheBeginingOfTheYear(getDay(), getMonth(), getYear());
    }

    static clsDate getDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate d(1, 1, Year);
        short remaining = DateOrderInYear;

        while (true)
        {
            short md = numberOfDaysInaMonth(d.getMonth(), Year);
            if (remaining > md)
            {
                remaining = static_cast<short>(remaining - md);
                d.setMonth(static_cast<short>(d.getMonth() + 1));
            }
            else
            {
                d.setDay(remaining);
                break;
            }
        }
        return d;
    }

    void AddDays(short Days)
    {
        short remaining = static_cast<short>(Days + daysFromTheBeginingOfTheYear(getDay(), getMonth(), getYear()));
        setMonth(1);

        while (true)
        {
            short md = numberOfDaysInaMonth(getMonth(), getYear());
            if (remaining > md)
            {
                remaining = static_cast<short>(remaining - md);
                setMonth(static_cast<short>(getMonth() + 1));

                if (getMonth() > 12)
                {
                    setMonth(1);
                    setYear(static_cast<short>(getYear() + 1));
                }
            }
            else
            {
                setDay(remaining);
                break;
            }
        }
    }










    // === comarisons ===
    static bool isDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        if (Date1.getYear() != Date2.getYear())
            return Date1.getYear() < Date2.getYear();
        if (Date1.getMonth() != Date2.getMonth())
            return Date1.getMonth() < Date2.getMonth();
        return Date1.getDay() < Date2.getDay();
    }

    bool isDateBeforeDate2(clsDate Date2) { return isDate1BeforeDate2(*this, Date2); }

    static bool isDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return Date1.getYear() == Date2.getYear() &&
               Date1.getMonth() == Date2.getMonth() &&
               Date1.getDay() == Date2.getDay();
    }

    bool isDateEqualDate2(clsDate Date2) { return isDate1EqualDate2(*this, Date2); }

    static bool isDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return !isDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2);
    }

    bool isDateAfterDate2(clsDate Date2) { return isDate1AfterDate2(*this, Date2); }

    enum enDatecomare { Before = -1, Equal = 0, After = 1 };

    static enDatecomare comareDates(clsDate Date1, clsDate Date2)
    {
        if (isDate1BeforeDate2(Date1, Date2)) return enDatecomare::Before;
        if (isDate1EqualDate2(Date1, Date2))  return enDatecomare::Equal;
        return enDatecomare::After;
    }

    enDatecomare comareDates(clsDate Date2) { return comareDates(*this, Date2); }

    // === Utils ===
    static bool isLastDayinMonth(clsDate Date)
    {
        return Date.getDay() == numberOfDaysInaMonth(Date.getMonth(), Date.getYear());
    }

    bool isLastDayinMonth() { return isLastDayinMonth(*this); }

    static bool isLastMonthinYear(short Month) { return Month == 12; }

    static clsDate AddOneDay(clsDate Date)
    {
        if (isLastDayinMonth(Date))
        {
            if (isLastMonthinYear(Date.getMonth()))
            {
                Date.setMonth(1);
                Date.setDay(1);
                Date.setYear(static_cast<short>(Date.getYear() + 1));
            }
            else
            {
                Date.setDay(1);
                Date.setMonth(static_cast<short>(Date.getMonth() + 1));
            }
        }
        else
        {
            Date.setDay(static_cast<short>(Date.getDay() + 1));
        }
        return Date;
    }

    void addOneDay() { *this = AddOneDay(*this); }

    static void swapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate tmp = Date1;
        Date1 = Date2;
        Date2 = tmp;
    }

    static int getDifferenceinDays(clsDate Date1, clsDate Date2, bool includeEndDay = false)
    {
        int days = 0;
        short sign = 1;

        if (!isDate1BeforeDate2(Date1, Date2))
        {
            swapDates(Date1, Date2);
            sign = -1;
        }

        while (isDate1BeforeDate2(Date1, Date2))
        {
            ++days;
            Date1 = AddOneDay(Date1);
        }

        return includeEndDay ? (days + 1) * sign : days * sign;
    }

    int getDifferenceinDays(clsDate Date2, bool includeEndDay = false)
    {
        return getDifferenceinDays(*this, Date2, includeEndDay);
    }

    static short calculateMyAgeinDays(clsDate DateOfBirth)
    {
        return static_cast<short>(getDifferenceinDays(DateOfBirth, clsDate::getSystemDate(), true));
    }

    // === increase helpers ===
    static clsDate increaseDateByOneWeek(clsDate& Date)
    {
        for (int i = 0; i < 7; ++i) Date = AddOneDay(Date);
        return Date;
    }

    void increaseDateByOneWeek() { increaseDateByOneWeek(*this); }

    static clsDate increaseDateByXWeeks(short Weeks, clsDate& Date)
    {
        for (short i = 0; i < Weeks; ++i) Date = increaseDateByOneWeek(Date);
        return Date;
    }

    void increaseDateByXWeeks(short Weeks) { increaseDateByXWeeks(Weeks, *this); }

    static clsDate increaseDateByOneMonth(clsDate& Date)
    {
        if (Date.getMonth() == 12)
        {
            Date.setMonth(1);
            Date.setYear(static_cast<short>(Date.getYear() + 1));
        }
        else
        {
            Date.setMonth(static_cast<short>(Date.getMonth() + 1));
        }

        short maxDay = numberOfDaysInaMonth(Date.getMonth(), Date.getYear());
        if (Date.getDay() > maxDay) Date.setDay(maxDay);

        return Date;
    }





    void increaseDateByOneMonth() { increaseDateByOneMonth(*this); }

    static clsDate increaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 0; i < Days; ++i) Date = AddOneDay(Date);
        return Date;
    }




    void increaseDateByXDays(short Days) { increaseDateByXDays(Days, *this); }





    static clsDate increaseDateByXMonths(short Months, clsDate& Date)
    {
        for (short i = 0; i < Months; ++i) Date = increaseDateByOneMonth(Date);
        return Date;
    }





    void increaseDateByXMonths(short Months) { increaseDateByXMonths(Months, *this); }






    static clsDate increaseDateByOneYear(clsDate& Date)
    {
        Date.setYear(static_cast<short>(Date.getYear() + 1));
        // Adjust Feb 29 → Feb 28 on non-leap target years
        short maxDay = numberOfDaysInaMonth(Date.getMonth(), Date.getYear());
        if (Date.getDay() > maxDay) Date.setDay(maxDay);
        return Date;
    }




    void increaseDateByOneYear() { increaseDateByOneYear(*this); }




    static clsDate increaseDateByXYears(short Years, clsDate& Date)
    {
        Date.setYear(static_cast<short>(Date.getYear() + Years));
        short maxDay = numberOfDaysInaMonth(Date.getMonth(), Date.getYear());
        if (Date.getDay() > maxDay) Date.setDay(maxDay);
        return Date;
    }




    void increaseDateByXYears(short Years) { increaseDateByXYears(Years, *this); } // fixed recursion




    static clsDate increaseDateByOneDecade(clsDate& Date)
    {
        return increaseDateByXYears(10, Date);
    }





    void increaseDateByOneDecade() { increaseDateByOneDecade(*this); }




    static clsDate increaseDateByXDecades(short Decades, clsDate& Date)
    {
        return increaseDateByXYears(static_cast<short>(Decades * 10), Date);
    }




    void increaseDateByXDecades(short Decades) { increaseDateByXDecades(Decades, *this); }




    static clsDate increaseDateByOneCentury(clsDate& Date)
    {
        return increaseDateByXYears(100, Date);
    }




    void increaseDateByOneCentury() { increaseDateByOneCentury(*this); }




    static clsDate increaseDateByOneMillennium(clsDate& Date)
    {
        return increaseDateByXYears(1000, Date);
    }




    void increaseDateByOneMillennium() { increaseDateByOneMillennium(*this); }




    // === Decrease helpers ===
    static clsDate decreaseDateByOneDay(clsDate Date)
    {
        if (Date.getDay() == 1)
        {
            if (Date.getMonth() == 1)
            {
                Date.setMonth(12);
                Date.setYear(static_cast<short>(Date.getYear() - 1));
                Date.setDay(31);
            }
            else
            {
                Date.setMonth(static_cast<short>(Date.getMonth() - 1));
                Date.setDay(numberOfDaysInaMonth(Date.getMonth(), Date.getYear()));
            }
        }
        else
        {
            Date.setDay(static_cast<short>(Date.getDay() - 1));
        }
        return Date;
    }




    void decreaseDateByOneDay() { *this = decreaseDateByOneDay(*this); }




    static clsDate decreaseDateByOneWeek(clsDate& Date)
    {
        for (int i = 0; i < 7; ++i) Date = decreaseDateByOneDay(Date);
        return Date;
    }




    void decreaseDateByOneWeek() { decreaseDateByOneWeek(*this); }




    static clsDate decreaseDateByXWeeks(short Weeks, clsDate& Date)
    {
        for (short i = 0; i < Weeks; ++i) Date = decreaseDateByOneWeek(Date);
        return Date;
    }




    void decreaseDateByXWeeks(short Weeks) { decreaseDateByXWeeks(Weeks, *this); }




    static clsDate decreaseDateByOneMonth(clsDate& Date)
    {
        if (Date.getMonth() == 1)
        {
            Date.setMonth(12);
            Date.setYear(static_cast<short>(Date.getYear() - 1));
        }
        else
        {
            Date.setMonth(static_cast<short>(Date.getMonth() - 1));
        }

        short maxDay = numberOfDaysInaMonth(Date.getMonth(), Date.getYear());
        if (Date.getDay() > maxDay) Date.setDay(maxDay);

        return Date;
    }




    void decreaseDateByOneMonth() { decreaseDateByOneMonth(*this); }




    static clsDate decreaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 0; i < Days; ++i) Date = decreaseDateByOneDay(Date);
        return Date;
    }




    void decreaseDateByXDays(short Days) { decreaseDateByXDays(Days, *this); }




    static clsDate decreaseDateByXMonths(short Months, clsDate& Date)
    {
        for (short i = 0; i < Months; ++i) Date = decreaseDateByOneMonth(Date);
        return Date;
    }




    void decreaseDateByXMonths(short Months) { decreaseDateByXMonths(Months, *this); }




    static clsDate decreaseDateByOneYear(clsDate& Date)
    {
        Date.setYear(static_cast<short>(Date.getYear() - 1));
        short maxDay = numberOfDaysInaMonth(Date.getMonth(), Date.getYear());
        if (Date.getDay() > maxDay) Date.setDay(maxDay);
        return Date;
    }




    void decreaseDateByOneYear() { decreaseDateByOneYear(*this); }




    static clsDate decreaseDateByXYears(short Years, clsDate& Date)
    {
        Date.setYear(static_cast<short>(Date.getYear() - Years));
        short maxDay = numberOfDaysInaMonth(Date.getMonth(), Date.getYear());
        if (Date.getDay() > maxDay) Date.setDay(maxDay);
        return Date;
    }




    void decreaseDateByXYears(short Years) { decreaseDateByXYears(Years, *this); }




    static clsDate decreaseDateByOneDecade(clsDate& Date)
    {
        return decreaseDateByXYears(10, Date);
    }



    void decreaseDateByOneDecade() { decreaseDateByOneDecade(*this); }




    static clsDate decreaseDateByXDecades(short Decades, clsDate& Date)
    {
        return decreaseDateByXYears(static_cast<short>(Decades * 10), Date);
    }




    void decreaseDateByXDecades(short Decades) { decreaseDateByXDecades(Decades, *this); }




    static clsDate decreaseDateByOneCentury(clsDate& Date)
    {
        return decreaseDateByXYears(100, Date);
    }




    void decreaseDateByOneCentury() { decreaseDateByOneCentury(*this); }




    static clsDate decreaseDateByOneMillennium(clsDate& Date)
    {
        return decreaseDateByXYears(1000, Date);
    }

    void decreaseDateByOneMillennium() { decreaseDateByOneMillennium(*this); }





    // === Week/Business helpers ===
    static short isEndOfWeek(clsDate Date)
    {
        return dayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear()) == 6;
    }




    short isEndOfWeek() { return isEndOfWeek(*this); }





    static bool isWeekEnd(clsDate Date)
    {
        short idx = dayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear());
        return (idx == 5 || idx == 6); // Fri/Sat as weekend
    }





    bool isWeekEnd() { return isWeekEnd(*this); }




    static bool isBusinessDay(clsDate Date)
    {
        return !isWeekEnd(Date);
    }




    bool isBusinessDay() { return isBusinessDay(*this); }

    static short daysUntilTheEndOfWeek(clsDate Date)
    {
        return static_cast<short>(6 - dayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear()));
    }




    short daysUntilTheEndOfWeek()
    {
        return daysUntilTheEndOfWeek(*this);
    }




    static short daysUntilTheEndOfMonth(clsDate Date1)
    {
        clsDate endOfMonth;
        endOfMonth.setYear(Date1.getYear());
        endOfMonth.setMonth(Date1.getMonth());
        endOfMonth.setDay(numberOfDaysInaMonth(Date1.getMonth(), Date1.getYear()));
        return static_cast<short>(getDifferenceinDays(Date1, endOfMonth, true));
    }




    short daysUntilTheEndOfMonth()
    {
        return daysUntilTheEndOfMonth(*this);
    }



    static short daysUntilTheEndOfYear(clsDate Date1)
    {
        clsDate endOfYear;
        endOfYear.setYear(Date1.getYear());
        endOfYear.setMonth(12);
        endOfYear.setDay(31);
        return static_cast<short>(getDifferenceinDays(Date1, endOfYear, true));
    }





    short daysUntilTheEndOfYear()
    {
        return daysUntilTheEndOfYear(*this);
    }



    static short calculateBusinessDays(clsDate DateFrom, const clsDate DateTo)
    {
        short days = 0;
        while (isDate1BeforeDate2(DateFrom, DateTo))
        {
            if (isBusinessDay(DateFrom)) ++days;
            DateFrom = AddOneDay(DateFrom);
        }
        return days;
    }



    static short calculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        return calculateBusinessDays(DateFrom, DateTo);
    }



    static clsDate calculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {
        short weekendCount = 0;

        for (short i = 0; i < VacationDays; ++i)
        {
            if (isWeekEnd(DateFrom)) ++weekendCount;
            DateFrom = AddOneDay(DateFrom);
        }
        for (short i = 0; i < weekendCount; ++i)
            DateFrom = AddOneDay(DateFrom);

        return DateFrom;
    }




    // === Validation (moved to bottom to use fixed funcs) ===
    static bool isValidDate(clsDate Date)
    {
        if (Date.getDay()   < 1 || Date.getDay()   > 31) return false;
        if (Date.getMonth() < 1 || Date.getMonth() > 12) return false;

        if (Date.getMonth() == 2)
        {
            if (isLeapYear(Date.getYear()))
            {
                if (Date.getDay() > 29) return false;
            }
            else
            {
                if (Date.getDay() > 28) return false;
            }
        }

        short dim = numberOfDaysInaMonth(Date.getMonth(), Date.getYear()); // fixed (Year, not Month)
        if (Date.getDay() > dim) return false;

        return true;
    }



    bool isValid() { return isValidDate(*this); }



    static string getCurrentDateAndTimeString() {
        time_t t = time(nullptr);
        tm* now  = localtime(&t);
        return dateToString(getSystemDate())+" - "+to_string(now->tm_hour)+":"+to_string(now->tm_min)+":"+to_string(now->tm_sec);
    }
};
