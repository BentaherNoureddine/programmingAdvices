#pragma once

#include <iostream>
using namespace std;





namespace MyMathLib{

    int getAddition(int left,int right) {
        return left+right;
    }


    int getSubtraction(int left,int right) {
        return left-right;
    }


    int getMultiplication(int left,int right) {
        return left*right;
    }


    int getDivision(int left,int right) {
        return left/right;
    }


    int getRandomNumber(int From, int To) {
        return rand() % (To - From + 1) + From;
    }

     



}