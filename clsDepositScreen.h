#pragma once
#include "clsBankScreen.h"



class clsDepositScreen:protected clsBankScreen {

private:

public:


    static void showDepositScreen() {

        showScreenType("Deposit Screen");

        clsBankClient client=clsBankClient::find(clsBankClient::readValidAccountNumber());

        printClient(client);

        const float amount =clsInputValidate::readFloat("Please enter deposit amount");

        if (clsInputValidate::yesNoQuestion("Are you sure you want to perform this this transaction?")) {
            client.deposit(amount);
            clsBankScreen::printClient(client);
        }else {
            cout<<"\n operation was canceled"<<endl;
        }

        cout<<"Amount Deposit successfully"<<endl;
        cout<<"New Balance is : "<<client.getBalance()<<endl;

    }



};
