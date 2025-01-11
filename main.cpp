#include <cmath>
#include <iostream>
using namespace std;


string ColumnSeparator(int i)
{
    if (i>9)
    {
        return "    |";
    }
    return "     |";


}


void calculate()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << " " <<i <<ColumnSeparator(i)<<"\t";
        for (int j = 1; j <= 10; j++)
        {
            cout <<i*j<<"\t \t \t\t";
        }
        cout << endl;
    }
}



void printResult()
{
    cout<<"                            Multiplication Table From 1 to 10             \n";
    cout<<"            1               2              3                4              5                6               7               8               9               10\n";
    cout<<"______________________________________________________________________________________________________________________________________________________________\n";
    calculate();

}



int main()
{




    printResult();
    return 0;



}
