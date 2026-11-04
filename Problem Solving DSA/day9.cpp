
#include <iostream>
using namespace std;
class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
    }

    int dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return arr[front++];
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
    bool isFull()
    {
        return rear == capacity - 1;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{

    // Queue q1= Queue(5);

    // q1.enqueue(45);
    // q1.enqueue(67);
    // q1.enqueue(23);
    // q1.enqueue(88);
    // q1.enqueue(84);
    // q1.enqueue(84);

    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();

    // cout<<q1.isEmpty()<<endl;
    // cout<<q1.peek()<<endl;
    // q1.display();

    // cout<<q1.isFull()<<endl;
    
    return 0;
}
