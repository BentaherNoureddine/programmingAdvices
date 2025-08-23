#pragma once
#include "clsBankScreen.h"


class clsFindUserScreen:protected clsBankScreen {

private:

public:



    static void showFindUserScreen() {

        showScreenType("Find User Screen");

        clsBankUser::printUser(clsBankUser::find(clsBankUser::readValidUserName()));
    }

};