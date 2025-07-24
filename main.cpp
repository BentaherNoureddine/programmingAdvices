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




void updateClient(string accountNumber,string filename,string sep) {

    vector<string>vLines;
    vector<ClientData> vClients = getAllClientsFromFile(filename,sep);

    for (ClientData& client: vClients) {
        if (client.accountNumber==accountNumber) {
            readClientData(client);
        }
    }
    for (ClientData& client : vClients) {
        vLines.push_back(convertStructToString(client,sep));
    }
    saveVStringToFile(vLines,filename);




}




void updateClientByAccountNumber(string accountNumber,string fileName,string sep) {

    ClientData client;
    if (findClientByAccountNumber(accountNumber,fileName,sep)) {
        cout<<"Are you sure you want to update this client?"<<endl;
        updateClient(accountNumber,fileName,sep);
        cout<<"Client updated Successfully"<<endl;

    }

}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    updateClientByAccountNumber(readString("Please enter Account Number :"),"test.txt","//");








    return 0;
}