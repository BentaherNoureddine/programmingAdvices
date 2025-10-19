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
       return  _myList.size();
    }

    T front() {
        return _myList.getItem(1);
    }

    T back() {
        return _myList.getItem(size());
    }



    void reverse() {
        _myList.reverse();

    }

    T getItem(const unsigned short index) {
        return _myList.getItem(index);
    }


    bool updateItem(const unsigned short index,const T data) {
        return _myList.updateItemByIndex(index,data);
    }

    bool insertAfter(const unsigned short index,const T data) {
        return _myList.insertAfterIndex(index,data);
    }

    void insertAtFront(const T data) {
        _myList.insertAtBeginning(data);
    }

    void insertAtBack(const T data) {
        this->push(data);
    }



    void clear() {
        _myList.clear();
    }


};