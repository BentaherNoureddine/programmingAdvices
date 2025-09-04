#pragma once
#include <iostream>
#include <limits>
#include "clsDate.h"


class clsInputValidate {

public:

    template  <typename T>
    static T readNumber(const std::string& message ) {
        T number;
        std::cout << message;
        while (!(std::cin >> number)) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        return (T)number;
    }

    static std::string readString (const std::string& message){
        std::string str;
        std::cout << message;

        // Only ignore if the last character read is a newline (i.e., if there’s something to clean)
        if (std::cin.peek() == '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        getline(std::cin>>ws, str);
        return str;
    }



    template <typename T>
    static T readNumberBetween(const T from,T to,const std::string message) {
        T number=readNumber<T>(message);

        while (!isNumberBetween(number,from,to)) {
            number=readNumber<T>("Please Enter a number between "+to_string(from)+" AND "+to_string(to));
        }
        return (T)number;
    }


    template <typename T>
    static bool isNumberBetween(const T number,const T from,const T to) {
        return number>=from&&number<=to;
    }


    static bool isDateBetween(clsDate date,const clsDate dateFrom,const clsDate dateTo) {
        return (date.isDateEqualDate2(dateFrom)||date.isDateEqualDate2(dateTo))||  (clsDate::isDate1BeforeDate2(dateFrom,dateTo)?(date.isDateBeforeDate2(dateTo)&&date.isDateAfterDate2(dateFrom)):(date.isDateBeforeDate2(dateFrom)&&date.isDateAfterDate2(dateTo)));
    }

    static bool isValidDate(const clsDate date) {
        return clsDate::isValidDate(date);
    }


    static bool yesNoQuestion(const std::string message) {
        char yes;

        std::cout<<message;
        std::cin>>yes;
        return (toupper(yes)=='Y');

    }


};




