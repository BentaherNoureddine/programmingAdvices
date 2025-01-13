#include <cmath>
#include <iostream>
using namespace std;



int readPositiveNumber(string s)
{
    int number;
    do
    {
        cout<<s;
        cin>>number;

    }while(number<0);
    return number;

}


void printNumberRows(int number)
{
    for (int i =0;i<number;i++)
    {
        cout<<number;
    }

}


void printNumber(int number)
{
    while(number>0)
    {
        printNumberRows(number);
        cout<<endl;
        number--;
    }
}


int main()
{

    printNumber(readPositiveNumber("Enter number"));
    return 0;



}
