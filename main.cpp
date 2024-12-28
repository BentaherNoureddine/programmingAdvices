#include <iostream>
using namespace std;


struct Person
{
    string name,city,country;
    float monthly_salary,yearly_salary;
    int age;
    char gender;
    bool maried;

};



int main()
{

    Person person;

    cout <<"Your Name : " ;
    cin >> person.name;
    cout <<"Your Age : " ;
    cin>> person.age;
    cout <<"Your City : " ;
    cin >> person.city;
    cout <<"Your Country : " ;
    cin >> person.country;
    cout <<"Your Monthly Salary : " ;
    cin >> person.monthly_salary;
    cout <<"Your Yearly Salary : " ;
    cin >> person.yearly_salary;
    cout <<"Your Gender : " ;
    cin >> person.gender;
    cout <<"Are you Maried 0/1 : " ;
    cin >> person.maried;

    cout << "************************************************************\n";
    cout <<"Your Name : " <<person.name<<endl;
    cout <<"Your Age : " <<person.age<<endl;
    cout <<"Your City : " <<person.city<<endl;
    cout <<"Your Country : " <<person.country<<endl;
    cout <<"Monthly Salary : " <<person.monthly_salary<<endl;
    cout <<"Yearly Salary : " <<person.yearly_salary<<endl;
    cout <<"Gender : " <<person.gender<<endl;
    cout <<"Maried : " <<person.maried<<endl;


}
