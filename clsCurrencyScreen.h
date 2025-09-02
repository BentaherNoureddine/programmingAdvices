#pragma once
#include <iomanip>

#include "clsCurrency.h"


class clsCurrencyScreen{

private:


public:

      static void print( clsCurrency& currency){

            cout<<"Currency Card"<<endl;
            cout<<"___________________________________________________________"<<endl;
            cout<<"Country             "<<currency.getCountry()<<endl;
            cout<<"Code                "<<currency.getCurrencyCode()<<endl;
            cout<<"Rate(1$) =          "<<currency.getExchangeRateToUSD()<<endl;
            cout<<"___________________________________________________________"<<endl;
      }

};