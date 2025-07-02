/*
name : muhammad adam irfan bin rusli
id : 22011423
group : 1
lab : 3
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) : name(name), next_ptr(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        }
    }

    void add_element(const string& name) {
        Node* node = new Node(name);
        if (!head) {
            head = tail = node;
        } else {
            tail->next_ptr = node;
            tail = node;
        }
    }

    void display_list() const {
        Node* current = head;
        if (!current) {
            cout << "List is empty\n";
            return;
        }
        while (current) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "nullptr\n";
    }

    void delete_by_value(const string& val) {
        if (!head) return;

        if (head->name == val) {
            Node* temp = head;
            head = head->next_ptr;
            delete temp;
            if (!head) tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next_ptr && current->next_ptr->name != val) {
            current = current->next_ptr;
        }

        if (current->next_ptr) {
            Node* temp = current->next_ptr;
            current->next_ptr = temp->next_ptr;
            if (temp == tail) tail = current;
            delete temp;
        }
    }
}
