#pragma once
#include "clsBankClient.h"
#include "clsBankScreen.h"



class clsFindClientScreen: protected clsBankScreen {

private:

public:

    static void findClientScreen() {

        if (!checkAccessRights(clsBankUser::enFindClient))
            return;

        showScreenType("Find Client Screen");

        clsBankClient client = clsBankClient::find(clsBankClient::readValidAccountNumber());

        if (client.isEmpty()) {
            std::cout << "Client is Not Found" << std::endl;
        } else {
            printClient(client);
        }

    }
};