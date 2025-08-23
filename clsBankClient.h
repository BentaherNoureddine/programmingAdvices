#pragma once
#include <fstream>
#include <vector>
#include "bank_library.h"
#include "clsPerson.h"
#include "clsUtility.h"


class clsBankClient: public clsPerson{

private:

    enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2,DeleteMode=3};

    enum enSaveResults{svFailedEmptyObject=0,svSucceeded=1,svCreated=2,svFailedAccountNumberExists=3,svDeleted=4};




    enMode _mode;
    std::string _accountNumber;
    std::string _pinCode;
    float _balance;





    static clsBankClient _convertLineToClientObject(const std::string line,const std::string sep="//") {
        std::vector<std::string> vItems=clsString::Split(line,sep);
        return clsBankClient(enMode::UpdateMode,vItems[0],vItems[1],vItems[2],vItems[3],vItems[4],vItems[5],stof(vItems[6]));
    }

    static std::vector<clsBankClient> _getAllClientsObjectsFromFile(const std::string sep="//") {
        std::vector<clsBankClient> vClients;
        fstream file;
        std::string line;
        file.open("bank_file.txt",ios::in);
        if (file.is_open()) {
            while (getline(file,line)&&!line.empty()) {
                vClients.push_back(_convertLineToClientObject(line,sep));
            }
            file.close();
        }
        return vClients;
    }


    static std::string _convertClientObjectToLine(clsBankClient client,const std::string sep="//") {
        return client.getFirstName()+sep+client.getLastName()+sep+client.getEmail()+sep+client.getPhone()+sep+client.getAccountNumber()+sep+client.getPinCode()+sep+to_string(client.getBalance());
    }

    static void _saveVClientsObjectsToFile(vector<clsBankClient> vClients,const std::string sep="//") {

        fstream file;
        std::string line;
        file.open("bank_file.txt",std::ios::out);
        if (file.is_open()) {
            for (clsBankClient& client:vClients) {
                if (client._mode!=enMode::DeleteMode) {
                    line=_convertClientObjectToLine(client,sep);
                    file <<line<<endl;
                }
            }
            file.close();
        }
    }


    void _addDataLineToFile(std::string line,std::string delim="//") {

        fstream file;
        file.open("bank_file.txt",ios::app);
        if (file.is_open()) {
            file<<line<<endl;;
        }
        file.close();
    }




    static clsBankClient _getEmptyClientObject() {
        return clsBankClient(enMode::EmptyMode,"","","","","","",0);
    }






    void _update() {

        vector<clsBankClient> vClients= _getAllClientsObjectsFromFile();

        for (clsBankClient& client:vClients) {
           if (client.getAccountNumber()==this->getAccountNumber()) {
               client=*this;
               break;
           }
        }

        _saveVClientsObjectsToFile(vClients);
    }


    void _create() {

        _addDataLineToFile(_convertClientObjectToLine(*this));
    }









public:

    static std::string readValidAccountNumber() {
        std::string accountNumber=clsInputValidate::readString("Please enter client account Number : ");

        while (!isClientExists(accountNumber)) {
            std::cout<<"Account Number is not found, choose an other one: ";
            accountNumber=clsInputValidate::readString("");
        }
        return accountNumber;
    }

    static std::string getSaveStatusMessage(const enSaveResults saveResult) {
        switch (saveResult) {
            case enSaveResults::svFailedEmptyObject:
                return "\nError Account was not saved because it's empty\n";
            case enSaveResults::svSucceeded:
                return "\nAccount updated Successfully\n";
            case  enSaveResults::svCreated:
                return "\n Account Created Successfully\n";
            case enSaveResults::svFailedAccountNumberExists:
                return "\n Error account Already exists with this account number\n";
            case enSaveResults::svDeleted:
                return "\n Account Deleted Successfully\n";
            default:
                return "\nError Account was not saved because it's empty\n";
        }

    }


    clsBankClient( enMode mode, std::string firstName, std::string lastName ,std::string email, std::string phone,std::string accountNumber, std::string pinCode,float balance):
    clsPerson(firstName,lastName,email,phone){
        this->_mode=mode;
        this->_accountNumber=accountNumber;
        this->_pinCode=pinCode;
        this->_balance=balance;
    }



    bool isEmpty() {
        return (this->_mode==enMode::EmptyMode);
    }

    std::string getAccountNumber() {
        return _accountNumber;
    }

    std::string getPinCode() {
        return _pinCode;
    }

    float getBalance() {
        return _balance;
    }



    void setPinCode(const std::string pinCode) {
        _pinCode=pinCode;
    }

    void setBalance(const float balance) {
        _balance=balance;
    }






    static clsBankClient find(const std::string accountNumber) {

        std::fstream file;

        file.open("bank_file.txt",std::ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file,line)) {
                clsBankClient client= _convertLineToClientObject(line);
                if (client.getAccountNumber()==accountNumber) {
                    file.close();
                    return client;
                }

            }
            file.close();
        }
        return _getEmptyClientObject();
    }



    static clsBankClient find(std::string accountNumber,std::string password) {

        std::fstream file;

        file.open("bank_file.txt",std::ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file,line)) {
                clsBankClient client= _convertLineToClientObject(line);
                if (client.getAccountNumber()==accountNumber&&client.getPinCode()==password) {
                    file.close();
                    return client;
                }
            }
            file.close();
        }
        return _getEmptyClientObject();
    }





    static bool isClientExists(const std::string accountNumber) {

        return !find(accountNumber).isEmpty();
    }


    static void readClientInfo(clsBankClient& client) {
        client.setFirstName(clsInputValidate::readString("Enter FirstName :"));
        client.setLastName(clsInputValidate::readString("Enter LastName :"));
        client.setEmail(clsInputValidate::readString("Enter Email :"));
        client.setPhone(clsInputValidate::readString("Enter Phone :"));
        client.setPinCode(clsInputValidate::readString("Enter PinCode :"));
        client.setBalance(clsInputValidate::readFloat("Enter Account Balance :"));
    }




    enSaveResults save() {

        if (isClientExists(this->getAccountNumber())&&this->_mode!=enMode::UpdateMode) {
            return enSaveResults::svFailedAccountNumberExists;
        }

        switch (this->_mode) {
            case enMode::EmptyMode:
                return enSaveResults::svFailedEmptyObject;
            case enMode::UpdateMode:
                _update();
                return enSaveResults::svSucceeded;
            case enMode::AddNewMode:
                _create();
                this->_mode=enMode::UpdateMode;
                return enSaveResults::svCreated;

            default:
                return enSaveResults::svFailedEmptyObject;
        }

    }




    static clsBankClient getAddNewClientObject(const std::string accountNumber) {
        clsBankClient client=_getEmptyClientObject();
        client._mode=enMode::AddNewMode;
        client._accountNumber=accountNumber;
        return client;
    }

    static enSaveResults deleteClient(const std::string accountNumber) {

        vector<clsBankClient> vClients =_getAllClientsObjectsFromFile();

        for (clsBankClient& c : vClients) {
            if (c.getAccountNumber()==accountNumber) {
                c._mode=enMode::DeleteMode;
                _saveVClientsObjectsToFile(vClients);
                break;
            }
        }

        return enSaveResults::svDeleted;
    }




    static clsBankClient getEmptyClientObject() {
        return _getEmptyClientObject();
    }





    static vector<clsBankClient> getClientsList() {
        return _getAllClientsObjectsFromFile();
    }





     void deposit(const float amount) {
        this->_balance+=amount;
        this->save();
    }


    bool withdraw(const float amount) {

        if (amount>this->getBalance()) {
            return false;
        }

        this->_balance-=amount;
        this->save();

        return true;
    }


    static double getTotalBalances() {
        vector<clsBankClient> clients=_getAllClientsObjectsFromFile();
        double totalBalances=0;

        for (clsBankClient& client:clients) {
            totalBalances+=client.getBalance();
        }
        return totalBalances;
    }




};