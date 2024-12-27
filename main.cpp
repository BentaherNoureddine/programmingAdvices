#include <iostream>
using namespace std;


int main()
{

    string Name  ;
    int Age ;
    string city;
    string country ;
    float monthly_salary;
    float yearly_salary;
    char gender = 'M';
    bool isMaried;

   for (int i =0; i < 10; i++)
   {
       cout<<"****";
   }
    cout<<endl;

    cout<<"Enter Your Name: ";
    cin>>Name;
    cout<<"Enter Your Age: ";
    cin>>Age;
    cout<< "Enter Your City : ";
    cin>>city;
    cout<< "Enter Your Country : ";
    cin>>country;
    cout<< "Enter Your Monthly Salary : ";
    cin>>monthly_salary;
    cout<< "Enter Your Yearly Salary : ";
    cin>>yearly_salary;
    cout<< "Enter your Gender : ";
    cin>>gender;
    cout<<"Aru You Maried 0/1 ";
    cin>>isMaried;

    cout<< "Name : " << Name <<endl;
    cout<< "Age : " << Age << endl;
    cout<< "City : "<<city<<endl;
    cout<< "Country : "<<country<<endl;
    cout<< "monthly_salary : "<<monthly_salary<<endl;
    cout<< "yearly_salary : "<<yearly_salary<<endl;
    cout<< "Gender : "<<gender<<endl;

    for (int i =0; i < 10; i++)
    {
        cout<<"*";
    }

    return 0;
}
