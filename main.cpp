#include <iostream>
using namespace std;



void readNums(int &num1,int &num2,int &num3)
{
    cout<<"Enter First Number: ";
    cin>> num1;
    cout<<"Enter Second Number: ";
    cin>> num2;
    cout<<"Enter Third Number: ";
    cin>> num3;
}


int sumOfNumbers(int num1,int num2,int num3)
{
    return num1+num2+num3;
}



float average(int num1,int num2,int num3)
{
    return (float)sumOfNumbers(num1,num2,num3) / 3;
}



bool checkAverage(float average)
{
    return average >=50;
}


void prinResult(float average)
{
    if (checkAverage(average))
    {
        cout<<"Pass"<<endl;
    }else
    {
        cout<<"Fail"<<endl;
    }
}

int main()
{

    int num1,num2,num3;
    readNums(num1,num2,num3);
    prinResult(average(num1,num2,num3));
    return 0;



}
