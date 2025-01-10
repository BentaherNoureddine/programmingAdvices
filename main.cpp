#include <cmath>
#include <iostream>
using namespace std;



void readNums(int &a,int &d)
{
    cout << "Enter  A: ";
    cin >> a;
    cout << "Enter D: ";
    cin >> d;
}


float getArea(int a,int d)
{

  return a * sqrt(pow(d, 2) - pow(a, 2));
}

void printResult(int num1,int num2)
{
    cout<<"The Ara of the Rectangle is "<<getArea(num1,num2)<<endl;
}


int main()
{

    int num1,num2;
    readNums(num1,num2);
    printResult(num1,num2);
    return 0;



}
