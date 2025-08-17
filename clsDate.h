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
        SetDay(static_cast<short>(now->tm_mday));
        SetMonth(static_cast<short>(now->tm_mon + 1));
        SetYear(static_cast<short>(now->tm_year + 1900));
    }

    clsDate(string sDate)
    {
        vector<string> vDate = clsString::Split(sDate, "/");
        SetDay(static_cast<short>(stoi(vDate[0])));
        SetMonth(static_cast<short>(stoi(vDate[1])));
        SetYear(static_cast<short>(stoi(vDate[2])));
    }

    clsDate(short Day, short Month, short Year)
    {
        SetDay(Day);
        SetMonth(Month);
        SetYear(Year);
    }

    // Construct from day-order in year
    clsDate(short DateOrderInYear, short Year)
    {
        clsDate d = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        SetDay(d.GetDay());
        SetMonth(d.GetMonth());
        SetYear(d.GetYear());
    }

    // === Accessors ===
    void  SetDay(short Day)     { _Day = Day; }
    short GetDay()        const { return _Day; }

    void  SetMonth(short Month) { _Month = Month; }
    short GetMonth()      const { return _Month; }

    void  SetYear(short Year)   { _Year = Year; }
    short GetYear()       const { return _Year; }

    // === I/O ===
    static string DateToString(const clsDate& Date)
    {
        return to_string(Date.GetDay()) + "/" +
               to_string(Date.GetMonth()) + "/" +
               to_string(Date.GetYear());
    }

    string DateToString() const { return DateToString(*this); }

    void Print() const { cout << DateToString() << endl; }

    static clsDate GetSystemDate()
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

    bool isLeapYear() const { return isLeapYear(GetYear()); }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12) return 0;
        static const short days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    short NumberOfDaysInAMonth() const
    {
        return NumberOfDaysInAMonth(GetMonth(), GetYear());
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365; // fixed
    }

    short NumberOfDaysInAYear() const { return NumberOfDaysInAYear(GetYear()); }

    static int NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }

    int NumberOfHoursInAYear() const { return NumberOfHoursInAYear(GetYear()); }

    static int NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }

    int NumberOfMinutesInAYear() const { return NumberOfMinutesInAYear(GetYear()); }

    static long long NumberOfSecondsInAYear(short Year)
    {
        return static_cast<long long>(NumberOfMinutesInAYear(Year)) * 60;
    }

    long long NumberOfSecondsInAYear() const
    {
        return NumberOfSecondsInAYear(GetYear()); // fixed (no recursion)
    }

    static short NumberOfHoursInAMonth(short Month, short Year)
    {
        return NumberOfDaysInAMonth(Month, Year) * 24;
    }

    short NumberOfHoursInAMonth() const
    {
        return NumberOfDaysInAMonth(GetMonth(), GetYear()) * 24;
    }

    static int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return NumberOfHoursInAMonth(Month, Year) * 60;
    }

    int NumberOfMinutesInAMonth() const
    {
        return NumberOfHoursInAMonth(GetMonth(), GetYear()) * 60;
    }

    static int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return NumberOfMinutesInAMonth(Month, Year) * 60;
    }

    int NumberOfSecondsInAMonth() const
    {
        return NumberOfMinutesInAMonth(GetMonth(), GetYear()) * 60;
    }

    // === Day-of-week & names ===
    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a = static_cast<short>((14 - Month) / 12);
        int y = Year - a;
        int m = Month + (12 * a) - 2;
        // 0=Sun,1=Mon,...6=Sat
        return static_cast<short>((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
    }

    short DayOfWeekOrder() const
    {
        return DayOfWeekOrder(GetDay(), GetMonth(), GetYear());
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        static const string arrDayNames[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
        return arrDayNames[DayOfWeekOrder];
    }

    static string DayShortName(short Day, short Month, short Year)
    {
        return DayShortName(DayOfWeekOrder(Day, Month, Year));
    }

    string DayShortName() const { return DayShortName(GetDay(), GetMonth(), GetYear()); }

    static string MonthShortName(short MonthNumber)
    {
        static const string Months[12] =
            {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        return Months[MonthNumber - 1];
    }

    string MonthShortName() const { return MonthShortName(GetMonth()); }

    // === Calendars ===
    static void PrintMonthCalendar(short Month, short Year)
    {
        int current = DayOfWeekOrder(1, Month, Year);
        int NumberOfDays = NumberOfDaysInAMonth(Month, Year);

        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
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

    void PrintMonthCalendar() const { PrintMonthCalendar(GetMonth(), GetYear()); }

    static void PrintYearCalendar(int Year)
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");
        for (int m = 1; m <= 12; ++m) PrintMonthCalendar(static_cast<short>(m), static_cast<short>(Year));
    }

    void PrintYearCalendar() const { PrintYearCalendar(GetYear()); }

    // === Date math ===
    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {
        short total = 0;
        for (short m = 1; m <= Month - 1; ++m)
            total = static_cast<short>(total + NumberOfDaysInAMonth(m, Year));
        return static_cast<short>(total + Day);
    }

    short DaysFromTheBeginingOfTheYear() const
    {
        return DaysFromTheBeginingOfTheYear(GetDay(), GetMonth(), GetYear());
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate d(1, 1, Year);
        short remaining = DateOrderInYear;

        while (true)
        {
            short md = NumberOfDaysInAMonth(d.GetMonth(), Year);
            if (remaining > md)
            {
                remaining = static_cast<short>(remaining - md);
                d.SetMonth(static_cast<short>(d.GetMonth() + 1));
            }
            else
            {
                d.SetDay(remaining);
                break;
            }
        }
        return d;
    }

    void AddDays(short Days)
    {
        short remaining = static_cast<short>(Days + DaysFromTheBeginingOfTheYear(GetDay(), GetMonth(), GetYear()));
        SetMonth(1);

        while (true)
        {
            short md = NumberOfDaysInAMonth(GetMonth(), GetYear());
            if (remaining > md)
            {
                remaining = static_cast<short>(remaining - md);
                SetMonth(static_cast<short>(GetMonth() + 1));

                if (GetMonth() > 12)
                {
                    SetMonth(1);
                    SetYear(static_cast<short>(GetYear() + 1));
                }
            }
            else
            {
                SetDay(remaining);
                break;
            }
        }
    }

    // === Comparisons ===
    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        if (Date1.GetYear() != Date2.GetYear())
            return Date1.GetYear() < Date2.GetYear();
        if (Date1.GetMonth() != Date2.GetMonth())
            return Date1.GetMonth() < Date2.GetMonth();
        return Date1.GetDay() < Date2.GetDay();
    }

    bool IsDateBeforeDate2(clsDate Date2) { return IsDate1BeforeDate2(*this, Date2); }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return Date1.GetYear() == Date2.GetYear() &&
               Date1.GetMonth() == Date2.GetMonth() &&
               Date1.GetDay() == Date2.GetDay();
    }

    bool IsDateEqualDate2(clsDate Date2) { return IsDate1EqualDate2(*this, Date2); }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
    }

    bool IsDateAfterDate2(clsDate Date2) { return IsDate1AfterDate2(*this, Date2); }

    enum enDateCompare { Before = -1, Equal = 0, After = 1 };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2)) return enDateCompare::Before;
        if (IsDate1EqualDate2(Date1, Date2))  return enDateCompare::Equal;
        return enDateCompare::After;
    }

    enDateCompare CompareDates(clsDate Date2) { return CompareDates(*this, Date2); }

    // === Utils ===
    static bool IsLastDayInMonth(clsDate Date)
    {
        return Date.GetDay() == NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
    }

    bool IsLastDayInMonth() { return IsLastDayInMonth(*this); }

    static bool IsLastMonthInYear(short Month) { return Month == 12; }

    static clsDate AddOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.GetMonth()))
            {
                Date.SetMonth(1);
                Date.SetDay(1);
                Date.SetYear(static_cast<short>(Date.GetYear() + 1));
            }
            else
            {
                Date.SetDay(1);
                Date.SetMonth(static_cast<short>(Date.GetMonth() + 1));
            }
        }
        else
        {
            Date.SetDay(static_cast<short>(Date.GetDay() + 1));
        }
        return Date;
    }

    void AddOneDay() { *this = AddOneDay(*this); }

    static void SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate tmp = Date1;
        Date1 = Date2;
        Date2 = tmp;
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int days = 0;
        short sign = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            sign = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            ++days;
            Date1 = AddOneDay(Date1);
        }

        return IncludeEndDay ? (days + 1) * sign : days * sign;
    }

    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return static_cast<short>(GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true));
    }

    // === Increase helpers ===
    static clsDate IncreaseDateByOneWeek(clsDate& Date)
    {
        for (int i = 0; i < 7; ++i) Date = AddOneDay(Date);
        return Date;
    }

    void IncreaseDateByOneWeek() { IncreaseDateByOneWeek(*this); }

    static clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
    {
        for (short i = 0; i < Weeks; ++i) Date = IncreaseDateByOneWeek(Date);
        return Date;
    }

    void IncreaseDateByXWeeks(short Weeks) { IncreaseDateByXWeeks(Weeks, *this); }

    static clsDate IncreaseDateByOneMonth(clsDate& Date)
    {
        if (Date.GetMonth() == 12)
        {
            Date.SetMonth(1);
            Date.SetYear(static_cast<short>(Date.GetYear() + 1));
        }
        else
        {
            Date.SetMonth(static_cast<short>(Date.GetMonth() + 1));
        }

        short maxDay = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > maxDay) Date.SetDay(maxDay);

        return Date;
    }

    void IncreaseDateByOneMonth() { IncreaseDateByOneMonth(*this); }

    static clsDate IncreaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 0; i < Days; ++i) Date = AddOneDay(Date);
        return Date;
    }

    void IncreaseDateByXDays(short Days) { IncreaseDateByXDays(Days, *this); }

    static clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
    {
        for (short i = 0; i < Months; ++i) Date = IncreaseDateByOneMonth(Date);
        return Date;
    }

    void IncreaseDateByXMonths(short Months) { IncreaseDateByXMonths(Months, *this); }

    static clsDate IncreaseDateByOneYear(clsDate& Date)
    {
        Date.SetYear(static_cast<short>(Date.GetYear() + 1));
        // Adjust Feb 29 → Feb 28 on non-leap target years
        short maxDay = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > maxDay) Date.SetDay(maxDay);
        return Date;
    }

    void IncreaseDateByOneYear() { IncreaseDateByOneYear(*this); }

    static clsDate IncreaseDateByXYears(short Years, clsDate& Date)
    {
        Date.SetYear(static_cast<short>(Date.GetYear() + Years));
        short maxDay = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > maxDay) Date.SetDay(maxDay);
        return Date;
    }

    void IncreaseDateByXYears(short Years) { IncreaseDateByXYears(Years, *this); } // fixed recursion

    static clsDate IncreaseDateByOneDecade(clsDate& Date)
    {
        return IncreaseDateByXYears(10, Date);
    }

    void IncreaseDateByOneDecade() { IncreaseDateByOneDecade(*this); }

    static clsDate IncreaseDateByXDecades(short Decades, clsDate& Date)
    {
        return IncreaseDateByXYears(static_cast<short>(Decades * 10), Date);
    }

    void IncreaseDateByXDecades(short Decades) { IncreaseDateByXDecades(Decades, *this); }

    static clsDate IncreaseDateByOneCentury(clsDate& Date)
    {
        return IncreaseDateByXYears(100, Date);
    }

    void IncreaseDateByOneCentury() { IncreaseDateByOneCentury(*this); }

    static clsDate IncreaseDateByOneMillennium(clsDate& Date)
    {
        return IncreaseDateByXYears(1000, Date);
    }

    void IncreaseDateByOneMillennium() { IncreaseDateByOneMillennium(*this); }

    // === Decrease helpers ===
    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date.GetDay() == 1)
        {
            if (Date.GetMonth() == 1)
            {
                Date.SetMonth(12);
                Date.SetYear(static_cast<short>(Date.GetYear() - 1));
                Date.SetDay(31);
            }
            else
            {
                Date.SetMonth(static_cast<short>(Date.GetMonth() - 1));
                Date.SetDay(NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear()));
            }
        }
        else
        {
            Date.SetDay(static_cast<short>(Date.GetDay() - 1));
        }
        return Date;
    }

    void DecreaseDateByOneDay() { *this = DecreaseDateByOneDay(*this); }

    static clsDate DecreaseDateByOneWeek(clsDate& Date)
    {
        for (int i = 0; i < 7; ++i) Date = DecreaseDateByOneDay(Date);
        return Date;
    }

    void DecreaseDateByOneWeek() { DecreaseDateByOneWeek(*this); }

    static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
    {
        for (short i = 0; i < Weeks; ++i) Date = DecreaseDateByOneWeek(Date);
        return Date;
    }

    void DecreaseDateByXWeeks(short Weeks) { DecreaseDateByXWeeks(Weeks, *this); }

    static clsDate DecreaseDateByOneMonth(clsDate& Date)
    {
        if (Date.GetMonth() == 1)
        {
            Date.SetMonth(12);
            Date.SetYear(static_cast<short>(Date.GetYear() - 1));
        }
        else
        {
            Date.SetMonth(static_cast<short>(Date.GetMonth() - 1));
        }

        short maxDay = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > maxDay) Date.SetDay(maxDay);

        return Date;
    }

    void DecreaseDateByOneMonth() { DecreaseDateByOneMonth(*this); }

    static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 0; i < Days; ++i) Date = DecreaseDateByOneDay(Date);
        return Date;
    }

    void DecreaseDateByXDays(short Days) { DecreaseDateByXDays(Days, *this); }

    static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
    {
        for (short i = 0; i < Months; ++i) Date = DecreaseDateByOneMonth(Date);
        return Date;
    }

    void DecreaseDateByXMonths(short Months) { DecreaseDateByXMonths(Months, *this); }

    static clsDate DecreaseDateByOneYear(clsDate& Date)
    {
        Date.SetYear(static_cast<short>(Date.GetYear() - 1));
        short maxDay = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > maxDay) Date.SetDay(maxDay);
        return Date;
    }

    void DecreaseDateByOneYear() { DecreaseDateByOneYear(*this); }

    static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
    {
        Date.SetYear(static_cast<short>(Date.GetYear() - Years));
        short maxDay = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > maxDay) Date.SetDay(maxDay);
        return Date;
    }

    void DecreaseDateByXYears(short Years) { DecreaseDateByXYears(Years, *this); }

    static clsDate DecreaseDateByOneDecade(clsDate& Date)
    {
        return DecreaseDateByXYears(10, Date);
    }

    void DecreaseDateByOneDecade() { DecreaseDateByOneDecade(*this); }

    static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
    {
        return DecreaseDateByXYears(static_cast<short>(Decades * 10), Date);
    }

    void DecreaseDateByXDecades(short Decades) { DecreaseDateByXDecades(Decades, *this); }

    static clsDate DecreaseDateByOneCentury(clsDate& Date)
    {
        return DecreaseDateByXYears(100, Date);
    }

    void DecreaseDateByOneCentury() { DecreaseDateByOneCentury(*this); }

    static clsDate DecreaseDateByOneMillennium(clsDate& Date)
    {
        return DecreaseDateByXYears(1000, Date);
    }

    void DecreaseDateByOneMillennium() { DecreaseDateByOneMillennium(*this); }

    // === Week/Business helpers ===
    static short IsEndOfWeek(clsDate Date)
    {
        return DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()) == 6;
    }

    short IsEndOfWeek() { return IsEndOfWeek(*this); }

    static bool IsWeekEnd(clsDate Date)
    {
        short idx = DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear());
        return (idx == 5 || idx == 6); // Fri/Sat as weekend
    }

    bool IsWeekEnd() { return IsWeekEnd(*this); }

    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay() { return IsBusinessDay(*this); }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return static_cast<short>(6 - DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()));
    }

    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(clsDate Date1)
    {
        clsDate endOfMonth;
        endOfMonth.SetYear(Date1.GetYear());
        endOfMonth.SetMonth(Date1.GetMonth());
        endOfMonth.SetDay(NumberOfDaysInAMonth(Date1.GetMonth(), Date1.GetYear()));
        return static_cast<short>(GetDifferenceInDays(Date1, endOfMonth, true));
    }

    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(clsDate Date1)
    {
        clsDate endOfYear;
        endOfYear.SetYear(Date1.GetYear());
        endOfYear.SetMonth(12);
        endOfYear.SetDay(31);
        return static_cast<short>(GetDifferenceInDays(Date1, endOfYear, true));
    }

    short DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(*this);
    }

    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom)) ++days;
            DateFrom = AddOneDay(DateFrom);
        }
        return days;
    }

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        return CalculateBusinessDays(DateFrom, DateTo);
    }

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {
        short weekendCount = 0;

        for (short i = 0; i < VacationDays; ++i)
        {
            if (IsWeekEnd(DateFrom)) ++weekendCount;
            DateFrom = AddOneDay(DateFrom);
        }
        for (short i = 0; i < weekendCount; ++i)
            DateFrom = AddOneDay(DateFrom);

        return DateFrom;
    }

    // === Validation (moved to bottom to use fixed funcs) ===
    static bool IsValidDate(clsDate Date)
    {
        if (Date.GetDay()   < 1 || Date.GetDay()   > 31) return false;
        if (Date.GetMonth() < 1 || Date.GetMonth() > 12) return false;

        if (Date.GetMonth() == 2)
        {
            if (isLeapYear(Date.GetYear()))
            {
                if (Date.GetDay() > 29) return false;
            }
            else
            {
                if (Date.GetDay() > 28) return false;
            }
        }

        short dim = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear()); // fixed (Year, not Month)
        if (Date.GetDay() > dim) return false;

        return true;
    }

    bool IsValid() { return IsValidDate(*this); }
};
