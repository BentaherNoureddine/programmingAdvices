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
    for (int i = 65;i<=65+number-1; i++)
    {

        for (int j=1;j<=number-(65+number-1-i);j++)
        {
            cout<<char(i);
        }
        cout<<endl;
    }

}

int main()
{

    printNumber(readPositiveNumber("Enter number"));
    return 0;



}
