#include <iostream>
using namespace std;


struct stPerson
{
    string firstName;
    string lastName;
    short age;
    int phoneNumber;
};

//READ INFOS
void readInfos(stPerson &person)
{
    cout<<"Enter First Name: ";
    cin>>person.firstName;
    cout<<"Enter Last Name: ";
    cin>>person.lastName;
    cout<<"Enter Age: ";
    cin>>person.age;
    cout<<"Enter Phone: ";
    cin>>person.phoneNumber;
}

//PRINT INFOS
void printInfos(stPerson person)
{
    cout<<"First Name: "<<person.firstName<<endl;
    cout<<"Last Name: "<<person.lastName<<endl;
    cout<<"Age: "<<person.age<<endl;
    cout<<"Phone: "<<person.phoneNumber<<endl;
}

//PRINT ALL PERSONS
void printAll(stPerson person[2])
{
    printInfos(person[0]);
    cout<<"************************************************"<<endl;
    cout<<"************************************************"<<endl;
    printInfos(person[1]);
}


int main()
{

    stPerson person[2];
    readInfos(person[0]);
    readInfos(person[1]);
    printAll(person);


}
