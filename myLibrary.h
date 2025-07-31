#pragma once
#include <iostream>

using namespace std;


namespace MyLib{








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





  string removePuncFromString(string s) {

    string s2;

    for (short i=0;i<s.length();i++) {
      if (std::ispunct(s[i])==false) {
        s2+=s[i];
      }
    }
    return s2;
  }



  

}