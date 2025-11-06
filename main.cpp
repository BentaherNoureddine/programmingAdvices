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




    myDynamicArray.deleteItemAt(2);
    myDynamicArray.printList();




    return 0;
}
