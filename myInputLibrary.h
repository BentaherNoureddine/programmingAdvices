#pragma once
#include <iostream>
#include <limits> 
using namespace std;

namespace myLibrary {
    


    float readFloat(string message){
        float number;

        cout << message;
        cin >> number;

        while (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid number: ";
            cin >> number;
        }
        return number;
    }


    int readInt(string message){
        int number;

        cout << message;
        cin >> number;

        while (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid number: ";
            cin >> number;
        }

        return number;

    }


    string readString(string message){
        string str;

        cout << message;
        cin >> str;
        
        while (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid string: ";
            cin >> str;
        }
        
        return str;

    }



}