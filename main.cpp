#include "dataStructure/clsDbLindedList.h"



int main()

{


    clsDbLinkedList<int> mydbLinkedList;

    mydbLinkedList.insertAtBeginning(5);
    mydbLinkedList.insertAtBeginning(4);
    mydbLinkedList.insertAtBeginning(3);
    mydbLinkedList.insertAtBeginning(2);
    mydbLinkedList.insertAtBeginning(1);

    std::cout<<"\n Linked List content"<<std::endl;
    mydbLinkedList.printList();


    clsDbLinkedList<int>::Node *n1 = mydbLinkedList.findNode(2);

    if (n1!=nullptr) {
        std::cout<<"\n Node with value 2 is found!"<<std::endl;
    }else {
        std::cout<<"Node is not found"<<std::endl;
    }

    mydbLinkedList.insertAfter(n1,500);
    std::cout<<"\n after inserting 500 after 2"<<std::endl;
    mydbLinkedList.printList();

    mydbLinkedList.insertAtEnd(700);
    std::cout<<"\n after inserting 700 at end"<<std::endl;
    mydbLinkedList.printList();


    clsDbLinkedList<int>::Node *n2 = mydbLinkedList.findNode(4);
    mydbLinkedList.deleteNode(n2);
    std::cout<<"\n after deleting 4"<<std::endl;
    mydbLinkedList.printList();

    mydbLinkedList.deleteFirstNode();
    std::cout<<"\n after deleting firs Node"<<std::endl;
    mydbLinkedList.printList();

    mydbLinkedList.deleteLastNode();
    std::cout<<"\n after deleting last Node"<<std::endl;
    mydbLinkedList.printList();





    return 0;
}
