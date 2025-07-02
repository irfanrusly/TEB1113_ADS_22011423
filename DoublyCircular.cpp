/*
name : muhammad adam irfan bin rusli
id : 22011423
group : 1
lab : L4 (circular doubly)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(string name, Node* next_ptr = nullptr, Node* prev_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
        this->prev_ptr = prev_ptr;
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
            node->next_ptr = node;
            node->prev_ptr = node;
        } else {
            node->next_ptr = head;
            node->prev_ptr = tail;
            tail->next_ptr = node;
            head->prev_ptr = node;
            tail = node;
        }
    }

    void display_list() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " <-> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "(back to head)" << endl;
    }

    void delete_by_value(string val) {
        if (!head) return;

        Node* current = head;
        Node* to_delete = nullptr;

        // Find node to delete
        do {
            if (current->name == val) {
                to_delete = current;
                break;
            }
            current = current->next_ptr;
        } while (current != head);

        if (!to_delete) return; // Not found

        // If only one node
        if (head == tail && to_delete == head) {
            delete head;
            head = tail = nullptr;
            return;
        }

        // Update links
        to_delete->prev_ptr->next_ptr = to_delete->next_ptr;
        to_delete->next_ptr->prev_ptr = to_delete->prev_ptr;

        // Update head or tail if needed
        if (to_delete == head) head = to_delete->next_ptr;
        if (to_delete == tail) tail = to_delete->prev_ptr;

        delete to_delete;
    }

    Node* get_head() const {
        return head;
    }

    void clear_memory() {
        if (!head) return;

        Node* current = head;
        Node* start = head;
        do {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        } while (current != start);

        head = tail = nullptr;
    }

    ~LinkedList() {
        clear_memory();
    }
};

int main() {
    // Create nodes
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alee");

    // Create list and add nodes
    LinkedList linkedlst;
    linkedlst.add_element(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    cout << "Original list: ";
    linkedlst.display_list();

    linkedlst.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    linkedlst.display_list();

    // Destructor automatically cleans up memory
    return 0;
}
