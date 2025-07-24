#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

#include "myMathLibrary.h"
#include "myInputLibrary.h"
#include "read_save_print_clientData.h"
using namespace fileClientData;
using namespace myInputLib;

using namespace myMathLib;
using namespace std;



const string fileName="test.txt";
const string sep="//";


void getBackToMenu();


void printActionsList() {
    cout<<"\t\t\t\t\t\t[1] Show Clients List."<<endl;
    cout<<"\t\t\t\t\t\t[2] Add new Client."<<endl;
    cout<<"\t\t\t\t\t\t[3] Delete Client."<<endl;
    cout<<"\t\t\t\t\t\t[4] Update Client."<<endl;
    cout<<"\t\t\t\t\t\t[5] Find Client."<<endl;
    cout<<"\t\t\t\t\t\t[6] Exit."<<endl;

}


void endProgram() {
    std::system("clear");
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"                        Program ends :-)"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    exit(0);


}

void chooseAction() {
    short choice;
    cout<<"Choose what do you want to do? [1 to [6]?"<<endl;
    cin>>choice;
    ClientData client;
    switch (choice) {
        case 1:
            printClients(fileName,sep);
            getBackToMenu();
            break;
        case 2:
            saveClientsToFile(client,fileName,sep);
            getBackToMenu();
            break;
        case 3:
            deleteClientByAccountNumber(readString("Please Enter Account Number"),fileName);
            getBackToMenu();
            break;
        case 4:
            updateClientByAccountNumber(readString("Please Enter Account Number"),fileName,sep);
            getBackToMenu();
            break;
        case 5:
            findClientByAccountNumber(readString("Please Enter Account Number"),fileName,sep);
            getBackToMenu();
            break;
        case 6:
            endProgram();
            break;
        default:
            chooseAction();
    }
}

void printMenu() {

    cout<<"========================================================================================"<<endl;
    cout<<"\t\t\t\t\t\tMain Menu Screen"<<endl;
    cout<<"========================================================================================"<<endl;
    printActionsList();
    cout<<"========================================================================================"<<endl;
    chooseAction();


}

void getBackToMenu() {

    char getback;
    cout <<"Press any key to gp back to Main Menu"<<endl;
    cin>>getback;
    std::system("clear");
    printMenu();

}





int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    printMenu();








    return 0;
}