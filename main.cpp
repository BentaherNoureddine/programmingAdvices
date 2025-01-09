#include <iostream>
using namespace std;


struct stInfo
{
    int age;
    bool haveDrivingLicence;
    bool hasRecommendation;
};


bool isAccepted(stInfo info)
{
    return (info.haveDrivingLicence && info.age>=21)||info.hasRecommendation;
}

void printResult(stInfo info)
{
    if (isAccepted(info))
    {
        cout<<"Your account has been accepted"<<endl;
    }else
    {
        cout<<"Your account has been rejected"<<endl;
    }

}

stInfo readInfo()
{
    stInfo info;
    cout << "Please enter your age: ";
    cin >> info.age;
    cout << "do you have a driving licence?: ";
    cin >> info.haveDrivingLicence;
    cout << "do you have a recommendation?: ";
    cin >> info.hasRecommendation;
    return info;
}


int main()
{


    printResult(readInfo());
    return 0;



}
