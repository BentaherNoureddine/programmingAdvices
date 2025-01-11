#include <cmath>
#include <iostream>
using namespace std;



struct stInputs
{
    int a,b;
};

stInputs readNums()
{
    stInputs inputs;
    cout << "Enter  a: ";
    cin >> inputs.a;
    cout << "Enter  b: ";
    cin >> inputs.b;
    return inputs;
}


float getArea(stInputs inputs)
{

  return  ((numbers::pi*pow(inputs.b,2))/4)*(2*inputs.a-inputs.b)/(2*inputs.a+inputs.b);
}

void printResult(stInputs inputs)
{
    cout<<"The Ara of the Circle is "<<getArea(inputs)<<endl;
}


int main()
{


    printResult(readNums());

    return 0;



}
