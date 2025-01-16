#include <cmath>
#include <iostream>
using namespace std;



string readString(string s)
{
        string input;
        cout<<s<<endl;
        cin>>input;


    return input;

}


string encrypt(string s,short encryptionKey)
{
    string encrypted="";
    for (int i=0;i<s.length();i++)
    {
        encrypted+=char(int(s[i])+encryptionKey);
    }
    return encrypted;

}


string decrypt(string s,short encryptionKey)
{

    string decrypted="";
    for (int i=0;i<s.length();i++)
    {
        decrypted+=char(int(s[i])-encryptionKey);
    }
    return decrypted;

}



void printResult(string input,short encryptionKey)
{
    cout<<"Text Before Encryption: "<<input<<endl;
    cout<<"Text After Encryption: "<<encrypt(input,encryptionKey)<<endl;
    cout<<"Text After Decryption: "<<decrypt(encrypt(input,encryptionKey),encryptionKey)<<endl;
}


int main()
{
    short encryptionKey=2;
    string input = readString("write a text");
    printResult(input,encryptionKey);
    return 0;



}
