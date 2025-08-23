#pragma once
#include "clsAddNewUserScreen.h"
#include "clsBankScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"


class clsManageUsersScreen:protected clsBankScreen {

private:

    enum enManageUsersOptions {
        ListUsers=1,AddUser=2,DeleteUser=3,UpdateUser=4,FindUser=5,MainMenu=6,
    };

    static void _printManageUsersOptions() {
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[1] List users."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[2] Add new user."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[3] Delete user."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[4] Update user."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[5] Find User."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[6] Main menu."<<std::endl;
        std::cout<<"\n\t\t\t\t\t\t\t============================================================================\n"<<std::endl;

    }

    static void _getBackToManageUsersMenu() {
        clsInputValidate::readString("Press anything to get back to Manage users menu");
        showManageUsersScreen();
    }

    static enManageUsersOptions _readManageUsersOption() {
        return (enManageUsersOptions)clsInputValidate::readShortNumberBetween(1,6,"Choose what you want to do [1 to 6]");
    }

    static void _listAllUsersScreen() {
        clsListAllUsersScreen::listAllUsersScreen();
    }

    static void _addUserScreen() {
        clsAddNewUserScreen::displayAddUserScreen();
    }

    static void _deleteUserScreen() {
       clsDeleteUserScreen::showDeleteUserScreen();
    }

    static void _updateUserScreen() {
        clsUpdateUserScreen::showUpdateUserScreen();
    }

    static void _findUserScreen() {
        clsFindUserScreen::showFindUserScreen();
    }

    static void _mainMenuScreen() {

    }


    static void _performManageUsersOption() {

        switch (_readManageUsersOption()) {
            case ListUsers:
                system("clear");
                _listAllUsersScreen();
                _getBackToManageUsersMenu();
                break;
            case AddUser:
                system("clear");
                _addUserScreen();
                _getBackToManageUsersMenu();
                break;
            case DeleteUser:
                system("clear");
                _deleteUserScreen();
                _getBackToManageUsersMenu();
                break;
            case UpdateUser:
                system("clear");
                _updateUserScreen();
                _getBackToManageUsersMenu();
                break;
            case FindUser:
                system("clear");
                _findUserScreen();
                _getBackToManageUsersMenu();
                break;
            case MainMenu:
                system("clear");
                _mainMenuScreen();
                break;
            default:
                system("clear");
                _listAllUsersScreen();
                _getBackToManageUsersMenu();
                break;

        }
    }


public:


    static void showManageUsersScreen() {

        showScreenType("Manage Users Screen");
        showHeader("Manage Users Menu");
        _printManageUsersOptions();
        _performManageUsersOption();

    }
};
