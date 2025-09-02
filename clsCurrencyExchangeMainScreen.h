#pragma once
#include "clsBankScreen.h"
#include "clsCurrency.h"
#include "clsFindCurrencyScreen.h"
#include "clsListCurrenciesScreen.h"


class clsCurrencyExchangeMainScreen:protected clsBankScreen {

private:

    enum enCurrencyExchangeOptions {
        ListCurrencies=1,FindCurrency=2,UpdateCurrency=3,CurrencyCalculator=4,MainMenu=5
    };

    static void _showCurrencyExchangeOptions() {
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[1] List Currencies."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[2] Find Currency."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[3] Update Currency."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[4] Currency Calculator."<<std::endl;
        std::cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t[5] Main Menu."<<std::endl;
    }

    static enCurrencyExchangeOptions _readCurrencyOption() {
        return (enCurrencyExchangeOptions)clsInputValidate::readShortNumberBetween(1,5,"Choose what you want to do [1 to 5]");
    }

    static void _showListCurrenciesScreen() {
        clsListCurrenciesScreen::showListCurrenciesScreen();
    }


    static void _showFindCurrencyScreen() {
       clsFindCurrencyScreen::showFindCurrencyScreen();
    }

    static void _showUpdateCurrencyScreen() {
        cout<<"update currency screen"<<endl;
    }

    static void _showCurrencyCalculatorScreen() {
        cout<<"currency calculator screen"<<endl;
    }

    static void _showMainMenu() {

    }

    static void _getBackToCurrencyExchangeMainScreen() {
        system("clear");
        char c;
        cout<<"Press anything to get back To currencies Menu"<<endl;
        cin>>c;
        showCurrencyExchangeMainScreen();
    }



    static void _performCurrencyExchangeOption() {

        switch (_readCurrencyOption()) {
            case ListCurrencies:
                system("clear");
                _showListCurrenciesScreen();
                _getBackToCurrencyExchangeMainScreen();
                break;
            case FindCurrency:
                system("clear");
                _showFindCurrencyScreen();
                _getBackToCurrencyExchangeMainScreen();
                break;
            case UpdateCurrency:
                system("clear");
                _showUpdateCurrencyScreen();
                _getBackToCurrencyExchangeMainScreen();
                break;
            case CurrencyCalculator:
                system("clear");
                _showCurrencyCalculatorScreen();
                _getBackToCurrencyExchangeMainScreen();
                break;
            case MainMenu:
                system("clear");
                break;
            default:
                system("clear");
                break;
        }


    }


public:


    static void showCurrencyExchangeMainScreen() {

        showScreenType("Currency Exchange Main Screen");
        showHeader("Currency Exchange Menu");
        _showCurrencyExchangeOptions();
        _performCurrencyExchangeOption();
    }
};
