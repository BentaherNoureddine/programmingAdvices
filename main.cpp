#include "dataStructure/clsDbLindedList.h"



int main()

{


    clsDbLinkedList<int> mydbLinkedList;

    mydbLinkedList.insertAtBeginning(5);
    mydbLinkedList.insertAtBeginning(4);
    mydbLinkedList.insertAtBeginning(3);
    mydbLinkedList.insertAtBeginning(2);
    mydbLinkedList.insertAtBeginning(1);

    std::cout<<"linked list content"<<std::endl;
    mydbLinkedList.printList();


   int item=mydbLinkedList.getItem(2);

   std::cout<<"\nnode value is "<<item<<std::endl;




    return 0;
}
