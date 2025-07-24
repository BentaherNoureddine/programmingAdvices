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




void printClient(ClientData client) {

    cout<<"Account Number: "<<client.accountNumber<<endl;
    cout<<"Pin Code: "<<client.pinCode<<endl;
    cout<<"Name: "<<client.name<<endl;
    cout<<"Phone : "<<client.phone<<endl;
    cout<<"Account Balance: "<<client.accountBalance<<endl;
}




void findClientByAccountNumber(string accountNumber,string fileName,string sep) {

    vector<ClientData> clientsData = getAllClientsFromFile(fileName,sep);
    short check=0;
    cout<<"The following are the client details :"<<endl;
    for (ClientData& client:clientsData) {
        if (client.accountNumber==accountNumber) {
            printClient(client);
            check++;
        }
    }
    if (check<=0) {
        cout<<"There is NO client with this Account Number"<<endl;
    }

}




int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    string accountNumber=readString("Please enter Account Number :");
    findClientByAccountNumber(accountNumber,"test.txt","//");








    return 0;
}