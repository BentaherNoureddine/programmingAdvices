#pragma once
#include "clsMyQueueArr.h"





template<class T>
class clsMyStackArr :protected clsMyQueueArr<T>{
private:



public:

    void push(const T data) {
        clsMyQueueArr<T>::insertAtBack(data);
    }


    T top() {
        return clsMyQueueArr<T>::front();
    }


    T bottom() {
        return clsMyQueueArr<T>::_d;
    }

    void print() {
        clsMyQueueArr<T>::print();
    }

};