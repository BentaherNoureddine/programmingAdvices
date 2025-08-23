#pragma once
#include "clsBankScreen.h"
#include "clsBankUser.h"


class clsAddNewUserScreen : protected clsBankScreen {

private:


public:


    static void displayAddUserScreen() {
        if (!checkAccessRights(clsBankUser::enAddClient))
            return;

        showScreenType("Add New User Screen");

        string userName=clsInputValidate::readString("Please enter a username");

        while (clsBankUser::isUserExists(userName)) {
            userName=clsInputValidate::readString("UserName already exists Please enter a new username");
        }

        clsBankUser newUser=clsBankUser::getAddNewUserObject(userName);

        clsBankUser::readUserInfo(newUser);

        cout<<clsBankUser::getSaveStatusMessage(newUser.save());

        clsBankUser::printUser(newUser);



    }

};
