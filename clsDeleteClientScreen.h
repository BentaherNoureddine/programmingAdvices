#pragma once
#include "clsBankClient.h"
#include "clsBankScreen.h"

class clsDeleteClientScreen: protected clsBankScreen {

private:



public:

    static void deleteClientScreen() {

        if (!checkAccessRights(clsBankUser::enDeleteClient))
            return;

        showScreenType("Delete Client Screen");

        clsBankClient client=clsBankClient::find(clsBankClient::readValidAccountNumber());

        printClient(client);

        if (clsInputValidate::yesNoQuestion("Are you sure you want to delete this Client Y/N? ")) {
                cout<<clsBankClient::getSaveStatusMessage(clsBankClient::deleteClient(client.getAccountNumber()));
                client=clsBankClient::getEmptyClientObject();

        }

        printClient(client);

    }
};