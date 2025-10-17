#include "dataStructure/clsDbLindedList.h"



int main()

{


    clsDbLinkedList<int> mydbLinkedList;

    if (mydbLinkedList.isEmpty()) {
        std::cout<<"Yes list is empty";
    }else
     std::cout<<"No list is not empty";



    return 0;
}
