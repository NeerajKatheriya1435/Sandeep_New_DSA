#include <iostream>
using namespace std;

class Node{

    public:
        Node *prev;
        Node *next;
        int data;

        Node(int value){
            data=value;
            next=nullptr;
            prev=nullptr;
        }
};

class DoublyLinkedList{
    public:
        Node *head;
        DoublyLinkedList(){
            head=nullptr;
        }

        void insertAtBegining(int value){
            Node *newNode=new Node(value);
            if(head!=nullptr){
                newNode->next=head;
                head->prev=newNode;
            }
            head=newNode;
        }
        void insertAtEnd(int value){
            Node *newNode=new Node(value);
            if(head==nullptr){
                head=newNode;
                return;
            }
            Node *temp=head;
            while (temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
        }

        void insertAtPosition(int pos,int value){
            Node *newNode=new Node(value);
            if(pos==0){
                insertAtBegining(value);
                return;
            }
            Node *temp=head;
            for (int i = 1; i < pos && temp!=nullptr; i++)
            {
                temp=temp->next;
            }

            if (temp == nullptr) {
                cout << "Invalid position!" << endl;
                return;
            }
            newNode->next=temp->next;
            newNode->prev=temp;

            if (temp->next != nullptr)
                temp->next->prev = newNode;
            temp->next = newNode;
        }

        void deleteAtPosition(){}
        void listSize(){}
        void deleteAtbegining(){}
        void deleteAtEnd(){}
        void searchElement(){}
        void getIndex(){}

        void displayData(){
            Node* temp=head;
            if(head==nullptr){
                cout<<"List is Empty"<<endl;
                return;
            }
            while (temp!=nullptr)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
};

int main()
{
    
    DoublyLinkedList d1;
    d1.insertAtBegining(45);
    // d1.insertAtBegining(23);
    // d1.insertAtBegining(56);
    d1.insertAtEnd(34);
    d1.insertAtEnd(23);
    d1.insertAtEnd(89);
    d1.insertAtEnd(74);
    d1.insertAtPosition(2,567);
    d1.insertAtPosition(4,222);
    d1.displayData();

    return 0;
}
