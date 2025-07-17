/*
name : muhammad adam irfan bin rusli
id : 22011423
group : 1
lab : L8 (binary search tree)
*/

#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *right;

    Node(string n)
    {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;

    void insert_recursive(Node* current, string name)
    {
        if (name < current->name)
        {
            if (!current->left)
                current->left = new Node(name);
            else
                insert_recursive(current->left, name);
        }
        else
        {
            if (!current->right)
                current->right = new Node(name);
            else
                insert_recursive(current->right, name);
        }
    }

    void destroy_tree(Node* node)
    {
        if (!node) return;
        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    ~BinarySearchTree()
    {
        destroy_tree(root);
    }

    void insert(string name)
    {
        if (!root)
            root = new Node(name);
        else
            insert_recursive(root, name);
    }

    void display_inorder(Node *node)
    {
        if (!node) return;
        display_inorder(node->left);
        cout << " " << node->name;
        display_inorder(node->right);
    }

    void display_preorder(Node *node)
    {
        if (!node) return;
        cout << " " << node->name;
        display_preorder(node->left);
        display_preorder(node->right);
    }

    void display_postorder(Node *node)
    {
        if (!node) return;
        display_postorder(node->left);
        display_postorder(node->right);
        cout << " " << node->name;
    }

    Node* get_root()
    {
        return root;
    }
};

int main()
{
    BinarySearchTree bst;
    string names[] = {"E", "B", "G", "A", "D", "F", "C"};

    for (const string& name : names)
    {
        bst.insert(name);
    }

    cout << "In-order   :";
    bst.display_inorder(bst.get_root());
    cout << "\nPre-order  :";
    bst.display_preorder(bst.get_root());
    cout << "\nPost-order :";
    bst.display_postorder(bst.get_root());

    return 0;
}
