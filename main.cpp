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

void updateRecordFromFile(string fileName, string oldRecord, string newRecord) {
    vector<string> vFileContent;
    loadDataFromFileToVector(fileName,vFileContent);
    for (string& line : vFileContent) {
        if (line == oldRecord) {
            line = newRecord;
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
    updateRecordFromFile("myFile.txt", "noureddine","hazem");
    cout<< "File after delete" << endl;
    printFile("myFile.txt");

    return 0;
}