#include <iostream>
#include <string>

#include "clsBankClient.h"
#pragma once

class clsBankScreen {

private:




protected:

    static void showScreenType(const std::string title,const std::string subTitle="") {
        std::system("clear");
        std::cout<<"\n\t\t\t\t\t\t\t-------------------------------------------------------------------------"<<std::endl;
        std::cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<title<<"                                 "<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<subTitle<<"                                 "<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t-------------------------------------------------------------------------\n"<<std::endl;
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





};