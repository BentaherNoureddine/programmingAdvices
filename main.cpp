#include <iostream>
using namespace std;



string readName()
{
    string name;
    cout << "Enter your name: ";
    getline(cin,name);
    return name;
}


void displayName(const string& name)
{
    cout << "your name is " <<name<< endl;
}


int main()
{

    displayName(readName());


}
