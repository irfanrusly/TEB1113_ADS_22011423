/*
id: 22011705
name: amir
group: g1
lab: L6 (array queue)
*/

#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    string *arr;     // Array to store queue elements
    int front;       // Index of front element
    int rear;        // Index of rear element
    int capacity;    // Maximum capacity of the queue
    int currentSize; // Current number of elements in the queue

public:
    Queue(int size = 100)
    {
        capacity = size;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    bool isFull()
    {
        return currentSize == capacity;
    }

    void enqueue(string name)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = name;
        currentSize++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Removing: " << arr[front] << endl;
        front = (front + 1) % capacity;
        currentSize--;
    }

    void display_queue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        int count = 0;
        int index = front;
        while (count < currentSize)
        {
            cout << arr[index] << " <- ";
            index = (index + 1) % capacity;
            count++;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Queue queue(100);

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");
    queue.enqueue("Abu");

    cout << "Initial Queue: ";
    queue.display_queue();

    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    return 0;
}
