#pragma once


namespace oop {


class clsPerson {




private:



    std::string _ID;
    std::string _firstName;
    std::string _lastName;
    std::string _email;
    std::string _phone;






public:

    clsPerson( std::string ID,
    std::string firstName,
    std::string lastName,
    std::string email,
    std::string phone) {
        _ID=ID;
        _firstName=firstName;
        _lastName=lastName;
        _email=email;
        _phone=phone;

    }
    ~clsPerson() {

    }

    std::string getID() {
        return _ID;
    }


    std::string getFirstName() {
        return _firstName;
    }

    std::string getLastName() {
        return _lastName;
    }


    std::string getEmail() {
        return _email;
    }

    std::string getPhone() {
        return _phone;
    }



    void setFirstName(std::string firsName) {
        _firstName=firsName;
    }

    void setLastName(std::string  lastName) {
       _lastName=lastName;
    }


    void setEmail(std::string email) {
       _email=email;
    }

    void getPhone(std::string phone) {
       _phone=phone;
    }


    std::string fullname() {
        return _firstName+" "+_lastName;
    }

    void print() {
        std::cout << "Info:" << std::endl;
        std::cout << "____________________________________" << std::endl;

        std::cout << std::left << std::setw(12) << "ID"        << ": " << _ID        << std::endl;
        std::cout << std::left << std::setw(12) << "First Name"<< ": " << _firstName << std::endl;
        std::cout << std::left << std::setw(12) << "Last Name" << ": " << _lastName  << std::endl;
        std::cout << std::left << std::setw(12) << "Full Name" << ": " << fullname() << std::endl;
        std::cout << std::left << std::setw(12) << "Email"     << ": " << _email     << std::endl;
        std::cout << std::left << std::setw(12) << "Phone"     << ": " << _phone     << std::endl;

        std::cout << "____________________________________" << std::endl;
    }

    void sendEmail(std::string subject,std::string body) {
        std::cout<<"The following message sent successfully to email "<<_email<<std::endl;
        std::cout<<"Subject :"<<subject<<std::endl;
        std::cout<<"Body : "<<body<<std::endl;
    }

    void sendSMS(std::string message ) {
        std::cout<<"The following SMS sent successfully to phone "<<_phone<<std::endl;
        std::cout<<message<<std::endl;
    }



};


class clsEmployee : public clsPerson {

private:

    std::string _title;
    std::string _department;
    float _salary;

public:

    clsEmployee(std::string ID,
    std::string firstName,
    std::string lastName,
    std::string email,
    std::string phone,
    std::string department,
    std::string title,
    float salary
    )
    :clsPerson(ID,firstName,lastName,email,phone){
        _department=department;
        _title=title;
        _salary=salary;
    }

    std::string getDepartment() {
        return _department;
    }

    std::string getTitle() {
        return _title;
    }

    float getSalary() {
        return _salary;
    }

    void setTitle(std::string title) {
        _title=title;
    }

    void setDepartment(std::string department) {
        _department=department;
    }

    void setSalary(float salary) {
        _salary=salary;
    }

    void print() {
        std::cout << "Info:" << std::endl;
        std::cout << "____________________________________" << std::endl;

        std::cout << std::left << std::setw(12) << "ID"        << ": " << getID()          << std::endl;
        std::cout << std::left << std::setw(12) << "First Name"<< ": " << getFirstName()   << std::endl;
        std::cout << std::left << std::setw(12) << "Last Name" << ": " << getLastName()    << std::endl;
        std::cout << std::left << std::setw(12) << "Full Name" << ": " << fullname()       << std::endl;
        std::cout << std::left << std::setw(12) << "Title"     << ": " << _title           << std::endl;
        std::cout << std::left << std::setw(12) << "Department"<< ": " << _department      << std::endl;
        std::cout << std::left << std::setw(12) << "Salary"     << ": " << _salary         << std::endl;
        std::cout << std::left << std::setw(12) << "Email"     << ": " << getEmail()       << std::endl;
        std::cout << std::left << std::setw(12) << "Phone"     << ": " << getPhone()       << std::endl;

        std::cout << "____________________________________" << std::endl;
    }



};



class clsDeveloper:oop::clsEmployee {

private:

    std::string _mainProgrammingLanguage;


public:
    clsDeveloper(std::string ID,
    std::string firstName,
    std::string lastName,
    std::string email,
    std::string phone,
    std::string department,
    std::string title,
    float salary,
    std::string mainProgrammingLanguage
    )
    :clsEmployee(ID,firstName,lastName,email,phone,department,title,salary) {

        _mainProgrammingLanguage=mainProgrammingLanguage;
    }

    std::string getMainProgrammingLanguage() {
        return _mainProgrammingLanguage;
    }

    void setMainProgrammingLanguage(std::string pLanguage) {
        _mainProgrammingLanguage=pLanguage;

    }

    void print() {
        std::cout << "Info:" << std::endl;
        std::cout << "____________________________________" << std::endl;

        std::cout << std::left << std::setw(12) << "ID"        << ": " << getID()          << std::endl;
        std::cout << std::left << std::setw(12) << "First Name"<< ": " << getFirstName()   << std::endl;
        std::cout << std::left << std::setw(12) << "Last Name" << ": " << getLastName()    << std::endl;
        std::cout << std::left << std::setw(12) << "Full Name" << ": " << fullname()       << std::endl;
        std::cout << std::left << std::setw(12) << "Title"     << ": " << getTitle()          << std::endl;
        std::cout << std::left << std::setw(12) << "Department"<< ": " << getDepartment()     << std::endl;
        std::cout << std::left << std::setw(12) << "Salary"     << ": " << getSalary()        << std::endl;
        std::cout << std::left << std::setw(12) << "MainProgrammingLanguage"     << ": " << _mainProgrammingLanguage        << std::endl;
        std::cout << std::left << std::setw(12) << "Email"     << ": " << getEmail()       << std::endl;
        std::cout << std::left << std::setw(12) << "Phone"     << ": " << getPhone()       << std::endl;

        std::cout << "____________________________________" << std::endl;
    }


};

}