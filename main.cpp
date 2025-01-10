#include <cmath>
#include <iostream>
using namespace std;



void readNums(int &a)
{
    cout << "Enter  R: ";
    cin >> a;
}


float getArea(int r)
{

  return numbers::pi*(pow(r,2));
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
