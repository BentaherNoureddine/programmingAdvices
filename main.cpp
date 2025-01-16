#include <cmath>
#include <iostream>
using namespace std;



string readString(string s)
{
    string input;
    do
    {
        cout<<s;
        cin>>input;

    }while(input.length()!=3);
    return input;

}






void getPassWord(string s)
{
    int sum=1;
    string password = "";
    for (int i = 65;i<=90; i++)
    {
        for (int j= 65;j<=90; j++)
        {
            for (int k= 65;k<=90; k++)
            {

                password+=char(i);
                password+=char(j);
                password+=char(k);
                cout<<"Trial["<<sum<<"] :"<<password<<endl;
                if (password==s)
                {
                        cout<<"Password is "<<password<<endl;
                        cout<<"Found Password after "<<sum<<" Trial(s)"<<endl;
                        return;
                }
                sum++;
                password="";

            }
        }

    }

}

int main()
{

    getPassWord(readString("WRITE YOUR PASSWORD"));
    return 0;



}
