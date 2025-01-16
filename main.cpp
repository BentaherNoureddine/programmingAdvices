#include <cstdlib>
#include <iostream>
using namespace std;




int readNumber(string message)
{
    short number;

    do
    {
        cout << message;
        cin >> number;
    }while (number < 0);
    return number;


}


int randomNumber(int from,int to)
{

    return rand()%(to-from+1)+from;
}



string getRandomString()
{
    string randomString="";
    for(int i=0;i<4;i++)
    {
     randomString+=char(randomNumber(65,90));
    }
    return randomString;

}


void printKey(int number)
{

    string key="";
    for(int i=1;i<=number;i++)
    {
        key=getRandomString();
        for (int j=0;j<3;j++)
        {
            key+="-"+getRandomString();
        }
        cout<<"Key ["<<i<<"] : "<<key<<endl;
        key="";
    }

}




int main()
{
    // seeds the random number generator in c++, called only once
    srand((unsigned)time(NULL));


    printKey(readNumber("Enter the number of keys you want to generate: "));


    return 0;



}
