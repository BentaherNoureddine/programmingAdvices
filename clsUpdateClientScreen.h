#pragma once
#include "clsBankClient.h"
#include "clsBankScreen.h"


class clsUpdateClientScreen:protected clsBankScreen {

private:

public:

    static void updateClientScreen() {

        if (!checkAccessRights(clsBankUser::enAddClient))
            return;

        showScreenType("Update Client Screen");

        clsBankClient client=clsBankClient::find(clsBankClient::readValidAccountNumber());

        printClient(client);

        std::cout<<"Update Client Info :"<<std::endl;
        std::cout<<"_________________________"<<std::endl;

        clsBankClient::readClientInfo(client);

        cout<<clsBankClient::getSaveStatusMessage(client.save());

        printClient(client);

    }

};