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


float getFrac(float number) {
    return number-int(number) ;
}


int getCiel(float number) {

  if (number<0) {

      return int(number);
  }
  if (getFrac(number)==0) {
      return int(number);
  }
  return int(number)+1;

}






int main()
{



    float number = readNumber("Enter a number: ");
    cout <<"My  Floor Result is: " << getCiel(number) << endl;
    cout<<"C++ Floor Result is "<< ::ceill(number) << endl;



    return 0;



}
