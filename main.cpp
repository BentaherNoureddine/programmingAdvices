#include <iostream>
using namespace std;






int main()
{

   int x[3];
   cout<< "Please enter Grade1 " << endl;
   cin>>x[0];
   cout<< "Please enter Grade2 " << endl;
   cin>>x[1];
   cout<< "Please enter Grade3 " << endl;
   cin>>x[2];
   cout <<"*****************************************************************************"<<endl;
   cout <<" The average of grades is "<< (x[0]+x[1]+x[2])/3<<endl;


}
