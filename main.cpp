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




int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


   vector<string> vString={{"noureddine"},{"mohamed"},"moeez"};
    string s=join(vString,"/");
   cout<<"Vector after join : "<<endl;
    cout <<s;


    return 0;
}
