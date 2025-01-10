#include <iostream>
using namespace std;



int readNumber()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}

float getHalf(int number)
{
    return number / 2;
}

void printHalf(float result)
{
    cout <<"The Half Is : " << result << endl;
}



int main()
{

    printHalf(getHalf(readNumber()));
    return 0;



}
