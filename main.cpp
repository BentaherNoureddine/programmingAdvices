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



int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


void printArray(short arr[],short number)
{
    cout<<"Array Elements :";
    for (int i = 1; i <=number; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void fillArray(short arr[100],short number)
{
    for (int i = 1; i <= number; i++)
    {
        arr[i] = RandomNumber(1,100);
    }
}

void getMax(short arr[100],short number)
{
    short min = arr[1];
    for (int i = 2; i <= number; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout<<"Max Number is: "<<min<<endl;
}


int main()
{

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    short arr[100];
    short number = readNumber("Enter Number : ");
    fillArray(arr,number);
    printArray(arr,number);
    getMax(arr,number);



    return 0;



}
