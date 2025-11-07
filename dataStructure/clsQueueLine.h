#pragma once
#include <iomanip>

#include "clsMyQueue.h"
#include <iostream>


#include "../lib/clsDate.h"




class clsQueueLine {

public:

    class Ticket {
    private :
        std::string _prefix;
        string _date;
        unsigned short _waitingClients;
        float _serveTime;
        bool served=false;





    public:
        Ticket() {
            _serveTime=0;
            _waitingClients=0;
        }

        Ticket( const std::string &prefix,const string &date ,const unsigned short &waitingClients,const float &serveTime) {
            this->_prefix=prefix;
            this->_date=date;
            this->_waitingClients=waitingClients;
            this->_serveTime=serveTime;
        }


        void printTicket() {
            cout<<left<<setw(12)<<"__________________________________________________"<<endl;
            cout<<left<<setw(14)<<this->_prefix<<endl;
            cout<<this->_date<<endl;
            cout<<"waiting clients = "<<this->_waitingClients<<endl;
            cout<<"Serve time In "<<this->_serveTime<<" Minutes"<<endl;;
            cout<<left<<setw(12)<<"__________________________________________________"<<endl;
        }

    };


private:

    std::string _prefix;
    float _waitingTime;
    clsMyQueue<Ticket> _queue;
    clsMyQueue<Ticket> _waitingClients;
    clsMyQueue<Ticket> _servedClients;
    clsMyQueue<string> _ticketsPrefixes;


    float _totalWaitingTime()  {
        return static_cast<float>(this->_waitingClients.size())*_waitingTime;
    }

    string _getTicketPrefix() {
        return _prefix+to_string(_queue.size()+1);
    }






public:

    clsQueueLine(const std::string &prefix,const float &waitingTime) {
        this->_prefix=prefix;
        this->_waitingTime=waitingTime;
    }


    unsigned short totalTickets() {
        return _queue.size();
    }


    void issueTicket() {
        const Ticket ticket=Ticket(_getTicketPrefix(),clsDate::getCurrentDateAndTimeString(),this->_queue.size(),_totalWaitingTime());
        _queue.push(ticket);
        _ticketsPrefixes.push(_getTicketPrefix());
        this->_waitingClients.push(ticket);
    }


    void printInfo() {
      //PRINT THE INFOS OF A TICKET PREFIX,TOTAL TICKETS, SERVED CLIENTS, WAITING CLIENTS
        cout<<setw(40)<<"____________________________________________________________________"<<endl;
        cout<<setw(40)<<"Queue Info "<<endl;
        cout<<left<<setw(10)<<"____________________________________________________________________"<<endl;
        cout<<setw(12)<<"Prefix  = "<<this->_prefix<<endl;
        cout<<left<<setw(12)<<"Total Tickets  = "<<this->_queue.size()<<endl;
        cout<<left<<setw(12)<<"Served Clients  = "<<this->_servedClients.size()<<endl;
        cout<<left<<setw(12)<<"Waiting Clients = "<<this->_waitingClients.size()<<endl;
        cout<<left<<setw(10)<<"____________________________________________________________________"<<endl;
    }

    void printTicketLineRTL() {
        _ticketsPrefixes.print();
    }

    void printTicketLineLTR() {
        clsMyQueue<string> reversedTicketsQueue=_ticketsPrefixes;
        reversedTicketsQueue.reverse();
        reversedTicketsQueue.print();
    }

    void printAllTickets() {
        cout<<setw(12)<<"---Tickets--"<<endl;
        cout<<setw(10)<<"--------------------------------------------------------"<<endl;
        for (unsigned short i=1;i<=_queue.size();i++) {
            _queue.getItem(i).printTicket();
        }
    }

    void serveNextClient() {
        _servedClients.push(_queue.back());
        _waitingClients.pop();
        _queue.pop();

    }


};