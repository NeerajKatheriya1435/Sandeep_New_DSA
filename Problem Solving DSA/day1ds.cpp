
#include <iostream>
using namespace std;
class Array{
    private:
        int *arr;
        int capacity;
        int length;

    public:
        Array(int size){
            capacity=size;
            arr=new int[capacity];
            length=0;
        }

        void insertAtLast(int value){
            arr[length]=value;
            length++;
        }
        void insertAtPosition(int pos,int value){
            if(length==capacity){
                cout<<"Array is full"<<endl;
                return;
            }
            if(pos<0 || pos>length){
                cout<<"Invalid position"<<endl;
                return;
            }
            for (int i = length; i > pos; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[pos]=value;
            length++;
        }

        void display(){
            for (int i = 0; i < length; i++)
            {
                cout<<arr[i]<<endl;
            }
            
        }
        int search(int value){
            for (int i = 0; i < length; i++)
            {
                if(arr[i]==value){
                    return 1;
                }
            }
            return 0;
        }


        void remove(int pos){
            if(pos<0 || pos>=length){
                cout<<"Inavlid Position"<<endl;
                return;
            }
            if(length==0){
                cout<<"Array is empty"<<endl;
                return;
            }

            for (int i = pos; i < length; i++)
            {
                arr[i]=arr[i+1];
            }
            length--;
            
        }
        int size(){
            return length;
        }
};

int main()
{
    
    Array a1=Array(9);
    a1.insertAtLast(56);
    a1.insertAtLast(67);
    a1.insertAtLast(47);
    a1.insertAtPosition(1,58);
    a1.insertAtLast(90);
    a1.insertAtPosition(4,679);
    a1.remove(4);
    a1.display();

    // cout<<a1.search(56);
    // cout<<a1.search(5566)<<endl;
    // cout<<a1.size()<<endl;

    return 0;
}
