#include <iostream>
using namespace std;

class Deque
{
private:
    int *arr;
    int front, rear, size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    // Check full
    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }
    // Check empty
    bool isEmpty()
    {
        return front == -1;
    }
    // Insert at front
    void insertFront(int x)
    {
        if (isFull())
        {
            cout << "Deque Overflow!" << endl;
            return;
        }
        if (front == -1)
        { // empty
            front = rear = 0;
        }

        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
    }

    void insertRear(int x)
    {
        if (isFull())
        {
            cout << "Deque Overflow!" << endl;
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }

        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }
    // Display deque
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
    // Delete at front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow!" << endl;
            return;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    // Delete at rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow!" << endl;
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main()
{

    Deque d1 = Deque(5);
    d1.insertFront(45);
    d1.insertFront(34);
    d1.insertRear(78);
    d1.insertRear(12);
    d1.insertFront(89);

    d1.deleteFront();
    d1.deleteRear();

    // d1.display();
cout<<d1.getFront();
cout<<d1.getRear();
    return 0;
}
