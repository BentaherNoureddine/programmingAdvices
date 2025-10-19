#include "dataStructure/clsDbLindedList.h"
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






    return 0;
}
