#include <iostream>
#include <stack>

template <typename T>
class Node {

public:
    T data;
    Node *next ;

};


template <typename T>
void addAtTheBeginning(Node<T> * &head,T data) {

    Node<T> * newNode=new Node<T>;

    newNode->data=data;

    newNode->next=head;

    head=newNode;
}


template <typename T>
void printList(Node<T> * head) {

    while (head!=nullptr) {
        std::cout<<head->data<<std::endl;
        head=head->next;
    }
}


template<typename T>
Node<T> *findNode(Node<T> *head,T data) {
    while (head!=nullptr) {
        if (head->data==data) {
            return head;
        }
        head=head->next;
    }
    return nullptr;
}


template<typename T>
void insertAfter(Node<T> *position,T data) {
       Node<T> *newNode = new Node<T>;
       newNode->next=position->next;
       newNode->data=data;
       position->next=newNode;
}

template<typename T>
void insertAtEnd(Node<T> *&head,T data) {

    Node<T> *newNode =new Node<T>;
    newNode->data=data;
    newNode->next=nullptr;


    if (head==nullptr) {
        head = new Node<T>();
        head=newNode;
        return;
    }

    Node<short> *node=head;
    while (node->next!=nullptr) {
        node=node->next;
    }
    node->next=newNode;
}

int main()

{
    Node<short> *head = nullptr;



    insertAtEnd<short>(head,1);
    insertAtEnd<short>(head,2);
    insertAtEnd<short>(head,3);

    std::cout<<"before"<<std::endl;
    printList(head);
    insertAtEnd<short>(head,7);
    std::cout<<"after"<<std::endl;
    printList<short>(head);








    return 0;
}
