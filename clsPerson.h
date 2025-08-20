#pragma once

#include <iostream>
using namespace std;

class clsPerson
{

private:

    string _firstName;
    string _lastName;
    string _email;
    string _phone;

public:

    clsPerson( string firstName, string lastName, string email, string phone)
    {

        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }





    //Property Set
    void setFirstName(string firstName)
    {
        _firstName = firstName;
    }

    //Property Get
    string getFirstName()
    {
        return _firstName;
    }

    //Property Set
    void setLastName(string lastName)
    {
        _lastName = lastName;
    }

    //Property Get
    string getLastName()
    {
        return _lastName;
    }

    //Property Set
    void setEmail(string email)
    {
        _email = email;
    }

    //Property Get
    string getEmail()
    {
        return _email;
    }

    //Property Set
    void setPhone(string phone)
    {
        _phone = phone;
    }

    //Property Get
    string getPhone()
    {
        return _phone;
    }

    string fullName()
    {
        return _firstName + " " + _lastName;
    }





};