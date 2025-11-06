#include "dataStructure/clsMyDynamicArray.h"


int main()

{


   clsMyDynamicArray<int> myDynamicArray(5);
    myDynamicArray.setItem(0,10);
    myDynamicArray.setItem(1,20);
    myDynamicArray.setItem(2,30);
    myDynamicArray.setItem(3,40);
    myDynamicArray.setItem(4,50);

    myDynamicArray.printList();
    std::cout<<std::endl;

   std::cout<<myDynamicArray.size()<<std::endl;
    myDynamicArray.resize(2);
    myDynamicArray.resize(10);
    myDynamicArray.printList();
    std::cout<<myDynamicArray.size()<<std::endl;




    return 0;
}
