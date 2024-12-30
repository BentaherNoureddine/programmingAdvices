#include <iostream>
using namespace std;


enum weekday { Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat };

void showWeekDays()
{
    cout <<"*************************************" <<endl;
    cout << "Weekdays: \n";
    cout<<  "(1) sunday" <<endl;
    cout << "(2) monday" <<endl;
    cout << "(3) tuesday" <<endl;
    cout << "(4) wednesday" <<endl;
    cout << "(5) thursday" <<endl;
    cout << "(6) friday" <<endl;
    cout << "(7) saturday" <<endl;
    cout <<"*************************************\n\n" <<endl;
}


// CAST AN INTEGER TO A WEEKDAY
weekday readWeekDay()
{
    //READ THE WEEKDAY
    int day;
    cin>>day;

    // RETURN THE CASTED WEEK DAY
    return (weekday)day;
}

// DETERMINE THE WEEK DAY BASED ON THE GIVEN INPUT

string getWeekDay(weekday weekday)
{
    switch (weekday)
    {
        case Sun:
            return "Sunday";
        case Mon:
            return "Monday";
        case Tue:
            return "Tuesday";
        case Wed:
            return "Wednesday";
        case Thu:
            return "Thursday";
        case Fri:
            return "Friday";
        case Sat:
            return "Saturday";
        default:
            return "Unknown";
    }
}


int main()
{

    showWeekDays();
    cout << "today is "<<getWeekDay(readWeekDay());
    return 0;



}
