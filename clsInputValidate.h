#pragma once
#include <iostream>
#include <limits>
#include "clsDate.h"


class clsInputValidate {

public:
    static float readFloat( const std::string message){
        float number;
        std::cout << message;
        while (!(std::cin >> number)) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        return number;
    }



    static double readDouble(const std::string message){
        double number;
        std::cout << message;
        while (!(std::cin >> number)) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        return number;
    }


    static int readInt(const std::string message){
        int number;
        std::cout << message;
        while (!(std::cin >> number)) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        return number;
    }


    static std::string readString (const std::string message){
        std::string str;
        std::cout << message;

        // Only ignore if the last character read is a newline (i.e., if there’s something to clean)
        if (std::cin.peek() == '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        getline(std::cin>>ws, str);
        return str;
    }


    static short readShort(const std::string message){
        short number;
        std::cout << message;
        while (!(std::cin >> number)) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        return number;
    }


    static int readIntNumberBetween(const int from,int to,const std::string message) {
        int number=readInt(message);

        while (!isNumberBetween(number,from,to)) {
            number=readInt("Please Enter a number between "+to_string(from)+" AND "+to_string(to));
        }
        return number;
    }

    static short  readShortNumberBetween(const short from,const short to,const std::string message) {
         short number=readShort(message);
        while (!isNumberBetween(number,from,to)) {
            number=readShort("Please Enter a number between "+to_string(from)+" AND "+to_string(to));
        }
        return number;
    }

    static double readDoubleNumberBetween(const double from,const double to,const std::string message) {
        double number=readDouble(message);
        while (!isNumberBetween(number,from,to)) {
            number=readDouble("Please Enter a number between "+to_string(from)+" AND "+to_string(to));
        }
        return number;
    }

    static float readFloatNumberBetween(const float from,const float to,const std::string message) {
        float number=readFloat(message);
        while (!isNumberBetween(number,from,to)) {
            number=readFloat("Please Enter a number between "+to_string(from)+" AND "+to_string(to));
        }
        return number;
    }

    static bool isNumberBetween(const int number,const int from,const int to) {
        return number>=from&&number<=to;
    }

    static bool isNumberBetween(const float number,const float from,const float to) {
        return number>=from&&number<=to;
    }

    static bool isNumberBetween(const double number,const double from,double  to) {
        return number>=from&&number<=to;
    }

    static bool isNumberBetween(const short  number,const short from,const short to) {
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




