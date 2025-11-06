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


    T getItem(const unsigned short &index) {
        return array[index];
    }


    void reverse() {
        T *tempArr=new T[_size];
        for (unsigned short i=0;i<_size;i++) {
            tempArr[_size-i-1]=array[i];
        }
        delete[] array;
        array=tempArr;
    }

    void clear() {
        delete[] array;
        array=nullptr;
        _size=0;
    }

    bool deleteItemAt(const unsigned short &index) {
        if (index<0||index>_size) {
            return false;
        }
        T *tempArr = new T[_size-1];
        unsigned short arrCounter=0;
        unsigned short tempArrCounter=0;
        while (arrCounter<_size) {
            if (index==arrCounter) {
                arrCounter++;
            }else {
                tempArr[tempArrCounter]=array[arrCounter];
                arrCounter++;
                tempArrCounter++;
            }

        }
        delete[] array;
        array=tempArr;
        _size--;
        return true;
    }


    bool deleteFirstItem() {
        return deleteItemAt(0);
    }

    bool deleteLastItem() {
       return deleteItemAt(_size-1) ;
    }

    unsigned short find(const T &value) {
        for (unsigned short i=0;i<_size;i++) {
            if (array[i]==value) {
                return i;
            }
        }
        return -1;
    }


    bool deleteItem(const T &value) {
        const short foundAt=find(value);
        if (foundAt==-1) {
            return false;
        }
        deleteItemAt(foundAt);
        return true;
    }






};
