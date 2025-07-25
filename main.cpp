#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"

using namespace myInputLib;

using namespace myMathLib;
using namespace std;


string getNumberText(int number) {

    if (number==0) {
        return "";
    }

    if (number>=1&&number<=19) {
        string arr[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
            "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen",
               "Eighteen","Nineteen",
        };
        return arr[number];
    }

    if (number>=20&&number<=99) {
        string arr[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        return arr[number/10]+ " "+getNumberText(number%10);
    }

    if (number>=100&&number<=999) {
        if (number==100) {
            return "One Hundred";
        }

        return getNumberText(number /100)+" Hundred and "+getNumberText(number%100);
    }

    if (number>=1000&&number<=999999) {
        if (number==1000) {
            return  "One Thousand";
        }
        if (number==10000) {
            return "Ten Thousand";
        }
        return getNumberText(number/1000)+" Thousand and "+getNumberText(number%1000);
    }

    if (number>=1000000&&number<=9999999) {
        if (number==100000) {
            return "One Million";
        }
        return getNumberText(number/1000000)+" Million and "+getNumberText(number%100000);
    }







}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    cout<<getNumberText(readInt("Enter a Number"));










    return 0;
}
