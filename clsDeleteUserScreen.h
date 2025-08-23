#pragma once
#include "clsBankScreen.h"
#include "clsBankUser.h"


class clsDeleteUserScreen:protected clsBankScreen {

private:

public:

    static void showDeleteUserScreen() {

        showScreenType("Delete User Screen");

        clsBankUser user = clsBankUser::find(clsBankUser::readValidUserName());

        clsBankUser::printUser(user);

        if (clsInputValidate::yesNoQuestion("Are you sure you want to delete this user? Y/N")) {

            cout<<clsBankUser::getSaveStatusMessage(user.deleteUser());
            clsBankUser::printUser(user);
        }else {
            cout<<"Operaction has been canceled"<<endl;
        }


    }
};
