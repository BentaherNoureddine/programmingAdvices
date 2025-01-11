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

    string stNumber = to_string(number);
    for (int i = stNumber.size()-1; i >= 0; i--)
    {
        cout<<stNumber[i]<<endl;
    }
}




int main()
{

    printReversedNumber(readPositiveNumber("Give a Positive Number"));
    return 0;



}
