#include <fstream>
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
    float accountBalance;
};


void readClientData(ClientData& clientData) {

    cout<<"Please Enter Client Data"<<endl;
    clientData.accountNumber = readString("Enter account Number");
    clientData.pinCode = readString("Enter PinCode");
    clientData.name = readString("Enter your Name");
    clientData.phone = readString("Enter PhoneNumber");
    clientData.accountBalance = readFloat("Enter Account Balance");
}

string convertStructToString(ClientData clientData,string sep) {

    string str;
    str+=clientData.accountNumber+sep;
    str+=clientData.pinCode+sep;
    str+=clientData.name+sep;
    str+=clientData.phone+sep;
    str+=to_string(clientData.accountBalance);

    return str;
}

void saveToFile(string fileName,string str) {
    fstream file;
    file.open(fileName, ios::app);
    if (file.is_open()) {
        file<<str;
    }
    file<<endl;

    file.close();
}

bool getChoice() {
    char choice;
    cout<<"Client added successfully, Do you want to add more clients(Y/N)?"<<endl;
    cin>>choice;
    return  toupper(choice)=='Y';
}


void printClientData(ClientData client,string sep) {
    cout<<client.accountNumber<<sep<<client.pinCode<<sep<<client.name<<sep<<client.phone<<sep<<client.accountBalance<<endl;
}

void saveClientsToFile(ClientData clientData,string fileName,string sep) {

    bool keep=true;
    string str;

    do {
        readClientData(clientData);
        str=convertStructToString(clientData,sep);
        saveToFile(fileName,str);
        keep=getChoice();

    }while (keep==true);


}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


    ClientData client;
    saveClientsToFile(client,"test.txt","//");





    return 0;
}