#include "dataStructure/clsQueueLine.h"


int main()

{


    clsQueueLine payBillsQueue("A0",10);

    payBillsQueue.issueTicket();
    payBillsQueue.issueTicket();
    payBillsQueue.issueTicket();
    payBillsQueue.issueTicket();
    payBillsQueue.issueTicket();


    std::cout<<"\n Pay Bills Queue Info : \n";
    payBillsQueue.printInfo();

    payBillsQueue.printTicketLineRTL();
    payBillsQueue.printTicketLineLTR();

    payBillsQueue.printAllTickets();

    payBillsQueue.serveNextClient();

    payBillsQueue.printAllTickets();

    return 0;
}
