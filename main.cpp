#include <iostream>
using namespace std;




int readNumber(string message)
{
    short number;

        cout << message;
        cin >> number;

    return number;


}


int getAbs(int number) {
    if (number < 0) {
        return -number;
    }
    return number;
}






int main()
{



    int number = readNumber("Enter a number: ");
    cout <<"My abs Result is: " << getAbs(number) << endl;
    cout<<"C++ abs Result is "<< abs(number) << endl;



    return 0;



}
