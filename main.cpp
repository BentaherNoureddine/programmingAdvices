#include <cmath>
#include <iostream>
using namespace std;



void readNums(int &a)
{
    cout << "Enter  L: ";
    cin >> a;
}


float getArea(int l)
{

  return pow(l,2)/(4*numbers::pi);
}

void printResult(int r)
{
    cout<<"The Ara of the Circle is "<<getArea(r)<<endl;
}


int main()
{

    int r;
    readNums(r);
    printResult(r);
    return 0;



}
