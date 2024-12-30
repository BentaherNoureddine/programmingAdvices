#include <iostream>
using namespace std;


//READ THE ARRAY
void readArray(int x[3])
{
   cout<< "Please enter Grade1 " << endl;
   cin>>x[0];
   cout<< "Please enter Grade2 " << endl;
   cin>>x[1];
   cout<< "Please enter Grade3 " << endl;
   cin>>x[2];
}



//PRINT THE ARRAY
int getAverage(const int x[3])
{
   return (x[0] + x[1] + x[2]) / 3;

}




int main()
{

   int x[3];

  readArray(x);
  cout<<"thee Average of grades is "<< getAverage(x);

}
