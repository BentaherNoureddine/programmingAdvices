#pragma once
#include "clsBankScreen.h"


class clsTransferScreen :protected clsBankScreen{


private:

    static string _readValidAccountNumber() {
        string accountNumber=clsInputValidate::readString("Please Enter Account number to transfer from: ");
        while (!clsBankClient::isClientExists(accountNumber)) {
            accountNumber=clsInputValidate::readString("Client DONT exists, Please Enter Account number to transfer from: ");
        }
        return accountNumber;
    }



    static double _readAmount(clsBankClient sourceClient) {
        double amount=clsInputValidate::readNumber<double>("Enter Transfer Amount");
        while (amount>sourceClient.getBalance()) {
            amount=clsInputValidate::readNumber<double>("Amount exceeded the sender client, Please  Enter new Transfer Amount");
        }
        return amount;
    }



    static void _transfer() {

        clsBankClient clientFrom =clsBankClient::find(_readValidAccountNumber());
        printClient(clientFrom);

        clsBankClient clientTo =clsBankClient::find(_readValidAccountNumber());
        printClient(clientTo);

        const double amount=_readAmount(clientFrom);

        if (clsInputValidate::yesNoQuestion("Are you sure you want to perform this operation? Y/N")) {
            if (clsBankClient::transfer(clientFrom,clientTo,amount)) {

                cout<<"Transfer Done successfully "<<endl;
                printClient(clientFrom);
                printClient(clientTo);

            }
        }else {
            cout<<"Operation Canceled"<<endl;
        }

    }


public:

    static void showTransferScreen() {

        showScreenType("Transfer Screen");
        _transfer();
    }
};
