#pragma once
#include "clsBankClient.h"
#include "clsBankScreen.h"


class clsShowAllClientsScreen:protected clsBankScreen {

private:
    static void _printClientRecordLine(clsBankClient client) {
        cout<<"| "<<left<<setw(15)<<client.getAccountNumber()<<"| "<<left<<setw(22)<<client.fullName()<<"| "<<left<<setw(17)<<client.getPhone();
        cout<<"| "<<left<<setw(30)<<client.getEmail()<<"| "<<left<<setw(15)<<client.getPinCode()<<"| "<<left<<setw(20)<<client.getBalance()<<endl;

    }



public:

    static void showAllClients() {

        if (!checkAccessRights(clsBankUser::enPermissions::enShowClients))
            return;

        std::vector<clsBankClient> vClients=clsBankClient::getClientsList();

        showScreenType("Client List Screen","("+to_string(vClients.size())+") Client(s)");


        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;
        cout<<"| "<<left<<setw(15)<<"Account Number"<<"| "<<left<<setw(22)<<"Client Name"<<"| "<<left<<setw(17)<<"Phone Number";
        cout<<"| "<<left<<setw(30)<<"Email"<<"| "<<left<<setw(15)<<"Pin Code"<<"| "<<left<<setw(20)<<"Balance"<<endl;
        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;

        if (vClients.empty()) {
            cout<<"\n\t\t\t\t\t\t\t\t\t\tNo clients available in the system"<<endl;
            return;
        }

        for (clsBankClient& client:vClients) {
            _printClientRecordLine(client);
        }

        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;

        }
};