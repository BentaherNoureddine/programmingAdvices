#include <cmath>
#include <iostream>
using namespace std;



int readNumber(string message)
{
    int number = 0;
    cout << message<<endl;
    cin >> number;
    return number;
}

int sumNumbers()
{
    int sum=0,counter=1,number=0;

    do
    {
        number = readNumber("Enter a number: " + to_string(counter));
        counter++;
        if (number == -99)
        {
            break;
        }
        sum += number;
    }while (number != -99);
    return sum;
}




int main()
{




    cout << sumNumbers() << endl;

    return 0;



}
