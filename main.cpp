#include <cstdlib>
#include <iostream>
using namespace std;


enum    enCharType{smallLetter=1,capitalLetter=2,specialCharacter=3,digit=4};


int randomNumber(int from,int to)
{

    return rand()%(to-from+1)+from;
}



char getRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::smallLetter:
        {
            return char(randomNumber(97, 122));
            break;
        }
    case enCharType::capitalLetter:
        {
            return char(randomNumber(65, 90));
            break;
        }
    case enCharType::specialCharacter:
        {
            return char(randomNumber(33, 47));
            break;
        }
    case enCharType::digit:
        {
            return char(randomNumber(48, 57));
            break;
        }
    }
}



int main()
{
    // seeds the random number generator in c++, called only once
    srand((unsigned)time(NULL));


    cout << getRandomCharacter(enCharType::smallLetter)<<endl;
    cout<<  getRandomCharacter(enCharType::capitalLetter)<<endl;
    cout<<  getRandomCharacter(enCharType::specialCharacter)<<endl;
    cout<<  getRandomCharacter(enCharType::digit)<<endl;


    return 0;



}
