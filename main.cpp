#include <iostream>
using namespace std;


struct stInfo
{
    string firstName;
    string lastName;
};

stInfo readInfo()
{
    stInfo info;
    cout << "Enter first name: ";
    cin >> info.firstName;
    cout << "Enter last name: ";
    cin >> info.lastName;
    return info;
}

string getFullName(stInfo info)
{
    return info.firstName + " " + info.lastName;
}

void printFullName(string fullName )
{
    cout << " FullName: " << fullName << endl;
}





int main()
{

    stInfo info;
    printFullName(getFullName(readInfo()));
    return 0;



}
