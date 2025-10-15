#include <iostream>
#include <stack>

template <typename T>
class Node {

public:
    T data;
    Node *next ;
    Node *prev;
};


template <typename T>
void addAtTheBeginning(Node<T> * &head,T data) {

    if (head==nullptr) {
        return;
    }

    Node<T> * newNode=new Node<T>;

    newNode->data=data;

    newNode->next=head;
    newNode->prev=nullptr;

    head->prev=newNode;

    head=newNode;
}


template <typename T>
void printList(Node<T> * head) {

    while (head!=nullptr) {
        std::cout<<head->data<<std::endl;
        head=head->next;
    }
}


template <typename T>
Node<T> *findNode(Node<T> *head,T data) {
    while (head!=nullptr) {
        if (head->data==data) {
            return head;
        }
        head=head->next;
    }
    return nullptr;
}

template <typename T>
void insertAfter(Node<T> *head,T after,T data) {
    if (head==nullptr) {
        return;
    }

    Node<T> *newNode= new Node<T>;
    newNode->data=data;

    Node<T> *node=findNode<short>(head,after);

    Node<T> *nextNode=node->next;


    node->next=newNode;

    newNode->prev=node;
    newNode->next=nextNode;
    nextNode->prev=newNode;



}


int main()

{
    Node<short> *head = new Node<short>;
    head->data=1;



    addAtTheBeginning<short>(head,2);
    addAtTheBeginning<short>(head,3);
    std::cout<<"before"<<std::endl;
    printList(head);

    insertAfter<short>(head,2,7);


    std::cout<<"after"<<std::endl;
    printList<short>(head);








    return 0;
}
