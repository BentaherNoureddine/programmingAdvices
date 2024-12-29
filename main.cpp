#include <iostream>
using namespace std;



int main()
{

   string string1;
   string string2;
   string string3;

   cout << "Please enter String1" << endl;
   getline(cin, string1);
   cout << "Please enter String2" << endl;
   getline(cin, string2);
   cout << "Please enter String3" << endl;
   getline(cin, string3);

   cout <<"**************************************************************"<<endl;

   cout << "the length of string 1 is "<<string1.length()<<endl;
   cout <<"characters at 0,2,4,7 are: "<<string1[0]<<" "<<string1[2]<<" "<<string1[4]<<" "<<string1[7]<<endl;
   cout <<"concatenating string2 and string 3  = "<<string2 + string3<<endl;
   cout<< stoi(string2) <<" * "<<stoi(string3) <<" = "<<stoi(string2) * stoi(string3)<< endl;

}
