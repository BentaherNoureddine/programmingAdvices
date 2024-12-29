#include <iostream>
using namespace std;



struct stPerson
{
    string firstName;
    string lastName;
    short age;
    int phoneNumber;
};


void readInfo(stPerson &person)
{
    cout << "Enter first name: ";
    cin >> person.firstName;
    cout << "Enter last name: ";
    cin >> person.lastName;
    cout << "Enter age: ";
    cin >> person.age;
    cout << "Enter phone number: ";
    cin >> person.phoneNumber;
}

void printInfo(const stPerson& person)
{
    cout << "First name: " << person.firstName << endl;
    cout << "Last name: " << person.lastName << endl;
    cout << "Age: " << person.age << endl;
    cout << "PhoneNumber: " << person.phoneNumber << endl;
}


int main()
{

    stPerson person;
    readInfo(person);
    printInfo(person);



}
