#include <iostream>
#include <vector>
#include "myInputLibrary.h"

using namespace std;

using namespace myLibrary;



void fillVector(vector<int> &vec) {

    char choice = 'Y' ;

     do{

        vec.push_back(readInt("Enter a number: "));
        cout << "Do you want to add another number? (Y/N): ";
        cin >> choice;
    }while (toupper(choice) == 'Y');
}


void printVector(vector<int>  vec) {

    for (int i :vec) {
        cout << i << endl;
    }

}






int main() {


    vector<int> vec;
    fillVector(vec);
    printVector(vec);


    return 0;
}