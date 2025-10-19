#include "dataStructure/clsDbLindedList.h"



int main()

{


    clsDbLinkedList<int> mydbLinkedList;

    mydbLinkedList.insertAtBeginning(1);
    mydbLinkedList.insertAtBeginning(2);
    mydbLinkedList.insertAtBeginning(3);
    mydbLinkedList.insertAtBeginning(4);
    mydbLinkedList.insertAtBeginning(5);

    std::cout<<"linked list content"<<std::endl;
    mydbLinkedList.printList();


    mydbLinkedList.reverse();

    std::cout<<"after reversing:"<<std::endl;
    mydbLinkedList.printList();





    return 0;
}
