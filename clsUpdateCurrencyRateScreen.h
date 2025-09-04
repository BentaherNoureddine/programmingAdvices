#pragma once
#include "clsBankScreen.h"


class clsUpdateCurrencyRateScreen:protected clsBankScreen {

private:

    static void _performUpdateRate(clsCurrency& currency) {
        cout<<"Update Currency Rate"<<endl;
        cout<<"________________________________"<<endl;
        currency.updateExchangeRate(clsInputValidate::readNumber<float>("Enter New Rate"));
    }

public:



    static void showUpdateCurrencyRateScreen() {
        showScreenType("Update Currency Rate Screen");
        string currencyCode=clsInputValidate::readString("Please Enter  Currency Code");

        while (!clsCurrency::isCurrencyExists(currencyCode)) {
            currencyCode=clsInputValidate::readString("Currency NOT Found please Enter a new one ");
        }
        clsCurrency currency=clsCurrency::findByCode(currencyCode);

        currency.print();

        if (clsInputValidate::yesNoQuestion("Are you sure you want to update the rate of this Currency y/n?")) {
            _performUpdateRate(currency);
            cout<<"Currency Rate Updated Successfully"<<endl;
            currency.print();
        }
    }

};