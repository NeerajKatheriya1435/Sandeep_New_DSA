
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int value){
            data=value;
            next=nullptr;
        }
};

class LinkedList{

    public:
        Node *head;
        LinkedList(){
            head=nullptr;
        }

        void insertAtbegining(int value){
            Node *newNode = new Node(value);
            newNode->next=head;
            head=newNode;
        }
        void insertAtEnd(int value){
            Node *newNode=new Node(value);
            if(head==nullptr){
                insertAtbegining(value);
                return;
            }
            Node *temp=head;
            while (temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }

        void insertAtPosition(int pos,int value){

            Node *newNode=new Node(value);

            if(pos==0){
                insertAtbegining(value);
                return;
            }
            Node* temp=head;

            for (int i = 1; i < pos && temp!=nullptr; i++)
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }

        void displayData(){
            Node *temp=head;

            if(temp==nullptr){
                cout<<"List is empty"<<endl;
            }

            while (temp!=nullptr)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }

        void deleteAtBegining(){
            if(head==nullptr){
                cout<<"List is Empty"<<endl;
                return;
            }
            Node *temp=head;
            head=head->next;
            delete temp;
        }
        void deleteAtEnd(){
            if(head==nullptr){
                cout<<"List is Empty"<<endl;
                return;
            }
            Node *temp=head;
            while (temp->next->next!=nullptr)
            {
                temp=temp->next;
            }
            delete temp->next;
            temp->next=nullptr;
        }
};

int main()
{
    
    LinkedList l1;
    l1.insertAtbegining(45);
    l1.insertAtEnd(34);
    l1.insertAtEnd(24);
    l1.insertAtEnd(54);
    // l1.insertAtbegining(55);
    // l1.insertAtPosition(2,788);
    // l1.insertAtPosition(1,453);
    // l1.insertAtEnd(90);

    // l1.deleteAtBegining();
    // l1.deleteAtBegining();
    l1.deleteAtEnd();

    l1.displayData();





    return 0;
}
