#include <iostream>

#include "myLibrary.h";
using namespace std;
using namespace MyLib;



int mult(int a, int b) {
    return a*b;
}

int main() {

    int a,b,c,res, arr[5]= {1,2,3,4,5};

    a=10;
    b=20;
    c=a+b;
    cout << "a = "<< a<<endl;
    cout << "b = "<< b<<endl;
    cout << "c = "<< c<<endl;
    res=mult(a,b);
    cout << "res = "<< res<<endl;
    a=0;
    b=0;
    cout << "a = "<< a<<endl;
    cout << "b = "<< b<<endl;
    cout << "c = "<< c<<endl;
    test();



    return 0;
}