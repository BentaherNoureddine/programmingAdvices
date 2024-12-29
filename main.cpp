#include <iostream>
using namespace std;



void swapme(int &a,int &b)
{
   int c = a;
   a=b;
   b=c;

}


int main()
{


   int a,b;

    cout<<"Enter a number a :";
    cin>>a;
    cout<<"Enter a number b :";
    cin>>b;

    swapme(a,b);
    cout<<a<<" "<<b<<endl;
}
