#include <iostream>
#include <stack>

template <typename T>
class Node {

public:
    T data;
    Node *next=nullptr ;
    Node *prev=nullptr;
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
void insertAfter(Node<T> *node,T data) {


    Node<T> *newNode= new Node<T>;
    newNode->data=data;



    Node<T> *nextNode=node->next;


    node->next=newNode;

    newNode->prev=node;
    newNode->next=nextNode;
    nextNode->prev=newNode;

}

template<typename T>
void insertAtEnd(Node<T> *&head,T data) {

    Node<T> *newNode =new Node<T>;
    newNode->data=data;


    if (head==nullptr) {
        head=newNode;
        return;
    }
    Node<T> *temp =head;
    while (temp->next!=nullptr) {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;

}





int main()

{
    Node<short> *head = new Node<short>;
    head->data=1;



    addAtTheBeginning<short>(head,2);
    addAtTheBeginning<short>(head,3);
    std::cout<<"before"<<std::endl;
    printList(head);

    Node<short> *node=findNode<short>(head,2);
    insertAtEnd<short>(head,10);


    std::cout<<"after"<<std::endl;
    printList<short>(head);








    return 0;
}
