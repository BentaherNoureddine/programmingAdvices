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


bool isPerfect(int number)
{
    int sum =0;
   for (int i=1; i<number; i++)
   {
       if(number%i==0)
       {
           sum+=i;;
       }
   }
   return sum==number;
}


void printResult(int number)
{

   cout<<"Perfect Numbers : \n";

   for(int i=1; i<=number; i++)
   {
       if (isPerfect(i))
       {
           cout<< i<<endl;
       }
   }


}


int main()
{

    printResult(readPositiveNumber("Give a Positive Number"));
    return 0;



}
