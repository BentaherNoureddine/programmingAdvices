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
    short pinCode;
    string name;
    short phone;
    float accountBalance;
};


void readClientData(ClientData& clientData) {

    cout<<"Please Enter Client Data"<<endl;
    clientData.accountNumber = readString("Enter account Number");
    clientData.pinCode = readShort("Enter PinCode");
    clientData.name = readString("Enter your Name");
    clientData.phone = readShort("Enter PhoneNumber");
    clientData.accountBalance = readFloat("Enter Account Balance");
}

void printClientData(ClientData client,string sep) {
    cout<<client.accountNumber<<sep<<client.pinCode<<sep<<client.name<<sep<<client.phone<<sep<<client.accountBalance<<endl;
}




int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


    ClientData client;

    readClientData(client);
    printClientData(client,"#//#");




    return 0;
}
