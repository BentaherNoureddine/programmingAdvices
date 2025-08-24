#pragma once
#include "clsBankScreen.h"


class clsTransferLogScreen : protected clsBankScreen {

private:


    static void _printLogLine(const clsBankClient::stLogTransfer &logLine) {
        cout<<clsUtility::tabs(7)<<"| "<<left<<setw(30)<<logLine.dateTime<<"| "<<left<<setw(12)<<logLine.sourceAccountNumber;
        cout<<"| "<<left<<setw(12)<<logLine.destinationAccountNumber<<"| "<<left<<setw(12)<<logLine.amount;
        cout<<"| "<<left<<setw(12)<<logLine.sourceBalance<<"| "<<left<<setw(12)<<logLine.destinationBalance;
        cout<<"| "<<left<<setw(12)<<logLine.userUserName<<endl;
    }



public:

    static void showTransferLogScreen() {

        const vector<clsBankClient::stLogTransfer> vLogs=clsBankClient::getAllTransferLogs();
        showScreenType("Transfer Log List Screen","("+to_string(vLogs.size())+") Record(s) ");

        cout<<"\n"<<clsUtility::tabs(7)<<"________________________________________________________________________________________________________________\n"<<endl;
        cout<<clsUtility::tabs(7)<<"| "<<left<<setw(30)<<"Date/Time"<<"| "<<left<<setw(12)<<"s.account";
        cout<<"| "<<left<<setw(12)<<"d.account"<<"| "<<left<<setw(12)<<"Amount";
        cout<<"| "<<left<<setw(12)<<"s.Balance"<<"| "<<left<<setw(12)<<"d.balance";
        cout<<"| "<<left<<setw(12)<<"User"<<endl;
        cout<<"\n"<<clsUtility::tabs(7)<<"________________________________________________________________________________________________________________\n"<<endl;

        for (const clsBankClient::stLogTransfer& log:vLogs) {
            _printLogLine(log);
        }

        cout<<"\n"<<clsUtility::tabs(7)<<"________________________________________________________________________________________________________________\n"<<endl;
    }
};