#pragma once
#include <iostream>


template<class  T>
class clsDbLinkedList {

public:
    class  Node {
    public:
        T data;
        Node *prev=nullptr;
        Node *next=nullptr;
    };

private:
    Node *_head=nullptr;
    Node *_tail=nullptr;
    unsigned short _size=0;

public:






    ~clsDbLinkedList() = default;




    void insertAtBeginning(T data) {

        if (_head==nullptr) {
            _head=new Node;
            _head->data=data;
            _head->next=nullptr;
            _head->prev=nullptr;
            _tail=_head;
            _size++;
            return;
        }

        Node * newNode=new Node;

        newNode->data=data;

        newNode->next=_head;
        newNode->prev=nullptr;

        _head->prev=newNode;

        _head=newNode;

        _size++;
    }



    void printList() {

        Node *tempNode=_head;
        while (tempNode!=nullptr) {
            std::cout<<tempNode->data<<" ";
            tempNode=tempNode->next;
        }
        std::cout<<std::endl;
    }



    Node *findNode(T data) {
        Node *tempNode=_head;
        while (tempNode!=nullptr) {
            if (tempNode->data==data) {
                return tempNode;
            }
            tempNode=tempNode->next;
        }
        return nullptr;
    }


    void insertAfter(Node *node,T data) {


        Node *newNode= new Node;
        newNode->data=data;



        Node *nextNode=node->next;


        node->next=newNode;

        newNode->prev=node;
        newNode->next=nextNode;
        nextNode->prev=newNode;

        _size++;

    }


    void insertAtEnd(T data) {

        Node *newNode =new Node;
        newNode->data=data;


        if (_head==nullptr) {
            _head=newNode;
            _size++;
            _tail=_head;
            return;
        }
        Node *temp =_head;
        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        _size++;

    }



    void deleteNode(Node *node) {
        if (_head==nullptr||findNode(node->data)==nullptr) {
            return;
        }
        if (_head->data==node->data) {
            _head=_head->next;
        }
        if (_head->next==nullptr) {
            _head=nullptr;
        }


        Node *temp = _head;

        while (temp->data!=node->data) {
            temp=temp->next;
        }

        if (temp->next==nullptr) {
            temp->prev->next=nullptr;
            delete temp;
            _tail=temp->prev;
            return;
        }
        _size--;

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        delete temp;


    }



    void deleteFirstNode() {
        if (_head==nullptr) {
            return;
        }

        if (_head->next!=nullptr) {
            _head=_head->next;
            delete _head->prev;
            _head->prev=nullptr;
            _size--;
            return;
        }
        _size--;
        delete _head;
        _head=nullptr;
    }



    void deleteLastNode() {

        if (_head==nullptr) {
            return;
        }

        if (_head->next==nullptr) {
            delete _head;
            _head=nullptr;
            _size--;
            return;
        }

        Node *temp=_head;

        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->prev->next=nullptr;
        _tail=temp->prev;
        delete temp;
        _size--;
    }


    unsigned short size() const {
        return _size;
    }


    bool isEmpty() const {
        return _size==0;
    }

    void clear() {
        if (this->isEmpty()) {
            return;
        }
        while (_size>0) {
            deleteFirstNode();
        }
    }

    void reverse() {
        if (this->isEmpty()) {
            return;
        }
        clsDbLinkedList newList;
        Node *temp=_tail;
        while (_size>0) {
            newList.insertAtBeginning(temp->data);
            temp=temp->prev;
            this->deleteLastNode();
        }

        this->_head=newList._head;
        this->_tail=newList._tail;
        this->_size=newList._size;
    }

};


