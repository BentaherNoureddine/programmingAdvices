#include <iostream>
using namespace std;




float readNumber(string message)
{
    float number;

        cout << message;
        cin >> number;

    return number;


}


short getFracPart(float number) {
    short intPart =short (number);

    return number - intPart;
}


short getRound(float number) {

    short intPart= short(number);
    short fracPart=  getFracPart(number);
    if (fracPart>=0.5) {
        return ++intPart;
    }
    return intPart;

}






int main()
{



    int number = readNumber("Enter a number: ");
    cout <<"My  Round Result is: " << getRound(number) << endl;
    cout<<"C++ Round Result is "<< abs(number) << endl;



    return 0;



}
