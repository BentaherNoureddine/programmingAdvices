#include <iomanip>
#include <iostream>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"
using namespace myInputLib;

using namespace myMathLib;
using namespace std;




string join(vector<string> vNames,string sep) {

    string names;
    for (string& name :vNames) {
     names+=name+sep;
    }
    return names.substr(0,names.length()-sep.length());

}

string join(string arr[],short arrLen,string sep) {
    string names;
    for (short i=0;i<arrLen;i++) {
        names+=arr[i]+sep;
    }
    return names.substr(0,names.length()-sep.length());

}




int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


   vector<string> vString={{"noureddine"},{"mohamed"},"moeez"};
   string arr[]={"momo","koukou","loulou"};

       string s=join(vString,"/");
   cout<<"Vector after join : "<<endl;
    cout <<s<<endl;
    cout<<"Array after join"<<endl;
    s=join(arr,3,")");
    cout<<s<<endl;


    return 0;
}
