#pragma once
#include "clsBankScreen.h"
#include "clsCurrency.h"


class clsFindCurrencyScreen:protected clsBankScreen {

private:

    enum enFindByOptions {
        Code=1,Country=2
    };


    static enFindByOptions _readFindOption() {
        return (enFindByOptions)clsInputValidate::readShortNumberBetween(1,2,"Find By: [1] Code or [2] Country ?");
    }

    static void _findByCode() {
        if (clsCurrency currency=clsCurrency::findByCode(clsInputValidate::readString("Please Enter Currency Code")); !currency.isEmpty()) {
            cout<<"Currency Found!"<<endl;
            currency.print();
        }else {
            cout<<"Currency NOT Found"<<endl;
        }
    }


    static void _findByCountry(){
        if (clsCurrency currency=clsCurrency::findByCountry(clsInputValidate::readString("Please Enter Currency Country Name")); !currency.isEmpty()) {
            cout<<"Currency Found!"<<endl;
            currency.print();
        }else {
            cout<<"Currency NOT Found"<<endl;
        }
    }

    static void _performFind() {

        switch (_readFindOption()) {
            case Code:
                system("clear");
                _findByCode();
                break;
            case Country:
                system("clear");
                _findByCountry();
                break;
            default:
                system("clear");
                break;
        }
    }




public:



    static void showFindCurrencyScreen() {
        showScreenType("Find Currency Screen");
        _performFind();
    }
};
