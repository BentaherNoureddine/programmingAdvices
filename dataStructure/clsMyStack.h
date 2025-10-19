#pragma once
#include "clsMysMyQueue.h"


template<class T>
class clsMyClass {
private:

protected:
    clsMyQueue<T> myQueue;
public:

    void push(const T data) {
        myQueue.insertAtFront(data);
    }

    void print() {
        myQueue.print();
    }

    unsigned short size() {
        return myQueue.size();
    }

    T top() {
        return myQueue.front();
    }

    T bottom() {
        return myQueue.back();
    }

    T getItem(const unsigned short index) {
        return myQueue.getItem(index);
    }

    void reverse() {
        myQueue.reverse();
    }

    bool updateItem(const unsigned short index,const T data) {
        return myQueue.updateItem(index,data);
    }

    void insertAfter(const unsigned short index,const T data) {
        myQueue.insertAfter(index,data);
    }

    void insertAtFront(const T data) {
        myQueue.insertAtFront(data);
    }

    void insertATBack(const T data) {
        myQueue.insertAtBack(data);
    }

    void clear() {
        myQueue.clear();
    }




};