#include <iostream>
#include <vector>
#include  <string>
#include <fstream>
using namespace std;






void loadDataFromFileToVector(string fileName, vector<string>& vFileContent ) {


    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vFileContent.push_back(line);
        }
    }
    file.close();

}

void saveVectorToFile(string fileName, vector<string> vFileContent) {
    fstream file;
    file.open(fileName, ios::out);
    if (file.is_open()) {
        for (string& line : vFileContent) {
            if (line != "") {
               file  << line << endl;
            }
        }
    }
    file.close();
}

void deleteRecordFromFile(string fileName, string record) {
    vector<string> vFileContent;
    loadDataFromFileToVector(fileName,vFileContent);
    for (string& line : vFileContent) {
        if (line == record) {
            line = "";
        }
    }
    saveVectorToFile(fileName,vFileContent);

}


void printFile(string fileName) {
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
}

int main() {


    cout<< "File before delete" << endl;
    printFile("myFile.txt");
    deleteRecordFromFile("myFile.txt", "ali");
    cout<< "File after delete" << endl;
    printFile("myFile.txt");

    return 0;
}