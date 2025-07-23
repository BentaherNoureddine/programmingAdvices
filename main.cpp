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



struct ClientData {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    float accountBalance;
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

ClientData fillDataStruct( string str,string sep) {

    ClientData clientData;
    vector<string> vStrings;
    fillVectorWithStrings(vStrings,str,sep);

    clientData.accountNumber = vStrings[0];
    clientData.pinCode = vStrings[1];
    clientData.name = vStrings[2];
    clientData.phone = vStrings[3];
    clientData.accountBalance = stod(vStrings[4]);

    return clientData;
}



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



vector<string> loadLinesFromFileToVector(string fileName ) {

    vector<string> vFileContent;
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vFileContent.push_back(line);
        }
    }
    file.close();
    return  vFileContent;

}

vector<ClientData> convertVstringToVclient(vector<string> vStrings,string sep) {

    vector<ClientData> vClients;
    ClientData clientData;
    for (string& line :vStrings) {
        vClients.push_back(fillDataStruct(line,sep));
    }

    return vClients;
}





vector<ClientData> getAllClientsFromFile(string fileName,string sep) {


    vector<string> vLines=loadLinesFromFileToVector(fileName);
    vector<ClientData> vClientsData=convertVstringToVclient(vLines,sep);

    return vClientsData;
}



void printClientData(ClientData clientData) {

    cout<<"| "<<setw(20)<<clientData.accountNumber<<"| "<<setw(20)<<clientData.pinCode<<"| "<<setw(20)<<clientData.name<<"| "<<setw(20)<<clientData.phone<<"| "<<setw(20)<<clientData.accountBalance<<endl;

}


void printClientsData(vector<ClientData> clientsData,string fileName,string sep) {
    clientsData =getAllClientsFromFile(fileName,sep);
    for (ClientData& clientData : clientsData ) {
        printClientData(clientData);

    }
}




void printClients(string fileName,string sep) {
    vector<ClientData> clientsData =getAllClientsFromFile(fileName,sep);
    cout <<"                                   Client List ("<<clientsData.size()<<") Client(s)."<<endl;
    cout<<"___________________________________________________________________________________________________________________"<<endl;
    cout<<setw(20)<<"| Account Number"<<setw(20)<<"|Pin Code"<<setw(20)<<"|Client Name"<<setw(20)<<"|phone"<<setw(20)<<"Balance"<<endl;
    cout<<"___________________________________________________________________________________________________________________"<<endl;
    printClientsData(clientsData,fileName,sep);
    cout<<"___________________________________________________________________________________________________________________"<<endl;

}


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));


    ClientData client;
    saveClientsToFile(client,"test.txt","//");
    printClients("test.txt","//");





    return 0;
}