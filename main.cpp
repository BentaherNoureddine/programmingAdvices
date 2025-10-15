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
void insertAfter(Node<T>*head,Node<T> *position,Node<T> *newNode) {

   if (findNode<short>(head,position->data)!=nullptr) {
       newNode->next=position->next;
       position->next=newNode;
   }

}

int main()

{
    Node<short> *head = nullptr;



    addAtTheBeginning<short>(head,1);

    addAtTheBeginning<short>(head,2);

    addAtTheBeginning<short>(head,3);

    std::cout<<"before"<<std::endl;
    printList(head);
    Node<short>* newNode=new Node<short>;
    newNode->data=7;
    insertAfter(head,findNode<short>(head,2),newNode);
    std::cout<<"after"<<std::endl;
    printList<short>(head);








    return 0;
}
