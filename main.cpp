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




int main() {


    vector<string> vFileContent;
    loadDataFromFileToVector("myFile.txt", vFileContent);
    for (string &line : vFileContent) {
        cout <<line << endl;
    }


    return 0;
}