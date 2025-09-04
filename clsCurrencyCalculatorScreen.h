#pragma once
#include "clsBankScreen.h"
#include "clsCurrency.h"


class clsCurrencyCalculatorScreen:protected clsBankScreen {

private:

    static string _readValidCurrencyCode(const string& message) {
        string currencyCode=clsInputValidate::readString(message);

        while (!clsCurrency::isCurrencyExists(currencyCode)) {
            currencyCode=clsInputValidate::readString("Currency NOT Found please Enter a new one ");
        }
        return currencyCode;
    }



    static void _calculateCurrency() {
        clsCurrency currency1=clsCurrency::findByCode(_readValidCurrencyCode("Please Enter Currency 1 Code"));
        clsCurrency currency2=clsCurrency::findByCode(_readValidCurrencyCode("Please Enter Currency 2 Code"));
        const float amount=clsInputValidate::readNumber<float>("Enter Amount to Exchange");
        cout<<"Convert From"<<endl;
        currency1.print();
        cout<<amount<<" "<<currency1.getCurrencyCode()<<" = "<<clsCurrency::getCurrencyRate(currency1,currency2,amount)<<" "<<currency2.getCurrencyCode()<<endl;
    }


public:


    static void showCurrencyCalculatorScreen() {
        showScreenType("Currency Calculator Screen");
        do {
            system("clear");
           _calculateCurrency();
        }while (clsInputValidate::yesNoQuestion("Do you want to perform another calculation? y/n"));

    }
};
