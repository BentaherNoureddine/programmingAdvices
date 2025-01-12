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


void printReversedNumber(int number)
{

  int remainder = 0,number2 = 0;;
    while(number>0)
    {
        remainder = number%10;
        number = number/10;
        number2 =number2*10+remainder;
    }
    cout<<number2<<endl;

}




int main()
{

    printReversedNumber(readPositiveNumber("Give a Positive Number"));
    return 0;



}
