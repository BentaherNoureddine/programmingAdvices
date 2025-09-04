#pragma once
#include <fstream>
#include <vector>
#include "bank_library.h"
#include "clsBankUser.h"
#include "clsPerson.h"
#include "clsUtility.h"
#include "global.h"
#include "secrets.h"


class clsBankClient: public clsPerson {
public:

    struct stLogTransfer {
        string dateTime;
        string sourceAccountNumber;
        string destinationAccountNumber;
        double amount=0;
        double sourceBalance=0;
        double destinationBalance=0;
        string userUserName;
    };


private:

    enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2,DeleteMode=3};

    enum enSaveResults{svFailedEmptyObject=0,svSucceeded=1,svCreated=2,svFailedAccountNumberExists=3,svDeleted=4};




    enMode _mode;
    std::string _accountNumber;
    std::string _pinCode;
    float _balance;



    static stLogTransfer _convertLineToStTransferLog(string line,string sep="//") {
        stLogTransfer logTransfer;
        const vector<string> vItems=clsString::Split(line,sep);
        logTransfer.dateTime=vItems[0];
        logTransfer.sourceAccountNumber=vItems[1];
        logTransfer.destinationAccountNumber=vItems[2];
        logTransfer.amount=static_cast<double>(stoi(vItems[3]));
        logTransfer.sourceBalance=static_cast<double>(stoi(vItems[4]));
        logTransfer.destinationBalance=static_cast<double>(stoi(vItems[5]));
        logTransfer.userUserName=vItems[6];
        return logTransfer;
    }

    static vector<stLogTransfer> _getAllTransferLogsFromFile(const string sep="//") {
        fstream file;
        vector<stLogTransfer> vLogs;
        file.open("transferFile.txt",ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file,line)) {
                vLogs.push_back(_convertLineToStTransferLog(line));
            }
        }
        return vLogs;
    }

    static string _getLogTransferString(clsBankClient from,clsBankClient to,const double amount,string sep="//") {
        return clsDate::getCurrentDateAndTimeString()+sep+from.getAccountNumber()+sep+to.getAccountNumber()+sep+to_string(amount)+sep+to_string(from._balance)+sep+to_string(to._balance)+sep+CurrentUser.getUserName();
    }

    static void _logTransferInFile(const clsBankClient& from, const clsBankClient& to,const double amount, const string &sep="//") {

        fstream file;
        file.open("transferFile.txt",ios::app);
        if (file.is_open()) {
            file<<_getLogTransferString(from,to,amount,sep)<<endl;
            file.close();
        }
    }


    static clsBankClient _convertLineToClientObject(const std::string& line,const std::string& sep="//") {
        std::vector<std::string> vItems=clsString::Split(line,sep);
        return clsBankClient(enMode::UpdateMode,vItems[0],vItems[1],vItems[2],vItems[3],vItems[4],clsUtility::encryptText(vItems[5],EncryptionKey),stof(vItems[6]));
    }

    static std::vector<clsBankClient> _getAllClientsObjectsFromFile(const std::string& sep="//") {
        std::vector<clsBankClient> vClients;
        fstream file;
        std::string line;
        file.open("clientsFile.txt",ios::in);
        if (file.is_open()) {
            while (getline(file,line)&&!line.empty()) {
                vClients.push_back(_convertLineToClientObject(line,sep));
            }
            file.close();
        }
        return vClients;
    }


    static std::string _convertClientObjectToLine(clsBankClient client,const std::string& sep="//") {
        return client.getFirstName()+sep+client.getLastName()+sep+client.getEmail()+sep+client.getPhone()+sep+client.getAccountNumber()+sep+clsUtility::decryptText(client.getPinCode(),EncryptionKey)+sep+to_string(client.getBalance());
    }

    static void _saveVClientsObjectsToFile( vector<clsBankClient>& vClients,const std::string& sep="//") {

        fstream file;
        file.open("clientsFile.txt",std::ios::out);
        if (file.is_open()) {
            for (clsBankClient& client:vClients) {
                if (client._mode!=enMode::DeleteMode) {
                    std::string line = _convertClientObjectToLine(client, sep);
                    file <<line<<endl;
                }
            }
            file.close();
        }
    }


    static void _addDataLineToFile(const std::string& line,const std::string& delim="//") {

        fstream file;
        file.open("clientsFile.txt",ios::out | ios::app);
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

        file.open("clientsFile.txt",std::ios::in);
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



    static clsBankClient find(const std::string& accountNumber,const std::string& password) {

        std::fstream file;

        file.open("clientsFile.txt",std::ios::in);
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





    static bool isClientExists(const std::string& accountNumber) {

        return !find(accountNumber).isEmpty();
    }


    static void readClientInfo(clsBankClient& client) {
        client.setFirstName(clsInputValidate::readString("Enter FirstName :"));
        client.setLastName(clsInputValidate::readString("Enter LastName :"));
        client.setEmail(clsInputValidate::readString("Enter Email :"));
        client.setPhone(clsInputValidate::readString("Enter Phone :"));
        client.setPinCode(clsInputValidate::readString("Enter PinCode :"));
        client.setBalance(clsInputValidate::readNumber<float>("Enter Account Balance :"));
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




    static clsBankClient getAddNewClientObject(const std::string& accountNumber) {
        clsBankClient client=_getEmptyClientObject();
        client._mode=enMode::AddNewMode;
        client._accountNumber=accountNumber;
        return client;
    }

    static enSaveResults deleteClient(const std::string& accountNumber) {

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


    static bool transfer(clsBankClient& from ,clsBankClient& to,const double& amount) {

        from.withdraw(amount);
        to.deposit(amount);
        _logTransferInFile(from,to,amount);
        return (from.save()==enSaveResults::svSucceeded)&&(to.save()==enSaveResults::svSucceeded);
    }


    static vector<stLogTransfer> getAllTransferLogs() {
        return _getAllTransferLogsFromFile();
    }







};
