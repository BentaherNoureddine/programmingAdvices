#include "dataStructure/clsMysMyQueue.h"


int main()

{


    clsMyQueue<short> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);

    std::cout<<"\nQueue : \n";
    myQueue.print();

    std::cout<<"\nQueue Size: " <<myQueue.size();
    std::cout<<"\nQueue Front : "<<myQueue.front();
    std::cout<<"\nQueue Back : "<<myQueue.back();

    myQueue.pop();

    std::cout<<"\nafter popping \n";
    myQueue.print();

    std::cout<<"\n Item(2) : "<<myQueue.getItem(2);

    myQueue.reverse();
    std::cout<<"\nqueue after reversing :\n";
    myQueue.print();

    myQueue.updateItem(2,600);
    std::cout<<"\nqueue after updating item(2) to 600 :\n";
    myQueue.print();


    myQueue.insertAfter(2,800);
    std::cout<<"\nqueue after inserting 800 after item 2 :\n";
    myQueue.print();


    myQueue.insertAtFront(1000);
    std::cout<<"\nqueue after inserting 1000 at the front :\n";
    myQueue.print();


    myQueue.insertAtBack(2000);
    std::cout<<"\nqueue after inserting 2000 at back :\n";
    myQueue.print();


    myQueue.clear();
    std::cout<<"\nqueue after clearing :\n";
    myQueue.print();




    return 0;
}
