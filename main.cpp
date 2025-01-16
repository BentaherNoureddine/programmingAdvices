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






void printNumber(int number)
{
    int number2 = number-1;
    for (int i = number+65-1;i>=65; i--)
    {

        for (int j=number2;j>=0;j--)
        {
            cout<<char(i);
        }
        number2--;
        cout<<endl;
    }

}

int main()
{

    printNumber(readPositiveNumber("Enter number"));
    return 0;



}
