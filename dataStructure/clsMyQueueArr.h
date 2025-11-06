#pragma once
#include "clsMyDynamicArray.h"
#include <iostream>



template<class  T>
class clsMyQueueArr {

private:
    clsMyDynamicArray<T> _dArray;




public:



    void print() {
        _dArray.printList();
    }

    void push(const T data) {
        _dArray.insertAtEnd(data);
    }


    void pop() {
        _dArray.deleteLastItem();
    }

    unsigned short size() {
        return  _dArray.size();
    }

    T front() {
        return _dArray.getItem(0);
    }

    T back() {
        return _dArray.getItem(_dArray.size()-1);
    }



    void reverse() {
        _dArray.reverse();

    }

    T getItem(const unsigned short index) {
        return _dArray.getItem(index);
    }


    bool updateItem(const unsigned short index,const T data) {
        return _dArray.setItem(index,data);
    }

    bool insertAfter(const unsigned short index,const T data) {
        return _dArray.insertAfter(index,data);
    }

    void insertAtFront(const T data) {
        _dArray.insertAtBeginning(data);
    }

    void insertAtBack(const T data) {
        this->push(data);
    }



    void clear() {
        _dArray.clear();
    }

    bool isEmpty() {
        return _dArray.isEmpty();
    }
};