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


int reverseNumber(int number)
{

    int remainder=0;int number2=0;
    while(number>0)
    {
        remainder=number%10;
        number=number/10;
        number2 = number2*10+remainder;
      
    }
  return number2;
}


void printReverse(int number)
{

    if (number==reverseNumber(number))
        cout <<" Yes, it s a Palindrome Number"<<endl;
    else
        cout <<" No, it s Not a Palindrome Number"<<endl;



}




int main()
{

    printReverse(readPositiveNumber("Give a Positive Number "));
    return 0;



}
