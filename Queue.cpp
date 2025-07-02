/*
name : muhammad adam irfan bin rusli
id : 22011423
group : 1
lab: L6 (queue)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
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

        if (!rear) {
            front = rear = node;
        } else {
            rear->next_ptr = node;
            rear = node;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Removing: " << temp->name << endl;
