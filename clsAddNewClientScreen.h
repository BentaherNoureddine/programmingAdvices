#pragma once
#include "clsBankScreen.h"
#include "clsBankClient.h"

class clsAddNewClientScreen:protected clsBankScreen {

private:


public:

    static void addNewClient() {


        showScreenType("Add new Client Screen");

        std::string accountNumber= clsInputValidate::readString("Please enter account Number");
        while (clsBankClient::isClientExists(accountNumber)) {
            cout<<"\n Account Number is already used, choose an other one : ";
            accountNumber=clsInputValidate::readString("Please enter account Number");
        }

        clsBankClient newClient=clsBankClient::getAddNewClientObject(accountNumber);

        clsBankClient::readClientInfo(newClient);

        clsBankClient::getSaveStatusMessage(newClient.save());


        printClient(newClient);
    }
};