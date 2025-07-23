#include <iomanip>
#include <iostream>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"
using namespace myInputLib;

using namespace myMathLib;
using namespace std;



struct ClientData {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};



string getWord(string str,string sep) {

    return str.substr(0,str.find(sep));
}

void fillVectorWithStrings(vector<string>& vStrings,string str,string sep) {

    while (str.find(sep)!=string::npos) {

        vStrings.push_back(getWord(str,sep));
        str=str.substr(str.find(sep)+sep.length(),str.length());
        if (str.find(sep)==string::npos) {
            vStrings.push_back(str);
            break;
        }



    }
}

void fillDataStruct(ClientData& clientData ,string str,string sep) {

    vector<string> vStrings;
    fillVectorWithStrings(vStrings,str,sep);

    clientData.accountNumber = vStrings[0];
    clientData.pinCode = vStrings[1];
    clientData.name = vStrings[2];
    clientData.phone = vStrings[3];
    clientData.accountBalance = stod(vStrings[4]);
}



void printClientData(ClientData client) {
    cout<<client.accountNumber<<endl<<client.pinCode<<endl<<client.name<<endl<<client.phone<<endl<<client.accountBalance<<endl;
}




int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


    ClientData clientData;

    fillDataStruct(clientData,"A101//123//noureddine//07777//0123","//");
    printClientData(clientData);




    return 0;
}
