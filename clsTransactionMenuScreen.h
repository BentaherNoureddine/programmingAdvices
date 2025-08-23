#pragma once
#include "clsBankScreen.h"
#include "clsDepositScreen.h"
#include "clsInputValidate.h"
#include "clsTotalbalancesScreen.h"
#include "clsWithdrawScreen.h"


class clsTransactionMenuScreen :protected clsBankScreen{

private:

    enum enTransactionsOptions {
        deposit=1,withdraw=2,totalBalances=3,mainMenu=4,
    };

    static void _printTransactionsOptions() {
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[1] Deposit."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[2] Withdraw."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[3] Total Balances."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[4] Main Menu."<<std::endl;
        std::cout<<"\n\t\t\t\t\t\t\t============================================================================\n"<<std::endl;

    }

    static enTransactionsOptions _readTransactionOption() {
        return (enTransactionsOptions)clsInputValidate::readShortNumberBetween(1,4,"chose what you want to do [1 to 4]");
    }

    static void _depositScreen() {
        clsDepositScreen::showDepositScreen();
    }

    static void _withdrawScreen() {
        clsWithdrawScreen::showWithdrawScreen();
    }

    static void _totalBalancesScreen() {
        clsTotalBalancesScreen::showTotalBalancesScreen();
    }

    static void _mainMenuScreen() {
    }

    static void _getBackToTransactionsMenu() {
        clsInputValidate::readString("Press Any thing to get back to Transaction Menu");
        showTransactionMenuScreen();
    }

    static void _performTransactionOption() {

        switch (_readTransactionOption()) {
            case enTransactionsOptions::deposit:
                system("clear");
                _depositScreen();
                _getBackToTransactionsMenu();
                break;
            case enTransactionsOptions::withdraw:
                system("clear");
                _withdrawScreen();
                _getBackToTransactionsMenu();
                break;
            case enTransactionsOptions::totalBalances:
                system("clear");
                _totalBalancesScreen();
                _getBackToTransactionsMenu();
                break;
            case enTransactionsOptions::mainMenu:
                system("clear");
                _mainMenuScreen();
                break;
            default:
                system("clear");
                _depositScreen();
                _getBackToTransactionsMenu();
                break;

        }
    }

public:

    static void showTransactionMenuScreen() {

        system("clear");
        showScreenType("Transactions Screen");
        showHeader("Transactions Menu");
        _printTransactionsOptions();
        _performTransactionOption();
    }
};
