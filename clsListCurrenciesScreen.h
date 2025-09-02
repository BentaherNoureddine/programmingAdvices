#pragma once
#include <set>

#include "clsBankScreen.h"


class clsListCurrenciesScreen:protected clsBankScreen {
private:

    static void _printHeader() {
        cout<<clsUtility::tabs(5)<<"______________________________________________________________________________________________________________________________\n"<<endl;
        cout<<clsUtility::tabs(5)<<"| "<<left<<setw(30)<<"Country"<<"| "<<left<<setw(7)<<"Code"<<"| "<<left<<setw(40)<<"Name";
        cout<<"| "<<left<<setw(10)<<"Rate/(1$)"<<endl;
        cout<<clsUtility::tabs(5)<<"______________________________________________________________________________________________________________________________\n"<<endl;
    }

    static void _printCurrencyLine(clsCurrency& currency) {
        cout<<clsUtility::tabs(5)<<"| "<<left<<setw(30)<<currency.getCountry()<<"| "<<left<<setw(7)<<currency.getCurrencyCode()<<"| "<<left<<setw(40)<<currency.getCurrencyName();
        cout<<"| "<<left<<setw(10)<<currency.getExchangeRateToUSD()<<endl;
    }


    static void _printCurrencyList(vector<clsCurrency>& vCurrencies) {


        for (clsCurrency& currency:vCurrencies) {
            _printCurrencyLine(currency);
        }

        cout<<clsUtility::tabs(5)<<"____________________________________________________________________________________________________________________\n"<<endl;

    }


public:



    static void showListCurrenciesScreen() {

        vector<clsCurrency> vCurrencies=clsCurrency::getCurrenciesList();
        showScreenType("Currencies List Screen","("+to_string(vCurrencies.size())+") Currency.");
        _printHeader();
        _printCurrencyList(vCurrencies);
    }
};