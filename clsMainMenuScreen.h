#pragma once
#include "clsAddNewClientScreen.h"
#include "string"
#include "clsBankScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsInputValidate.h"
#include "clsLoginRegisterScreen.h"
#include "clsManageUsersScreen.h"
#include "clsShowAllClientsScreen.h"
#include "clsTransactionMenuScreen.h"
#include "clsUpdateClientScreen.h"
#include "global.h"


class clsMainMenuScreen :protected clsBankScreen {
private:

    enum enMainMenuOptions {
        enShowClients=1,
        enAddClient=2,
        enDeleteClient=3,
        enUpdateClient=4,
        enFindClient=5,
        enTransactions=6,
        enManageUsers=7,
        enLoginRegister=8,
        enLogout=9,
    };

    static void _printMainMenuActionsList() {
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[1] Show Clients List."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[2] Add new Client."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[3] Delete Client."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[4] Update Client."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[5] Find Client."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[6] Transactions."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[7] Manage Users."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[8] Login Register."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[9] Logout."<<std::endl;
        std::cout<<"\n\t\t\t\t\t\t\t============================================================================\n"<<std::endl;

    }

    static enMainMenuOptions readMainMenuOption(const std::string message) {
        return (enMainMenuOptions)clsInputValidate::readShortNumberBetween(1,9,message);
    }


    static void _showAllClientsScreen() {
        clsShowAllClientsScreen::showAllClients();
    }

    static void _showAddClientsScreen() {
        clsAddNewClientScreen::showAddNewClientScreen();
    }

    static void _showDeleteClientsScreen() {
        clsDeleteClientScreen::deleteClientScreen();
    }


    static void _showUpdateClientsScreen() {
        clsUpdateClientScreen::updateClientScreen();
    }

    static void _showFindClientScreen() {
        clsFindClientScreen::findClientScreen();
    }

    static void _showTransactionScreen() {
        clsTransactionMenuScreen::showTransactionMenuScreen();
    }

    static void _showManageUsersScreen() {
        clsManageUsersScreen::showManageUsersScreen();
    }

    static void _showLoginRegisterScreen() {
        clsLoginRegisterScreen::showLoginRegisterScreen();
    }


    static void _goBackToMainMenu() {

        clsInputValidate::readString("\nPress any thing to getBack to Main Menu");

        displayMainMenu();
    }

    static void _logout() {
        CurrentUser=clsBankUser::getEmptyUserObject();

    }

    static void _performMainMenuAction(const std::string message) {

        switch (readMainMenuOption(message)) {
            case enShowClients:
                system("clear");
                _showAllClientsScreen();
                _goBackToMainMenu();
                break;
            case enAddClient:
                system("clear");
                _showAddClientsScreen();
                _goBackToMainMenu();
                break;
            case enDeleteClient:
                system("clear");
                _showDeleteClientsScreen();
                _goBackToMainMenu();
                break;
            case enUpdateClient:
                system("clear");
                _showUpdateClientsScreen();
                _goBackToMainMenu();
                break;
            case enFindClient:
                system("clear");
                _showFindClientScreen();
                _goBackToMainMenu();
                break;
            case enTransactions:
                system("clear");
                _showTransactionScreen();
                _goBackToMainMenu();
                break;
            case enManageUsers:
                system("clear");
                _showManageUsersScreen();
                _goBackToMainMenu();
                break;
            case enLoginRegister:
                system("clear");
                _showLoginRegisterScreen();
                _goBackToMainMenu();
            case enLogout:
                system("clear");
                _logout();
                break;
            default:
                system("clear");
                _showAllClientsScreen();
                _goBackToMainMenu();

        }


    }


public:

    static void displayMainMenu() {
        showScreenType("Main Menu");
        showHeader("Main Menu");
        _printMainMenuActionsList();
        _performMainMenuAction("choose what do you want to do [1 to 9]");

    }


};
