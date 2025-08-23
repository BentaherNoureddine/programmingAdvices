#include <iostream>
#include <string>

#include "clsBankClient.h"
#include "clsBankUser.h"
#include "global.h"
#pragma once

class clsBankScreen {

private:


   static  void _showAccessDeniedScreen() {

        std::system("clear");
        std::cout<<"\n\t\t\t\t\t\t\t----------------------------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Access Denied Please Contact Your Admin                                  "<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t------------------------------------------------------------------------------------------------------\n"<<std::endl;
    }


protected:

    static void showScreenType(const std::string title,const std::string subTitle="") {
        std::system("clear");
        std::cout<<"\n\t\t\t\t\t\t\t-------------------------------------------------------------------------"<<std::endl;
        std::cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<title<<"                                 "<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<subTitle<<"                                 "<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t-------------------------------------------------------------------------\n"<<std::endl;
        std::cout<<"\t\t\t\t\t\t\tuser: "<<CurrentUser.getUserName()<<std::endl;
        std::cout<<"\t\t\t\t\t\t\tDate: "<<clsDate::getSystemDate().dateToString()<<endl;
    }



    static void showHeader(const std::string header) {
        std::cout<<"\n\t\t\t\t\t\t\t============================================================================"<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t                            "<<header<<"                                 "<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t============================================================================\n"<<std::endl;
    }


    static void printClient(clsBankClient client) {
        cout << "\n"<<clsUtility::tabs(10)<<"Client Card:";
        cout << "\n"<<clsUtility::tabs(10)<<"___________________";
        cout << "\n"<<clsUtility::tabs(10)<<"FirstName       : " << client.getFirstName();
        cout << "\n"<<clsUtility::tabs(10)<<"LastName        : " << client.getLastName();
        cout << "\n"<<clsUtility::tabs(10)<<"Full Name       : " << client.fullName();
        cout << "\n"<<clsUtility::tabs(10)<<"Email           : " << client.getEmail();
        cout << "\n"<<clsUtility::tabs(10)<<"Phone           : " << client.getPhone();
        cout << "\n"<<clsUtility::tabs(10)<<"Account. Number : " << client.getAccountNumber();
        cout << "\n"<<clsUtility::tabs(10)<<"Password        : " << client.getPinCode();
        cout << "\n"<<clsUtility::tabs(10)<<"Balance         : " << client.getBalance();
        cout << "\n"<<clsUtility::tabs(10)<<"___________________\n";
    }



    static bool checkAccessRights(clsBankUser::enPermissions permissions) {
        if (CurrentUser.hasPermissions(permissions)) {
            return true;
        }
        _showAccessDeniedScreen();
        return false;

    }





};