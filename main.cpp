#include <cmath>
#include <iostream>
using namespace std;



int readNumber()
{
    int number;
    cout<<"Enter a number: ";
    cin>>number;
    return number;
}


bool isPrime(int number)
{
    if(number <= 1)
        return false;
    for (int i=2;i<number;i++)
    {
        if(number % i == 0)
            return false;

    }
    return true;
}


void printPrimeNumbers(int number)
{
    for (int i=2;i<number;i++)
    {
        if(isPrime(i))
        {
            cout<<i<<" ";
        }
    }
}


int main()
{

    printPrimeNumbers(readNumber());
    return 0;



}
