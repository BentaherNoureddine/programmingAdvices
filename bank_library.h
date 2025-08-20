#pragma once
#include <iomanip>

#include "read_save_from_file.h"
using namespace fileClientData;

#include "clsInputValidate.h"

namespace bankLib {






struct ClientData {
        string accountNumber;
        string pinCode;
        string name;
        string phone;
        float accountBalance;

    };

void chooseAction();

struct User {
        string userName;
        string password;
        int permissions=0;

    };

enum enOptions {
        enShowClients=1,
        enAddClient=2,
        enDeleteClient=3,
        enUpdateClient=4,
        enFindClient=5,
        enTransactions=6,
        enManageUsers=7,
        enLogout=8,

};

User getAuthenticatedUser();


    void showTransactionMenu(User user);


    void getBackToTransMenu(User user) {

        char cc;
        cout <<"press any key to go back to transactions Menu ..."<<endl;
        cin>>cc;
        showTransactionMenu(getAuthenticatedUser());
    }

void loginScreen();

void getBackToMenu();
void unAuthenticateUser();

void showScreentype(string tranType) {
        system("clear");
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"                          "<<tranType<<"                                 "<<endl;
        cout<<"-------------------------------------------------------------------------"<<endl;
}

ClientData fillDataStructFromLine( string str,string sep) {

    ClientData clientData;
    vector<string> vStrings;
    fillVectorWithStrings(vStrings,str,sep);

    clientData.accountNumber = vStrings[0];
    clientData.pinCode = vStrings[1];
    clientData.name = vStrings[2];
    clientData.phone = vStrings[3];
    clientData.accountBalance = stod(vStrings[4]);

    return clientData;
}

void noPermissionMessage() {
    system("clear");
    cout<<"_____________________________________________________________"<<endl;
    cout<<"Access Denied,\nYou dont have permission to do this,\n Please contact your admin."<<endl;
    cout<<"_____________________________________________________________"<<endl;
    getBackToMenu();


}

void readClientData(ClientData& clientData) {

    showScreentype("Add New Client Screen");
    cout<<"Please Enter Client Data"<<endl;
    clientData.accountNumber = clsInputValidate::readString("Enter account Number");
    clientData.pinCode = clsInputValidate::readString("Enter PinCode");
    clientData.name = clsInputValidate::readString("Enter your Name");
    clientData.phone = clsInputValidate::readString("Enter PhoneNumber");
    clientData.accountBalance = clsInputValidate::readFloat("Enter Account Balance");

}

string convertStructToString(ClientData clientData,string sep) {

    string str;
    str+=clientData.accountNumber+sep;
    str+=clientData.pinCode+sep;
    str+=clientData.name+sep;
    str+=clientData.phone+sep;
    str+=to_string(clientData.accountBalance);

    return str;
}


void saveStructClientVecToFile(vector<ClientData> vClients,string fileName,string sep) {

    vector<string> vLines;
    for (ClientData& client:vClients) {
        vLines.push_back(convertStructToString(client,sep));
    }
    saveVStringToFile(vLines,fileName);

}



bool getChoice() {
    char choice;
    cout<<"Client added successfully, Do you want to add more clients(Y/N)?"<<endl;
    cin>>choice;
    return  toupper(choice)=='Y';
}

void saveClientsToFile(ClientData clientData,string fileName,string sep,User user) {

    bool keep=true;
    string str;

    if ((user.permissions&enAddClient)==enAddClient||user.permissions==-1) {
        do {
            readClientData(clientData);
            str=convertStructToString(clientData,sep);
            saveToFile(fileName,str);
            keep=getChoice();

        }while (keep==true);

    }else {
        noPermissionMessage();
    }


}


vector<string> loadLinesFromFileToVector(string fileName ) {


    vector<string> vFileContent;
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vFileContent.push_back(line);
        }
    }
    file.close();
    return  vFileContent;

}

vector<ClientData> convertVstringToVclient(vector<string> vStrings,string sep) {

    vector<ClientData> vClients;
    ClientData clientData;
    for (string& line :vStrings) {
        vClients.push_back(fillDataStructFromLine(line,sep));
    }

    return vClients;
}


vector<ClientData> getAllClientsFromFile(string fileName,string sep) {


    vector<string> vLines=loadLinesFromFileToVector(fileName);


    return convertVstringToVclient(vLines,sep);
}


short getClientsNumber() {
    return loadLinesFromFileToVector(fileName).size();

}

void printClient(ClientData client) {

    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"Account Number: "<<client.accountNumber<<endl;
    cout<<"Pin Code: "<<client.pinCode<<endl;
    cout<<"Name: "<<client.name<<endl;
    cout<<"Phone : "<<client.phone<<endl;
    cout<<"Account Balance: "<<client.accountBalance<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
}

bool findClientByAccountNumber(string accountNumber,string fileName,string sep,User user) {
    if (user.permissions&(short)enFindClient||user.permissions==-1) {
        vector<ClientData> clientsData = getAllClientsFromFile(fileName,sep);
        short check=0;
        cout<<"The following are the client details :"<<endl;
        for (ClientData& client:clientsData) {
            if (client.accountNumber==accountNumber) {
                printClient(client);
                return true;
            }
        }
        cout <<"Client is Not Found"<<endl;
        return false;
    }

    noPermissionMessage();
    return false;
}








void printClientData(ClientData clientData) {

    cout<<"| "<<setw(20)<<clientData.accountNumber<<"| "<<setw(20)<<clientData.pinCode<<"| "<<setw(20)<<clientData.name<<"| "<<setw(20)<<clientData.phone<<"| "<<setw(20)<<clientData.accountBalance<<endl;

}


void printClientsData(vector<ClientData> clientsData,string fileName,string sep) {
    clientsData =getAllClientsFromFile(fileName,sep);
    for (ClientData& clientData : clientsData ) {
        printClientData(clientData);

    }
}


void printClients(string fileName,string sep,User user) {
    if ((user.permissions&enShowClients)==enShowClients||user.permissions==-1) {
        vector<ClientData> clientsData =getAllClientsFromFile(fileName,sep);
        cout <<"                                   Client List ("<<clientsData.size()<<") Client(s)."<<endl;
        cout<<"___________________________________________________________________________________________________________________"<<endl;
        cout<<setw(20)<<"| Account Number"<<setw(20)<<"|Pin Code"<<setw(20)<<"|Client Name"<<setw(20)<<"|phone"<<setw(20)<<"Balance"<<endl;
        cout<<"___________________________________________________________________________________________________________________"<<endl;
        printClientsData(clientsData,fileName,sep);
        cout<<"___________________________________________________________________________________________________________________"<<endl;
        getBackToMenu();
    }else {
        noPermissionMessage();
    }


}





void deleteClientByAccountNumber(string accountNumber,string fileName) {

    vector<string> vLines= loadLinesFromFileToVector(fileName);
    deleteLineFromVector(vLines,accountNumber);
    saveVStringToFile(vLines,fileName);

    cout<<"Client deleted successfully"<<endl;


}


void deleteClientByAccountNumberScreen(string accountNumber,string fileName,string sep,User user) {


    if ((user.permissions&enDeleteClient)==enDeleteClient||user.permissions==-1) {

        char choice;
        showScreentype("Delete Client");
        if (findClientByAccountNumber(accountNumber,fileName,sep,getAuthenticatedUser())) {
            cout<<"Are you sure you want to delete this Client(Y/N)"<<endl;
            cin>>choice;
            if (toupper(choice)=='Y') {
                deleteClientByAccountNumber(accountNumber,fileName);
            }
        }

    }else {
        noPermissionMessage();
    }





}


void updateClient(string accountNumber,string filename,string sep) {

    vector<ClientData> vClients = getAllClientsFromFile(filename,sep);

    for (ClientData& client: vClients) {
        if (client.accountNumber==accountNumber) {
            readClientData(client);
        }
    }
    saveStructClientVecToFile(vClients,filename,sep);

}

void updateClientByAccountNumber(string accountNumber,string fileName,string sep,User user) {


    if ((user.permissions&enUpdateClient)==enUpdateClient||user.permissions==-1) {

        ClientData client;
        char sure;
        if (findClientByAccountNumber(accountNumber,fileName,sep,getAuthenticatedUser())) {
            cout<<"Are you sure you want to update this client?"<<endl;
            cin>>sure;
            if (toupper(sure)=='Y') {
                updateClient(accountNumber,fileName,sep);
                cout<<"Client updated Successfully"<<endl;
            }
        }
    }else {
        noPermissionMessage();
    }


}



enum enTransactionsOptions {
    enDeposit=1,
    enWithdraw=2,
    enTotalBalances=3,
    enMainMenue=4,
};



enTransactionsOptions getTransactionsOption() {
        short choice;
        do {
            cout<<"Choose what do you want to do? [1] to [4]?"<<endl;
            cin>>choice;
        }while (choice<1||choice>4);

        return (enTransactionsOptions)choice;
}






void printActionsList() {
    cout<<"\t\t\t\t\t\t[1] Show Clients List."<<endl;
    cout<<"\t\t\t\t\t\t[2] Add new Client."<<endl;
    cout<<"\t\t\t\t\t\t[3] Delete Client."<<endl;
    cout<<"\t\t\t\t\t\t[4] Update Client."<<endl;
    cout<<"\t\t\t\t\t\t[5] Find Client."<<endl;
    cout<<"\t\t\t\t\t\t[6] Transactions."<<endl;
    cout<<"\t\t\t\t\t\t[7] Manage Users."<<endl;
    cout<<"\t\t\t\t\t\t[8] Logout."<<endl;

}


void endProgram() {
    std::system("clear");
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"                        Program ends :-)"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    exit(0);


}


enOptions getOption() {
    short choice;
    do {
        cout<<"Choose what do you want to do? [1] to [8]?"<<endl;
        cin>>choice;
    }while (choice<1||choice>8);

    return (enOptions)choice;
}


void printTransactionList() {
    cout<<"\t\t\t\t\t\t[1] Deposit."<<endl;
    cout<<"\t\t\t\t\t\t[2] withdraw."<<endl;
    cout<<"\t\t\t\t\t\t[3] Total Balances."<<endl;
    cout<<"\t\t\t\t\t\t[4] Main Menue."<<endl;

}



void showClientAndDeposit(string accountNumber) {
    findClientByAccountNumber(accountNumber,fileName,sep,getAuthenticatedUser());


}

void addBalance(string accountNumber,float amount) {

    vector<ClientData> vClients = getAllClientsFromFile(fileName,sep);

    for (ClientData& client:vClients) {
        if (client.accountNumber==accountNumber) {
            client.accountBalance+=amount;
        }
    }
    saveStructClientVecToFile(vClients,fileName,sep);
}





void deposit(string accountNumber) {

    float amount =clsInputValidate::readFloat("Please Enter deposit amount");
    char choice;
    cout<<"Are you sure you want to deposit(Y/N)"<<endl;
    cin>>choice;
    if (toupper(choice)=='Y') {
        addBalance(accountNumber,amount);
    }
    getBackToTransMenu(getAuthenticatedUser());


}



void depositAction() {

    string accountNumber=clsInputValidate::readString("Please Enter Account Number");

    while (!findClientByAccountNumber(accountNumber,fileName,sep,getAuthenticatedUser())) {

        accountNumber=clsInputValidate::readString("Please Enter Account Number");
    }
    deposit(accountNumber);
}

void withdraw(string accountNumber) {
    float amount =clsInputValidate::readFloat("Please Enter withdraw amount");
    char choice;

    vector<ClientData> vClients=getAllClientsFromFile(fileName,sep);
    for (ClientData& client:vClients) {
        if (accountNumber==client.accountNumber) {

            if (client.accountBalance>=amount) {
                client.accountBalance-=amount;
            }else {
                cout<<"Amount Exceeds the balance, you can withdraw up to : "<<client.accountBalance<<endl;
                do {
                    amount=clsInputValidate::readFloat("Please Enter deposit amount");
                }while (amount>=client.accountBalance);
                client.accountBalance-=amount;
            }
        }
    }

    cout<<"Are you sure you want to perform this transaction? (Y/N)"<<endl;
    cin>>choice;
    if (toupper(choice)=='Y') {
        saveStructClientVecToFile(vClients,fileName,sep);
    }

    getBackToTransMenu(getAuthenticatedUser());

}

void withDrowAction() {
    string accountNumber=clsInputValidate::readString("Please Enter Account Number");

    while (!findClientByAccountNumber(accountNumber,fileName,sep,getAuthenticatedUser())) {

        accountNumber=clsInputValidate::readString("Please Enter Account Number");
    }
    withdraw(accountNumber);
}

void doDeposit() {
    showScreentype("Deposit Screen");
    depositAction();
    getBackToTransMenu(getAuthenticatedUser());

}


void doWithdraw() {
    showScreentype("Withdraw Screen");
    withDrowAction();
    getBackToTransMenu(getAuthenticatedUser());
}

void showBalances() {

    vector<ClientData> vClients = getAllClientsFromFile(fileName,sep);
    for (ClientData& client : vClients) {
        cout<<"   |  "<<client.accountNumber<<setw(28)<< "| "<<client.name<<setw(20)<< "| "<<client.accountBalance<<endl;
    }

}

double getTotalBalances() {
    vector<ClientData> vClients=getAllClientsFromFile(fileName,sep);
    double balances=0;
    for (ClientData& client : vClients) {
        balances+=client.accountBalance;
    }
    return balances;
}


void doTotalBalances() {
    cout<<"\t\t\t\t\t\t\t Balances List ("<< getClientsNumber()<<") Clients(s)"<<endl;
    cout<<"___________________________________________________________________________________________________"<<endl;
    cout<<setw(20)<< "| Account Number "<<setw(30)<< "| Client Name "<<setw(20)<< "| Balance "<<endl;
    showBalances();
    cout<<"___________________________________________________________________________________________________"<<endl;
    cout<<"\t\t\t\t\t\t\t Total Balances = "<<getTotalBalances()<<endl;
    getBackToTransMenu(getAuthenticatedUser());



}

void doTransaction() {

    enTransactionsOptions choice =getTransactionsOption();

    switch (choice) {
        case enDeposit:
            doDeposit();
            break;
        case enWithdraw:
            doWithdraw();
            break;
        case enTotalBalances:
            doTotalBalances();
            break;
        case enMainMenue:
            getBackToMenu();
            break;
        default:
            getBackToMenu();
            break;
    }
}








void printMenu() {

    system("clear");
    cout<<"========================================================================================"<<endl;
    cout<<"\t\t\t\t\t\tMain Menu Screen"<<endl;
    cout<<"========================================================================================"<<endl;
    printActionsList();
    cout<<"========================================================================================"<<endl;
    chooseAction();


}



void getBackToMenu() {

    cout <<"Press any key to get back to Main Menu"<<endl;

    char c;
    cin>>c;

    printMenu();


}


void showManageUsersMenu(User user);
void loginScreen();

void chooseAction() {

    enOptions choice=getOption();
    ClientData client;
    switch (choice) {
        case enShowClients:
            printClients(fileName,sep,getAuthenticatedUser());
            getBackToMenu();
            break;
        case enAddClient:
            saveClientsToFile(client,fileName,sep,getAuthenticatedUser());
            getBackToMenu();
            break;
        case enDeleteClient:
            deleteClientByAccountNumberScreen(clsInputValidate::readString("Please Enter Account Number"),fileName,sep,getAuthenticatedUser());
            getBackToMenu();
            break;
        case enUpdateClient:
            updateClientByAccountNumber(clsInputValidate::readString("Please Enter Account Number"),fileName,sep,getAuthenticatedUser());
            getBackToMenu();
            break;
        case enFindClient:
            findClientByAccountNumber(clsInputValidate::readString("Please Enter Account Number"),fileName,sep,getAuthenticatedUser());
            getBackToMenu();
            break;
        case enTransactions:
            showTransactionMenu(getAuthenticatedUser());
            break;
        case enManageUsers:
            showManageUsersMenu(getAuthenticatedUser());
            break;
        case enLogout:
            loginScreen();
            unAuthenticateUser();
            break;

        default:
            chooseAction();
    }
}



enum enManageUsersOptions {
      enListAllUsers=1,
      enAddNewUser=2,
      enDeleteUser=3,
      enUpdateUser=4,
      enFindUser=5,
      enMainMenu=6,
    };


    void showTransactionMenu(User user) {

        if ((user.permissions&enTransactions)==enTransactions||user.permissions==-1) {
            system("clear");
            printTransactionList();
            doTransaction();
        }else {
            noPermissionMessage();
        }


    }

void showManageUsersActions() {
        cout<<"[1] List All Users."<<endl;
        cout<<"[2] Add New User"<<endl;
        cout<<"[3] Delete User."<<endl;
        cout<<"[4] Update User."<<endl;
        cout<<"[5] Find User."<<endl;
        cout<<"[6] Main Menu."<<endl;
    }

enManageUsersOptions getManageUsersOption() {

        short choice;
        do {
            cout<<"Choose what do you want to do? [1] to [6]?"<<endl;
            cin>>choice;
        }while (choice<1||choice>6);

        return (enManageUsersOptions)choice;
}

User fillUserStructFromLine(string line,string sep) {
        User user ;
        vector<string> vStrings;
        fillVectorWithStrings(vStrings,line,sep);

        user.userName=vStrings[0];
        user.password=vStrings[1];
        user.permissions=stoi(vStrings[2]);

        return user;

}


vector<User>convertLinesToUsers(vector<string> vStrings,string sep) {
        vector<User> vUsers;
        User user;
        for (string& line :vStrings) {
            vUsers.push_back(fillUserStructFromLine(line,sep));
        }

        return vUsers;

    }

vector<User> getAllUsersFromFile(string usersFileName,string sep) {
        vector<string> vLines =loadLinesFromFileToVector(usersFileName);

        vector<User>users=convertLinesToUsers(vLines,sep);
        return users;
}


void printUsersList(vector<User> users) {
        for (User& user:users) {
            cout<<"| "<<user.userName<<"\t\t"<<"|"<<user.password<<"\t\t|"<<user.permissions<<endl;
            cout<<"_______________________________________________________________________________________________________"<<endl;

        }
}
void printUsers(string usersFileName,string sep) {
        vector<User> users =getAllUsersFromFile(usersFileName,sep);

        cout<<"                             Users List ("<<users.size()<<") user(s)."<<endl;
        cout<<"_______________________________________________________________________________________________________"<<endl;
        printUsersList(users);


}






int giveAllPermissions() {

    return -1;

}

void getAuthorities(User& user) {

        if (clsInputValidate::yesNoQuestion("Do you want to give full access? y/n")) {
            user.permissions=giveAllPermissions();
            return;
        }
        cout<<"do you want to give access to : "<<endl;
        if (clsInputValidate::yesNoQuestion("Show Client List? y/n")) {
            user.permissions=user.permissions|enListAllUsers;
        }
        if (clsInputValidate::yesNoQuestion("Add New Client? y/n")) {
            user.permissions=user.permissions|enAddNewUser;
        }
        if (clsInputValidate::yesNoQuestion("Delete Client ? y/n")) {
            user.permissions=user.permissions|enDeleteUser;
        }
        if (clsInputValidate::yesNoQuestion("Update Client ? y/n")) {
            user.permissions=user.permissions|enUpdateUser;
        }
        if (clsInputValidate::yesNoQuestion("Find Client? y/n")) {
            user.permissions=user.permissions|enFindUser;
        }
        if (clsInputValidate::yesNoQuestion("Transactions? y/n")) {
            user.permissions=user.permissions|enTransactions;
        }
        if (clsInputValidate::yesNoQuestion("Manage Users? y/n")) {
            user.permissions=user.permissions|enManageUsers;
        }



    }

bool userExists(string userNameToCheck,string usersFileName,string sep) {
    vector<User> vUsers=getAllUsersFromFile(usersFileName,sep);
    for (User& user:vUsers) {
        if (userNameToCheck==user.userName) {
            return true;
        }
    }
    return false;
}

User readUser() {
    User user;
    cout<<"Adding New User"<<endl;

    user.userName=clsInputValidate::readString("Enter UserName");
    while(userExists(user.userName,usersFileName,sep)) {
        cout<<"User with ["<<user.userName<<"] already exists, Enter another Username"<<endl;
        user.userName=clsInputValidate::readString("Enter UserName");
    }
    user.password=clsInputValidate::readString("Enter Password");
    getAuthorities(user);

    return user;
}

void getBackToManageUsersMenu(User user) {

     cout <<"Press any key to gp back to Main Menu"<<endl;

        char c;
        cin>>c;
        showManageUsersMenu(getAuthenticatedUser());




}


string convertStructUserToString(User user,string sep) {
    return user.userName+sep+user.password+sep+to_string(user.permissions);
}

void saveStructUsersVecToFile(vector<User> vUsers,string usersFileName,string sep) {

    vector<string> vLines;
    for (User& user:vUsers) {
        vLines.push_back(convertStructUserToString(user,sep));
    }
    saveVStringToFile(vLines,usersFileName);

}



void saveUserToFile(User user,string usersFileName,string sep,ios_base::openmode mode = ios::app) {

        if (mode==ios::app) {

            string userString=convertStructUserToString(user,sep);
            saveToFile(usersFileName,userString);


        }else {
            string userString=convertStructUserToString(user,sep);
            saveToFileOut(usersFileName,userString);

        }


}



void addNewUser() {
    User user;
    bool yes;
    do {
        user=readUser();
        saveUserToFile(user,usersFileName,sep);

    }while (clsInputValidate::yesNoQuestion("Do you want to add more users?"));

}


void addNewUserScreen() {
        showScreentype("Add New User");
        addNewUser();

}


void printUser(User user) {
    cout<<"____________________________________________________________"<<endl;
    cout<<"Username       :"<<user.userName<<endl;
    cout<<"Password       :"<<user.password<<endl;
    cout<<"Permissions    :"<<user.permissions<<endl;
    cout<<"____________________________________________________________"<<endl;
}


User getUserByUserName(string userName,string usersFileName,string sep) {
    vector<User> vUsers=getAllUsersFromFile(usersFileName,sep);
    User user1;
    for (User& user:vUsers) {
        if (user.userName==userName) {
            user1= user;
        }
    }
    return user1;

}


void deleteUser(User user,string usersFileName) {

    vector<string> vLines= loadLinesFromFileToVector(usersFileName);
    deleteLineFromVector(vLines,user.userName);
    saveVStringToFile(vLines,usersFileName);
}

void deleteUserMenu(string userName,string usersFileName,string sep) {

    if (userExists(userName,usersFileName,sep)) {
        cout<<"The following are the client details :"<<endl;
        printUser(getUserByUserName(userName,usersFileName,sep));
        if (clsInputValidate::yesNoQuestion("Are you sure you want to delete this user? y/n")) {
            deleteUser(getUserByUserName(userName,usersFileName,sep),usersFileName);
            cout<<"User deleted Successfully."<<endl;
        }else {
            getBackToManageUsersMenu(getAuthenticatedUser());
        }
    }else {
        cout<<"User DONT exists"<<endl;
    }

}

void updateUser(User userToUpdate,string usersFileName,string sep) {
    vector<User> vUsers=getAllUsersFromFile(usersFileName,sep);

    for (User& user:vUsers) {
        if (userToUpdate.userName==user.userName) {
            user=readUser();
        }
    }
    saveStructUsersVecToFile(vUsers,usersFileName,sep);
}

void updateUserMenu(string userName,string usersFileName,string sep) {

    if (userExists(userName,usersFileName,sep)) {
        cout<<"The following are the client details :"<<endl;
        printUser(getUserByUserName(userName,usersFileName,sep));
        if (clsInputValidate::yesNoQuestion("Are you sure you want to update this user? y/n")) {
            updateUser(getUserByUserName(userName,usersFileName,sep),usersFileName,sep);
            cout<<"User updated Successfully."<<endl;
            getBackToManageUsersMenu(getAuthenticatedUser());
        }else {
            getBackToManageUsersMenu(getAuthenticatedUser());
        }
    }else {
        cout<<"User DONT exists"<<endl;
    }

}

void deleteUserScreen(string usersFileName,string sep) {
    showScreentype("Delete Users Screen");
    string userName=clsInputValidate::readString("Plsease enter userName");
    deleteUserMenu(userName,usersFileName,sep);
}



void updateUserByUserNameScreen(string userName,string usersFileName,string sep) {

    showScreentype("Update users Screen");
    printUser(getUserByUserName(userName,usersFileName,sep));
    updateUserMenu(userName,usersFileName,sep);

}


void findUserByUserNameMenu(string usersFileName,string sep) {
    showScreentype("Find User");
    string userName=clsInputValidate::readString("Please enter a UserName");
    if (userExists(userName,usersFileName,sep)) {
        printUser(getUserByUserName(userName,usersFileName,sep));
        getBackToManageUsersMenu(getAuthenticatedUser());
    }else {
        cout<<"User DONT exists "<<endl;
        getBackToManageUsersMenu(getAuthenticatedUser());
    }


}

void getManageUsersMenueChoice() {

            enManageUsersOptions choice=getManageUsersOption();

            switch (choice) {
                case enListAllUsers:
                    printUsers(usersFileName,sep);
                    getBackToManageUsersMenu(getAuthenticatedUser());
                    break;
                case enAddNewUser:
                    addNewUserScreen();
                    getBackToManageUsersMenu(getAuthenticatedUser());
                    break;
                case enDeleteUser:
                    deleteUserScreen(usersFileName,sep);
                    getBackToManageUsersMenu(getAuthenticatedUser());
                    break;
                case enUpdateUser:
                    updateUserByUserNameScreen(clsInputValidate::readString("Please Enter UserName"),usersFileName,sep);
                    getBackToManageUsersMenu(getAuthenticatedUser());
                    break;
                case enFindUser:
                    findUserByUserNameMenu(usersFileName,sep);
                    getBackToManageUsersMenu(getAuthenticatedUser());
                    break;
                case enMainMenu:
                    printMenu();
                    break;
                default:
                    break;
            }

    }

void showManageUsersMenu(User user) {

    if (((user.permissions&enManageUsers)==enManageUsers)||user.permissions==-1) {


        system("clear");
        cout<<"===================================================================="<<endl;
        cout<<"                Manage Users Menue Sceen"<<endl;
        cout<<"===================================================================="<<endl;
        showManageUsersActions();
        cout<<"===================================================================="<<endl;
        getManageUsersMenueChoice();


    }else {
        noPermissionMessage();
    }
}




void authenticateUser(string userName) {
    User user=getUserByUserName(userName,usersFileName,sep);
    saveUserToFile(user,authenticatedUsersFileName,sep,ios::out);

}

User getAuthenticatedUser() {
    vector<User> vUsers=getAllUsersFromFile(authenticatedUsersFileName,sep);
    return vUsers[0];
}
void unAuthenticateUser() {
    deleteUser(getAuthenticatedUser(),authenticatedUsersFileName);
}

void login() {
        const string userName=clsInputValidate::readString("Enter username ");
        const string password=clsInputValidate::readString("Enter password");
        if (userExists(userName,usersFileName,sep)&&
            getUserByUserName(userName,usersFileName,sep).password==password) {
            authenticateUser(userName);
                printMenu();

        }else {
            cout<<"Invalid Username/Password!"<<endl;
            login();
        }
    }
void loginScreen() {
        cout<<"______________________________________________"<<endl;
        cout<<"                Login Screen                  "<<endl;
        cout<<"______________________________________________"<<endl;
        login();
    }






}
