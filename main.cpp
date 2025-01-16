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






void printFromAToZ()
{
    for (int i = 65;i<=90; i++)
    {
        for (int j= 65;j<=90; j++)
        {
            for (int k= 65;k<=90; k++)
            {
                cout<<char(i)<<char(j)<<char(k)<<endl;
            }
        }

    }

}

int main()
{

    printFromAToZ();
    return 0;



}
