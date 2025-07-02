/*
name : muhammad adam irfan bin rusli 
id : 22011423
group : 1
lab : L5 (stack)
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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(const string& name) {
        Node* node = new Node(name);
        node->next_ptr = top;
        top = node;
    }

    void pop() {
        if (!top) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        top = top->next_ptr;
        delete temp;
    }

    string peek() const {
        if (!top) {
            cout << "Stack is empty" << endl;
            return "";
        }
        return top->name;
    }

    void display_stack() const {
        if (!top) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* current = top;
        cout << "Stack (top -> bottom): ";
        while (current) {
            cout << current->name;
            current = current->next_ptr;
            if (current) cout << " -> ";
        }
        cout << endl;
    }

    bool is_empty() const {
        return top == nullptr;
    }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next_ptr;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    // Push elements
    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Alee");

    // Display
    stack.display_stack();

    // Peek
    cout << "Top element: " << stack.peek() << endl;
    stack.display_stack();

    // Pop
    stack.pop();
    cout << "After popping top element: ";
    stack.display_stack();

    // Destructor will auto-clean memory
    return 0;
}
