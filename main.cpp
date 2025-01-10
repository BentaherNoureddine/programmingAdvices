#include <cmath>
#include <iostream>
using namespace std;



void readNums(int &a,int &d)
{
    cout << "Enter  A: ";
    cin >> a;
    cout << "Enter H: ";
    cin >> d;
}


float getArea(int a,int h)
{

  return a/2 *h;
}

void printResult(int num1,int num2)
{
    cout<<"The Ara of the Triangle is "<<getArea(num1,num2)<<endl;
}


int main()
{

    int num1,num2;
    readNums(num1,num2);
    printResult(num1,num2);
    return 0;



}
