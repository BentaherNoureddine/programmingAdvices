#pragma once
#include <fstream>

#include "clsPerson.h"
#include <vector>
#include "clsUtility.h"
#include "clsInputValidate.h"
#include "clsString.h"


class clsBankUser:public clsPerson {

public:
    struct stLog {
        string dateTime;
        string userName;
        string password;
        short permissions;
    };

private:


    enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2,DeleteMode=3};
    enum enSaveResults{svFailedEmptyObject=0,svSucceeded=1,svCreated=2,svFailedAccountExists=3,svDeleted=4};


    string _userName;
    string _password;
    enMode _mode;
    short  _permissions=0;






    std::string _getLogLine(std::string sep="//") {
        return clsDate::getCurrentDateAndTimeString()+sep+_userName+sep+_password+sep+to_string(_permissions);
    }

    static stLog _convertLineToStLog(const string line,const string sep="//") {
        const vector<string> vItems=clsString::Split(line,sep);
        stLog log;
        log.dateTime=vItems[0];
        log.userName=vItems[1];
        log.password=vItems[2];
        log.permissions=static_cast<short>(stoi(vItems[3]));
        return log;
    }

    static vector<stLog> _loadAllLogsFromFile(const string sep="//") {
        fstream file;
        file.open("logFile.txt",ios::in);
        vector<stLog> vLogs;
        if (file.is_open()) {

            string line;
            while (getline(file,line)) {
                vLogs.push_back(_convertLineToStLog(line,sep));
            }
            file.close();
        }
        return vLogs;
    }

    static clsBankUser _convertLineToUserObject(string line, string sep = "//") {
        vector<string> vItems=clsString::Split(line,sep);
        return clsBankUser(enMode::UpdateMode,vItems[0],vItems[1],vItems[2],vItems[3],vItems[4],vItems[5],static_cast<short>(stoi(vItems[6])));
    }


    static string _convertUserObjectToLine(clsBankUser user,string sep="//") {
        return user.getFirstName()+sep+user.getLastName()+sep+user.getEmail()+sep+user.getPhone()+sep+user._userName+sep+user._password+sep+to_string(user._permissions);
    }

    static vector<clsBankUser> _loadAllUsersFromFile(const string sep="//") {
        vector<clsBankUser> vUsers;
        fstream file;
        file.open("usersFile.txt",ios::in);
        string line;
        if (file.is_open()) {
            while (getline(file,line)) {
                vUsers.push_back(_convertLineToUserObject(line,sep));
            }
            file.close();
        }
        return vUsers;
    }

    static void _saveVUsersObjectsTofile(vector<clsBankUser> vUsers,string sep="//") {

        fstream file;
        file.open("usersFile.txt",ios::out);
        if (file.is_open()) {
            for (clsBankUser& user:vUsers) {
                if (user._mode!=enMode::DeleteMode)
                file<<_convertUserObjectToLine(user,sep)<<endl;
            }
            file.close();
        }
    }

     void _addDataLineToFile(clsBankUser user,string sep="//") {
        fstream file;
        file.open("usersFile.txt",ios::app);
        if (file.is_open()) {
            file<<_convertUserObjectToLine(user,sep)<<endl;
            file.close();
        }
    }


    void _update() {

        vector<clsBankUser> vUsers =_loadAllUsersFromFile();

        for (clsBankUser& user:vUsers) {
            if (this->_userName==user._userName) {
                user=*this;
            }
        }
        _saveVUsersObjectsTofile(vUsers);
    }


    void _create() {
        _addDataLineToFile(*this);
    }








public:

    enum enPermissions {
        enAllPermissions=-1,
        enShowClients=1,
        enAddClient=2,
        enDeleteClient=3,
        enUpdateClient=4,
        enFindClient=5,
        enTransactions=6,
        enManageUsers=7,
        enLogRegister=8,
        enLogout=9,
    };




    bool isEmpty() {
        return this->_mode==enMode::EmptyMode;
    }




    clsBankUser(enMode mode,string firstName, string lastName, string email, string phone,string userName,string password,short permissions):
    clsPerson(firstName,lastName,email,phone) {
        _mode=mode;
        _userName=userName;
        _password=password;
        _permissions=permissions;
    }

    string getUserName() {
        return this->_userName;
    }

    string getPassword() {
        return this->_password;
    }

    short getPermissions() {
        return this->_permissions;
    }

    void setUserName(const string userName) {
        this->_userName=userName;
    }

    void setPassword(const string password) {
        this->_password=password;
    }

    void setPermissions(const short permissions) {
        this->_permissions=permissions;
    }

    static clsBankUser getEmptyUserObject() {
        return clsBankUser(enMode::EmptyMode,"","","","","","",0);
    }





    static clsBankUser find(const string userName) {

        fstream file;
        file.open("usersFile.txt",ios::in);
        if (file.is_open()) {
            string line;
            clsBankUser user=getEmptyUserObject();
            while (getline(file,line)) {
                user=_convertLineToUserObject(line);
                if (userName==user._userName) {
                    return user;
                }
            }
            file.close();
        }
        return getEmptyUserObject();
    }

    static clsBankUser find(const string userName,string password) {

        fstream file;
        file.open("usersFile.txt",ios::in);
        if (file.is_open()) {
            string line;
            clsBankUser user=getEmptyUserObject();
            while (getline(file,line)) {
                user=_convertLineToUserObject(line);
                if (userName==user._userName&&password==user._password) {
                    return user;
                }
            }
            file.close();
        }
        return getEmptyUserObject();
    }




    static bool isUserExists(const string userName) {
        return !find(userName).isEmpty();
    }


    static bool isUserExists(const string userName,const string password) {
        return !find(userName,password).isEmpty();
    }


    static std::string getSaveStatusMessage(const enSaveResults saveResult) {
        switch (saveResult) {
            case enSaveResults::svFailedEmptyObject:
                return "\nError Account was not saved because it's empty\n";
            case enSaveResults::svSucceeded:
                return "\nAccount updated Successfully\n";
            case  enSaveResults::svCreated:
                return "\n Account Created Successfully\n";
            case enSaveResults::svFailedAccountExists:
                return "\n Error account Already exists with this account number\n";
            case enSaveResults::svDeleted:
                return "\n Account Deleted Successfully\n";
            default:
                return "\nError Account was not saved because it's empty\n";
        }

    }



    enSaveResults save() {

        if (isUserExists(this->_userName)&&this->_mode!=enMode::UpdateMode) {
            return enSaveResults::svFailedAccountExists;
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

    static short readPermissions() {

        short permissions=0;

        if (clsInputValidate::yesNoQuestion("Do you want to give full access? y/n")) {
            return enPermissions::enAllPermissions;
        }

        cout<<"do you want to give access to : "<<endl;
        if (clsInputValidate::yesNoQuestion("Show Client List? y/n")) {
            permissions=permissions|enPermissions::enShowClients;
        }
        if (clsInputValidate::yesNoQuestion("Add New Client? y/n")) {
            permissions=permissions|enPermissions::enAddClient;
        }
        if (clsInputValidate::yesNoQuestion("Delete Client ? y/n")) {
            permissions=permissions|enPermissions::enDeleteClient;
        }
        if (clsInputValidate::yesNoQuestion("Update Client ? y/n")) {
            permissions=permissions|enPermissions::enUpdateClient;
        }
        if (clsInputValidate::yesNoQuestion("Find Client? y/n")) {
            permissions=permissions|enPermissions::enFindClient;
        }
        if (clsInputValidate::yesNoQuestion("Transactions? y/n")) {
            permissions=permissions|enPermissions::enTransactions;
        }
        if (clsInputValidate::yesNoQuestion("Manage Users? y/n")) {
            permissions=permissions|enPermissions::enManageUsers;
        }
        if (clsInputValidate::yesNoQuestion("Login Register? y/n")) {
            permissions=permissions|enPermissions::enLogRegister;
        }
        return permissions;
    }

    static void readUserInfo(clsBankUser& client) {
        client.setFirstName(clsInputValidate::readString("Enter FirstName :"));
        client.setLastName(clsInputValidate::readString("Enter LastName :"));
        client.setPhone(clsInputValidate::readString("Enter Phone Number :"));
        client.setEmail(clsInputValidate::readString("Enter Email :"));
        client.setPassword(clsInputValidate::readString("Enter Password :"));
        client.setPermissions(readPermissions());
    }



    static string readValidUserName() {
        string userName =clsInputValidate::readString("Please enter a UserName");
        while (!isUserExists(userName)) {
            userName =clsInputValidate::readString("Please Enter a valid UserName");
        }
        return userName;
    }


    enSaveResults deleteUser() {
        vector<clsBankUser> vUsers=_loadAllUsersFromFile();

        for (clsBankUser& tempUser:vUsers) {
            if (tempUser._userName==this->_userName) {
                tempUser._mode=enMode::DeleteMode;
                _saveVUsersObjectsTofile(vUsers);
                *this=getEmptyUserObject();
                break;
            }
        }
        return enSaveResults::svDeleted;
    }


    static vector<clsBankUser> getAllUsers() {
        return _loadAllUsersFromFile();
    }

    static clsBankUser getAddNewUserObject(const string userName) {
        clsBankUser newUser=getEmptyUserObject();
        newUser._userName=userName;
        newUser._mode=enMode::AddNewMode;
        return newUser;
    }




    static void printUser(clsBankUser user) {
        cout << "\n"<<clsUtility::tabs(10)<<"Client Card:";
        cout << "\n"<<clsUtility::tabs(10)<<"___________________";
        cout << "\n"<<clsUtility::tabs(10)<<"FirstName       : " << user.getFirstName();
        cout << "\n"<<clsUtility::tabs(10)<<"LastName        : " << user.getLastName();
        cout << "\n"<<clsUtility::tabs(10)<<"Full Name       : " << user.fullName();
        cout << "\n"<<clsUtility::tabs(10)<<"Email           : " << user.getEmail();
        cout << "\n"<<clsUtility::tabs(10)<<"Phone           : " << user.getPhone();
        cout << "\n"<<clsUtility::tabs(10)<<"User Name       : " << user.getUserName();
        cout << "\n"<<clsUtility::tabs(10)<<"Password        : " << user.getPassword();
        cout << "\n"<<clsUtility::tabs(10)<<"Permissions     : " << user.getPermissions();
        cout << "\n"<<clsUtility::tabs(10)<<"___________________\n";
    }


    bool hasPermissions(enPermissions permissions) {

        if ((this->getPermissions()==enPermissions::enAllPermissions)||((this->getPermissions()&permissions)==permissions)) {
            return true;
        }
        return false;

    }


    void registerLogin() {
        std::fstream file;
        file.open("logFile.txt",ios::app);
        if (file.is_open()) {
            file<<_getLogLine()<<endl;
            file.close();
        }
    }

    static vector<stLog> getAllLogs() {
        return _loadAllLogsFromFile();
    }





};
