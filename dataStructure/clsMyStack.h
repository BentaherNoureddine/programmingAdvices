#pragma once
#include "clsMysMyQueue.h"


template<class T>
class clsMyStack:public clsMyQueue<T>{
private:


public:

    void push(const T data) {
        clsMyQueue<T>::_myList.insertAtBeginning(data);
    }


    T top() {
        return clsMyQueue<T>::front();
    }

    T bottom() {
        return clsMyQueue<T>::back();
    }




};