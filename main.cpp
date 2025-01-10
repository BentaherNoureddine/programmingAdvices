#include <iostream>
using namespace std;



float readNumber()
{
    float number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}

bool checkPass(float number)
{
    return number>=50;
}

void printResult(float number)
{
    if (checkPass(number))
    {
        cout << "Passed!" << endl;
    }else
    {
        cout << "Failed!" << endl;
    }
}



int main()
{

    printResult(readNumber());
    return 0;



}
