#pragma once
#include "clsBankScreen.h"
#include "clsBankUser.h"
#include "clsLog.h"
#include "clsMainMenuScreen.h"
#include "global.h"


class clsLoginScreen:protected clsBankScreen {

private:

    static bool _login() {
        string userName =clsInputValidate::readString("Please Enter your UserName");
        string password =clsInputValidate::readString("Please Enter your Password");
        short trials=3;
        while (!clsBankUser::isUserExists(userName,password)) {
            trials--;
            cout<<"Account DONT EXISTS Please enter a NEW UserName and Password"<<endl;
            cout<<"You Have Only "<<trials<<" Trials left to Login."<<endl;

            if (trials==0) {
                cout<<"You are locked after 3 failed trails"<<endl;
                return false;
            }

            userName =clsInputValidate::readString("Please Enter your UserName");
            password =clsInputValidate::readString("Please Enter your Password");

        }

        CurrentUser=clsBankUser::find(userName,password);
        CurrentUser.registerLogin();
        clsMainMenuScreen::displayMainMenu();


        return true;
    }


public:

    static bool showLoginScreen() {
        system("clear");
        showScreenType("Login Screen");
        return _login();
    }
};
