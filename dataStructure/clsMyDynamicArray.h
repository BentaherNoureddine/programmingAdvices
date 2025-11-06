#pragma once
#include <iostream>
template<class T>
class clsMyDynamicArray {


protected:
    unsigned short _size;





public:

    T *array;


    clsMyDynamicArray(unsigned short size=0) {

        if (size<0) {
            _size=0;
        }
        _size=size;
        array=new T[size];
    }

    ~clsMyDynamicArray() {
        delete[] array;
    }

    bool setItem(unsigned short index,T item) {
        if (index<0 ||index>_size) {
            return false;
        }
        *(array+index)=item;
        return true;
    }

    unsigned short size() {
        return size();
    }

    bool isEmpty() {
        return _size<1;
    }

    void printList() {
        std::cout<<"\n";
        for (unsigned short i=0;i<_size;i++) {
            std::cout<<*(array+i)<<" ";
        }
        std::cout<<std::endl;
    }






};
