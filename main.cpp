#include <iomanip>
#include <iostream>
#include <time.h>
#include <stdlib.h>


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

    std::string lastName() {
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


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    clsPerson person("10","noureddine","bentaher","noureddinebentaher20@gmail.com","55530835");

    person.print();

    person.sendEmail("HI","How are you");
    person.sendSMS("How are you");






    return 0;
}
