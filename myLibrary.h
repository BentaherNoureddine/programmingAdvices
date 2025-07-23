#pragma once
#include <iostream>
using namespace std;

namespace MyLib{


  void test(){
    cout <<"Hello from MyLib!" << endl;
  }

  string removePuncFromString(string s) {

    string s2;
    bool n;
    for (short i=0;i<s.length();i++) {
      if (std::ispunct(s[i])==false) {
        s2+=s[i];
      }
    }
    return s2;
  }

  

}