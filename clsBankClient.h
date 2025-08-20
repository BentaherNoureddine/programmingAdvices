#pragma once
#include <fstream>
#include <set>
#include <vector>

#include "bank_library.h"
#include "clsPerson.h"
#include "clsUtility.h"
#include "strings.h"

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
        return client.getFirstName()+sep+client.getLastName()+sep+client.getEmail()+sep+client.getAccountNumber()+sep+client.getPinCode()+sep+to_string(client.getBalance());
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


    static std::string _readValidAccountNumber() {
        std::string accountNumber=clsInputValidate::readString("Please enter client account Number : ");

        while (!isClientExists(accountNumber)) {
            std::cout<<"Account Number is not found, choose an other one: ";
            accountNumber=clsInputValidate::readString("");
        }
        return accountNumber;
    }


    static std::string _getSaveStatusMessage(const enSaveResults saveResult) {
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



    static enSaveResults _delete(const std::string accountNumber) {

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

    static double _getTotalBalances() {
        vector<clsBankClient> clients=_getAllClientsObjectsFromFile();
        double totalBalances=0;

        for (clsBankClient& client:clients) {
            totalBalances+=client.getBalance();
        }
        return totalBalances;
    }
















public:


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


    void print() {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName       : " << getFirstName();
        cout << "\nLastName        : " << getLastName();
        cout << "\nFull Name       : " << fullName();
        cout << "\nEmail           : " << getEmail();
        cout << "\nPhone           : " << getPhone();
        cout << "\nAccount. Number : " << getAccountNumber();
        cout << "\nPassword        : " << getPinCode();
        cout << "\nBalance         : " << getBalance();
        cout << "\n___________________\n";
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

        std::vector<clsBankClient> vClients;
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

        if (isClientExists(this->getAccountNumber())) {
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


    static void updateClient() {

        clsBankClient client=find(_readValidAccountNumber());
        client.print();

        std::cout<<"Update Client Info :"<<std::endl;
        std::cout<<"_________________________"<<std::endl;

        readClientInfo(client);

        _getSaveStatusMessage(client.save());
        client.print();

    }

    static clsBankClient getAddNewClientObject(const std::string accountNumber) {
        clsBankClient client=_getEmptyClientObject();
        client._mode=enMode::AddNewMode;
        client._accountNumber=accountNumber;
        return client;
    }



    static void addNewClient() {

        std::string accountNumber= clsInputValidate::readString("Please enter account Number");


        while (isClientExists(accountNumber)) {
            cout<<"\n Account Number is already used, choose an other one : ";
            accountNumber=clsInputValidate::readString("Please enter account Number");
        }

        clsBankClient newClient=getAddNewClientObject(accountNumber);

        readClientInfo(newClient);

        _getSaveStatusMessage(newClient.save());

        newClient.print();
    }







    static void deleteClient() {

        std::string accountNumber=_readValidAccountNumber();

        clsBankClient client=find(accountNumber);
        client.print();

        if (clsInputValidate::yesNoQuestion("Are you sure you want to delete this Client Y/N? ")) {
            cout<<_getSaveStatusMessage(_delete(accountNumber));
            client=_getEmptyClientObject();

        }
        client.print();
    }

    static vector<clsBankClient> getClientsList() {
        return _getAllClientsObjectsFromFile();
    }

    static void printClientRecordLine(clsBankClient client) {
        cout<<"| "<<left<<setw(15)<<client.getAccountNumber()<<"| "<<left<<setw(22)<<client.fullName()<<"| "<<left<<setw(17)<<client.getPhone();
        cout<<"| "<<left<<setw(26)<<client.getEmail()<<"| "<<left<<setw(15)<<client.getPinCode()<<"| "<<left<<setw(20)<<client.getBalance()<<endl;

    }


    static void listAllClients() {

        std::vector<clsBankClient> vClients=getClientsList();

        std::cout<<"\n\t\t\t\t\t\t\t\t\t\t\tClients List ("<<vClients.size()<<") Client(s)"<<endl;
        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;
        cout<<"| "<<left<<setw(15)<<"Account Number"<<"| "<<left<<setw(22)<<"Client Name"<<"| "<<left<<setw(17)<<"Phone Number";
        cout<<"| "<<left<<setw(26)<<"Email"<<"| "<<left<<setw(15)<<"Pin Code"<<"| "<<left<<setw(20)<<"Balance"<<endl;
        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;

        if (vClients.empty()) {
            cout<<"\n\t\t\t\t\t\t\t\t\t\tNo clients available in the system"<<endl;
            return;
        }

        for (clsBankClient& client:vClients) {
           printClientRecordLine(client);
        }

        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;
    }

    static void printClientBalanceLine(clsBankClient client) {
        cout<<"| "<<left<<setw(15)<<client.getAccountNumber()<<"| "<<left<<setw(30)<<client.fullName()<<"| "<<left<<setw(30)<<client.getBalance()<<endl;
    }

    static void showTotalBalances() {

        std::vector<clsBankClient> vClients=getClientsList();

        //HEADER
        std::cout<<"\n\t\t\t\t\t\t\t\t\t\t\tClients List ("<<vClients.size()<<") Client(s)"<<endl;
        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;
        cout<<"| "<<left<<setw(15)<<"Account Number"<<"| "<<left<<setw(30)<<"Client Name"<<"| "<<left<<setw(30)<<"Balance"<<endl;
        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;

        //PRINT CLIENT BALANCES LIST
        for (clsBankClient& client:vClients) {
            printClientBalanceLine(client);
        }

        cout<<"\n__________________________________________________________________________________________________________________________\n"<<endl;

        const double _totalBalances=_getTotalBalances();

        cout<<"\n\t\t\t\t\t\t\t\tTotal balances = "<<_totalBalances<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t("<<clsUtility::numberToText(_totalBalances)<<")"<<endl;


    }



};