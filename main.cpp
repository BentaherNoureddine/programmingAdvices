#include <cstdlib>
#include <iostream>
using namespace std;



int randomNumber(int from,int to)
{

    return rand()%(to-from+1)+from;
}



int main()
{
    // seeds the random number generator in c++, called only once
    srand((unsigned)time(NULL));
    cout<<randomNumber(0,2)<<endl;


    return 0;



}
