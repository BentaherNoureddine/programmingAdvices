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




short getFloor(float number) {

    return short(number);

}






int main()
{



    int number = readNumber("Enter a number: ");
    cout <<"My  Floor Result is: " << getFloor(number) << endl;
    cout<<"C++ Floor Result is "<< ::floor(number) << endl;



    return 0;



}
