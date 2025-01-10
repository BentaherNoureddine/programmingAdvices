#include <iostream>
using namespace std;



void readNums(int &num1,int &num2, int &num3)
{
    cout<<"Enter First Number: ";
    cin>> num1;
    cout<<"Enter Second Number: ";
    cin>> num2;
    cout<<"Enter Third Number: ";
    cin>> num3;
}


int getMax(int num1,int num2,int num3)
{
   if (num1>num2&&num1>num3)
       return num1;

   else if(num2>num3)
       return num2;

   else
       return num3;

}

void printResult(int num1,int num2,int num3)
{
    cout<<"The Max Value is "<<getMax(num1,num2,num3)<<endl;
}


int main()
{

    int num1,num2,num3;
    readNums(num1,num2,num3);
    printResult(num1,num2,num3);
    return 0;



}
