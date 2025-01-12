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


int calculateFrequency(int number,int i)
{

    int remainder=0,frequency=0;

    while (number>0)
    {

        remainder=number%10;
        if (i==remainder)
        {
            frequency++;
        }
        number/=10;

    }
    return frequency;

}


void printFrequency(int number)
{

    for (int i = 0; i <= 9; i++)
    {
        if (calculateFrequency(number,i)>=1)
        {
            cout<< "Digit "<<i<<" frequency is "<<calculateFrequency(number,i)<<endl;
        }
    }



}




int main()
{

    printFrequency(readPositiveNumber("Give a Positive Number "));
    return 0;



}
