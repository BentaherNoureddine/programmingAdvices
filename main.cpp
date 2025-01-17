#include <cstdlib>
#include <iostream>
using namespace std;




int readNumber(string message)
{
    short number;

    do
    {
        cout << message;
        cin >> number;
    }while (number < 0);
    return number;


}


void fillArray(short arr[],short n)
{
    for (int i = 1; i <= n; i++)
    {
        arr[i] = readNumber("Element ["+to_string(i)+"] :");
        cout<<endl;
    }
}


void printArray(short arr[])
{
    cout<<"Original Array:";
    for (int i = 1; i <=sizeof(arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

short getReputation(short arr[],short number)
{
    int sum =0;
    for (int i = 0; i <sizeof(arr); i++)
    {
        if (arr[i] == number)
         sum++;
    }
    return sum;
}

void checkNumber(short number)
{
    short arr[number];
    fillArray(arr,number);
    short numberToCheck= readNumber("Enter Number to check : ");
    printArray(arr);
    cout<<numberToCheck<<" is repeated "<<getReputation(arr,numberToCheck)<<" time(s)"<<endl;



}


int main()
{

    checkNumber(readNumber("Enter the number of elements : "));


    return 0;



}
