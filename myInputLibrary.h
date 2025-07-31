#pragma once
#include <iostream>
#include <limits> 
using namespace std;

namespace myInputLib {
    


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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return number;
    }

double readDouble(string message){
        double number;

        cout << message;
        cin >> number;

        while (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid number: ";
            cin >> number;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return number;

    }


    string readString(string message){
        string str;
        cout << message;

        // Only ignore if the last character read is a newline (i.e., if there’s something to clean)
        if (cin.peek() == '\n') {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        getline(cin>>ws, str);
        return str;
    }



    short readShort(string message){
        short number;

        cout << message;
        cin >> number;

        while (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid number: ";
            cin >> number;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return number;
    }


    bool yesNoQuestion(string message) {
    char yes;

        cout<<message;
        cin>>yes;
    return (toupper(yes)=='Y'||yes=='Y');

}
}



