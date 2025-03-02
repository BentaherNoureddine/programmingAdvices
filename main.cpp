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

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


void printArray(short arr[],short arrLength)
{
    for (int i = 0; i <arrLength; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void fillArray(short arr[100],short arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(-100,100);
    }
}


int countNegativeNumbers(short arr[100],short arrLength) {

    int count = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}


int main()
{

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    short arr[100];
    short arrayLength=readNumber("Enter the Array size : ");
    fillArray(arr,arrayLength);
    cout<<"Array Elements : "<<endl;
    printArray(arr,arrayLength);
    cout<<"Positive Numbers : "<<countNegativeNumbers(arr,arrayLength)<<endl;



    return 0;



}
