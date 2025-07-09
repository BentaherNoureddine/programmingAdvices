#pragma once
#include <iostream>
using namespace std;


namespace checkLib{


    bool isEven(int number) {
        return number % 2 == 0;
    }


    void numberSign(int number){
        number ==0 ? cout<< "Zero" : (number>0 ? cout <<"Positive" : cout <<"Negative");
    }

}