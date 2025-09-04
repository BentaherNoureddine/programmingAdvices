#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "clsUtility.h"


class clsCurrency {

private:

    enum enMode{EmptyMode=0,UpdateMode=1};

    enMode _mode;
    std::string _country;
    std::string _countryCode;
    std::string _currencyName;
    float _exchangeRateToUSD=0;





    static clsCurrency _convertLineToCurrencyObject(const std::string& line,const std::string& sep="//") {
        const std::vector<std::string> vItems=clsString::Split(line,sep);
        return clsCurrency(enMode::UpdateMode,vItems[0],vItems[1],vItems[2],stof(vItems[3]));
    }

    static std::string _convertCurrencyObjectToLine(const clsCurrency& currency,const std::string& sep="//") {
        return currency._country+sep+currency._countryCode+sep+currency._currencyName+sep+to_string(currency._exchangeRateToUSD);
    }


    static std::vector<clsCurrency> _loadAllCurrenciesFromFile(const std::string& sep="//") {
        std::vector<clsCurrency> vCurrencies;
        std::fstream file;

        file.open("currenciesFile.txt",std::ios::in);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file,line)) {
                vCurrencies.push_back(_convertLineToCurrencyObject(line,sep));
            }
           file.close();
        }
        return vCurrencies;
    }


    static void _saveVCurrenciesToFile(const std::vector<clsCurrency>& vCurrencies,const std::string& sep="//") {
        std::fstream file;
        file.open("currenciesFile.txt",std::ios::out|std::ios::app);
        if (file.is_open()) {
            std::string line;
            for (const clsCurrency& currency:vCurrencies) {
                file<<_convertCurrencyObjectToLine(currency)<<endl;
            }
            file.close();
        }
    }


    void _update() const {
        std::vector<clsCurrency> vCurrencies=_loadAllCurrenciesFromFile();

        for (clsCurrency& currency:vCurrencies) {
            if (currency._country==this->_country) {
                currency=*this;
                _saveVCurrenciesToFile(vCurrencies);
                break;
            }
        }
    }



public:


    clsCurrency(const enMode mode, const std::string &country, const std::string &countryCode, const std::string &currencyName,float exchangeRateToUSD) {
        this->_mode=mode;
        this->_country=country;
        this->_countryCode=countryCode;
        this->_currencyName=currencyName;
        this->_exchangeRateToUSD=exchangeRateToUSD;
    }


    static clsCurrency getEmptyCurrencyObject() {
        return clsCurrency(enMode::EmptyMode,"","","",0);
    }

    bool isEmpty() {
        return this->_mode==enMode::EmptyMode;
    }


    std::string getCountry() {
        return  this->_country;
    }

    std::string getCurrencyName() {
        return this->_currencyName;
    }

    std::string getCurrencyCode() {
        return this->_countryCode;
    }


    float getExchangeRateToUSD() {
        return this->_exchangeRateToUSD;
    }

    void updateExchangeRate(const float& exchangeRateToUSD) {
        this->_exchangeRateToUSD=exchangeRateToUSD;
        _update();
    }







    static clsCurrency findByCode(const std::string& countryCode) {

        const std::vector<clsCurrency> vCurrencies=_loadAllCurrenciesFromFile();
        for (const clsCurrency& currency:vCurrencies) {
            if (clsString::UpperAllString(currency._countryCode)==clsString::UpperAllString(countryCode)) {
                return currency;
            }
        }
        return getEmptyCurrencyObject();
    }

    static clsCurrency findByCountry(const std::string& country) {
        const std::vector<clsCurrency> vCurrencies=_loadAllCurrenciesFromFile();
        for (const clsCurrency& currency:vCurrencies) {
            if (clsString::UpperAllString(currency._country)==clsString::UpperAllString(country)) {
                return currency;
            }
        }
        return getEmptyCurrencyObject();
    }


    static bool isCurrencyExists(const std::string& currencyCode) {
        return !findByCode(currencyCode).isEmpty();
    }

    static vector<clsCurrency> getCurrenciesList() {
        return _loadAllCurrenciesFromFile();
    }

    static float getCurrencyRate(clsCurrency from,clsCurrency to,const float amount) {
        const float usdtAMount=amount/from.getExchangeRateToUSD();
        return usdtAMount*to.getExchangeRateToUSD();
    }


    void print() {
        cout<<"_________________________________________"<<endl;
        cout<<"Country         :"<<this->getCountry()<<endl;
        cout<<"Code            :"<<this->getCurrencyCode()<<endl;
        cout<<"Name            :"<<this->getCurrencyName()<<endl;
        cout<<"Rate(1$) =      :"<<this->getExchangeRateToUSD()<<endl;
        cout<<"_________________________________________"<<endl;
    }



};
