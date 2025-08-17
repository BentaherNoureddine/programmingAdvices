#include <iostream>
#include "clsInputValidate.h"

int main()

{
    cout << clsInputValidate::isNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::isNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::isDateBetween(clsDate(),
                                       clsDate(17,8,2025),
                                       clsDate(31, 12, 2025)) << endl;
    
    cout << clsInputValidate::isDateBetween(clsDate(),
                                       clsDate(31, 12, 2022),
                                       clsDate(8, 12, 2022)) << endl;
    
    cout << "\nPlease Enter a Number:\n";
    int x= clsInputValidate::readInt("Invalid Number, Enter again:\n");
    cout << "x=" << x;

    cout << "\nPlease Enter a Number between 1 and 5:\n";
    int y = clsInputValidate::readIntNumberBetween(1,5,"Number is not within range, enter again:\n");
    cout << "y=" << y;

    cout << "\nPlease Enter a Double Number:\n";
    double a = clsInputValidate::readDouble("Invalid Number, Enter again:\n");
    cout << "a=" << a;

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    double b = clsInputValidate::readDoubleNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "b=" << b;

    cout << endl << clsInputValidate::isValidDate(clsDate(35,12,2022)) << endl;

    system("pause>0");

    return 0;
}