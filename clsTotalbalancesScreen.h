#pragma once
#include "clsBankScreen.h"


class clsTotalBalancesScreen:protected clsBankScreen {

private:
    static void _printClientBalanceLine(clsBankClient client) {
        cout<<clsUtility::tabs(10)<<"| "<<left<<setw(15)<<client.getAccountNumber()<<"| "<<left<<setw(30)<<client.fullName()<<"| "<<left<<setw(30)<<client.getBalance()<<endl;
    }

public:

    static void showTotalBalancesScreen() {


        std::vector<clsBankClient> vClients=clsBankClient::getClientsList();

        showScreenType("Total balances Screen","("+to_string(vClients.size())+") client(s)");


        //HEADER
        std::cout<<clsUtility::tabs(14)<<"Clients List ("<<vClients.size()<<") Client(s)"<<endl;
        cout<<"\n"<<clsUtility::tabs(10)<<"_____________________________________________________________________________________\n"<<endl;
        cout<<clsUtility::tabs(10)<<"| "<<left<<setw(15)<<"Account Number"<<"| "<<left<<setw(30)<<"Client Name"<<"| "<<left<<setw(30)<<"Balance"<<endl;
        cout<<"\n"<<clsUtility::tabs(10)<<"_____________________________________________________________________________________\n"<<endl;

        //PRINT CLIENT BALANCES LIST
        for (clsBankClient& client:vClients) {
            _printClientBalanceLine(client);
        }

        if (vClients.empty())
            cout<<clsUtility::tabs(10)<<"No clients available in the system"<<endl;
        else
            cout<<"\n"<<clsUtility::tabs(10)<<"_____________________________________________________________________________________\n"<<endl;

            const double totalBalances=clsBankClient::getTotalBalances();

            cout<<"\n"<<clsUtility::tabs(14)<<"Total balances = "<<totalBalances<<endl;
            cout<<"\n"<<clsUtility::tabs(13)<<"("<<clsUtility::numberToText(totalBalances)<<")"<<endl;


    }
};