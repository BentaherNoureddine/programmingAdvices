#pragma once
#include "clsBankScreen.h"
#include "clsBankUser.h"


class clsAddNewUserScreen : protected clsBankScreen {

private:


public:


    static void displayAddUserScreen() {

        showScreenType("Add New User Screen");

        const string userName=clsBankUser::readValidUserName();

        clsBankUser newUser=clsBankUser::getAddNewUserObject(userName);

        clsBankUser::readUserInfo(newUser);

        cout<<clsBankUser::getSaveStatusMessage(newUser.save());

        clsBankUser::printUser(newUser);



    }

};
