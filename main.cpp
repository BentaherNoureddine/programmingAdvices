#include <iostream>
#include <vector>
#include "myInputLibrary.h"

using namespace std;

using namespace myLibrary;



struct  stEmployee {

    string firstName;
    string lastName;
    float salary;
};


void readEmployees(vector<stEmployee> &employees) {


    char choice = 'Y';
    stEmployee employee;

    do {
        employee.firstName = readString("Enter first name: ");
        employee.lastName = readString("Enter last name: ");
        employee.salary = readFloat("Enter salary: ");
        employees.push_back(employee);

        cout << "Do you want to add another employee? (Y/N): ";
        cin >> choice;
    }while (toupper(choice) == 'Y');

}

void printEmployees(vector<stEmployee> &employees) {

    for (stEmployee employee : employees) {

        cout << "First name: " << employee.firstName << endl;
        cout << "Last name: " << employee.lastName << endl;
        cout << "Salary: " << employee.salary << endl;
        cout << endl;
    }
}





int main() {


    vector<stEmployee> employees;
    readEmployees(employees);
    printEmployees(employees);


    return 0;
}