#pragma once
#include "clsMyDynamicArray.h"





template<class T>
class clsMyStackArr {
private:

    clsMyDynamicArray<T> _dArr;

public:

    void push(const T data) {
        _dArr.insertAtBeginning(data);
    }


    T top() {
        return _dArr.getItem(_dArr.size()-1);
    }

    T bottom() {
        return _dArr.getItem(0);
    }

};