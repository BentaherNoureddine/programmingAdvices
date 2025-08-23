#pragma once
#include "clsBankScreen.h"
#include "clsBankUser.h"


class clsUpdateUserScreen:protected clsBankScreen {

private:

public:



    static void showUpdateUserScreen() {
        showScreenType("Update User Screen");

        clsBankUser user =clsBankUser::find(clsBankUser::readValidUserName());

        clsBankUser::printUser(user);

        if (clsInputValidate::yesNoQuestion("Are you sure you want to delete this user? Y/N")) {

            clsBankUser::readUserInfo(user);
            cout<<clsBankUser::getSaveStatusMessage(user.save());
            clsBankUser::printUser(user);

        }else {
            cout<<"Operation canceled"<<endl;
        }
    }
};
