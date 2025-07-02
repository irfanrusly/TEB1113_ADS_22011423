/*
name : muhammad adam irfan bin rusli
id : 22011423
group: 1
lab : L6 (circular queue)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(const string& name) {
        Node* node = new Node(name);

        if (!front) {
            front = rear = node;
            rear->next_ptr = front; // circular link
        } else {
            rear->next_ptr = node;
            rear = node;
            rear->next_ptr = front; // maintain circularity
        }
    }

    void dequeue()
