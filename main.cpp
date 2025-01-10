#include <cmath>
#include <iostream>
using namespace std;



void readNums(int &a)
{
    cout << "Enter  D: ";
    cin >> a;
}


float getArea(int d)
{

  return (numbers::pi*pow(d, 2))/4;
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
