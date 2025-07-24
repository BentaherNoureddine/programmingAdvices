#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"
#include "read_save_print_clientData.h"
using namespace fileClientData;
using namespace myInputLib;

using namespace myMathLib;
using namespace std;


void deleteLineFromVector(vector<string>& vLines,string word) {

    for (string& line : vLines) {
        if (line.find(word)!=string::npos) {
            line="";
        }
    }
}

void clearFile(const string& fileName) {
    ofstream file(fileName, ios::trunc); // Open in truncate mode
    file.close(); // Optional, but good practice
}


void saveVStringToFile(vector<string>vLines,string fileName ) {


    clearFile(fileName);

    for (string& line : vLines) {
        if (line!="") {
            saveToFile(fileName,line);
        }

    }
}


void deleteClientByAccountNumber(string accountNumber,string fileName) {

    vector<string> vLines= loadLinesFromFileToVector(fileName);
    deleteLineFromVector(vLines,accountNumber);
    saveVStringToFile(vLines,fileName);

    cout<<"Client deleted successfully"<<endl;


}




void deleteClientByAccountNumber(string accountNumber,string fileName,string sep) {


    char choice;
    if (findClientByAccountNumber(accountNumber,fileName,sep)) {
        cout<<"Are you sure you want to delete this Client(Y/N)"<<endl;
        cin>>choice;
        if (toupper(choice)=='Y') {
            deleteClientByAccountNumber(accountNumber,fileName);
        }
    }



}






int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    deleteClientByAccountNumber(readString("Please enter Account Number :"),"test.txt","//");








    return 0;
}