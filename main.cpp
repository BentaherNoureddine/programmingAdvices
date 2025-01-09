#include <iostream>
using namespace std;




int main()
{

   for (int i=65;i<91;i++)
   {

      for (int j=65;j<91;j++)
      {
         cout<< static_cast<char>(i);
         cout<<static_cast<char>(j)<<endl;
      }
   }


}
