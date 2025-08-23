#pragma once
#include "clsBankScreen.h"

class clsWithdrawScreen :protected clsBankScreen {

private:

public:


    static void showWithdrawScreen() {

        showScreenType("Withdraw Screen");

        clsBankClient client=clsBankClient::find(clsBankClient::readValidAccountNumber());

        printClient(client);

        float amount =clsInputValidate::readFloat("Please enter withdraw amount");

        if (clsInputValidate::yesNoQuestion("Are you sure you want to perform this this transaction?")) {
            while (!client.withdraw(amount)) {
                amount =clsInputValidate::readFloat("Cannot withdraw, Insufficient Balance!\n"
                "Amount to withdraw is: "+to_string(amount)+"\nYour Balance is: "+to_string(client.getBalance())+"\n");
            }
            clsBankScreen::printClient(client);
        }else {
            cout<<"\n operation was canceled"<<endl;
        }

        cout<<"Amount Withdraw successfully"<<endl;
        cout<<"New Balance is : "<<client.getBalance()<<endl;

    }


};