#include <iostream>
using namespace std;



int mySum()
{
   cout <<"Please enter Number1" <<endl;
   int number1;
   cin >> number1;
   cout <<"Please enter Number2" <<endl;
   int number2;
   cin >> number2;
   cout<<"********************************************************************" <<endl;
   return  number1+number2 ;
}


int main()
{


   cout <<mySum() <<endl;
}
