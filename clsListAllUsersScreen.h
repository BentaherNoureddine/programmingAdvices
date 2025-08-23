#pragma once
#include "clsBankScreen.h"
#include "clsBankUser.h"


class clsListAllUsersScreen : protected clsBankScreen {

private:

    static void _printUserLine(clsBankUser user) {
        cout<<clsUtility::tabs(5)<<"____________________________________________________________________________________________________________________________\n"<<endl;
        cout<<clsUtility::tabs(5)<<"| "<<left<<setw(15)<<user.getUserName()<<"| "<<left<<setw(20)<<user.fullName()<<"| "<<left<<setw(16)<<user.getPhone();
        cout<<"| "<<left<<setw(28)<<user.getEmail()<<"| "<<left<<setw(20)<<user.getPassword()<<"| "<<left<<setw(8)<<user.getPermissions()<<endl;
    }

public:


    static void listAllUsersScreen() {
        vector<clsBankUser> vUsers=clsBankUser::getAllUsers();
        showScreenType("Users List Screen","("+to_string(vUsers.size())+") user(s)");

        //HEADER
        cout<<clsUtility::tabs(5)<<"___________________________________________________________________________________________________________________________\n"<<endl;
        cout<<clsUtility::tabs(5)<<"| "<<left<<setw(15)<<"userName"<<"| "<<left<<setw(20)<<"Full Name"<<"| "<<left<<setw(16)<<"Phone";
        cout<<"| "<<left<<setw(28)<<"Email"<<"| "<<left<<setw(20)<<"Password"<<"| "<<left<<setw(8)<<"permissions"<<endl;

        for (clsBankUser& user:vUsers) {
            _printUserLine(user);
        }

        cout<<clsUtility::tabs(5)<<"____________________________________________________________________________________________________________________________\n"<<endl;
    }
};
