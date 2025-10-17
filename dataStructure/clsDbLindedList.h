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
    Node *head;
    unsigned short _size=0;

public:






    clsDbLinkedList() {
        this->head=nullptr;
    }

    ~clsDbLinkedList() = default;




    void insertAtBeginning(T data) {

        if (head==nullptr) {
            head=new Node;
            head->data=data;
            head->next=nullptr;
            head->prev=nullptr;
            _size++;
            return;
        }

        Node * newNode=new Node;

        newNode->data=data;

        newNode->next=head;
        newNode->prev=nullptr;

        head->prev=newNode;

        head=newNode;

        _size++;
    }



    void printList() {

        Node *tempNode=head;
        while (tempNode!=nullptr) {
            std::cout<<tempNode->data<<" ";
            tempNode=tempNode->next;
        }
        std::cout<<std::endl;
    }



    Node *findNode(T data) {
        Node *tempNode=head;
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


        if (head==nullptr) {
            head=newNode;
            _size++;
            return;
        }
        Node *temp =head;
        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        _size++;

    }



    void deleteNode(Node *node) {
        if (head==nullptr||findNode(node->data)==nullptr) {
            return;
        }
        if (head->data==node->data) {
            head=head->next;
        }
        if (head->next==nullptr) {
            head=nullptr;
        }


        Node *temp = head;

        while (temp->data!=node->data) {
            temp=temp->next;
        }

        if (temp->next==nullptr) {
            temp->prev->next=nullptr;
            return;
        }
        _size--;

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        delete temp;


    }



    void deleteFirstNode() {
        if (head==nullptr) {
            return;
        }

        if (head->next!=nullptr) {
            head=head->next;
            delete head->prev;
            head->prev=nullptr;
            _size--;
            return;
        }
        _size--;
        delete head;
        head=nullptr;
    }



    void deleteLastNode() {

        if (head==nullptr) {
            return;
        }

        if (head->next==nullptr) {
            delete head;
            head=nullptr;
            _size--;
            return;
        }

        Node *temp=head;

        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->prev->next=nullptr;
        delete temp;
        _size--;
    }


    unsigned short size() const {
        return _size;
    }


    bool isEmpty() {
        return head==nullptr;
    }

};


