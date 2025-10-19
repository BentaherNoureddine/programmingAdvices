#pragma once
#include <iostream>
#include "clsDbLindedList.h"

template<class T>
class clsMyQueue {


protected:
    clsDbLinkedList<T>  _myList;


public:


    void push(const T data) {
       _myList.insertAtEnd(data);
    }


    void pop() {
       _myList.deleteFirstNode();
    }

    unsigned short size() {
        _myList.size();
    }

    T front() {
        return _myList.getItem(1);
    }

    T back() {
        return _myList.getItem(size());
    }

    bool isEmpty() {
        return _myList.isEmpty();
    }

    void print() {
        _myList.printList();
    }


};