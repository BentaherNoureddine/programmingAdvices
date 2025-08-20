#pragma once
#include <fstream>
#include <vector>

#include "clsInputValidate.h"

#include "clsInputValidate.h"

namespace fileClientData {

const std::string fileName="test.txt";
const std::string usersFileName="users.txt";
const std::string authenticatedUsersFileName="authenticatedUsers.txt";
const std::string sep="//";


void saveToFile(string fileName,string str) {
        fstream file;
        file.open(fileName, ios::app);
        if (file.is_open()) {
            file<<str;
        }
        file<<endl;

        file.close();
}

void saveToFileOut(string fileName,string str) {
    fstream file;
    file.open(fileName, ios::out);
    if (file.is_open()) {
        file<<str;
    }
    file<<endl;

    file.close();
}






string getWord(string str,string sep) {

    return str.substr(0,str.find(sep));
}

void fillVectorWithStrings(vector<string>& vStrings,string str,string sep) {

    while (str.find(sep)!=string::npos) {

        vStrings.push_back(getWord(str,sep));
        str=str.substr(str.find(sep)+sep.length(),str.length());
        if (str.find(sep)==string::npos) {
            vStrings.push_back(str);
            break;
        }



    }
}



void deleteLineFromVector(vector<string>& vLines,string word) {

    for (string& line : vLines) {
        if (line.find(word)!=string::npos) {
            line="";
        }
    }
}

void clearFile(const string& fileName) {
    ofstream file(fileName, ios::trunc); // Open in truncate mode
    file.close(); // Optional, but good practice
}


void saveVStringToFile(vector<string>vLines,string fileName ) {


    clearFile(fileName);

    for (string& line : vLines) {
        if (line!="") {
            saveToFile(fileName,line);
        }

    }
}









}