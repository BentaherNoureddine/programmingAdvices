#include <cmath>
#include <iostream>
using namespace std;



enum enOptype{Add = '+',Subtract='-',Multiply = '*',Divide = '/'};

int readNumber(string input)
{
    int number;
    cout<<input;
    cin>>number;
    return number;
}


enOptype readOperator()
{
    cout<<"Please enter an operator (+,-,*,/):"<<endl;
    char input='+';
    cin>>input;
    return (enOptype)input;
}

float calculate(int a,int b,enOptype optype)
{
    switch(optype)
    {
        case Add:
            return a+b;
        case Subtract:
            return a-b;
        case Multiply:
            return a*b;
        case Divide:
            return a/b;
        default:
            return a+b;
    }

}


int main()
{


    int num1,num2;
    num1 = readNumber("Enter First Number: ");
    num2 = readNumber("Enter Second Number: ");
    enOptype op= readOperator();
    cout<<"The result is: "<<calculate(num1,num2,op)<<endl;



    return 0;



}
