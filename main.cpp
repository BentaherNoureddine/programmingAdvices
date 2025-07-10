#include <iostream>

using namespace std;



void rec(int m, int n){

    if (m>n) {
        cout << m << endl;
        rec(m-1,n);
    }
}





int main() {


    rec(10,5);

    return 0;
}