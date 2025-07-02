/*
name : muhammad adam irfan bin rusli
id : 22011423
group : 1
lab: L4 (singly circular)
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

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(Node* node) {
        if (!node) return;

        if (!head) {
            head = tail = node;
            node->next_ptr = head;  // Circular link
        } else {
            tail->next_ptr = node;
            tail = node;
            tail->next_ptr = head;  // Maintain circular link
        }
    }

    void display_list() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "head (" << head->name << ")" << endl;
    }

    void delete_by_value(string val) {
        if (!head) return;

        Node* current = head;
        Node* prev = tail;
        bool found = false;

        do {
            if (current->name == val) {
                found = true;
                if (current == head) {
                    if (head == tail) { // Only one node
                        delete head;
                        head = tail = nullptr;
                        return;
                    } else {
                        head = head->next_ptr;
                        tail->next_ptr = head;
                        delete current;
                        return;
                    }
                } else {
                    prev->next_ptr = current->next_ptr;
                    if (current == tail)
                        tail = prev;
                    delete current;
                    return;
                }
            }
            prev = current;
            current = current->next_ptr;
        } while (current != head);

        if (!found)
            cout << "Value not found: " << val << endl;
    }

    Node* get_head() const {
        return head;
    }

    void clear_memory() {
        if (!head) return;

        Node* current = head;
        Node* next;
        do {
            next = current->next_ptr;
            delete current;
            current = next;
        } while (current != head);

        head = tail = nullptr;
    }

    ~LinkedList() {
        clear_memory();
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alee");

    LinkedList linkedlst;
    linkedlst.add_element(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    cout << "Original list: ";
    linkedlst.display_list();

    linkedlst.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    linkedlst.display_list();

    // Destructor will automatically clean up memory
    return 0;
}
