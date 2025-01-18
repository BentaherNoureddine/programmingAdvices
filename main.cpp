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
        arr[i] = RandomNumber(1,number);
    }
}

string getResult(short number)
{

        if ( number>0)
            return "The number found at position : " + to_string(number)+"\n"+"The Number found its order : "+to_string(number+1);
        return "The Number is not found :-(";


}

void searchNumber(short arr[100],short arrayLength,short number)

{
    short result = 0;
    for (short i = 1; i <= arrayLength; i++)
    {
        if (number == arr[i])
        {
            result = i;
            break;
        }
    }
    cout<<"Number  you are looking for is : "<<number<<endl;
    cout<<getResult(result)<<endl;

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
    short number=readNumber("Enter the Number to search for: ");
    searchNumber(arr,arrayLength,number);


    return 0;



}
