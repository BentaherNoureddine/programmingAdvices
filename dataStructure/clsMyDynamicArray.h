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
        return _size;
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

    bool resize(const unsigned short &newSize) {
        if (newSize<0||newSize==_size) {
            return false;
        }
        T *tempArray =new T[newSize];

        for (unsigned short i=0;i<_size;i++) {
            tempArray[i]=array[i];
        }

        delete[] array;
        array=tempArray;
        _size=newSize;

        return true;
    }






};
