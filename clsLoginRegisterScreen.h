#pragma once
#include "clsBankScreen.h"


class clsLoginRegisterScreen :protected clsBankScreen {


private:
    static void _printLogRecordLine(clsBankUser::stLog log) {
        cout<<"| "<<left<<setw(30)<<log.dateTime<<"| "<<left<<setw(22)<<log.userName<<"| "<<left<<setw(17)<<log.password;
        cout<<"| "<<left<<setw(10)<<log.permissions<<endl;

    }

public:

    static void showLoginRegisterScreen() {

        if (!checkAccessRights(clsBankUser::enPermissions::enLogRegister))
            return;



        const vector<clsBankUser::stLog> vLogs=clsBankUser::getAllLogs();

        showScreenType("Login Register List Screen","("+to_string(vLogs.size())+") Record(s)");


        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;
        cout<<"| "<<left<<setw(30)<<"Date-Time"<<"| "<<left<<setw(22)<<"UserName"<<"| "<<left<<setw(17)<<"Password";
        cout<<"| "<<left<<setw(10)<<"Permissions"<<endl;
        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;

        if (vLogs.empty()) {
            cout<<"\n\t\t\t\t\t\t\t\t\t\tNo logs available in the system"<<endl;
            return;
        }

        for (clsBankUser::stLog log:vLogs) {
            _printLogRecordLine(log);
        }

        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;


    }
};