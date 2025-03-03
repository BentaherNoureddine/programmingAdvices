#include <cmath>
#include <iostream>
using namespace std;




float readNumber(string message)
{
    float number;

        cout << message;
        cin >> number;

    return number;


}




int getSqrt(float number) {

    return pow(number,0.5);


}






int main()
{



    float number = readNumber("Enter a number: ");
    cout <<"My  sqrt Result is: " <<getSqrt(number) << endl;
    cout<<"C++ sqrt Result is "<< sqrt(number) << endl;



    return 0;



}
