#pragma once
#include <iostream>
using namespace std;

namespace myLibrary {
    


    float readFloat(string message){
        float number;

            cout << message;
            cin >> number;

        return number;

    }


    int readInt(string message){
        int number;

            cout << message;
            cin >> number;

        return number;

    }


    string readString(string message){
        string str;

            cout << message;
            cin >> str;

        return str;

    }



}