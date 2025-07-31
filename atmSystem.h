#pragma once


namespace AtmSystem {

    #include <cmath>

#include "bank_library.h"

using namespace bankLib;
using namespace std;


void showAtmMainMenu();
void loginAtm();
void logout();
void loginAtm();
void showBalance(ClientData client);

ClientData currentClient;

enum enATmChoice{
    enQuickWithdraw=1,
    enNormalWithdraw=2,
    enDeposit=3,
    enCheckBalance=4,
    enLogout=5,
};

enATmChoice readAtmChoice(string message) {

    short choice=readShort(message);
    while (choice<1||choice>5) {
        cout<<"enter a choice between 1 to 5"<<endl;
        choice=readShort(message);
    }
    return (enATmChoice)choice;
}

enum enQuickWithDrawOption {
    enTwenty=1,
    enHundred=3,
    enFourHundred=5,
    enEightHundred=7,
    enFifty=2,
    enTwoHundred=4,
    enSixHundred=6,
    enThousand=8,
    enExit=9,
};
enum enWithDrawAmount {
    amountTwenty=20,
    amountHundred=100,
    amountFourHundred=400,
    amountEightHundred=800,
    amountFifty=50,
    amountTwoHundred=200,
    amountSixHundred=600,
    amountThousand=1000,

};


void doATMWithdraw(ClientData& currClient,float withAmount) {

    float amount =withAmount;
    char choice;

    vector<ClientData> vClients=getAllClientsFromFile(fileName,sep);
    for (ClientData& client:vClients) {
        if (currClient.accountNumber==client.accountNumber) {

            if (client.accountBalance>=amount) {
                client.accountBalance-=amount;
                currClient.accountBalance-=amount;
            }else {
                cout<<"Amount Exceeds the balance, you can withdraw up to : "<<client.accountBalance<<endl;
                do {
                    amount=readFloat("Please Enter deposit amount");
                }while (amount>=client.accountBalance);
                client.accountBalance-=amount;
                currClient.accountBalance-=amount;
            }
        }
    }

    cout<<"Are you sure you want to perform this transaction? (Y/N)"<<endl;
    cin>>choice;
    if (toupper(choice)=='Y') {
        saveStructClientVecToFile(vClients,fileName,sep);
    }

    showBalance(currClient);


}

void getBackToAtmMenuScreen() {

    cout<<"press any key to get back to main menu"<<endl;
    char c;
    cin>>c;
    showAtmMainMenu();


}


void performQuickWithdraw(enQuickWithDrawOption option) {

    switch (option) {
        case enTwenty:
            doATMWithdraw(currentClient,amountTwenty);
            getBackToAtmMenuScreen();

        case enFifty:
            doATMWithdraw(currentClient,amountFifty);
            getBackToAtmMenuScreen();

        case enHundred:
            doATMWithdraw(currentClient,amountHundred);
            getBackToAtmMenuScreen();

        case enTwoHundred:
            doATMWithdraw(currentClient,amountTwenty);
            getBackToAtmMenuScreen();

        case enFourHundred:
            doATMWithdraw(currentClient,amountFourHundred);
            getBackToAtmMenuScreen();

        case enSixHundred:
            doATMWithdraw(currentClient,amountSixHundred);
            getBackToAtmMenuScreen();

        case enEightHundred:
            doATMWithdraw(currentClient,amountEightHundred);
            getBackToAtmMenuScreen();

        case enThousand:
            doATMWithdraw(currentClient,amountThousand);
            getBackToAtmMenuScreen();

        case enExit:
            getBackToAtmMenuScreen();
    }
}

void quickWithDrawMenu() {
    cout<<"\t\t"<<setw(5)<<"[1] 20\t\t[2] 50"<<endl;
    cout<<"\t\t"<<setw(5)<<"[3] 100\t\t[4] 50"<<endl;
    cout<<"\t\t"<<setw(5)<<"[5] 400\t\t[6] 50"<<endl;
    cout<<"\t\t"<<setw(5)<<"[7] 800\t\t[8] 50"<<endl;
    cout<<"\t\t"<<setw(5)<<"[9] Exist"<<endl;
}


void showBalance(ClientData client) {
    cout<<"Your Balance is "<<client.accountBalance<<endl;
}

enQuickWithDrawOption getWithdrawOption() {

    short withdrawOption;
    do {
        withdrawOption=readShort("Enter a choice between [1] to [9]");
    }while (withdrawOption<1||withdrawOption>9);

    return (enQuickWithDrawOption)withdrawOption;
}



void showQuickWithDrawScreen() {
    showScreentype("Quick withdraw Screen");
    quickWithDrawMenu();
    performQuickWithdraw(getWithdrawOption());
}



float getWithDrawAmount(short number) {

    float amount;
    do {
        cout<<"Enter an amount multiple of "<<number<<"'s";
        cin>>amount;
    } while (fmod(amount, number) != 0);
    return amount;

}

void performWithdraw() {

    float withDrawAmount=getWithDrawAmount(5);
    doATMWithdraw(currentClient,withDrawAmount);
    getBackToAtmMenuScreen();
}

void showNormalWithDrawScreen() {
    showScreentype("Normal Withdraw Screen");
    performWithdraw();
    getBackToAtmMenuScreen();
}

void performDeposit() {

    vector<ClientData> vClients=getAllClientsFromFile(fileName,sep);
    float amount;
    do {
        amount=readFloat("Enter a positive Amount.");
    }while (amount<0);

    for (ClientData& C:vClients) {
        if (C.accountNumber==currentClient.accountNumber) {
          C.accountBalance+=amount;

        }
    }
    saveStructClientVecToFile(vClients,fileName,sep);
    currentClient.accountBalance+=amount;

}


void showDepositScreen() {

    showScreentype("Deposit Screen");
    performDeposit();
    cout<<"Done Successfully. new Balance is : "<<currentClient.accountBalance<<endl;
    getBackToAtmMenuScreen();
}

void showCheckBalanceScreen() {
    showScreentype("Check Balance Screen");
    showBalance(currentClient);
    getBackToAtmMenuScreen();
}

void performAtmChoice(enATmChoice choice) {

    switch (choice) {
        case enQuickWithdraw:
            showQuickWithDrawScreen();
            getBackToAtmMenuScreen();

        case enNormalWithdraw:
            showNormalWithDrawScreen();
            getBackToAtmMenuScreen();

        case enATmChoice::enDeposit:
            showDepositScreen();
            getBackToAtmMenuScreen();

        case enCheckBalance:
            showCheckBalanceScreen();
            getBackToAtmMenuScreen();

        case enATmChoice::enLogout:
            logout();

    }

}



void showAtmMainMenu() {

    showScreentype("Atm main Menu Screen");
    cout<<"[1] Quick withdraw "<<endl;
    cout<<"[2] Normal withdraw "<<endl;
    cout<<"[3] Deposit  "<<endl;
    cout<<"[4] Check balance  "<<endl;
    cout<<"[5] logout "<<endl;
    performAtmChoice(readAtmChoice("choose what do you want to do?[1 to 5]"));



}


bool clientExists(string accountNumer,string pincode,ClientData& client) {

    vector<ClientData> vClients=getAllClientsFromFile(fileName,sep);

    for (ClientData& C :vClients) {
        if (C.accountNumber==accountNumer&&C.pinCode==pincode) {
            client=C;
            return true;
        }
    }
    return false;


}
void logout() {
    loginAtm();
}
void loginAtm(){
    system("clear");
    showScreentype("Client Login Screen");


    string accountNumber=readString("Enter Account Number");
    string pinCode=readString("Enter pinCode");

    bool exists=true;
    do {
        if (clientExists(accountNumber,pinCode,currentClient)) {
            showAtmMainMenu();

        }else {
            cout<<"Invalid account Number/pincode"<<endl;
            accountNumber=readString("Enter Account Number");
            pinCode=readString("Enter pinCode");
            exists=false;
        }

    }while (!exists);
}




}